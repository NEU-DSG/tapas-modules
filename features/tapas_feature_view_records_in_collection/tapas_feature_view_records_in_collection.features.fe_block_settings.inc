<?php
/**
 * @file
 * tapas_feature_view_records_in_collection.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_view_records_in_collection_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-ece40a341bd3abd96179414c41afa18d'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-9 pull-right',
    'custom' => 0,
    'delta' => 'ece40a341bd3abd96179414c41afa18d',
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
        'weight' => 23,
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
        'weight' => 23,
      ),
    ),
    'title' => 'Records',
    'visibility' => 0,
  );

  return $export;
}
