<?php
/**
 * @file
 * tapas_feature_content_shared.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_feature_content_shared_node_info() {
  $items = array(
    'tapas_shared' => array(
      'name' => t('TAPAS Shared'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
