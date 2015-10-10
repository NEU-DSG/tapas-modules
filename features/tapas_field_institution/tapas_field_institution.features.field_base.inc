<?php
/**
 * @file
 * tapas_field_institution.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tapas_field_institution_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tapas_institution'
  $field_bases['field_tapas_institution'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tapas_institution',
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
          'vocabulary' => 'tapas_institution',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
