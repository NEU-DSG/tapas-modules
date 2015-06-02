<?php
/**
 * @file
 * tapas_feature_content_tapasrecord_as_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tapas_feature_content_tapasrecord_as_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tei_record_tags'
  $field_bases['field_tei_record_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tei_record_tags',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
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
