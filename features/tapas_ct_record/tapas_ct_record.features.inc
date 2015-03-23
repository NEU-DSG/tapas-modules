<?php
/**
 * @file
 * tapas_ct_record.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tapas_ct_record_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tapas_ct_record_node_info() {
  $items = array(
    'tapas_record' => array(
      'name' => t('Tapas Record'),
      'base' => 'node_content',
      'description' => t('Holds an uploaded TEI file and associated metadata.'),
      'has_title' => '1',
      'title_label' => t('Record Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
