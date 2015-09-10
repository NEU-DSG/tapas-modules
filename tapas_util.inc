<?php
/**
 * @file
 * TAPAS constants and utility functions.
 *
 * Functions useful to more than one tapas module and that are not
 * module specific go here, as do project-wide constnts.
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

// ====================================================================================
// Constants
// ====================================================================================

// Prefixes for fields and field instances

/** Prefix used on all tapascollection field base names. */
define ('TAPAS_FIELD_PREFIX', 'field_tapas_');
/** Prefix used by all Collection field instances. */
define ('TAPAS_C_INSTANCE_PRE', 'fi_tapas_c_');
/** Prefix used by all project field instances. */
define ('TAPAS_P_INSTANCE_PRE', 'fi_tapas_p_');

// The content types.

/** Machine name of the Collection content type. */
define ('TAPAS_COLLECTION', 'tapascollection_collection');

/** Machine name of the Project content type. */
define ('TAPAS_PROJECT', 'tapascollection_project');


// Other constants

/** Field name for collection-to-project OG audience link*/
define ('TAPAS_C_TO_P', 'og_tapas_c_to_p');

define ('TAPAS_C_DEFAULT_IMAGE', 0);
define ('TAPAS_P_DEFAULT_IMAGE', 0);

define ('TAPAS_C_IMAGE_DIR', '');
define ('TAPAS_P_IMAGE_DIR', '');

define ('TAPAS_THUMB_MAX_FILESIZE', '');
define ('TAPAS_THUMB_MAX_RES', '');
define ('TAPAS_THUMB_MIN_RES', '');

define ('TAPAS_THUMB_PREVIEW_STYLE', 'thumbnail');
define ('TAPAS_THUMB_PROGRESS_IND', 'throbber');

// Field Instance decriptions.

define ('TAPAS_INSTANCE_DESC_HIDDENIMAGENAME', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_INSTITUTIONS', t(''));
define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_HIDDENINST', t(''));
define ('TAPAS_INSTANCE_DESC_TAGS', t(''));
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_LINKS', t(''));
define ('TAPAS_INSTANCE_DESC_HIDDENTITLESTRING', t(''));


// ====================================================================================
// TAPAS field instance types
// ====================================================================================

/**
 * Returns a field instance array for a hidden text field.
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

function tapas_instance_plaintext() {

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
 * The fields of the instane array common to all instances.
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
