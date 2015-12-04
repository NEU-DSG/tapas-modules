<?php
/**
 * @file
 * tapas_feature_block_homepage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_block_homepage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-home_page_4_components'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'home_page_4_components',
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
        'weight' => -15,
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
        'weight' => -20,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-home_page_bottom'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'home_page_bottom',
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
        'weight' => -14,
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
        'weight' => -19,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-home_page_header'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'home_page_header',
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
        'weight' => -13,
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
        'weight' => -18,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
