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

  // Exported menu link: menu-primary-menu_about:node/228.
  $menu_links['menu-primary-menu_about:node/228'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/228',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn more about the TAPAS project',
      ),
      'identifier' => 'menu-primary-menu_about:node/228',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_discover:node/3.
  $menu_links['menu-primary-menu_discover:node/3'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Discover',
    'options' => array(
      'attributes' => array(
        'title' => 'Discover projects, collections, items in the TAPAS archive',
      ),
      'identifier' => 'menu-primary-menu_discover:node/3',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/.
  $menu_links['menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/234/',
    'router_path' => '',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_emcontactem:http://tapasdev.neu.edu/?q=node/234/',
  );
  // Exported menu link: menu-primary-menu_more:<front>.
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_my-tapas:my_tapas.
  $menu_links['menu-primary-menu_my-tapas:my_tapas'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'my_tapas',
    'router_path' => 'my_tapas',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_my-tapas:my_tapas',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Discover');
  t('FAQ');
  t('More');
  t('My Tapas');

  return $menu_links;
}
