<?php
/**
 * @file
 * feature_tapas_newsitem.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_tapas_newsitem_node_info() {
  $items = array(
    'tapas_newsitem' => array(
      'name' => t('TAPAS Newsitem'),
      'base' => 'node_content',
      'description' => t('A news or blog-type post from the maintainers of TAPAS'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
