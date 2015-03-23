<?php
/**
 * @file
 * tapas_ct_project.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_ct_project_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_list-all-projects:list-all-projects
  $menu_links['navigation_list-all-projects:list-all-projects'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'list-all-projects',
    'router_path' => 'list-all-projects',
    'link_title' => 'List all Projects',
    'options' => array(
      'identifier' => 'navigation_list-all-projects:list-all-projects',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('List all Projects');


  return $menu_links;
}
