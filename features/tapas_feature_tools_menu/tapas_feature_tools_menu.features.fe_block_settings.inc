<?php
/**
 * @file
 * tapas_feature_tools_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_tools_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-tools-menu'] = array(
    'cache' => -1,
    'css_class' => 'tools wrench',
    'custom' => 0,
    'delta' => 'menu-tools-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
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
        'weight' => 3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
