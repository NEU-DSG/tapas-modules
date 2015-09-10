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
include_once '../tapas_util.inc';


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
			'field_name' => $prefix . 'description',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text_long',
		),
		'image' => array(
			'field_name' => $prefix . 'image',
			'cardinality' => 1,
			'module' => 'image',
			'type' => 'image',
		),
		'slug' => array(
			'field_name' => $prefix . 'slug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),
		'tags' => array(
			'field_name' => $prefix . 'tags',
			'cardinality' => -1, // i.e. unlimited
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference',
		),
		'institution' => array(
			'field_name' => $prefix . 'institution',
			'cardinality' => -1,
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference',
		),
		'links' => array(
			'field_name' => $prefix . 'links',
			'cardinality' => -1,
			'module' => 'link',
			'type' => 'link_field'
		),

		// This holds the raw text of the slug of the project to which this
		// collection belongs, to make hydra post calls easier.
		'parentslug' => array(
			'field_name' => $prefix . 'parentslug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),

		// Hidden fields to help with the migration into the new system, and
		// potentially could help with exporting into a newer system eventually.
		// (Title is probably redundant and can be removed after migration to 2.0)
		// TODO: Remove hidden_title field after migration.

		'hide_title' => array(
			'field_name' => $prefix . 'hide_title',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),

		// Other hidden fields to help with migration, might be useful in future migrations.
		'hide_imname' => array(
			'field_name' => $prefix . 'hide_imname',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text'
		),
		'hide_instname' => array(
			'field_name' => $prefix . 'hide_instname',
			'cardinality' => -1, 
			'module' => 'text',
			'type' => 'text'),
	);

	return $bases;
}

/**
 * Field instance arrays for TAPAS_COLLECTION content type.
 *
 * @return array An array of Drupal field instance arrays.
 */

function tapas_collection_field_instances() {

	return array(

		// Title field is added by the content type definition.

		TAPAS_C_INSTANCE_PRE . 'description' => array_merge(
			tapas_instance_common(
				'description',
				t('Collection Description'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION
			),
			tapas_instance_paragraph()
		),

		TAPAS_C_INSTANCE_PRE . 'image' => array_merge(
			tapas_instance_common(
				'image',
				t('Collection Thumbnail'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONTHUMB
			),
			tapas_instance_thumbnail()
		),

		TAPAS_C_INSTANCE_PRE . 'slug' => array_merge(
			tapas_instance_common(
				'slug',
				t('Collection Slug'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONSLUG
			),
			tapas_instance_uniqueid()
		),

		TAPAS_C_INSTANCE_PRE . 'tags' => array_merge(
			tapas_instance_common(
				'tags',
				t('Tags'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_TAGS
			),
			tapas_instance_taxonomy()
		),

		TAPAS_C_INSTANCE_PRE . 'parent_slug' => array_merge(
			tapas_instance_common(
				'parent_slug',
				t('Parent Slug'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_PARENTSLUG
			),
			tapas_instance_hiddentext()
		)
	);

}

/**
 * Field instance arrays for TAPAS_PROJECT content type.
 *
 * @return array An array of Drupal field instance arrays.
 */

function tapas_project_field_instances() {
	return  array(

		// Title field is added by the content type definition.

		TAPAS_P_INSTANCE_PRE . 'institution' => array_merge(
			tapas_instance_common(
				'institution',
				t('Affiliated Institutions'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_INSTITUTIONS
			),
			tapas_instance_taxonomy()
		),


		TAPAS_P_INSTANCE_PRE . 'description' => array_merge(
			tapas_instance_common(
				'description',
				t('Project Description'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJDESCRIPTION
			),
			tapas_instance_paragraph()
		),

		TAPAS_P_INSTANCE_PRE . 'image' => array_merge(
			tapas_instance_common(
				'image',
				t('Project Thumbnail'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJTHUMB
			),
			tapas_instance_thumbnail()
		),


		TAPAS_P_INSTANCE_PRE . 'links' => array_merge(
			tapas_instance_common(
				'links',
				t('External Links'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_LINKS
			),
			tapas_instance_hyperlinks()
		),

	);

}

function tapas_hidden_field_instances() {

	return array(

		TAPAS_C_INSTANCE_PRE . 'hide_title' => array_merge(
			tapas_instance_common(
				'hide_title',
				t('Titlestring'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_HIDDENTITLESTRING
			),
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'hide_title' => array_merge(
			tapas_instance_common(
				'hide_title',
				t('Titlestring'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_HIDDENTITLESTRING
			),
			tapas_instance_hiddentext()
		),

		TAPAS_C_INSTANCE_PRE . 'hidden_imname' => array_merge(
			tapas_instance_common(
				'hide_imname',
				t('Imagename'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_HIDDENIMAGENAME
			),
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'hidden_imname' => array_merge(
			tapas_instance_common(
				'hide_imname',
				t('Imagename'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_HIDDENIMAGENAME
			),
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'hide_instname' => array_merge(
			tapas_instance_common(
				'hide_instname',
				t('Institutionname'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_HIDDENINST
			),
			tapas_instance_hiddentext()
		),

	);

}
/**
 * Generates Organic Groups fields.
 *
 * Calls to the Organic Groups module api to make Project and Collection Organic
 *   Groups entitites. See also tapas_module/features/tapas_feature_collection_type
 *   and tapas_modules/features/tapas_feature_project_type. Role, Permission, and
 *   access settings (and hence the group_access and og_roles_permisions fields)
 *   will be set via the feature rather than here.
 *
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
