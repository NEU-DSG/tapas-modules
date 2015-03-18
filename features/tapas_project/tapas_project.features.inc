<?php
/**
 * @file
 * tapas_project.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tapas_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A "project" in TAPAS is a group of people working together. Projects contain Collections, which contain TEI records and other content.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
