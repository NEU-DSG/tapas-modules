<?php
/**
 * @file
 * tapas_feature_record_field_groups.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tapas_feature_record_field_groups_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_file_content|node|tapas_record|full';
  $field_group->group_name = 'group_record_file_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_record_files';
  $field_group->data = array(
    'label' => 'File Content',
    'weight' => '16',
    'children' => array(
      0 => 'field_tapas_tei_file',
      1 => 'field_tapas_attachments',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'File Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-record-file-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_record_file_content|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_files|node|tapas_record|full';
  $field_group->group_name = 'group_record_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tei_record';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '3',
    'children' => array(
      0 => 'group_record_file_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-record-files field-group-tab',
      ),
    ),
  );
  $export['group_record_files|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_metadata_content|node|tapas_record|full';
  $field_group->group_name = 'group_record_metadata_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_record_metadata';
  $field_group->data = array(
    'label' => 'Metadata Content',
    'weight' => '16',
    'children' => array(
      0 => 'field_tapas_display_auth',
      1 => 'field_tapas_display_contrib',
      2 => 'tapas_tab_meta',
      3 => 'tapas_tab_meta',
      4 => 'tapas_tab_meta',
      5 => 'tapas_tab_meta',
      6 => 'tapas_tab_meta',
      7 => 'tapas_tab_meta',
      8 => 'tapas_tab_meta',
      9 => 'tapas_tab_meta',
      10 => 'tapas_tab_meta',
      11 => 'tapas_tab_meta',
      12 => 'tapas_tab_meta',
      13 => 'tapas_tab_meta',
      14 => 'tapas_tab_meta',
      15 => 'tapas_tab_meta',
      16 => 'tapas_tab_meta',
      17 => 'tapas_tab_meta',
      18 => 'tapas_tab_meta',
      19 => 'tapas_tab_meta',
      20 => 'tapas_tab_meta',
      21 => 'tapas_tab_meta',
      22 => 'tapas_tab_meta',
      23 => 'tapas_tab_meta',
      24 => 'tapas_tab_meta',
      25 => 'tapas_tab_meta',
      26 => 'tapas_tab_meta',
      27 => 'tapas_tab_meta',
      28 => 'tapas_tab_meta',
      29 => 'tapas_tab_meta',
      30 => 'tapas_tab_meta',
      31 => 'tapas_tab_meta',
      32 => 'tapas_tab_meta',
      33 => 'tapas_tab_meta',
      34 => 'tapas_tab_meta',
      35 => 'tapas_tab_meta',
      36 => 'tapas_tab_meta',
      37 => 'tapas_tab_meta',
      38 => 'tapas_tab_meta',
      39 => 'tapas_tab_meta',
      40 => 'tapas_tab_meta',
      41 => 'tapas_tab_meta',
      42 => 'tapas_tab_meta',
      43 => 'tapas_tab_meta',
      44 => 'tapas_tab_meta',
      45 => 'tapas_tab_meta',
      46 => 'tapas_tab_meta',
      47 => 'tapas_tab_meta',
      48 => 'tapas_tab_meta',
      49 => 'tapas_tab_meta',
      50 => 'tapas_tab_meta',
      51 => 'tapas_tab_meta',
      52 => 'tapas_tab_meta',
      53 => 'tapas_tab_meta',
      54 => 'tapas_tab_meta',
      55 => 'tapas_tab_meta',
      56 => 'tapas_tab_meta',
      57 => 'tapas_tab_meta',
      58 => 'tapas_tab_meta',
      59 => 'tapas_tab_meta',
      60 => 'tapas_tab_meta',
      61 => 'tapas_tab_meta',
      62 => 'tapas_tab_meta',
      63 => 'tapas_tab_meta',
      64 => 'tapas_tab_meta',
      65 => 'tapas_tab_meta',
      66 => 'tapas_tab_meta',
      67 => 'tapas_tab_meta',
      68 => 'tapas_tab_meta',
      69 => 'tapas_tab_meta',
      70 => 'tapas_tab_meta',
      71 => 'tapas_tab_meta',
      72 => 'tapas_tab_meta',
      73 => 'tapas_tab_meta',
      74 => 'tapas_tab_meta',
      75 => 'tapas_tab_meta',
      76 => 'tapas_tab_meta',
      77 => 'tapas_tab_meta',
      78 => 'tapas_tab_meta',
      79 => 'tapas_tab_meta',
      80 => 'tapas_tab_meta',
      81 => 'tapas_tab_meta',
      82 => 'tapas_tab_meta',
      83 => 'tapas_tab_meta',
      84 => 'tapas_tab_meta',
      85 => 'tapas_tab_meta',
      86 => 'tapas_tab_meta',
      87 => 'tapas_tab_meta',
      88 => 'tapas_tab_meta',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Metadata Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-record-metadata-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_record_metadata_content|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_metadata|node|tapas_record|full';
  $field_group->group_name = 'group_record_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tei_record';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'group_record_metadata_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-record-metadata field-group-tab',
      ),
    ),
  );
  $export['group_record_metadata|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_reader_content|node|tapas_record|full';
  $field_group->group_name = 'group_record_reader_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_record_reader';
  $field_group->data = array(
    'label' => 'Reader Content',
    'weight' => '16',
    'children' => array(
      0 => 'tapas_tab_reader',
      1 => 'tapas_tab_reader',
      2 => 'tapas_tab_reader',
      3 => 'tapas_tab_reader',
      4 => 'tapas_tab_reader',
      5 => 'tapas_tab_reader',
      6 => 'tapas_tab_reader',
      7 => 'tapas_tab_reader',
      8 => 'tapas_tab_reader',
      9 => 'tapas_tab_reader',
      10 => 'tapas_tab_reader',
      11 => 'tapas_tab_reader',
      12 => 'tapas_tab_reader',
      13 => 'tapas_tab_reader',
      14 => 'tapas_tab_reader',
      15 => 'tapas_tab_reader',
      16 => 'tapas_tab_reader',
      17 => 'tapas_tab_reader',
      18 => 'tapas_tab_reader',
      19 => 'tapas_tab_reader',
      20 => 'tapas_tab_reader',
      21 => 'tapas_tab_reader',
      22 => 'tapas_tab_reader',
      23 => 'tapas_tab_reader',
      24 => 'tapas_tab_reader',
      25 => 'tapas_tab_reader',
      26 => 'tapas_tab_reader',
      27 => 'tapas_tab_reader',
      28 => 'tapas_tab_reader',
      29 => 'tapas_tab_reader',
      30 => 'tapas_tab_reader',
      31 => 'tapas_tab_reader',
      32 => 'tapas_tab_reader',
      33 => 'tapas_tab_reader',
      34 => 'tapas_tab_reader',
      35 => 'tapas_tab_reader',
      36 => 'tapas_tab_reader',
      37 => 'tapas_tab_reader',
      38 => 'tapas_tab_reader',
      39 => 'tapas_tab_reader',
      40 => 'tapas_tab_reader',
      41 => 'tapas_tab_reader',
      42 => 'tapas_tab_reader',
      43 => 'tapas_tab_reader',
      44 => 'tapas_tab_reader',
      45 => 'tapas_tab_reader',
      46 => 'tapas_tab_reader',
      47 => 'tapas_tab_reader',
      48 => 'tapas_tab_reader',
      49 => 'tapas_tab_reader',
      50 => 'tapas_tab_reader',
      51 => 'tapas_tab_reader',
      52 => 'tapas_tab_reader',
      53 => 'tapas_tab_reader',
      54 => 'tapas_tab_reader',
      55 => 'tapas_tab_reader',
      56 => 'tapas_tab_reader',
      57 => 'tapas_tab_reader',
      58 => 'tapas_tab_reader',
      59 => 'tapas_tab_reader',
      60 => 'tapas_tab_reader',
      61 => 'tapas_tab_reader',
      62 => 'tapas_tab_reader',
      63 => 'tapas_tab_reader',
      64 => 'tapas_tab_reader',
      65 => 'tapas_tab_reader',
      66 => 'tapas_tab_reader',
      67 => 'tapas_tab_reader',
      68 => 'tapas_tab_reader',
      69 => 'tapas_tab_reader',
      70 => 'tapas_tab_reader',
      71 => 'tapas_tab_reader',
      72 => 'tapas_tab_reader',
      73 => 'tapas_tab_reader',
      74 => 'tapas_tab_reader',
      75 => 'tapas_tab_reader',
      76 => 'tapas_tab_reader',
      77 => 'tapas_tab_reader',
      78 => 'tapas_tab_reader',
      79 => 'tapas_tab_reader',
      80 => 'tapas_tab_reader',
      81 => 'tapas_tab_reader',
      82 => 'tapas_tab_reader',
      83 => 'tapas_tab_reader',
      84 => 'tapas_tab_reader',
      85 => 'tapas_tab_reader',
      86 => 'tapas_tab_reader',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Reader Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-record-reader-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_record_reader_content|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_reader|node|tapas_record|full';
  $field_group->group_name = 'group_record_reader';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tei_record';
  $field_group->data = array(
    'label' => 'Reader',
    'weight' => '1',
    'children' => array(
      0 => 'group_record_reader_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Reader',
      'instance_settings' => array(
        'classes' => 'group-record-reader field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_record_reader|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_record_settings|node|tapas_record|full';
  $field_group->group_name = 'group_record_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tei_record';
  $field_group->data = array(
    'label' => 'Tapas Settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_tapas_display_date',
      1 => 'og_tapas_r_to_c',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-record-settings field-group-tab',
      ),
    ),
  );
  $export['group_record_settings|node|tapas_record|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tei_record|node|tapas_record|full';
  $field_group->group_name = 'group_tei_record';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tapas_record';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TEI Record',
    'weight' => '1',
    'children' => array(
      0 => 'group_record_files',
      1 => 'group_record_metadata',
      2 => 'group_record_settings',
      3 => 'group_record_reader',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tei-record field-group-tabs',
      ),
    ),
  );
  $export['group_tei_record|node|tapas_record|full'] = $field_group;

  return $export;
}
