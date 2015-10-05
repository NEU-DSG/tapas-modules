<?php
/**
 * @file
 * tapas_feature_og_settings.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tapas_feature_og_settings_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'og_tapas_c_to_p'
  $field_bases['og_tapas_c_to_p'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_tapas_c_to_p',
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
        ),
        'membership_type' => 'og_membership_type_default',
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'settubgs' => array(
      'target_type' => 'tapas_project',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'og_tapas_r_to_c'
  $field_bases['og_tapas_r_to_c'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_tapas_r_to_c',
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
        ),
        'membership_type' => 'og_membership_type_default',
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'settubgs' => array(
      'target_type' => 'tapas_collection',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
