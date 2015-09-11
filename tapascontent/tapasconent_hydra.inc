<?php

/**
 * @file /tapascontent/tapascontent_hydra.inc
 * Encapsulates the calls to the Hydra API.
 * 
 * @author Linda Moss (Github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */



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

function tapas_hydra_post($data, $url_base) {
	
	$url = "$url_base/" . $data['uid'];

	$curl_options = array(
		CURLOPT_POST => TRUE,
		CURLOPT_POSTFIELDS => $data,
	);

	return _tapas_hydra_curlcall($url, $curl_options);

}

/**
 * DELETE a record from Hydra.
 *
 * @param string $url_base: Which API url to point to.
 * @param node $node: The Drupal node for the record to be deleted.
 *
 * @return string: The message returned by Hydra.
 */

function tapas_hydra_delete($url_base, $node) {

	$uniqueid = tapashydra_simple_fieldval($node, TAPAS_FIELD_PREFIX . 'slug');
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'DELETE');

	return _tapas_hydracurl_call("$url_base/$uniqueid", $curl_options);

}

// ====================================================================================
// Internal functions handling the POST and DELETE.
// ====================================================================================

/**
 * Perform the actual POST or DELETE curl call.
 * @internal: Access via tapas_hydra_post or tapas_hydra_delete, not directly.
 *
 * @param string $url: Which url to POST or DELETE to (including slug/uid).
 * @param array $options: Additional curl options to set.
 *
 * @return string" The Hydra result message.
 */

function _tapas_hydra_curlcall($url, $options) {

	$header = array('Authorization: Token token=' . TAPAS_HYDRA_AUTH_TOKEN);

	$common_opts = array(
		CURLOPT_URL => $url,
		CURLOPT_HTTPHEADER => $header,
	);


	if (TAPASHYDRA_INCLUDE_CURL_DEBUG) {
		// Deubuggin node: if array_merge is used, the keys change to 0, 1, 2, 3, etc, 
		// and everything breaks.
		$curlopt = $options + _tapas_hydra_debugopts() + $common_opts;
	} else {
		$curlopt = $options + $common_opts;
	}
	
	$ch = curl_init($url);
	if (!curl_setopt_array($ch, $curlopt)) {
		drupal_set_message("CURL error: One or more of the options falied to set.");
	}
	$result = curl_exec($ch);

	if (TAPASHYDRA_INCLUDE_CURL_DEBUG) {
		_tapashydra_curl_messages($ch, $result);
	}

	curl_close($ch);
	return $result;

}

/**
 * @internal Provdes an array of curloptions used for debugging.
 */

function _tapas_hydra_debugopts() {

	if (TAPASRECORD_INCLUDE_CURL_DEBUG) {
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

/**
 * Internal. Builds the data array to post to hydra on instert/update
 *
 * @param $node: The node that will be posted.
 */

function _tapasrecord_httpdata($node, $uid) {

	$data = array(
		'uid' => $uid,
		'collection_dids' => tapashydra_php_to_http_array(
			og_get_entity_groups('node', $node), 'collection_dids'),
		'depositor' => $node->uid,
		'file_types' => tapashydra_drupal_field_to_http_array($node, 'field_tapas_tei_type'),
		'display_author' => tapashydra_simple_fieldval($node, 'tc_display_authors'),
		'display_contributors' => tapashydra_drupal_field_to_http_array($node, 'tc_display_contributors'),
		'display_date' => tapashydra_simple_fieldval($node, 'tc_timeline_date'), // I thought we weren't sending this to Hydra?
		'tei:'=> tapashydra_filestring($node, 'tapas_teifile'),
		'support_files' => _tapasrecord_auxillary_curlzip($node),
	);

	return $data;
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
 * Helper. Given a node and a field-name, gets the filestring for posting the file so named.
 *
 * Note: this way of passing a file is depricated in newer versions of PHP, but we have
 *    an older version that doesn't have the new, object-based way available yet.
 */
function tapashydra_filestring($node, $field_name, $val_if_unset='', $delta=0) {

	$array = field_get_items('node', $node, $field_name);

	if ($array) {
		$thumb_file = file_load($node->tc_field_image['und'][0]['fid']);
		return '@' . drupal_realpath($thumb_file->uri);
	} else {
		return $val_if_unset;
	}

}	


/**
 * Helper. Builds an HTTP array from multiple values in a Drupal field.
 *
 * @param $node: A drupal node.
 * @param $field_name: the name of a field that allows multiple values.
 *
 * @return: A string parsing the field values into an HTTP style array.
 */

function tapashydra_drupal_field_to_http_array($node, $field_name) {

	$value_list = field_get_items('node', $node, $field_name);

	$new_array = array();
	$i = 0;
	foreach ($value_list as $value) {
		$new_array[] = $value_list[$i]['value'];
	}

	return tapashydra_php_to_http_array($new_array);

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

	if (!$array()) {
		return FALSE;
	}

	$outstr_arr = '';
	$i = 0;

	foreach ($array as $item) {
		$outstr_arr .= "$param\[$i\]=$item";
	}

	return implode('&amp;', $outstring_arr);

}
