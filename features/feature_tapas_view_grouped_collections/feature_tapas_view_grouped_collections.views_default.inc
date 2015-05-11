<?php
/**
 * @file
 * feature_tapas_view_grouped_collections.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_tapas_view_grouped_collections_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'proj_and_coll';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Grouped Collections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Grouped Collections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'og_collection_to_project_ref',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'og_collection_to_project_ref' => 'og_collection_to_project_ref',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_collection_to_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_collection_to_project_ref']['id'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['field'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['label'] = '';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_collection_to_project_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_collection_to_project_ref']['settings'] = array(
    'link' => 0,
  );
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['group_access_value']['expose']['operator_id'] = 'group_access_value_op';
  $handler->display->display_options['filters']['group_access_value']['expose']['label'] = 'Group visibility (group_access)';
  $handler->display->display_options['filters']['group_access_value']['expose']['operator'] = 'group_access_value_op';
  $handler->display->display_options['filters']['group_access_value']['expose']['identifier'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'grouped-collections';
  $export['proj_and_coll'] = $view;

  return $export;
}
