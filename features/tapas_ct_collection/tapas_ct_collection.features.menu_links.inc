<?php
/**
 * @file
 * tapas_ct_collection.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_ct_collection_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_list-all-collections:list-all-collections
  $menu_links['navigation_list-all-collections:list-all-collections'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'list-all-collections',
    'router_path' => 'list-all-collections',
    'link_title' => 'List all Collections',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'navigation_list-all-collections:list-all-collections',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('List all Collections');


  return $menu_links;
}
