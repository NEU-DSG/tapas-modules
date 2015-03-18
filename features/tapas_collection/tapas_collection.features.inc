<?php
/**
 * @file
 * tapas_collection.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_collection_node_info() {
  $items = array(
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A TAPAS Collection is a group of related TEI documents. Each collection belongs to a project.'),
      'has_title' => '1',
      'title_label' => t('Collection Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
