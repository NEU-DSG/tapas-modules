<?php
/**
 * @file
 * tapas_feature_tools_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_feature_tools_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-tools-menu_add-a-record:node/add/tapas-record.
  $menu_links['menu-tools-menu_add-a-record:node/add/tapas-record'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'node/add/tapas-record',
    'router_path' => 'node/add/tapas-record',
    'link_title' => 'Add a Record',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_add-a-record:node/add/tapas-record',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-tools-menu_create-a-collection:node/add/tapas-collection.
  $menu_links['menu-tools-menu_create-a-collection:node/add/tapas-collection'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'node/add/tapas-collection',
    'router_path' => 'node/add/tapas-collection',
    'link_title' => 'Create a Collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_create-a-collection:node/add/tapas-collection',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-tools-menu_create-a-project:node/add/tapas-project.
  $menu_links['menu-tools-menu_create-a-project:node/add/tapas-project'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'node/add/tapas-project',
    'router_path' => 'node/add/tapas-project',
    'link_title' => 'Create a Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_create-a-project:node/add/tapas-project',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-tools-menu_my-collections:my_collections.
  $menu_links['menu-tools-menu_my-collections:my_collections'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'my_collections',
    'router_path' => 'my_collections',
    'link_title' => 'My Collections',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_my-collections:my_collections',
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
  // Exported menu link: menu-tools-menu_my-projects:my_projects.
  $menu_links['menu-tools-menu_my-projects:my_projects'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'my_projects',
    'router_path' => 'my_projects',
    'link_title' => 'My Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_my-projects:my_projects',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-tools-menu_my-records:my_records.
  $menu_links['menu-tools-menu_my-records:my_records'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'my_records',
    'router_path' => 'my_records',
    'link_title' => 'My Records',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_my-records:my_records',
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
  // Exported menu link: menu-tools-menu_my-tapas:my_tapas.
  $menu_links['menu-tools-menu_my-tapas:my_tapas'] = array(
    'menu_name' => 'menu-tools-menu',
    'link_path' => 'my_tapas',
    'router_path' => 'my_tapas',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-tools-menu_my-tapas:my_tapas',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a Record');
  t('Create a Collection');
  t('Create a Project');
  t('My Collections');
  t('My Projects');
  t('My Records');
  t('My Tapas');

  return $menu_links;
}
