<?php
/**
 * @file
 * tapas_record.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tapas_record_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-tapas_record-field_tei_attatchments'
  $field_instances['node-tapas_record-field_tei_attatchments'] = array(
    'bundle' => 'tapas_record',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tei_attatchments',
    'label' => 'TEI Attatchments',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'tei_attatchments',
      'file_extensions' => 'txt jpg jpeg xml gif tiff png pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-tapas_record-field_tei_file'
  $field_instances['node-tapas_record-field_tei_file'] = array(
    'bundle' => 'tapas_record',
    'deleted' => 0,
    'description' => 'Choose a TEI file to upload',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tei_file',
    'label' => 'TEI file',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'tei_files',
      'file_extensions' => 'xml tei',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-tapas_record-og_group_ref'
  $field_instances['node-tapas_record-og_group_ref'] = array(
    'bundle' => 'tapas_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'og_ui',
        'settings' => array(),
        'type' => 'og_list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => FALSE,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Choose a TEI file to upload');
  t('Groups audience');
  t('TEI Attatchments');
  t('TEI file');

  return $field_instances;
}
