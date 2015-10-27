<?php
/**
 * @file
 * tapas_feature_context_collection.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tapas_feature_context_collection_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tapas_parent_slug'
  $field_bases['field_tapas_parent_slug'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tapas_parent_slug',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
