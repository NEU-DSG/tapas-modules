<?php
/**
 * @file
 * feature_tapas_collection.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_tapas_collection_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_tapas_collection_node_info() {
  $items = array(
    'tapas_collection' => array(
      'name' => t('TAPAS Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Collection Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
