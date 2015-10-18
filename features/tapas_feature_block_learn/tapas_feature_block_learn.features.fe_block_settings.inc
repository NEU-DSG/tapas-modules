<?php
/**
 * @file
 * tapas_feature_block_learn.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_block_learn_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-commons_learn_block'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-12',
    'custom' => 0,
    'machine_name' => 'commons_learn_block',
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
        'weight' => 26,
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
        'weight' => 26,
      ),
    ),
    'title' => 'Learn',
    'visibility' => 0,
  );

  return $export;
}
