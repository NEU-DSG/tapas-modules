<?php
/**
 * @file
 * tapas_feature_menu_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_feature_menu_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_my-tapas:my_tapas.
  $menu_links['menu-footer-menu_my-tapas:my_tapas'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'my_tapas',
    'router_path' => 'my_tapas',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_my-tapas:my_tapas',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_search:search.
  $menu_links['menu-footer-menu_search:search'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_search:search',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('My Tapas');
  t('Search');

  return $menu_links;
}
