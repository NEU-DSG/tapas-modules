<?php
// ===========================================
// XSLT Processing
// ===========================================

/**
 * Runs the validation scripts on the given TEI file, returns any errors
 *
 * If errors are found at certain stages, the function my return the 
 * error list early rather than continuing to run the rest of the validation
 * checks.
 * 
 * @param $teiDOM: the DOMDocument object containing the TEI file
 *
 * @return an array of strings, containing any errors found
 */
function _tapasrecord_validate_xslt($teiDOM) {

	$errors = array();

	$xsltDOM = new DOMDocument();
	$xslt_path = drupal_get_path('module', 'tapasrecord') . TAPAS_VALIDATION_XSLT_SUBDIRECTORY;
	$iterator = new \DirectoryIterator($xslt_path);

	foreach ($iterator as $next_xslt) {
		$ext = $next_xslt->getExtension();
		if ($ext == 'xsl' || $ext == 'xslt') {
			$err_msg = TAPAS_ERROR_MESSAGE_FILE_ERR . 
				": [Unable to validate the TEI file. using " . $next_xslt->getPathname() . "]";
			$result = tapasrecord_apply_stylesheet($next_xslt->getPathname(), $teiDOM, $errors, $err_msg);
		
			// $errors contains any libxml errors encountered while trying to run the validation
			// $result contains one of:
			//		FALSE, if the xslt was unable to rune
			//		an empty string, if the xslt ran without errors
			//		a non-empty string, containing the validation error,
		
			if ($result === FALSE) {
				$errors[] = TAPAS_ERROR_MESSAGE_UNKNOWN;
				return $errors;
			} elseif ($result) {
				$errors[] = $result;
				return $errors;
			}
			
		} // if $ext xsl or xslt
	} // foreach

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
	$err_msg = '##' . t("Unable to process the TEI file.") . '##';	
	$tfc_result = tapasrecord_apply_stylesheet($transform_path, $teiDOM, $errors, $err_msg);

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
function tapasrecord_domdoc_load($filepath, $err_msg, &$errors, $show_raw=TRUE) {
	$docDOM = new DOMDocument();
	_tapasrecord_libxml_call($docDOM, 'load', $filepath, $err_msg, $errors, $show_raw);
	
	return $docDOM;

}

/**
 * Applies a stylesheet to an XML DOM
 *
 * @param $xsltpath: the stylesheet to apply
 * @param $xmlDOM: a DOMDocument containing the xml file on which to run it
 * @param $&errors: any error strings will be added to this array
 * @param $result_err_msg: error to display if there are problems running the XSLT
 *
 * @return the transformed data, as a string
 */
function tapasrecord_apply_stylesheet($xsltpath, $xmlDOM, &$errors, $result_err_msg) {
	
	$err_msg = TAPAS_ERROR_MESSAGE_OUR_END . "##unable to read xslt at $xsltpath##";
	$xsltDOM = tapasrecord_domdoc_load($xsltpath, $err_msg, $errors, TAPASRECORD_SHOW_INTERNAL_ERRS);

	if ($errors) {
		return FALSE;
	}
	
	$proc = new \XSLTProcessor();	
	$err_msg = TAPAS_ERROR_MESSAGE_OUR_END . "##unable to import the xslt stylesheet at $xsltpath##";

	_tapasrecord_libxml_call($proc, 'importStylesheet', $xsltDOM, $err_msg, $errors, TAPASRECORD_SHOW_INTERNAL_ERRS);
	if ($errors) {
		return FALSE;
	}

	$result =  _tapasrecord_libxml_call($proc, 'transformToXML', $xmlDOM, $result_err_msg, $errors, TRUE);
	return $result;
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
 * @param $err_msg: Custom error message to display if there are any errors
 * @param &$errors: array in which to return all non-suppressed errors
 * @param $show_raw: also show the libxml errors, prefixed with "(more info:"
 *
 * @return Returns the result that the called function returns.
 */
function _tapasrecord_libxml_call(&$obj, $func, $param, $err_msg, &$errors, $show_raw=TRUE) {

	assert(is_callable(array($obj, $func)));

	libxml_use_internal_errors(TRUE);

	$result = call_user_func(array($obj, $func), $param);

	$libxml_errors = libxml_get_errors();
	if ($libxml_errors) {
		$errors[] = $err_msg;
		if ($show_raw) {
			foreach ($libxml_errors as $e) {
				$new_err = _tapasrecord_interpret_libxml_err($e->message);
				if ($new_err) {
					$errors[] = "(More info on why: " . $new_err . ")";
				}
			}
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
