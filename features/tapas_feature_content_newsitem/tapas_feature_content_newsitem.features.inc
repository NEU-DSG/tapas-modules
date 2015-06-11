<?php
/**
 * @file
 * tapas_feature_content_newsitem.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_feature_content_newsitem_node_info() {
  $items = array(
    'tapas_newsitem' => array(
      'name' => t('Newsitem'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('News Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
