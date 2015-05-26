<?php

/**
 * Runs the validation scripts on the given TEI file
 *
 * If errors are found at certain stages, the function my return the 
 * error list early rather than continuing to run the rest of the validation
 * checks.
 */
function _tapasrecord_validate_xslt($teiDOM) {

	$xsltDOM = new DOMDocument();
	$xslt_path = drupal_get_path('module', 'tapasrecord') . TAPAS_VALIDATION_XSLT_SUBDIRECTORY;
	$iterator = new \DirectoryIterator($xslt_path);

	$known_errors = array();
	$known_err_found = FALSE;

	foreach ($iterator as $next_xslt) {
		$ext = $next_xslt->getExtension();
		if ($ext == 'xsl' || $ext == 'xslt') {
			$result = tapasrecord_apply_stylesheet($next_xslt->getPathname(), $teiDOM, $errors);
		
			// $errors contains any libxml errors encountered while trying to run the validation
			// $result contains one of:
			//		FALSE, if the xslt was unable to run
			//		an empty string, if the validation ran without errors
			//		a non-empty string, containing the validation error, otherwise.
		
			if ($result === FALSE) {
				drupal_set_message(TAPAS_ERROR_UNKNOWN_ERROR);
			} elseif ($result) {
				drupal_set_message($result, 'warning');
				$known_err_found = TRUE;
			}
			
		} // if $ext xsl or xslt
	} // foreach
	
	if ($known_err_found) {
		$errors[] = TAPAS_ERROR_KNOWN_FILE_ERROR;
	}

	return $errors;
}

/**
 * Extract metadata from the TEI header
 */

function _tapasrecord_extract_tei_metadata($teiDOM) {

	$teiXPATH = new \DOMXPath($teiDOM);
	$teiXPATH->registerNamespace('tei', 'http://www.tei-c.org/ns/1.0');
	
	$result = $teiXPATH->query("//tei:teiHeader/tei:fileDesc/tei:titleStmt/tei:title");


	drupal_set_message("Title: " . $result->item(0)->nodeValue);
	if (!$result->item(0)) {
		drupal_set_message("there is no item zero");
	}
	foreach($result as $title) {
		drupal_set_message("Result: " . $title->nodeValue);
	}
	drupal_set_message("Length: " . $result->length);

	return "The metadata extraction function returned successfully.";
}

/**
 * Create the TFC from the uploaded TEI file.
 *
 * @param $teiDOM: the DOMDocument object containing the TEI file to transform
 * @param $file: the Drupal file object, so we can get the non-temp name.
 *
 * @return: an array of strings containing any errors found (an empty array if none)
 */

function _tapasrecord_run_transform($teiDOM, $file) {

	$transform_path = drupal_get_path('module', 'tapasrecord') . '/' . TAPAS_TFC_TRANSFORM_FILENAME;
	$errors = array();
	$tfc_result = tapasrecord_apply_stylesheet($transform_path, $teiDOM, $errors);

	if ($errors || !$tfc_result) {
		$errors[] = TAPASRECORD_ERROR_MESSAGE_UNKNWON;
		return $errors;
	}

	$basename = preg_replace('/\.[^.]+$/','',$file->filename);
	$tfc_saveloc = _tapasrecord_get_file_upload_location() . '/' . $basename . "_TFC.xml";

	file_unmanaged_save_data($tfc_result, $tfc_saveloc, FILE_EXISTS_REPLACE);

	return $errors;

}





// ----------------------------------------------
// XSLT Helpers
// ----------------------------------------------


/**
 * Loads the file at $filepath to a DOMDocument
 *
 * @param $filepath: which file to load into the DOM
 * @param $err_msg: Custom error message to display if there are problems
 * @param &$errors: any non-supressed error strings will be added to this array
 * @param $show_raw: whether to include the raw libxml errors in &$errors
 *
 * @return The DocumentDOM containing the file at $filepath
 */
function tapasrecord_domdoc_load($filepath, &$errors, $show_raw=TRUE) {
	$docDOM = new DOMDocument();
	_tapasrecord_libxml_call($docDOM, 'load', $filepath, $errors, $show_raw);
	
	return $docDOM;

}

/**
 * Applies a stylesheet to an XML DOM
 *
 * @param $xsltpath: the stylesheet to apply
 * @param $xmlDOM: a DOMDocument containing the xml file on which to run it
 * @param $&errors: any error strings will be added to this array
 *
 * @return 
 *    -- If the XSLT ran successfully, this will be a string containing the
 *       result (the string may be empty)
 *    -- If the XSLT was unable to run, this will be FALSE.
 *
 * Note that because a successful run could potentially return an empty string,
 *   checks against the result should be $result === FALSE, not $result == FALSE.
 */
function tapasrecord_apply_stylesheet($xsltpath, $xmlDOM, &$errors) {
	
	$xsltDOM = tapasrecord_domdoc_load($xsltpath, $errors);

	if ($errors) {
		drupal_set_message(TAPAS_ERROR_OUR_END , "##unable to read stylesheet at $xsltpath##");
		return FALSE;
	}
	
	$proc = new \XSLTProcessor();	
	_tapasrecord_libxml_call($proc, 'importStylesheet', $xsltDOM, $errors);
	if ($errors) {
		drupal_set_message(TAPAS_ERROR_OUR_END , "##unable to import stylesheet at $xsltpath##");
		return FALSE;
	}

	return _tapasrecord_libxml_call($proc, 'transformToXML', $xmlDOM, $errors, TRUE);
}


/**
 * Runs a libxml function and takes control of the error display.
 *
 * libxml displays errors on the webpage that cannot be caught as exceptions-- the only
 *    way (to my knowledge) to prevent the raw error from being displayed to the user
 *    is to temporarily hijack libxml's error reporting. I dislike
 *    supressing errors, but we want to be able to provide a non-confusing message if,
 *    for instance, the user tries to upload a non-xml file in the TEI field.
 *
 * @param &$obj: the object on which to run the function
 * @param $func: the name of the function to call
 * @param $param: parameter to give the function (currently only one param supported)
 * @param &$errors: array in which to return all non-suppressed errors
 *
 * @return Returns the result that the called function returns.
 */
function _tapasrecord_libxml_call(&$obj, $func, $param, &$errors) {

	assert(is_callable(array($obj, $func)));

	libxml_use_internal_errors(TRUE);

	$result = call_user_func(array($obj, $func), $param);

	$libxml_errors = libxml_get_errors();
	foreach ($libxml_errors as $e) {
		$new_err = _tapasrecord_interpret_libxml_err($e->message);
		if ($new_err) {
			$errors[] = "(More info on why: " . $new_err . ")";
		}
	}
		
	libxml_clear_errors();
	// give libxml control of its own error handling again.
	libxml_use_internal_errors(FALSE);

	return $result;

}

/**
 * Translates some common libxml errors into plain english for the user.
 *
 * @param $err_msg: The error message from libxml
 *
 * @return string: empty if the function displayed an error message 
 *                 or otherwise handed the error itself, or a string
 *                 error message for the calling function to handle.
 */
function _tapasrecord_interpret_libxml_err($err_msg) {

	// I tried to use a switch statement, but strings didn't register as
	// matches even when I included the whitespace.

	if (strpos($err_msg, "invalid name prefix 'xml'") !== FALSE) {
	
			$new_err = "The W3C forbids any prefix beginning with 'xml' (except for xml: when used for the default w3c schema)" .
				" and as a result, the parser that we are using chokes on these files. Please check this file for the use of" .
				" a prefix beginning with 'xml', and if found, prepend another character to all instances to make it legal." .
				" For more info, see " .
				"<a href='http://www.w3.org/TR/xml-names/#xmlReserved'>XML: Reserved Prefixes and Namespace Names</a>";
			drupal_set_message($new_err, 'warning');
			return;
	}

	return $err_msg;

}