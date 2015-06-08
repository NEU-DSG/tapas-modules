<?php
/**
 * @file
 * tapas_feature_menu_main.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_feature_menu_main_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_discover:<front>
  $menu_links['main-menu_discover:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Discover',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_discover:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-tapas:<front>
  $menu_links['main-menu_my-tapas:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_my-tapas:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Discover');
  t('My Tapas');


  return $menu_links;
}
