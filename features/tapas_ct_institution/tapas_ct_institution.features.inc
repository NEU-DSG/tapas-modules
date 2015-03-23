<?php
/**
 * @file
 * tapas_ct_institution.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_ct_institution_node_info() {
  $items = array(
    'tapas_institution' => array(
      'name' => t('Institution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Institution Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
