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

  // Exported menu link: main-menu_about:node/165
  $menu_links['main-menu_about:node/165'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/165',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/165',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_commons:node/166
  $menu_links['main-menu_commons:node/166'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/166',
    'router_path' => 'node/%',
    'link_title' => 'Commons',
    'options' => array(
      'identifier' => 'main-menu_commons:node/166',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_discover:node/167
  $menu_links['main-menu_discover:node/167'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/167',
    'router_path' => 'node/%',
    'link_title' => 'Discover',
    'options' => array(
      'identifier' => 'main-menu_discover:node/167',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
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
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Commons');
  t('Discover');
  t('My Tapas');


  return $menu_links;
}
