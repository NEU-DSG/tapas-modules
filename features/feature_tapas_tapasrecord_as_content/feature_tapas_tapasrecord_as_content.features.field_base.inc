<?php
/**
 * @file
 * feature_tapas_tapasrecord_as_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_tapas_tapasrecord_as_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'og_record_to_collection_ref'
  $field_bases['og_record_to_collection_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_record_to_collection_ref',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'og',
      'handler_settings' => array(
        'behaviors' => array(
          'og_behavior' => array(
            'status' => TRUE,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'membership_type' => 'og_membership_type_default',
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'tapas_collection' => 'tapas_collection',
        ),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'tapas_teifield'
  $field_bases['tapas_teifield'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'tapas_teifield',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'label' => 'TEI File',
    'locked' => 1,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
