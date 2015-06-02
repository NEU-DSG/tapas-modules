<?php

function _tapascollection_field_bases() {

	$prefix = 'tapascollection_field';

	$bases = array(
		'description' => array(
			'field_name' => $prefix . '_description',
			'cardinality' => 1,
			'module' => 'text',
			'type' => 'text_long',
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
			'cardinality' => -1, // i.e. unlimitted
			'module' => 'taxonomy',
			'type' => 'taxonomy_term_reference'
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
	);

	return $bases;
}

function _tapascollection_common_instances($short_nodetype) {

	$type = 'tapascollection' . $short_nodetype;
	$base_array = array(
		'entity_type' => 'node',
		'bundle' => 'type'
	);

	$prefix = 'tapascollection_field';


	$instances = array(
		'description_' . $type => array_merge($base_array, array(
			'field_name' => $prefix . '_description',
			'label' => t('Description'),
		)),
		'image_' . $type => array_merge($base_array, array(
			'field_name' => $prefix . '_image',
			'label' => 'Image',
		)),
		'slug_' . $type => array_merge($base_array, array(
			'field_name' => $prefix . '_slug', 
			'label' => 'Slug',
			'required' => TRUE,
		)),
		'tags_' . $type => array_merge($base_array, array(
			'field_name' => $prefix. '_tags',
			'label' => 'Tags',
			'widget' => array(
				'type' => 'taxonomy_autocomplete',
			),
		)),
	);

	return $instances;

}

function _tapascollection_project_instances() {

	$type = 'tapascollection_project';

	$base_array = array(
		'entity_type' => 'node',
		'bundle' => $type,
	);

	$prefix = 'tapascollection_field';

	$instances = array(
		'institution_' . $type => array_merge($base_array, array(
			'field_name' => $prefix . '_institution',
			'label' => t('Institutional Affiliation'),
			'description' => t('A comma-separated list of institutions with which this project is affiliated.'),
			'settings' => array(
				'allowed_values' => array(
					0 => array(
						'vocabulary' => 'institution',
						'parent' => 0,
					),
				),
			),
			'widget' => array(
				'type' => 'taxonomy_autocomplete',
			),
		)),
		'links_' . $type => array_merge($base_array, array(
			'field_name' => $prefix . '_links',
			'label' => t('External Links'),
		)),
	);

	return $instances;

}

