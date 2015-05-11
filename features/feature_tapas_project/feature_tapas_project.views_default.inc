<?php
/**
 * @file
 * feature_tapas_project.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_tapas_project_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_all_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'List All Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List All Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_project_image' => 'field_project_image',
    'group_access' => 'group_access',
    'title' => 'title',
    'field_project_slug' => 'field_project_slug',
    'field_project_institution' => 'field_project_institution',
    'field_project_description' => 'field_project_description',
    'field_external_links' => 'field_external_links',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_project_image' => array(
      'sortable' => 0,
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_slug' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_institution' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_external_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Project Image */
  $handler->display->display_options['fields']['field_project_image']['id'] = 'field_project_image';
  $handler->display->display_options['fields']['field_project_image']['table'] = 'field_data_field_project_image';
  $handler->display->display_options['fields']['field_project_image']['field'] = 'field_project_image';
  $handler->display->display_options['fields']['field_project_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_project_image']['settings'] = array(
    'image_style' => 'tapas_tiny',
    'image_link' => 'content',
  );
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access']['id'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access']['field'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['type'] = 'list_key';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project Slug */
  $handler->display->display_options['fields']['field_project_slug']['id'] = 'field_project_slug';
  $handler->display->display_options['fields']['field_project_slug']['table'] = 'field_data_field_project_slug';
  $handler->display->display_options['fields']['field_project_slug']['field'] = 'field_project_slug';
  /* Field: Content: Institutional Affiliation */
  $handler->display->display_options['fields']['field_project_institution']['id'] = 'field_project_institution';
  $handler->display->display_options['fields']['field_project_institution']['table'] = 'field_data_field_project_institution';
  $handler->display->display_options['fields']['field_project_institution']['field'] = 'field_project_institution';
  /* Field: Content: Project Description */
  $handler->display->display_options['fields']['field_project_description']['id'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['table'] = 'field_data_field_project_description';
  $handler->display->display_options['fields']['field_project_description']['field'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_project_description']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: External Links */
  $handler->display->display_options['fields']['field_external_links']['id'] = 'field_external_links';
  $handler->display->display_options['fields']['field_external_links']['table'] = 'field_data_field_external_links';
  $handler->display->display_options['fields']['field_external_links']['field'] = 'field_external_links';
  $handler->display->display_options['fields']['field_external_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_links']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_external_links']['delta_offset'] = '0';
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
    'tapas_project' => 'tapas_project',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-all-projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List All Projects';
  $export['list_all_projects'] = $view;

  return $export;
}
