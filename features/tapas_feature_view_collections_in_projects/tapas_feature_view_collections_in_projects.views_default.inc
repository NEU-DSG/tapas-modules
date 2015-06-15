<?php
/**
 * @file
 * tapas_feature_view_collections_in_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_view_collections_in_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'collections_in_project';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Collections in Project';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collections in Project';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['tc_field_image']['id'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['table'] = 'field_data_tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['field'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['label'] = '';
  $handler->display->display_options['fields']['tc_field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tc_field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['tc_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['tc_field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Parent Project (og_collection_to_project_ref) */
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['id'] = 'og_collection_to_project_ref_target_id';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['field'] = 'og_collection_to_project_ref_target_id';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_collection_to_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['collections_in_project'] = $view;

  return $export;
}
