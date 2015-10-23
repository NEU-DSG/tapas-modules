<?php
/**
 * @file
 * tapas_field_groups.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tapas_field_groups_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_files|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '5',
    'children' => array(
      0 => 'field_tapas_tei_file',
      1 => 'field_tapas_attachments',
      2 => 'field_tapas_display_auth',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-files field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_files|node|tapas_record|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_metacontent|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_metacontent';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tapas_metadata';
  $field_group->data = array(
    'label' => 'Metadata Content',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-metacontent field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_metacontent|node|tapas_record|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_metadata|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '5',
    'children' => array(
      0 => 'group_tapas_metacontent',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-metadata field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_metadata|node|tapas_record|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_readercontent|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_readercontent';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tapas_reader';
  $field_group->data = array(
    'label' => 'Reader Content',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-readercontent field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_readercontent|node|tapas_record|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_reader|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_reader';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reader',
    'weight' => '5',
    'children' => array(
      0 => 'group_tapas_readercontent',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-reader field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_reader|node|tapas_record|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tapas_web|node|tapas_record|form';
  $field_group->group_name = 'group_tapas_web';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tapas Web',
    'weight' => '5',
    'children' => array(
      0 => 'field_tapas_display_contrib',
      1 => 'field_tapas_display_date',
      2 => 'og_tapas_r_to_c',
      3 => 'field_tapas_record_ography_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-tapas-web field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tapas_web|node|tapas_record|form'] = $field_group;

  return $export;
}
