<?php
/**
 * @file
 * tapas_feature_view_package_settings_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_view_package_settings_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'record_edit_view_package';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Record Edit View Package';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Record Edit View Package';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Edit record view packages',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'tapas_record::field_tapas_default_view' => 'tapas_record::field_tapas_default_view',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Default View Package */
  $handler->display->display_options['fields']['field_tapas_default_view']['id'] = 'field_tapas_default_view';
  $handler->display->display_options['fields']['field_tapas_default_view']['table'] = 'field_data_field_tapas_default_view';
  $handler->display->display_options['fields']['field_tapas_default_view']['field'] = 'field_tapas_default_view';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Collections (og_tapas_r_to_c) */
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['id'] = 'og_tapas_r_to_c_target_id';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['field'] = 'og_tapas_r_to_c_target_id';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['validate_options']['types'] = array(
    'tapas_collection' => 'tapas_collection',
  );
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['og_tapas_r_to_c_target_id']['validate_options']['access_op'] = 'update';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/record-edit-view-package';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'View Package Settings';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $export['record_edit_view_package'] = $view;

  return $export;
}
