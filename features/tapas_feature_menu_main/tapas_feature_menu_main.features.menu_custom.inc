<?php
/**
 * @file
 * tapas_feature_menu_main.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function tapas_feature_menu_main_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-primary-menu.
  $menus['menu-primary-menu'] = array(
    'menu_name' => 'menu-primary-menu',
    'title' => 'Primary Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Primary Menu');

  return $menus;
}
