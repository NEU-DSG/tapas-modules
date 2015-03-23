<?php
/**
 * @file
 * tapas_ct_project.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tapas_ct_project_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tapas_ct_project_node_info() {
  $items = array(
    'tapas_project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A "Project" is a group of people working together.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
