<?php
/**
 * @file
 * tapas_feature_content_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_feature_content_page_node_info() {
  $items = array(
    'tapas_staticpage' => array(
      'name' => t('Static Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
