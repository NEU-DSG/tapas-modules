<?php

/**
 * @file
 * tapascontent_fields.inc
 *
 * Contains the information for the field bases created by the
 * Project, Collection, and Record content types.
 *
 * Notably absent:
 *   title -- this comes with the node during content type creation,
 *      so we don't need to add it here.
 *   the OG fields -- some are added via the OG api, others are added
 *      later via a feature.
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */


include_once('tapascontent_constants.inc');


define ('STATUS_INPROGRESS', 0);
define ('STATUS_FAILED', 1);
define ('STATUS_SUCCESS', 2);

// ====================================================================================
// Field Instance Descriptions.
// ====================================================================================

/*
 * The following constants are for the user-facing field descriptions for various
 * custom fields.
 */

define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_PROJSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_PROJLINKS', t(''));

define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', t(''));

define ('TAPAS_INSTANCE_DESC_SHAREDDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_SHARAEDTHUMB', t(''));

define ('TAPAS_INSTANCE_DESC_PERSISTID', t(''));
define ('TAPAS_INSTANCE_DESC_TEIFILE', t(''));
define ('TAPAS_INSTANCE_DESC_ATTACH', t(''));
define ('TAPAS_INSTANCE_DESC_AUTHORS', t(''));
define ('TAPAS_INSTANCE_DESC_CONTRIBUTORS', t(''));
define ('TAPAS_INSTANCE_DESC_DISPLAYDATE', t(''));
define ('TAPAS_INSTANCE_DESC_RECORD_OGRAPHY_TYPE', t(''));


// ====================================================================================
// Instance Prefixes
// ====================================================================================

define ('TAPAS_C_INSTANCE_PRE', 'fi_tapas_c_');
define ('TAPAS_P_INSTANCE_PRE', 'fi_tapas_p_');
define ('TAPAS_R_INSTANCE_PRE', 'fi_tapas_r_');
define ('TAPAS_S_INSTANCE_PRE', 'fi_tapas_s_');

// ====================================================================================
// Thumbnails.
// ====================================================================================

define ('TAPAS_C_DEFAULT_IMAGE', 0);
define ('TAPAS_P_DEFAULT_IMAGE', 0);
define ('TAPAS_S_DEFAULT_IMAGE', 0);

define ('TAPAS_C_IMAGE_DIR', '');
define ('TAPAS_P_IMAGE_DIR', '');

define ('TAPAS_THUMB_MAX_FILESIZE', '');
define ('TAPAS_THUMB_MAX_RES', '');
define ('TAPAS_THUMB_MIN_RES', '');

define ('TAPAS_THUMB_PREVIEW_STYLE', 'thumbnail');
define ('TAPAS_THUMB_PROGRESS_IND', 'throbber');

// ====================================================================================
// Other Files.
// ====================================================================================

/** Maximum filesize allowed for any uploaded file. */
define ('TAPAS_FILE_MAXSIZE', '');

// ====================================================================================
// Field Definitions
// ====================================================================================
/**
 * Custom base fields for TAPAS content types.
 *
 * Excludes 'title' (which is inherited from 'node' when we create
 *   the content type) and og fields (some of which are added via
 *   the og api, others are added later via a feature.
 */

function tapas_field_bases() {

  $allowed_ographies = array ( 
    'allowed_values' => array(
      'bibliography' => 'bibliography', 
      'odd_file' => 'odd_file', 
      'orgography' => 'orgography', 
      'otherography' => 'otherography', 
      'personography' => 'personography', 
      'placeography' => 'placeography'
    ),
  );

  $allowed_status = array(
    'allowed_values' => array(
      STATUS_INPROGRESS => "This record is currently being processed.  Please check back later.",
      STATUS_FAILED => "Record uploaded failed!",
      STATUS_SUCCESS => "Record upload completed successfully"
    ),
  );

	return array(
		'description' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'description',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text_long',
		),
		'thumbnail' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'thumbnail',
			'cardinality' => 1,
			'module' => 'image',
			'type' => 'image',
		),
		'slug' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'slug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),
		'project' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'project',
			'cardinality' => 1,
			'module' => 'entityreference',
			'type' => 'entityreference',
		),
		'links' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'links',
			'cardinality' => -1,
			'module' => 'link',
			'type' => 'link_field',
		),
		'tei_file' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'tei_file',
			'cardinality' => -1,
			'module' => 'file',
			'type' => 'file',
		),
		'attatchments' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'attatchments',
			'cardinality' => -1,
			'module' => 'file',
			'type' => 'file',
		),
		'display_auth' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'display_auth',
			'cardinality' => -1,
			'module' => 'text',
			'type' => 'text',
		),
		'display_contrib' => array(
			'field_name' => TAPAS_FIELD_PREFIX .'display_contrib',
			'cardinality' => -1,
			'module' => 'text',
			'type' => 'text',
		),
		'display_date' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'display_date',
			'cardinality' => 1,
			'module' => 'date',
			'type' => 'date',
		),
		'record_ography_type' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'record_ography_type',
			'cardinality' => -1,
			'module' => 'text',
			'type' => 'list_text',
			'settings' => $allowed_status,
		),
		'upload_status' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'upload_status',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'list_text',
			'settings' => $allowed_status,
		)
	);

}

/**
 * Returns field instance arrays for all tapas content types.
 */

function _tapascontent_all_fields() {

	// Title fields are added via the content type definition.

	return  array(
		TAPAS_P_INSTANCE_PRE . 'description' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'description',
				'label' => t('Project Description'),
				'entity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
				'description' => TAPAS_INSTANCE_DESC_PROJDESCRIPTION,
			) +
			tapas_instance_paragraph()
		),

		TAPAS_P_INSTANCE_PRE . 'thumbnail' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'thumbnail',
				'label' => t('Project Thumbnail'),
				'entity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
				'description' => TAPAS_INSTANCE_DESC_PROJTHUMB,
			) +
			tapas_instance_thumbnail()
		),

		TAPAS_P_INSTANCE_PRE . 'slug' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'slug',
				'label' => t('Projet Slug'),
				'entity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
				'description' => TAPAS_INSTANCE_DESC_PROJSLUG,
			) +
			tapas_instance_uniqueid()
		),

		TAPAS_P_INSTANCE_PRE . 'links' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'links',
				'label' => t('External Links'),
				'entity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
				'description' => TAPAS_INSTANCE_DESC_PROJLINKS,
			) +
			tapas_instance_hyperlinks()
		),

    TAPAS_P_INSTANCE_PRE . 'upload_status' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'upload_status',
				'label' => t('Upload Status'),
				'enity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
      ) + 
      tapas_instance_multiselect() // TODO: Why is this multiselect?
    ),

		TAPAS_C_INSTANCE_PRE . 'description' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'description',
				'label' => t('Collection Description'),
				'entity_type' => 'node',
				'bundle' => TAPAS_PROJECT,
				'description' => TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION,
			) +
			tapas_instance_paragraph()
		),

		TAPAS_C_INSTANCE_PRE . 'thumbnail' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'thumbnail',
				'label' => t('Collection Thumbnail'),
				'entity_type' => 'node',
				'bundle' => TAPAS_COLLECTION,
				'description' => TAPAS_INSTANCE_DESC_COLLECTIONTHUMB,
			) +
			tapas_instance_thumbnail()
		),

		TAPAS_C_INSTANCE_PRE . 'slug' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'slug',
				'label' => t('Collection Slug'),
				'entity_type' => 'node',
				'bundle' => TAPAS_COLLECTION,
				'description' => TAPAS_INSTANCE_DESC_COLLECTIONSLUG,
			) +
			tapas_instance_uniqueid()
		),

    TAPAS_C_INSTANCE_PRE . 'upload_status' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'upload_status',
				'label' => t('Upload Status'),
				'entity_type' => 'node',
				'bundle' => TAPAS_COLLECTION,
      ) + 
      tapas_instance_multiselect()
    ),

		TAPAS_S_INSTANCE_PRE . 'description' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'description',
				'label' => t('Shared Repository Description'),
				'entity_type' => 'node',
				'bundle' => TAPAS_SHARED,
				'description' => TAPAS_INSTANCE_DESC_SHAREDDESCRIPTION,
			) +
			tapas_instance_paragraph()
		),

		TAPAS_P_INSTANCE_PRE . 'thumbnail' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'thumbnail',
				'label' => t('Shared Repository Thumbnail'), 
				'entity_type' => 'node',
				'bundle' => TAPAS_SHARED,
				'description' => TAPAS_INSTANCE_DESC_SHAREDTHUMB,
			) +
			tapas_instance_thumbnail()
		),
		TAPAS_R_INSTANCE_PRE . 'tei_file' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'tei_file',
				'label' => t('TEI File'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_TEIFILE,
			) +
			tapas_instance_filefield('tei xml')
		),

		TAPAS_R_INSTANCE_PRE . 'attachments' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'attachments',
				'label' => t('Auxillary Files'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_ATTACH,
			) +
			tapas_instance_filefield('png jpg gif jpeg')
		),

		TAPAS_R_INSTANCE_PRE . 'display_auth' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'display_auth',
				'label' => t('Author Names'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_AUTHORS,
			) +
			tapas_instance_simpletext()
		),

		TAPAS_R_INSTANCE_PRE . 'display_contrib' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'display_contrib',
				'label' => t('Contributor Names'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_CONTRIBUTORS,
			) +
			tapas_instance_simpletext()
		),

		TAPAS_R_INSTANCE_PRE . 'display_date' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'display_date',
				'label' => t('Timeline Date'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_DISPLAYDATE,
			) +
			tapas_instance_datefield() // @todo: write this function.
		),

    TAPAS_R_INSTANCE_PRE . 'record_ography_type' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'record_ography_types',
				'label' => t('Ography Types'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
				'description' => TAPAS_INSTANCE_DESC_RECORD_OGRAPHY_TYPE,
      ) + 
      tapas_instance_multiselect()
    ),

    TAPAS_R_INSTANCE_PRE . 'project' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'project',
				'label' => t('Record Project'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
      ) + 
      tapas_instance_project()
    ),

    TAPAS_R_INSTANCE_PRE . 'upload_status' => (
			array(
				'field_name' => TAPAS_FIELD_PREFIX . 'upload_status',
				'label' => t('Upload Status'),
				'entity_type' => 'node',
				'bundle' => TAPAS_RECORD,
      ) + 
      tapas_instance_multiselect()
    ),
	);

}



// ====================================================================================
// Helper functions for field instance generation.
// ====================================================================================


 /** Returns a field instance array for a hidden text field.
 *
 * @return array A field instance array.
 */

function tapas_instance_hiddentext() {

	return array(
		'required' => FALSE,
		'display' => array('default' => array('type' => 'hidden')),
		'settings' => array('text_processing' => 0),
		'widget' => array(
			'module' => 'text',
			'settings' => array('size' => 60),
			'type' => 'text_textfield',
		)
	);

}

/** Returns a field instance array for entitytext using the checkbox widget
 * @return array A field instance array
 */

function tapas_instance_project() { 
  return array(
    'required' => FALSE, 
    'display' => array('default' => array('type' => 'hidden')),
    'widget' => array(
      'module' => 'options',
      'type' => 'options_buttons'
    ),
  );
}

/** Returns a field instance array for specifically the ography type field
 *
 * @return array A field instance array 
 */

function tapas_instance_multiselect() {
  return array(
    'required' => FALSE, 
    'widget' => array(
      'module' => 'multiselect', 
      'type'=>'multiselect', 
    ),
  );
}

/**
 * Returns a field instance array for a thumbnail field.
 *
 * @return array A field instance array.
 */

function tapas_instance_thumbnail() {

	return array(
		'display' => array(
			'default' => array(
				'label' => 'hidden',
				'module' => 'image',
				'type' => 'image',
			),
			'teaser' => array(
				'label' => 'hidden',
				'type' => 'image',
			),
		),
		'settings' => array(
			//'alt_field' => $alt,
			'default_image' => TAPAS_C_DEFAULT_IMAGE,
			'file_directory' => TAPAS_C_IMAGE_DIR,
			'file_extentions' => 'png gif jpg jpeg',
			'max_filesize' => TAPAS_THUMB_MAX_FILESIZE,
			'max_resolution' => TAPAS_THUMB_MAX_RES,
			'min_resolution' => TAPAS_THUMB_MIN_RES,
		),
		'widget' => array(
			'module' => 'image',
			'settings' => array(
				'preview_image_style' => TAPAS_THUMB_PREVIEW_STYLE,
				'progress_indicator' => TAPAS_THUMB_PROGRESS_IND,
			),
			'type' => 'image_image',
		)
	);
}

/**
 * Returns a field instance array for a plaintext field.
 *
 * @return array A field instance array.
 */

function tapas_instance_simpletext() {
	return array(
		'required' => FALSE,
		'display' => array(
			'default' => array(
				'type' => 'text_default',
				'module' => 'text',
				'label' => 'inline',
			)
		),
		'settings' => array('text_processing' => 0),
		'widget' => array(
			'module' => 'text',
			'settings' => array('size' => 60),
			'type' => 'text_textfield',
		)
	);
}

/**
 * Returns a field instance array for a file field.
 *
 * @return array: A field instance array.
 */

function tapas_instance_filefield($file_extensions) {

	return array(
		'display' => array(
			'default' => array(
				'label' => 'inline',
				'module' => 'file',
				'type' => 'file_default',
			),
			'teaser' => array(
				'type' => 'hidden',
			),
		),
		'settings' => array(
			'description_field' => FALSE,
			'field_directory' => '',
			'file_extensions' => $file_extensions,
			'max_filesize' => TAPAS_FILE_MAXSIZE,
		),
		'widget' => array(
			'module' => 'file',
			'settings' => array( 'progress_indicator' => 'throber'),
			'type' => 'file_generic',
		),
	);
}

/**
 * Returns a field instance array for a date field.
 *
 * @return aray: A file instance array.
 */

function tapas_instance_datefield() {
	return array(
		'display' => array(
			'default' => array(
				'label' => 'inline',
				'module' => 'date', 
				'type' => 'date_default', 
			),
		),
		'widget' => array(
			'type' => 'date_select',
			'module' => 'date',
		),
	
	);
}


/**
 * Returns a field instance array for a paragraph field.
 *
 * @return array A field instance array.
 */

function tapas_instance_paragraph() {

	return array(
		'display' => array(
			'default' => array(
				'label' => 'hidden',
				'module' => 'text',
				'type' => 'text_default',
			),
		),
		'required' => FALSE,
		'settings' => array('text_processing' => TRUE),
		'widget' => array(
			'active' => TRUE,
			'module' => 'text',
			'settings' => array('rows' => 5),
			'type' => 'text_textarea',
		)
	);

}

/**
 * Returns a field instance array for an alphanumeric unique id field.
 *
 * @return array A field instance array.
 */

function tapas_instance_uniqueid() {

	return array(
		'required' => TRUE,
		'settings' => array('text_processing' => 0),
		'display' => array(
			'default' => array(
				'label' => 'inline',
				'module' => 'text',
				'settings' => array(),
				'type' => 'text_default',
			),
			'teaser' => array('type' => 'hidden'),
		),
		'widget' => array(
			'module' => 'text',
			'settings' => array('size' => 60),
			'type' => 'text_textfield',
		)
	);

}

/**
 * Returns a field instance array for a collection of hyperlinks.
 */

function tapas_instance_hyperlinks() {

	return array(
		'display' => array(
			'default' => array(
				'label' => 'above',
				'module' => 'link',
				'type' => 'link_default',
			),
			'teaser' => array('type' => 'hidden'),
		),
		'required' => FALSE,
		'settings' => array(
			'absolute_url' => TRUE,
			'display' => array('url_cutoff' => 80),
			'enable_tokens' => TRUE,
			'title' => 'optional',
			'title_label_use_field_label' => FALSE,
			'title_maxlength' => 128,
			'validate_url' => TRUE,
		),
		'widget' => array(
			'module' => 'link',
			'type' => 'link_field',
		),
	);
}
