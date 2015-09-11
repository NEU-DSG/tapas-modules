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


/**
 * Custom base fields for TAPAS content types. 
 *
 * Excludes 'title' (which is inherited from 'node' when we create
 *   the content type) and og fields (some of which are added via
 *   the og api, others are added later via a feature.
 */

function tapas_field_bases() {

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
		'tags' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'tags',
			'cardinality' => -1,
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference',
		),
		'insitutions' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'institutions',
			'cardinality' => -1,
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference'
		),
		'links' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'links',
			'cardinality' => -1,
			'module' => 'link',
			'type' => 'link_field',
		),
		'migration_title' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'migration_title',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text',
		),
		'migration_thumb' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'migrration_thumb',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text'
		),
		'migration_instnames' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'migration_instnames',
			'cardinality'=>  -1,
			'module' => 'text',
			'type' => 'text'
		),
		'parent_slug' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'parent_slug',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text'
		),
		'tei_file' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'tei_file',
			'cardinality' => 1,
			'module' => 'file',
			'type' => 'file' // @todo: Confirm!
		),
		'attachments' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'attatchments',
			'cardinality' => -1,
			'module' => 'file',
			'type' => 'file' // @todo: confirm!
		),
		'display_auth' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'display_auth',
			'cardinality' => -1,
			'module' => 'text',
			'type' => 'text',
		),
		'display_contrib' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'display_contrib',
			'cardinality' => -1,
			'module' => 'text',
			'type' => 'text',
		),
		'display_date' => array(
			'field_name' => TAPAS_FIELD_PREFIX . 'display_date',
			'cardinality' => 1,
			'module' => 'date',
			'type' => 'date' // @todo: this is a guess! Confirm or change.
		),
	);
}


/**
 * Field instances for Project fields.
 */

function tapas_fields_project() {

	return  array(

		TAPAS_P_INSTANCE_PRE . 'description' => array_merge(
			tapas_instance_common(
				'description',
				t('Project Description'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJDESCRIPTION
			),
			tapas_instance_paragraph()
		),

		TAPAS_P_INSTANCE_PRE . 'thumbnail' => array_merge(
			tapas_instance_common(
				'thumbnail',
				t('Project Thumbnail'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJTHUMB
			),
			tapas_instance_thumbnail()
		),

		TAPAS_P_INSTANCE_PRE . 'slug' => array_merge(
			tapas_instance_common(
				'slug',
				t('Project Slug'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJECTSLUG
			),
			tapas_instance_uniqueid()
		),

		TAPAS_P_INSTANCE_PRE . 'tags' => array_merge(
			tapas_instance_common( 
				'tags',
				t('Tags'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_TAGS
			),
			tapas_instance_taxonomy()
		),

		TAPAS_P_INSTANCE_PRE . 'institution' => array_merge(
			tapas_instance_common(
				'institution',
				t('Affiliated Institutions'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_INSTITUTIONS
			),
			tapas_instance_taxonomy()
		),

		TAPAS_P_INSTANCE_PRE . 'links' => array_merge(
			tapas_instance_common(
				'links',
				t('External Links'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_PROJLINKS
			),
			tapas_instance_hyperlinks()
		),

		TAPAS_P_INSTANCE_PRE . 'migration_title' => array_merge(
			tapas_instance_common(
				'migration_title',
				t('Migration Title'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONTITLE
			),
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'migration_image' => array_merge(
			tapas_instance_common(
				'migration_image',
				t('Migration Image'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONIMAGE
			),
			tapas_instance_hiddentext()
		),

		TAPAS_P_INSTANCE_PRE . 'migration_instnames' => array_merge(
			tapas_instance_common(
				'migration_instnames',
				t('Institutionname'),
				TAPAS_PROJECT,
				TAPAS_INSTANCE_DESC_MIGRATIONINST
			),
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

		TAPAS_C_INSTANCE_PRE . 'description' => array_merge(
			tapas_instance_common(
				'description',
				t('Collection Description'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION
			),
			tapas_instance_paragraph()
		),

		TAPAS_C_INSTANCE_PRE . 'thumbnail' => array_merge(
			tapas_instance_common(
				'thumbnail',
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
		),

		TAPAS_C_INSTANCE_PRE . 'migration_title' => array_merge(
			tapas_instance_common(
				'migration_title',
				t('Migration Title'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_HIDDENTITLESTRING
			),
			tapas_instance_hiddentext()
		),

		TAPAS_C_INSTANCE_PRE . 'migration_image' => array_merge(
			tapas_instance_common(
				'migration_image',
				t('Migration Image'),
				TAPAS_COLLECTION,
				TAPAS_INSTANCE_DESC_HIDDENIMAGENAME
			),
			tapas_instance_hiddentext()
		),
	);
}


/** 
 * Field instances for TEI Record fields.
 */

function tapas_fields_record() {

	return array(
		TAPAS_R_INSTANCE_PRE . 'slug' => array_merge(
			tapas_instance_common(
				'slug',
				t('Persistant ID'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_PERSISTID
			),
			tapas_instance_uniqueid()
		),

		TAPAS_R_INSTANCE_PRE . 'tei_file' => array_merge(
			tapas_instance_common(
				'tei_file',
				t('TEI File'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_TEIFILE
			),
			tapas_instance_filefield() // @todo: this is not written yet!
		),

		TAPAS_R_INSTANCE_PRE . 'attatchments' => array_merge(
			tapas_instance_common(
				'attatchments',
				t('Auxillary Files'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_ATTATCH
			),
			tapas_instance_fieldfield() // @todo: this has not been written yet!
		),

		TAPAS_R_INSTANCE_PRE . 'display_auth' => array_merge(
			tapas_instance_common(
				'display_auth',
				t('Author Names'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_AUTHORS
			),
			tapas_instance_simpletext() // @todo: verify field name. Also, not written yet.
		),

		TAPAS_R_INSTANCE_PRE . 'display_contrib' => array_merge(
			tapas_instance_common(
				'display_auth',
				t('Contributor Names'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_CONTRIBUTORS
			),
			tapas_instance_simpletext() // @todo: confirm function name, write function.
		),

		TAPAS_R_INSTANCE_PRE . 'display_date' => array_merge(
			tapas_instance_common(
				'display_date',
				t('Timeline Date'),
				TAPAS_RECORD,
				TAPAS_INSTANCE_DESC_DISPLAYDATE
			),
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


// ====================================================================================
// Organic Groups fields.
// ====================================================================================

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
