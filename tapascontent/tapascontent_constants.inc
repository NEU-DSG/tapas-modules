<?php
/**
 * @file
 * tapascontent_constants.inc
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

// ====================================================================================
// Prefixes for fields and field instances.
// ====================================================================================

/** Prefix used on all tapasfield base names. */
define ('TAPAS_FIELD_PREFIX', 'field_tapas_');
/** Prefix before element names on forms */
//define ('TAPAS_FORM_FIELD', 'tapas_ff_');
/** Prefix before display element names (other than forms) */
//define ('TAPAS_VIEW_FIELD', 'tapas_vf_');


// ====================================================================================
// Content Types.
// ====================================================================================

/** Machine name of the Collection content type. */
define ('TAPAS_COLLECTION', 'tapas_collection');

/** Machine name of the Project content type. */
define ('TAPAS_PROJECT', 'tapas_project');

/** Machine name of the TEI Record content type. */
define ('TAPAS_RECORD', 'tapas_record');




// ====================================================================================
// Content Type Descriptions
// ====================================================================================

/* User-facing descriptions for content types. */
define ('TAPAS_CONTENT_PROJ_DESC', '');
define ('TAPAS_CONTENT_COLL_DESC', '');
define ('TAPAS_CONTENT_REC_DESC', '');

/* User-facing help text for content types. */
define ('TAPAS_CONTENT_PROJ_HELP', '');
define ('TAPAS_CONTENT_COLL_HELP', '');
define ('TAPAS_CONTENT_REC_HELP', '');

// ====================================================================================
//  Hydra API.
// ====================================================================================

// include_once('/var/www/hydratoken.php');
// define ('TAPAS_AUTH_TOKEN', HYDRA_API_KEY);
define ('TAPASHYDRA_AUTH_TOKEN', 'tapas12345');

/** Base URL to build the API calls off of. */
define('TAPAS_BASE_API_URL', 'http://rails_api.localhost:8080');

/** Send Project POST calls to this url. */
define('TAPAS_POST_PROJECT_URL', TAPAS_BASE_API_URL . "/communities");
/** Send Collection POST calls to this url. */
define('TAPAS_POST_COLLECTION_URL', TAPAS_BASE_API_URL . "/collections");
/** Send TEI Record POST calls to this url. */
define('TAPAS_POST_TEI_URL', TAPAS_BASE_API_URL . "/files");

/* The following three constants tell which view of a tei record is being
 * Fetched by a GET command. 
 */
define('TAPAS_GET_RAW', 'tei');
define('TAPAS_GET_BP', 'teibp');
define('TAPAS_GET_GENERIC', 'tapas_generic');

/** Whether to include debug output. Not intended for production! */
define("TAPAS_INCLUDE_CURL_DEBUG", TRUE);

// ====================================================================================
// Helper Functions
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

function tapas_simple_fieldval($node, $field_name, $val_if_unset='', $delta=0) {

	$array = field_get_items('node', $node, $field_name);

	if ($array == FALSE) {
		return $val_if_unset;
	}
	else {
		return $array[$delta]['value'];
	}

}

function tapas_array_fieldval($node, $field_name) { 
  $from_node = field_get_items('node', $node, $field_name); 
  $result = [];

  if ($from_node == false) { 
    return $result;
  }

  foreach($from_node as $key => $value){
    $result[] = $value['value'];
  }

  return $result;
}
