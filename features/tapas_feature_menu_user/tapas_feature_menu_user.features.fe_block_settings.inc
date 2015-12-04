<?php
/**
 * @file
 * tapas_feature_menu_user.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_menu_user_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['system-user-menu'] = array(
    'cache' => -1,
    'css_class' => 'navbar-nav',
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
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
        'weight' => 5,
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
        'weight' => 2,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
