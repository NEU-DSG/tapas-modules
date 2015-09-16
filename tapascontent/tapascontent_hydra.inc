<?php

/**
 * @file /tapascontent/tapascontent_hydra.inc
 * Encapsulates the calls to the Hydra API.
 * 
 * @author Linda Moss (Github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

include_once('tapascontent_constants.inc');

// ====================================================================================
// POST and DELETE functions called from outside the file.
// ====================================================================================

/**
 * POST new or updated project, collection, or tei recrd to Hydra.
 *
 * @param array $data: The curl data fields to post.
 * @param string $url_base: Which API url to point to.
 *
 * @return string The return message passed back by Hydra.
 */

function tapashydra_post($data, $url_base) {
	
	$url = "$url_base/" . $data['uniqueid'];

	drupal_set_message("@@ URL: $url");
	drupal_set_message("@@ data: " . http_build_query($data, '', '|'));

	$curl_options = array(
		CURLOPT_POST => TRUE,
		CURLOPT_POSTFIELDS => $data,
	);

	return _tapashydra_curlcall($url, $curl_options);

}

/**
 * DELETE a record from Hydra.
 *
 * @param string $url_base: Which API url to point to.
 * @param node $node: The Drupal node for the record to be deleted.
 *
 * @return string: The message returned by Hydra.
 */

function tapashydra_delete($url_base, $node) {

	$uniqueid = tapashydra_simple_fieldval($node, TAPAS_FIELD_PREFIX . 'slug');
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'DELETE');

	return _tapashydra_curlcall("$url_base/$uniqueid", $curl_options);

}

// ====================================================================================
// Internal functions handling the POST and DELETE.
// ====================================================================================

/**
 * Perform the actual POST or DELETE curl call.
 * @internal: Access via tapashydra_post or tapashydra_delete, not directly.
 *
 * @param string $url: Which url to POST or DELETE to (including slug/uniqueid).
 * @param array $options: Additional curl options to set.
 *
 * @return string" The Hydra result message.
 */

function _tapashydra_curlcall($url, $options) {

	$header = array('Authorization: Token token=' . TAPASHYDRA_AUTH_TOKEN);

	$common_opts = array(
		CURLOPT_URL => $url,
		CURLOPT_HTTPHEADER => $header,
	);


	if (TAPAS_INCLUDE_CURL_DEBUG) {
		// Deubuggin node: if array_merge is used, the keys change to 0, 1, 2, 3, etc, 
		// and everything breaks.
		$curlopt = $options + _tapashydra_debugopts() + $common_opts;
	} else {
		$curlopt = $options + $common_opts;
	}
	
	$ch = curl_init($url);
	if (!curl_setopt_array($ch, $curlopt)) {
		drupal_set_message("CURL error: One or more of the options falied to set.");
	}
	$result = curl_exec($ch);

	if (TAPAS_INCLUDE_CURL_DEBUG) {
		_tapashydra_curl_messages($ch, $result);
	}

	curl_close($ch);
	return $result;

}

/**
 * @internal Provdes an array of curloptions used for debugging.
 */

function _tapashydra_debugopts() {

	if (TAPAS_INCLUDE_CURL_DEBUG) {
		$result = array(
			CURLOPT_RETURNTRANSFER => TRUE,
			CURLOPT_VERBOSE => TRUE,
			CURLINFO_HEADER_OUT => TRUE,
			CURLOPT_HEADER => TRUE,
		);
	} else {
		$result = array();
	}

	return $result;

}


/**
 * @internal Prints curl debugging information to the message area.
 *
 * @param $ch, the curl-handle we are printing results from.
 * @param $result, the result passed back from hydra.
 */

function _tapashydra_curl_messages($ch, $result) {

		$header_size = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
		$return_header = substr($result, 0, $header_size);
		$body = substr($result, $header_size);

		drupal_set_message("### Header ### " . $return_header);
		drupal_set_message("### Body ### " . $body);
		drupal_set_message("### Header Out ### " . curl_getinfo($ch, CURLINFO_HEADER_OUT));

}

// ====================================================================================
// Retrieving and displaying TEI records from Hydra
// ====================================================================================



// ====================================================================================
// Other helper functions, used internally and externally.
// ====================================================================================

/**
 * Helper. Syntactic sugar to safely get the value of a Drupal node field.
 *
 * Only works for fields that have a simple string or numeric value. Not for
 * use with fields that contain a file, etc.
 *
 * @param $node: The Drupal node who's field value we are checking.
 * @param $field_name: The name of the field.
 * @param $val_if_unset: The string to return if the field value is unset. (default '')
 * @param $delta: If the field has more than one value, which to return (default 0)
 *
 * @return string or number: The value of the field.
 */

function tapashydra_simple_fieldval($node, $field_name, $val_if_unset='', $delta=0) {

	$array = field_get_items('node', $node, $field_name);

	if ($array == FALSE) {
		return $val_if_unset;
	}
	else {
		return $array[$delta]['value'];
	}

}

/**
 * Helper. Given a file handled, returns the HTTP filestring.
 *
 * This method (string beginning with '@') for posting files to HTTP is depricated in 
 * HTTP, but the version of PHP we are using does not yet support the new (object-based)
 * way of posting files, so we need to stick with this.
 */

function tapashydra_filestring($file_handle) {
	return '@' . drupal_realpath($file_handle->uri);

}

/**
 * Helper. Given a node and a file-field name, return the HTTP string for the FIRST file
 *
 * i.e. if there is one file, that string will be returned. If there is more than one, only
 * the first will be returned.
 */

function tapashydra_filestring_from_field($node, $field_name) {
	$fielditems = field_get_items('node', $node, $field_name);
	if (!$fielditems) {
		return;
	}
	$file_handle = file_load($fielditems[0]['fid']);
	return tapashydra_filestring($file_handle);
}

/**
 * Helper. Get an array of file handles from a filefield on a node. 
 *
 * @param node $node The node.
 * @param string $field_name the name of the field to get the files from.
 *
 * @return array An array of file-handles, one for each file listed in the field.
 */

function tapashydra_filearray_from_field($node, $field_name) {
	$fielditems = field_get_items('node', $node, $field_name);

	if (!$fielditems) {
		return;
	}

	$handle_array = array();
	foreach ($fielditesm as $item) {
		$handle_array[] = file_load($item['fid']);	
	}
	
	return $handle_array;

}
/**
 * Helper. Given a node and a field-name, gets the filestring for posting the file so named.
 *
 * Note: this way of passing a file is depricated in newer versions of PHP, but we have
 *    an older version that doesn't have the new, object-based way available yet.
 */
//function tapashydra_filestring($node, $field_name, $val_if_unset='', $delta=0) {

	//$fielditems = field_get_items('node', $node, $field_name);

	//if (!$array) {
		//drupal_set_message("The array for $fielditems was empty.");
		//return $val_if_unset;
	//}


	//$i = 0;
	//foreach ($fielditems as $item) {
		//$filestring
			
	//}

	//if ($array) {
		//drupal_set_message("@@ The array for $field_name was NOT empty.");
		//$thumb_file = file_load($node->tc_field_image['und'][0]['fid']);
		//return '@' . drupal_realpath($thumb_file->uri);
	//} else {
		//drupal_set_message("@@ The array for $field_name WAS empty.");
		//return $val_if_unset;
	//}

//}	


/**
 * Helper. Builds an HTTP array from multiple values in a Drupal field.
 *
 * @param node $node: A drupal node.
 * @param string $field_name: the name of a field that allows multiple values.
 * @param string $param : the name of the http parameter.
 *
 * @return: A string parsing the field values into an HTTP style array.
 */

function tapashydra_field_to_http_array($node, $field_name, $param) {

	$value_list = field_get_items('node', $node, $field_name);

	if(!$value_list) {
		drupal_set_message("@@The value_list for $param WAS empty.");
		return;
	} else {
		drupal_set_message("@@The value_lists for $param was NOT empty.");
	}

	drupal_set_message("@@value_list is: " . http_build_query($value_list, '', '|'));

	$new_array = array();
	$i = 0;
	foreach ($value_list as $value) {
		$new_array[] = $value_list[$i]['value'];
	}

	return tapashydra_php_to_http_array($new_array, $param);

}

/**
 * Helper. Converts a php array into an HTTP-formatted array.
 *
 * @param array(): The array to convert.
 * @param string: The http parameter receiving the array.
 *
 * @return string: The HTTP formatted array. (or FALSE, if the input array was empty).
 */

function tapashydra_php_to_http_array($array = array(), $param) {

	if ($array) {
		drupal_set_message("There IS a php-to-http array for $param.");
	} else {
		drupal_set_message("There is NOT a php-to-http array for $param.");
		return FALSE;
	}

	//$outstr_arr = '';
	$outstr_arr = array();
	$i = 0;

	foreach ($array['node'] as $item) {
		$outstr_arr[] = "$param\[$i\]=$item";
	}

	return implode('&amp;', $outstr_arr);

}
