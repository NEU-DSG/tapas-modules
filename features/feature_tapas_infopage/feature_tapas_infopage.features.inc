<?php
/**
 * @file
 * feature_tapas_infopage.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_tapas_infopage_node_info() {
  $items = array(
    'tapas_infopage' => array(
      'name' => t('TAPAS infopage'),
      'base' => 'node_content',
      'description' => t('A general purpose page type for the TAPAS website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
