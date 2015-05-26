<?php
/**
 * @file
 * tapas_feature_content_labnote.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_feature_content_labnote_node_info() {
  $items = array(
    'lab_note' => array(
      'name' => t('Lab Note'),
      'base' => 'node_content',
      'description' => t('A "lab note" can be attached to a project, a collection, or a record to give information about such things as the encoding process.'),
      'has_title' => '1',
      'title_label' => t('Lab Note Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
