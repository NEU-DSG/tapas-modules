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

  // Exported menu link: menu-primary-menu_about:node/1
  $menu_links['menu-primary-menu_about:node/1'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_about:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_advanced-search:search
  $menu_links['menu-primary-menu_advanced-search:search'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Advanced Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_advanced-search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_all-collections:list-all-collections
  $menu_links['menu-primary-menu_all-collections:list-all-collections'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'list-all-collections',
    'router_path' => 'list-all-collections',
    'link_title' => 'All Collections',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_all-collections:list-all-collections',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_more:<front>',
  );
  // Exported menu link: menu-primary-menu_all-institutions:list-all-institutions
  $menu_links['menu-primary-menu_all-institutions:list-all-institutions'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'list-all-institutions',
    'router_path' => 'list-all-institutions',
    'link_title' => 'All Institutions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_all-institutions:list-all-institutions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_more:<front>',
  );
  // Exported menu link: menu-primary-menu_all-projects:list-all-projects
  $menu_links['menu-primary-menu_all-projects:list-all-projects'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'list-all-projects',
    'router_path' => 'list-all-projects',
    'link_title' => 'All Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_all-projects:list-all-projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_more:<front>',
  );
  // Exported menu link: menu-primary-menu_commons:node/2
  $menu_links['menu-primary-menu_commons:node/2'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Commons',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_commons:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_discover:node/3
  $menu_links['menu-primary-menu_discover:node/3'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Discover',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_discover:node/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_more:<front>
  $menu_links['menu-primary-menu_more:<front>'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'More',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_more:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_my-tapas:user
  $menu_links['menu-primary-menu_my-tapas:user'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_my-tapas:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_news:news
  $menu_links['menu-primary-menu_news:news'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_news:news',
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
  t('Advanced Search');
  t('All Collections');
  t('All Institutions');
  t('All Projects');
  t('Commons');
  t('Discover');
  t('More');
  t('My Tapas');
  t('News');

  return $menu_links;
}
