<?php
/**
 * @file
 * tapas_feature_content_project.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tapas_feature_content_project_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tapas_feature_content_project_node_info() {
  $items = array(
    'tapas_project' => array(
      'name' => t('TAPAS Project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
