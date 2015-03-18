<?php
/**
 * @file
 * tapas_record.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_record_node_info() {
  $items = array(
    'tapas_record' => array(
      'name' => t('TAPAS Record'),
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
