<?php
/**
 * @file
 * Contains information for all of the tapascollection module 
 * custom fields.
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

/**
 * Field prefixes and content type names as constants.
 */
include_once 'tapascollection_constants.inc';


// ====================================================================================
// Functions called from .install file.
// ====================================================================================

/**
 * Provides an array of field base info arrays.
 *
 * @return array An array of field info arrays.
 */

function tapascollection_field_bases() {

	//$prefix = 'tc_field';
	$prefix = TAPAS_FIELD_PREFIX;

	$bases = array(
		'description' => array(
			'field_name' => $prefix . '_description',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'long_text',
		),
		'image' => array(
			'field_name' => $prefix . '_image',
			'cardinality' => 1,
			'module' => 'image',
			'type' => 'image',
		),
		'slug' => array(
			'field_name' => $prefix . '_slug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),
		'tags' => array(
			'field_name' => $prefix . '_tags',
			'cardinality' => -1, // i.e. unlimited
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference',
		),
		'institution' => array(
			'field_name' => $prefix . '_institution',
			'cardinality' => -1,
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference',
		),
		'links' => array(
			'field_name' => $prefix . '_links',
			'cardinality' => -1,
			'module' => 'link',
			'type' => 'link_field'
		),

		// This holds the raw text of the slug of the project to which this
		// collection belongs, to make hydra post calls easier.
		'parentslug' => array(
			'field_name' => $prefix . '_parentslug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),

		// Hidden fields to help with the migration into the new system, and
		// potentially could help with exporting into a newer system eventually.
		// (Title is probably redundant and can be removed after migration to 2.0)
		// TODO: Remove hidden_title field after migration.

		'hidden_title' => array(
			'field_name' => $prefix . '_hidden_title',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),

		// Other hidden fields to help with migration, might be useful in future migrations.
		'hidden_imagename' => array(
			'field_name' => $prefix . '_hidden_imagename',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text'
		),
		'hidden_institutionnames' => array(
			'field_name' => $prefix . '_hidden_institutionnames',
			'cardinality' => -1, 
			'module' => 'text',
			'type' => 'text'),
	);

	return $bases;
}

/**
 * Array of all instance information arrays.
 *
 * @return array An array of field instance info arrays.
 *
 * @uses _tapascollection_common_instances
 * @uses _tapascollection_field_instance
 */

function tapascollection_field_instances() {

	// Common instances
	$instances = array_merge(
		_tapascollection_common_instances(TAPAS_PROJECT),
		_tapascollection_common_instances(TAPAS_COLLECTION)
	);


	// Project-only instances


	$project_fields = array(
		'institution', t('Institutional Affiliation'),
		'links', t('Links'),
		'hidden_institutionnames', t('(hidden institution-names)'));

	$instances = array_merge($instances, _tapascollection_field_instances(
		TAPAS, $project_fields));

	$instution = 'institution_' . TAPAS_PROJECT;
	$instances[$institution]['description'] = t('A comma-seaparated list of institutions with which this ' .
		'project is affiliated.');
	$instances[$institution]['settings'] = array(
		'allwoed_values' => array(
			0 => array(
				'vocabulary' => 'institution',
				'parent' => 0,
			),
		),
	);
	$instances[$institution]['widget'] = array('type' => 'taxonomy_autocomplete');

	// Collection-only instance

	$instances[] = array(
		'entity_type' => 'node',
		'bundle' => TAPAS_COLLECTION,
		'field_name' => 'parentslug_' . TAPAS_COLLECTION,
		'label' => '(parent slug)'
	);

	return $instances;

}

/**
 * Generates Organic Groups fields
 *
 * Calls to the Organic Groups module api to make Project and Collection Organic
 *   Groups entitites.
 */

function tapascollection_ogfields() {

		// Make collections and projects both be organic groups.
		og_create_field(OG_GROUP_FIELD, 'node', TAPAS_COLLECTION);
		og_create_field(OG_GROUP_FIELD, 'node', TAPAS_PROJECT);

		// collections should also be a content type for the project organic group.
		$og_c_to_p = og_fields_info(OG_AUDIENCE_FIELD);
		$og_field['field']['settings']['target_type'] = TAPAS_PROJECT;
		og_create_field(TAPAS_C_TO_P, 'node', TAPAS_COLLECTION, $og_c_to_p);
}


// ====================================================================================
// Internal functions
// ====================================================================================

/** 
 * Field instances common to 'project' and 'collection'
 *
 * @internal Gets common bases for tapascollection_field_bases
 * 
 * @param string indicating either project or collection. Project is
 *   indicated by the constant TAPAS_PROJECT, collection by the 
 *   constant TAPAS_COLLECTION
 *
 * @return array An array of field instance info arrays.
 *
 * @uses _tapascollection_instance().
 */
function _tapascollection_common_instances($type) {

	$prefix = TAPAS_FIELD_PREFIX;

	// Common Instances

	$common_fields = array(
		'description' => t('Description'),
		'image' => t('Image'),
		'slug' => t('Slug'),
		'tags' => t('Tags'), 
		'hidden_title' => '(hidden title)',
		'hidden_imagename' => '(hidden image-name)',
	);

	$instances = _tapascollection_instance($type, $common_fields);

	$instances['slug_' . $type]['required'] = TRUE;
	$instances['tags_' . $type]['widget'] = array(
		'type' => 'taxonomy_autocomplte');

	return $instances;

}


/** 
 * Builds field instance array for a group of fields.
 *
 * @internal Gets field instance arrays for tapascollection_field_instances.
 *
 * @param string $type Whether this is a project or collection. A project
 *   is indicated by the constant TAPAS_PROJECT, a collection by the 
 *   constant TAPAS_COLLECTION.
 * @param array $fields An associative array that uses the field name
 *   as the key, and the translated label as the value.
 *
 * @return array An array of field instance info arrays.
 */

function _tapascollection_instance($type, $fields) {

	$instances = array();
	foreach ($fields as $field => $label) {
		$instances[$field . '_' . $type] = array(
			'entity_type' => 'node',
			'bundle' => $type,
			'field_name' => TAPAS_FIELD_PREFIX . '_' . $field,
			'label' => $label
		);
	}

}

/**
 * Helper Functions
 */

function tapas_tagtax_fieldinst(
	$bundle,
	$description,
	$name,
	$label
) {
	return array(
		'bundle' => $bundle,
		'default_value' => NULL,
		'description' => $description,
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
		'entity_type' => 'node',
		'field_name' => TAPAS_FIELD_PREFIX . $name,
		'label' => $label,
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

function tapascollection_simpletext_field_display(
	$visible_default = TRUE,
	$visible_teaser = TRUE,
	$label_default = 'inline',
	$label_teaser = 'inline',
	$is_long = FALSE) {

	if ($is_long) {
		$type = 'text_textarea';
		$settings = array('rows' => 5);
	} else {
		$type = 'text_textfield';
		$settings = array('size' => 60);
	}

	return array(
		'display' => array(
			'default' => array(
				'label' => $label_default,
				'module' => 'text',
				'type' => $visible_default?'text_default':'hidden',
			),
			'teaser' => array(
				'label' => $label_teaser,
				'module' => 'text',
				'type' => $visible_teaser?'text_default':'hidden',
			),
		),
		'widget' => array(
			'module' => 'text',
			'settings' => $settings,
			'type' => $type,
		),
	);

}

/**
 * Thumbnail field instance array
 *
 * For use by every thumbnail field defined by Tapas.
 *
 * @param string $name Fieldname, without the TAPAS_FIELD_PREFIX.
 * @param string $type either TAPAS_PROJECT or TAPAS_COLLECTION.
 * @param string $label The translated label.
 * @param string $description The translated description.
 * @param string $alt The translated alt text, if any.
 *
 * @return array The instance array for the field instance.
 */

function tapascollection_thumbnail_instance(
	$name, $type, $label, $description='', $alt='') {

return array(
	'bundle' => TAPAS_COLLECTION,
	'description' => $description,
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
	'entity_type' => 'node',
	'field_name' => TAPAS_FIELD_PREFIX . $name,
	'label' => $label,
	'settings' => array(
		'alt_field' => $alt,
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
			'progress_indicator' => TAPAS_THUMB_PROGRESS_INDICATOR,
		),
		'type' => 'image_image',
	)
);

}

/** 
 * Field instances.
 */

function tapascollection_collection_instances() {

$field_instances = array(
		TAPAS_C_INSTANCE_PRE . 'hidden_imagename' => array_merge(
			tapascollection_simpletext_field_display(
				FALSE, FALSE, 'hidden', 'hidden'),
			array(
				'bundle' => TAPAS_COLLECTION,
				'description' => 'Internal -- used as migration aid.',
				'entity_type' => 'node',
				'field_name' => TAPAS_FIELD_PREFIX . 'hidden_imagename',
				'label' => 'image name (internal use)',
				'settings' => array('text_processing' => 0),
			)
		),
		// Skipping 'title', should be added automatically?
		// Skipping 'group_access', added in og section
		// Skipping 'group_group', added in og section
		// Skipping 'og_collection_to_project_ref', added in og section.
		// Skipping 'og_roles_permissions', added in og section
		TAPAS_C_INSTANCE_PRE . 'description' => array_merge(
			tapascollection_simpletext_field_display(
				TRUE, TRUE, 'hidden', 'hidden', TRUE, 1),
			array (
				'bundle' => TAPAS_COLLECTION,
				'description' => t('Describe this collection.'),
				'entity_type' => 'node',
				'field_name' => TAPAS_FIELD_PREFIX . 'description',
				'label' => t('Collection Description'),
				'settings' => array('text_processing' => 1),
			)
		),
		TAPAS_C_INSTANCE_PRE . 'image' => 
			tapascollection_thumbnail_instance(
				'image',
				TAPAS_COLLECTION,
				t('Collection Thumbnail'),
				t('You can add an image to be a thumbnail for this collection.'),
				t('Thumbnail image for this collection.')
			),

		TAPAS_C_INSTANCE_PRE . 'slug' => array_merge(
			tapascollection_simple_text_field_display(
				TRUE, FALSE, 'inline', 'hidden'),
				array(
					'bundle' => TAPAS_COLLECTION,
					'description' => t('A machine-readable identifier for this file. Must contain only letters and hyphens, no spaces.'),
					'entity_type' => 'node',
					'field_name' => TAPAS_FIELD_PREFIX . 'slug',
					'settings' => array('text_processing' => 0),
					'label' => t('Slug'),
					'required' => TRUE,
				)
		),

		TAPAS_C_INSTANCE_PRE . 'tags' => tapas_tagtax_fieldinst(
			TAPAS_COLLECTION, '', 'tags', t('Tags')),

		TAPAS_P_INSTANCE_PRE . 'hidden_imagename' => array_merge(
			tapascollection_simpletext_field_display(
				FALSE, FALSE, 'hidden', 'hidden'),
			array(
				'bundle' => TAPAS_PROJECT,
				'description' => 'Internal -- used as migration aid.',
				'entity_type' => 'node',
				'field_name' => TAPAS_FIELD_PREFIX . 'hidden_imagename',
				'label' => 'image name (internal use)',
				'settings' => array('text_processing' => 0),
			)
		),
		
		TAPAS_P_INSTANCE_PRE . 'instiution' => tapas_tagtax_fieldinst(
			TAPAS_PROJECT, 
			t('You may list one or more institutions that this project is affiliated with. Institutions listed will appear on the institution list; autocomplete will suggest institutions already on the list.'),
			'institution',
			t('Affiliated Institutions')
		),

		// skipping title
		// skipping group_access
		// skipping group_group
		// skipping og_roles_permissions

		TAPAS_P_INSTANCE_PRE . 'description' => array_merge(
			tapascollection_simpletext_field_display(
				TRUE, TRUE, 'hidden', 'hidden', TRUE, 1),
			array (
				'bundle' => TAPAS_PROJECT,
				'description' => t('Describe this project.'),
				'entity_type' => 'node',
				'field_name' => TAPAS_FIELD_PREFIX . 'description',
				'label' => t('Project Description'),
				'settings' => array('text_processing' => 1),
			)
		),
		
		TAPAS_P_INSTANCE_PRE . 'image' => 
			tapascollection_thumbnail_instance(
				'image',
				TAPAS_COLLECTION,
				t('Project Thumbnail'),
				t('You can add an image to be a thumbnail for this project.'),
				t('Thumbnail image for this project.')
			),
	);

}
