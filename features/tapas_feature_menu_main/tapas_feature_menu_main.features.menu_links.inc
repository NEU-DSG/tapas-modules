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

  // Exported menu link: main-menu_about:node/179
  $menu_links['main-menu_about:node/179'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/179',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/179',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_commons:node/182
  $menu_links['main-menu_commons:node/182'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/182',
    'router_path' => 'node/%',
    'link_title' => 'Commons',
    'options' => array(
      'identifier' => 'main-menu_commons:node/182',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_discover:node/184
  $menu_links['main-menu_discover:node/184'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/184',
    'router_path' => 'node/%',
    'link_title' => 'Discover',
    'options' => array(
      'identifier' => 'main-menu_discover:node/184',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-tapas:my_tapas
  $menu_links['main-menu_my-tapas:my_tapas'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'my_tapas',
    'router_path' => 'my_tapas',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_my-tapas:my_tapas',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_news:news
  $menu_links['main-menu_news:news'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_news:news',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
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
  t('News');


  return $menu_links;
}
