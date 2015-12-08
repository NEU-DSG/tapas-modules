<?php
/**
 * @file
 * tapas_field_institution.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tapas_field_institution_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-tapas_project-field_tapas_institution'.
  $field_instances['node-tapas_project-field_tapas_institution'] = array(
    'bundle' => 'tapas_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tapas_institution',
    'label' => 'Institutional Affiliation',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 6,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Institutional Affiliation');

  return $field_instances;
}
