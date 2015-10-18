<?php
/**
 * @file
 * tapas_feature_view_records_in_collection.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_view_records_in_collection_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'records_in_collection_view';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'tapas, og';
  $view->base_table = 'node';
  $view->human_name = 'Records in Collection View';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Records';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no records for this collection yet. <a href=\'/node/add/tapas-record\' class="btn btn-xs btn-default"><span class="fa fa-plus"></span> Add a Record</a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Groups audience (og_tapas_r_to_c) */
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['id'] = 'og_tapas_r_to_c_target_id';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['field'] = 'og_tapas_r_to_c_target_id';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tapas_record' => 'tapas_record',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['records_in_collection_view'] = $view;

  return $export;
}
