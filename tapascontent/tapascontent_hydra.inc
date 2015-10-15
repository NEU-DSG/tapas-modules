<?php

/**
 * @file
 * tapascontent_hydra.inc
 *
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

// Takes all arrays detected in the $data array and translates them into arrays that 
// php's curl functionality will actually handle.
// So if we have $data = { "members" => ['bill', 'john', 'joe']}
// We wind up with $data = { "members[0]" => "bill", "members[1]" => "john", 
// "members[2]" => "joe"}
function _tapashydra_associative_arrays($data) {
	foreach($data as $key => $value) {
		if(is_array($value)){
			foreach($value as $vkey => $vvalue) {
        $data[$key.'['.$vkey.']'] = $vvalue; 
			}	
      unset($data[$key]);
		}
	}

	return $data;
}

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
	$data_sanitized = _tapashydra_associative_arrays($data);

  $curl_options = array(
		CURLOPT_POST => TRUE,
		CURLOPT_POSTFIELDS => $data_sanitized,
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
	$uniqueid = tapas_simple_fieldval($node, TAPAS_FIELD_PREFIX . 'slug');
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'DELETE');
	
	drupal_set_message("Calling the followign URL for delete: $url_base/$uniqueid");

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

function tapashydra_get_tei($did, $type) {

	if(!isset($did) || !isset($type)) {
		drupal_set_message("One of the values is not set. DID: $did Type: $type");
	}

	$url = TAPAS_BASE_API_URL . "/files/$did/$type";

	drupal_set_message("URL is $url");
	
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'GET');
		
	return _tapashydra_curlcall($url, $curl_options);
}

// ====================================================================================
// Other helper functions, used internally and externally.
// ====================================================================================


/**
 * Helper. Given a file field object, returns the HTTP filestring.
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

	$file_objects = array();
	foreach ($fielditems as $field) {
		$file_objects[] = file_load($field['fid']);	
	}

  $filestrings = array();
  foreach($file_objects as $file) { 
    $filestrings[] = drupal_realpath($file->uri);
  }
  
	return $filestrings;
}

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

	//drupal_set_message("Getting the field items for node " . $node->nid . " with fieldname $field_name and param $param.");
	$value_list = field_get_items('node', $node, $field_name);

	if(!$value_list) {
		//drupal_set_message("The value_list for $param WAS empty.");
		return;
	} else {
		//drupal_set_message("The value_lists for $param was NOT empty.");
	}

	//drupal_set_message("value_list is: " . http_build_query($value_list, '', '|'));

	$new_array = array();
	$i = 0;
	foreach ($value_list as $value) {
		$new_array[] = $value_list[$i]['value'];
		$i++;
	}

	//return tapashydra_php_to_http_array($new_array, $param);
	return tapashydra_http_array($new_array, $param);

}

function _tapashydra_watchdog_debug($message) { 
  watchdog('tapascontent', $message, [], WATCHDOG_DEBUG);
}
