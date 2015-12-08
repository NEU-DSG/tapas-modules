<?php
/**
 * @file
 * tapas_feature_context_discover.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_context_discover_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-data_commons'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-3 pull-right',
    'custom' => 0,
    'machine_name' => 'data_commons',
    'module' => 'block',
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
        'weight' => 0,
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
        'weight' => -32,
      ),
    ),
    'title' => 'DATA Commons',
    'visibility' => 0,
  );

  $export['block-discover_intro_text'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-9',
    'custom' => 0,
    'machine_name' => 'discover_intro_text',
    'module' => 'block',
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
        'weight' => 0,
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
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
