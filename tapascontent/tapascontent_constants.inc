<?php
/**
 * @file
 * tapascontent_constants.inc
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.1
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

/** Machine name of the Shared Repository content type. */
define ('TAPAS_SHARED', 'tapas_shared');

/** Machine name of the TEI Record content type. */
define ('TAPAS_RECORD', 'tapas_record');


// ====================================================================================
// Content Type Descriptions
// ====================================================================================

/* User-facing descriptions for content types. */
define ('TAPAS_CONTENT_PROJ_DESC', '');
define ('TAPAS_CONTENT_COLL_DESC', '');
define ('TAPAS_CONTENT_SHARED_DESC', '');
define ('TAPAS_CONTENT_REC_DESC', '');

/* User-facing help text for content types. */
define ('TAPAS_CONTENT_PROJ_HELP', '');
define ('TAPAS_CONTENT_COLL_HELP', '');
define ('TAPAS_CONTENT_SHARED_HELP', '');
define ('TAPAS_CONTENT_REC_HELP', '');

// ====================================================================================
//  Hydra API.
// ====================================================================================


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

// Can't delete yet; still used in SOLR indexing file.
function tapas_simple_fieldval($node, $field_name, $val_if_unset='', $delta=0) {

	$array = field_get_items('node', $node, $field_name);

	if ($array == FALSE) {
		return $val_if_unset;
	}
	else {
		return $array[$delta]['value'];
	}

}

// ====================================================================================
// Other helper functions, used internally and externally.
// ====================================================================================


function _tapashydra_watchdog_debug($message) { //TODO: move to constants/common file.
  watchdog('tapascontent', $message, [], WATCHDOG_DEBUG);
}

