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
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', t(''));

define ('TAPAS_INSTANCE_DESC_PERSISTID', t(''));
define ('TAPAS_INSTANCE_DESC_TEIFILE', t(''));
define ('TAPAS_INSTANCE_DESC_ATTACH', t(''));
define ('TAPAS_INSTANCE_DESC_AUTHORS', t(''));
define ('TAPAS_INSTANCE_DESC_CONTRIBUTORS', t(''));
define ('TAPAS_INSTANCE_DESC_DISPLAYDATE', t(''));
define ('TAPAS_INSTANCE_DESC_RECORD_OGRAPHY_TYPE', t(''));

define ('TAPAS_INSTANCE_DESC_UPLOADSTATUS', t(''));

define ('TAPAS_INSTANCE_DESC_PARENT_SLUG', t(''));


// ====================================================================================
// Instance Prefixes
// ====================================================================================

define ('TAPAS_C_INSTANCE_PRE', 'fi_tapas_c_');
define ('TAPAS_P_INSTANCE_PRE', 'fi_tapas_p_');
define ('TAPAS_R_INSTANCE_PRE', 'fi_tapas_r_');

// ====================================================================================
// Thumbnails.
// ====================================================================================

define ('TAPAS_C_DEFAULT_IMAGE', 0);
define ('TAPAS_P_DEFAULT_IMAGE', 0);

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

function _tapas_fieldarray($name, $cardinality, $module, $type) {
	return array(
		'field_name' => TAPAS_FIELD_PREFIX . $name,
		'cardinality' => $cardinality,
		'module' => $module,
		'type' => $type,
	);
}

function _tapas_fieldarray_with_settings($name, $cardinality, $module, $type, $settings) {
  return array(
    'field_name' => TAPAS_FIELD_PREFIX . $name, 
    'cardinality' => $cardinality, 
    'module' => $module, 
    'type' => $type, 
    'settings' => $settings
  );
}

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

	return array(
		'description' => _tapas_fieldarray('description', 1, 'text', 'text_long'),
		'thumbnail' => _tapas_fieldarray('thumbnail', 1, 'image', 'image'),
		'slug' => _tapas_fieldarray('slug', 1, 'text', 'text'),
    'parent_slug' => _tapas_fieldarray('parent_slug', 1, 'text', 'text'),
		'links' => _tapas_fieldarray('links', -1, 'link', 'link_field'),
		'tei_file' => _tapas_fieldarray('tei_file', 1, 'file', 'file'),
		'attachments' => _tapas_fieldarray('attachments', -1, 'file', 'file'),
		'display_auth' => _tapas_fieldarray('display_auth', -1, 'text', 'text'),
		'display_contrib' => _tapas_fieldarray('display_contrib', -1, 'text', 'text'),
		'display_date' => _tapas_fieldarray('display_date', 1, 'date', 'date'), //@TODO: not sure on second 'date'!!
    'record_ography_type' => _tapas_fieldarray_with_settings('record_ography_type', 
      -1, 'text', 'list_text', $allowed_ographies),
		//'upload_state' => _tapas_fieldarray('upload_state', 1, 'list', 'list_integer'),
	);

}

/**
 * Upload status instance template
 */

//function _tapas_uploadstatus_template($type) {

	//$fielddata = array(
		//tapas_instance_common(
			//'upload_status',
			//t('Upload Status'),
			//$type,
			//TAPAS_INSTANCE_DESC_UPLOADSTATUS
		//)
	//);

	//$fielddata['settings']['allowed_values'] = array(
		//STATUS_INPROGRESS => t('In Progress'),
		//STATUS_FAILED => t('Upload Failed'),
		//STATUS_SUCCESS => t('Uploaded Successfully')
	//);

	//return $fielddata;
//}

/**
 * Field instances for Project fields.
 */

function tapas_fields_project() {

	return  array(
		TAPAS_P_INSTANCE_PRE . 'description' => (
			tapas_instance_common(
				'description',
				t('Project Description'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJDESCRIPTION
			) +
			tapas_instance_paragraph()
		),

		TAPAS_P_INSTANCE_PRE . 'thumbnail' => (
			tapas_instance_common(
				'thumbnail',
				t('Project Thumbnail'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJTHUMB
			) +
			tapas_instance_thumbnail()
		),

		TAPAS_P_INSTANCE_PRE . 'slug' => (
			tapas_instance_common(
				'slug',
				t('Project Slug'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJSLUG
			) +
			tapas_instance_uniqueid()
		),

		TAPAS_P_INSTANCE_PRE . 'links' => (
			tapas_instance_common(
				'links',
				t('External Links'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJLINKS
			) +
			tapas_instance_hyperlinks()
		),

		//TAPAS_P_INSTANCE_PRE . 'upload_status' => _tapas_uploadstatus_template(TAPAS_PROJECT),

	);
}


/**
 * Field instances for Collection fields.
 */

function tapas_fields_collection() {


	return array(

		// Title field is added by the content type definition.

		TAPAS_C_INSTANCE_PRE . 'description' => (
			tapas_instance_common(
				'description',
				t('Collection Description'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION
			) +
			tapas_instance_paragraph()
		),

		TAPAS_C_INSTANCE_PRE . 'thumbnail' => (
			tapas_instance_common(
				'thumbnail',
				t('Collection Thumbnail'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONTHUMB
			) +
			tapas_instance_thumbnail()
		),

		TAPAS_C_INSTANCE_PRE . 'slug' => (
			tapas_instance_common(
				'slug',
				t('Collection Slug'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONSLUG
			) +
			tapas_instance_uniqueid()
		),

    TAPAS_C_INSTANCE_PRE . 'parent_slug' => (
      tapas_instance_common(
        'parent_slug', 
        t('Parent Slug'), 
        TAPAS_COLLECTION, 
        TAPAS_INSTANCE_DESC_PARENT_SLUG
      ) + 
      tapas_instance_hiddentext()
    ),
		//TAPAS_P_INSTANCE_PRE . 'upload_status' => _tapas_uploadstatus_template(TAPAS_COLLECTION),
	);
}


/**
 * Field instances for TEI Record fields.
 */

function tapas_fields_record() {

	return array(
		TAPAS_R_INSTANCE_PRE . 'tei_file' => (
			tapas_instance_common(
				'tei_file',
				t('TEI File'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_TEIFILE
			) +
			tapas_instance_filefield('tei xml')
		),

		TAPAS_R_INSTANCE_PRE . 'attachments' => (
			tapas_instance_common(
				'attachments',
				t('Auxillary Files'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_ATTACH
			) +
			tapas_instance_filefield('png jpg gif jpeg')
		),

		TAPAS_R_INSTANCE_PRE . 'display_auth' => (
			tapas_instance_common(
				'display_auth',
				t('Author Names'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_AUTHORS
			) +
			tapas_instance_simpletext() // @todo: verify field name. Also, not written yet.
		),

		TAPAS_R_INSTANCE_PRE . 'display_contrib' => (
			tapas_instance_common(
				'display_contrib',
				t('Contributor Names'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_CONTRIBUTORS
			) +
			tapas_instance_simpletext() // @todo: confirm function name, write function.
		),

		TAPAS_R_INSTANCE_PRE . 'display_date' => (
			tapas_instance_common(
				'display_date',
				t('Timeline Date'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_DISPLAYDATE
			) +
			tapas_instance_datefield() // @todo: write this function.
		),

    TAPAS_R_INSTANCE_PRE . 'record_ography_type' => (
      tapas_instance_common(
        'record_ography_type', 
        t('Ography Types'), 
        TAPAS_RECORD, 
        TAPAS_INSTANCE_DESC_RECORD_OGRAPHY_TYPE
      ) + 
      tapas_instance_record_ography_type()
    ),

    TAPAS_R_INSTANCE_PRE . 'parent_slug' => (
      tapas_instance_common(
        'parent_slug',
        t('Parent Slug'),
        TAPAS_RECORD, 
        TAPAS_INSTANCE_DESC_PARENT_SLUG
      ) + 
      tapas_instance_hiddentext()
    ),
		//TAPAS_P_INSTANCE_PRE . 'upload_status' => _tapas_uploadstatus_template(TAPAS_RECORD),

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

/** Returns a field instance array for specifically the ography type field
 *
 * @return array A field instance array 
 */

function tapas_instance_record_ography_type() {
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
	return array(); // @TODO
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
		'settings' => array( //@TODO
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
	return array(); //@TODO
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

/**
 * The fields of the instance array common to all instances.
 *
 * @param string $name Field name (without the TAPAS_FIELD_PREFIX)
 * @param string $label The translated label.
 * @param string $bundle TAPAS_PROJECT or TAPAS_COLLECTION constant.
 * @param string $description the translated description.
 *
 * @return array A field instance array.
 */

function tapas_instance_common(
	$name,
	$label,
	$bundle,
	$description='') {

	return array(
		'field_name' => TAPAS_FIELD_PREFIX . $name,
		'label' => $label,
		'entity_type' => 'node',
		'bundle' => $bundle,
		'description' => $description);
}
