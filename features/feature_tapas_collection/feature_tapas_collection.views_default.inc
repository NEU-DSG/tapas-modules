<?php
/**
 * @file
 * feature_tapas_collection.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_tapas_collection_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_all_collections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'List all Collections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List all Collections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_collection_image' => 'field_collection_image',
    'title' => 'title',
    'field_collection_slug' => 'field_collection_slug',
    'field_collection_description' => 'field_collection_description',
    'og_collection_to_project_ref' => 'og_collection_to_project_ref',
    'group_access' => 'group_access',
  );
  $handler->display->display_options['style_options']['default'] = 'field_collection_slug';
  $handler->display->display_options['style_options']['info'] = array(
    'field_collection_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection_slug' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_collection_to_project_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'group_access' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Collection Image */
  $handler->display->display_options['fields']['field_collection_image']['id'] = 'field_collection_image';
  $handler->display->display_options['fields']['field_collection_image']['table'] = 'field_data_field_collection_image';
  $handler->display->display_options['fields']['field_collection_image']['field'] = 'field_collection_image';
  $handler->display->display_options['fields']['field_collection_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_collection_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Collection Slug */
  $handler->display->display_options['fields']['field_collection_slug']['id'] = 'field_collection_slug';
  $handler->display->display_options['fields']['field_collection_slug']['table'] = 'field_data_field_collection_slug';
  $handler->display->display_options['fields']['field_collection_slug']['field'] = 'field_collection_slug';
  /* Field: Content: Collection Description */
  $handler->display->display_options['fields']['field_collection_description']['id'] = 'field_collection_description';
  $handler->display->display_options['fields']['field_collection_description']['table'] = 'field_data_field_collection_description';
  $handler->display->display_options['fields']['field_collection_description']['field'] = 'field_collection_description';
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_collection_to_project_ref']['id'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['field'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access']['id'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access']['field'] = 'group_access';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tapas_collection' => 'tapas_collection',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-all-collections';
  $export['list_all_collections'] = $view;

  return $export;
}
