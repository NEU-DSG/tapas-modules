<?php
/**
 * @file
 * tapas_ct_collection.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tapas_ct_collection_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tapas_ct_collection_node_info() {
  $items = array(
    'tapas_collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A \'Collection\' is a group of documents. Each \'Collection\' belongs to a product.'),
      'has_title' => '1',
      'title_label' => t('Collection Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
