<?php
/**
 * @file
 * tapas_feature_views_all.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_views_all_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Records';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Ography Types */
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['id'] = 'field_tapas_record_ography_type';
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['table'] = 'field_data_field_tapas_record_ography_type';
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['field'] = 'field_tapas_record_ography_type';
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['label'] = '';
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['alter']['text'] = 'support-file';
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_record_ography_type']['delta_offset'] = '0';
  /* Field: Content: Project Thumbnail */
  $handler->display->display_options['fields']['field_tapas_thumbnail']['id'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['table'] = 'field_data_field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['field'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_thumbnail']['empty'] = '<a href="/node/[nid]" class="collection-no-image"><img src="/sites/default/files/default_images/tapaslogo-opaque.png" /></a>';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
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
    'tapas_record' => 'tapas_record',
  );

  /* Display: Records */
  $handler = $view->new_display('page', 'Records', 'page');
  $handler->display->display_options['path'] = 'all_records';

  /* Display: Collections */
  $handler = $view->new_display('page', 'Collections', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Collections';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Project Thumbnail */
  $handler->display->display_options['fields']['field_tapas_thumbnail']['id'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['table'] = 'field_data_field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['field'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_thumbnail']['empty'] = '<a href="/node/[nid]" class="collection-no-image"><img src="/sites/default/files/default_images/tapaslogo-opaque.png" /></a>';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'all_collections';

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Projects';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Project Thumbnail */
  $handler->display->display_options['fields']['field_tapas_thumbnail']['id'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['table'] = 'field_data_field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['field'] = 'field_tapas_thumbnail';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_thumbnail']['empty'] = '<a href="/node/[nid]" class="collection-no-image"><img src="/sites/default/files/default_images/tapaslogo-opaque.png" /></a>';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tapas_thumbnail']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'all_projects';
  $export['all'] = $view;

  return $export;
}
