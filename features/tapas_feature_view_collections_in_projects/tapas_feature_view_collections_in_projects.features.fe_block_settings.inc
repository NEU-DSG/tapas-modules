<?php
/**
 * @file
 * tapas_feature_view_collections_in_projects.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_view_collections_in_projects_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-collections_in_project-block'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-9 pull-right',
    'custom' => 0,
    'delta' => 'collections_in_project-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'garland' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'garland',
        'weight' => 7,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'tapas_redesign' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tapas_redesign',
        'weight' => 7,
      ),
    ),
    'title' => 'Collections',
    'visibility' => 0,
  );

  return $export;
}
