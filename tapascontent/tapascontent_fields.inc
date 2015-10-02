<?php

/**
 * @file tapascontent/tapascontent_fields.inc
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

// ====================================================================================
// Field Instance Descriptions.
// ====================================================================================

/*
 * The following constants are for the user-facing field descriptions for various
 * custom fields.
 */

define ('TAPAS_INSTANCE_DESC_TAGS', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONTITLE', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONIMAGE', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONINST', t(''));

define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_PROJSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_INSTITUTIONS', t(''));
define ('TAPAS_INSTANCE_DESC_PROJLINKS', t(''));

define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', t(''));

define ('TAPAS_INSTANCE_DESC_PERSISTID', t(''));
define ('TAPAS_INSTANCE_DESC_TEIFILE', t(''));
define ('TAPAS_INSTANCE_DESC_ATTATCH', t(''));
define ('TAPAS_INSTANCE_DESC_AUTHORS', t(''));
define ('TAPAS_INSTANCE_DESC_CONTRIBUTORS', t(''));
define ('TAPAS_INSTANCE_DESC_DISPLAYDATE', t(''));


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

function tapas_field_bases() {

	return array(
		'description' => _tapas_fieldarray('description', 1, 'text', 'text_long'),
		'thumbnail' => _tapas_fieldarray('thumbnail', 1, 'image', 'image'),
		'slug' => _tapas_fieldarray('slug', 1, 'text', 'text'),
		'tags' => _tapas_fieldarray('tags', -1, 'taxonomy', 'taxonomy_term_reference'),
		'institutions' => _tapas_fieldarray('institutions', -1, 'taxonomy', 'taxonomy_term_reference'),
		'links' => _tapas_fieldarray('links', -1, 'link', 'link_field'),
		'migration_title' => _tapas_fieldarray('migration_title', 1, 'text', 'text'),
		'migration_thumb' => _tapas_fieldarray('migration_thumb', 1, 'text', 'text'),
		'migration_instnames' => _tapas_fieldarray('migration_instnames', -1, 'text', 'text'),
		'parent_slug' => _tapas_fieldarray('parent_slug', 1, 'text', 'text'),
		'tei_file' => _tapas_fieldarray('tei_file', 1, 'file', 'file'),
		'attatchments' => _tapas_fieldarray('attatchments', -1, 'file', 'file'),
		'display_auth' => _tapas_fieldarray('display_auth', -1, 'text', 'text'),
		'display_contrib' => _tapas_fieldarray('display_contrib', -1, 'text', 'text'),
		'display_date' => _tapas_fieldarray('display_date', 1, 'date', 'date'), //@TODO: not sure on second 'date'!!
	);

}


/**
 * Field instances for Project fields.
 */

//function _tapas_fieldinstance($data, $prefix, $bundle) {
	//$result = array();
	//foreach ($data as $name => $values) {
		//$result[$prefix . $name] = 
			//tapas_instance_common($name, $values['label'], $values['description']) + $values['extra'];
	//}
	//return $result;

//}

function tapas_fields_project() {

	//return array(
		//'description' => array(
			//'label' => t('Project Description'),
			//'description' => TAPAS_INSTANCE_DESC_PROJDESCRIPTION,
			//'extra' => tapas_instance_paragraph()),
		//'thumbnail' => array(
			//'label' => t('Project Thumbnail'),
			//'description' => TAPAS_INSTANCE_DESC_PROJTHUMB,
			//'extra' => tapas_instance_thumbnail()),
		//'slug' => array(
			//'label' => t('Project Slug'),
			//'description' => TAPAS_INSTANCE_DESC_PROJSLUG,
			//'extra' => tapas_instance_uniquide()),
		//'tags' => array(
			//'label' => t('Tags'),
			//'description' => TAPAS_INSTANCE_DESC_TAGS,
			//'extra' => tapas_instance_taxonomy()),
		//'institutions' => array(
			//'label' => t('Affiliated Institutions'),
			//'description' => TAPAS_INSTANCE_DESC_INSTUTUTIONS,
			//'extra' => tapas_instance_taxonomy()),
		//'links' => array(
			//'label' => t('External Links'),
			//'description' => TAPAS_INSTANCE_DESC_PROJLINKS,
			//'extra' => tapas_instance_hyperlinks()),
		//'migration_title' => array(
			//'label' => t('Migration Title'),
			//'description' => TAPAS_INSTANCE_DESC_MIGRATIONTITLE,
			//'extra' => tapas_instance_hiddentext()),
		//'migration_thumb' => array(
			//'label' => t('Migration Thumb Name'),
			//'description' => TAPAS_INSTANCE_DESC_MIGRATIONIMAGE,
			//'extra' => tapas_instance_hiddentext()),
		//'migration_instnames' => array(
			//'label' => t('Migration Institution Names'),
			//'description' => TAPAS_INSTANCE_MIGRATIONINST,
			//'extra' => tapas_instance_hiddentext()),
		//);

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

		TAPAS_P_INSTANCE_PRE . 'tags' => (
			tapas_instance_common(
				'tags',
				t('Tags'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_TAGS
			) +
			tapas_instance_taxonomy()
		),

		TAPAS_P_INSTANCE_PRE . 'institutions' => (
			tapas_instance_common(
				'institutions',
				t('Affiliated Institutions'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_INSTITUTIONS
			) +
			tapas_instance_taxonomy()
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

		TAPAS_P_INSTANCE_PRE . 'migration_title' => (
			tapas_instance_common(
				'migration_title',
				t('Migration Title'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONTITLE
			) +
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'migration_thumb' => (
			tapas_instance_common(
				'migration_thumb',
				t('Migration Thumb'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONIMAGE
			) +
			tapas_instance_hiddentext()
		),


		TAPAS_P_INSTANCE_PRE . 'migration_instnames' => (
			tapas_instance_common(
				'migration_instnames',
				t('Institutionname'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONINST
			) +
			tapas_instance_hiddentext()
		),
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

		TAPAS_C_INSTANCE_PRE . 'tags' => (
			tapas_instance_common(
				'tags',
				t('Tags'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_TAGS
			) +
			tapas_instance_taxonomy()
		),

		TAPAS_C_INSTANCE_PRE . 'parent_slug' => (
			tapas_instance_common(
				'parent_slug',
				t('Parent Slug'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_PARENTSLUG
			) +
			tapas_instance_hiddentext()
		),

		TAPAS_C_INSTANCE_PRE . 'migration_title' => (
			tapas_instance_common(
				'migration_title',
				t('Migration Title'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_MIGRATIONTITLE
			) +
			tapas_instance_hiddentext()
		),

		TAPAS_C_INSTANCE_PRE . 'migration_thumb' => (
			tapas_instance_common(
				'migration_thumb',
				t('Migration Thumb'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_MIGRATIONIMAGE
			) +
			tapas_instance_hiddentext()
		),
	);
}


/** 
 * Field instances for TEI Record fields.
 */

function tapas_fields_record() {

	return array(
		TAPAS_R_INSTANCE_PRE . 'slug' => (
			tapas_instance_common(
				'slug',
				t('Persistant ID'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_PERSISTID
			) +
			tapas_instance_uniqueid()
		),

		TAPAS_R_INSTANCE_PRE . 'tei_file' => (
			tapas_instance_common(
				'tei_file',
				t('TEI File'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_TEIFILE
			) +
			tapas_instance_filefield('tei xml') 
		),

		TAPAS_R_INSTANCE_PRE . 'attatchments' => (
			tapas_instance_common(
				'attatchments',
				t('Auxillary Files'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_ATTATCH
			) +
			tapas_instance_filefield('jpeg') 
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
 * Returns a field instance array for a tag-like taxonomy field.
 *
 * @return array A field instance array.
 */

function tapas_instance_taxonomy() {

	return array(
		'default_value' => NULL,
		'display' => array(
			'default' => array(
				'label' => 'inline',
				'module' => 'taxonomy',
				'type' => 'taxonomy_term_reference_link',
			),
			'teaser' => array(
				'label' => 'inline',
				'module' => 'taxonomy',
				'type' => 'taxonomy_term_reference_link',
			),
		),
		'widget' => array(
			'module' => 'taxonomy',
			'settings' => array(
				'autocomplete_path' => 'taxonomy/autocomplete',
				'size' => 60,
			),
			'type' => 'taxonomy_autocomplete',
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

