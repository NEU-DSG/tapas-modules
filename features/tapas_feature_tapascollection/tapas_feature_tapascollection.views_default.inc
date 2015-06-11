<?php
/**
 * @file
 * tapas_feature_tapascollection.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_tapascollection_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_all_collections';
  $view->description = '';
  $view->tag = 'tapas, structure';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['tc_field_description']['id'] = 'tc_field_description';
  $handler->display->display_options['fields']['tc_field_description']['table'] = 'field_data_tc_field_description';
  $handler->display->display_options['fields']['tc_field_description']['field'] = 'tc_field_description';
  /* Field: Content: Group */
  $handler->display->display_options['fields']['group_group']['id'] = 'group_group';
  $handler->display->display_options['fields']['group_group']['table'] = 'field_data_group_group';
  $handler->display->display_options['fields']['group_group']['field'] = 'group_group';
  /* Field: Content: Group roles and permissions */
  $handler->display->display_options['fields']['og_roles_permissions']['id'] = 'og_roles_permissions';
  $handler->display->display_options['fields']['og_roles_permissions']['table'] = 'field_data_og_roles_permissions';
  $handler->display->display_options['fields']['og_roles_permissions']['field'] = 'og_roles_permissions';
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access_1']['id'] = 'group_access_1';
  $handler->display->display_options['fields']['group_access_1']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access_1']['field'] = 'group_access';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['tc_field_image']['id'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['table'] = 'field_data_tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['field'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['tc_field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Institutional Affiliation */
  $handler->display->display_options['fields']['tc_field_institution']['id'] = 'tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['table'] = 'field_data_tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['field'] = 'tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['delta_offset'] = '0';
  /* Field: Content: Slug */
  $handler->display->display_options['fields']['tc_field_slug']['id'] = 'tc_field_slug';
  $handler->display->display_options['fields']['tc_field_slug']['table'] = 'field_data_tc_field_slug';
  $handler->display->display_options['fields']['tc_field_slug']['field'] = 'tc_field_slug';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['tc_field_tags']['id'] = 'tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['table'] = 'field_data_tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['field'] = 'tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['delta_offset'] = '0';
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
    'tapascollection_collection' => 'tapascollection_collection',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-all-collections';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List all Collections';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['list_all_collections'] = $view;

  $view = new view();
  $view->name = 'list_all_projects';
  $view->description = '';
  $view->tag = 'tapas, structure';
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
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Slug */
  $handler->display->display_options['fields']['tc_field_slug']['id'] = 'tc_field_slug';
  $handler->display->display_options['fields']['tc_field_slug']['table'] = 'field_data_tc_field_slug';
  $handler->display->display_options['fields']['tc_field_slug']['field'] = 'tc_field_slug';
  /* Field: Content: Institutional Affiliation */
  $handler->display->display_options['fields']['tc_field_institution']['id'] = 'tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['table'] = 'field_data_tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['field'] = 'tc_field_institution';
  $handler->display->display_options['fields']['tc_field_institution']['delta_offset'] = '0';
  /* Field: Content: institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['tc_field_image']['id'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['table'] = 'field_data_tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['field'] = 'tc_field_image';
  $handler->display->display_options['fields']['tc_field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['tc_field_image']['settings'] = array(
    'image_style' => 'tapas_tiny',
    'image_link' => 'content',
  );
  /* Field: Content: image name */
  $handler->display->display_options['fields']['field_image_name']['id'] = 'field_image_name';
  $handler->display->display_options['fields']['field_image_name']['table'] = 'field_data_field_image_name';
  $handler->display->display_options['fields']['field_image_name']['field'] = 'field_image_name';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['tc_field_description']['id'] = 'tc_field_description';
  $handler->display->display_options['fields']['tc_field_description']['table'] = 'field_data_tc_field_description';
  $handler->display->display_options['fields']['tc_field_description']['field'] = 'tc_field_description';
  $handler->display->display_options['fields']['tc_field_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['tc_field_description']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: External Links */
  $handler->display->display_options['fields']['tc_field_links']['id'] = 'tc_field_links';
  $handler->display->display_options['fields']['tc_field_links']['table'] = 'field_data_tc_field_links';
  $handler->display->display_options['fields']['tc_field_links']['field'] = 'tc_field_links';
  $handler->display->display_options['fields']['tc_field_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['tc_field_links']['delta_offset'] = '0';
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access_1']['id'] = 'group_access_1';
  $handler->display->display_options['fields']['group_access_1']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access_1']['field'] = 'group_access';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['tc_field_tags']['id'] = 'tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['table'] = 'field_data_tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['field'] = 'tc_field_tags';
  $handler->display->display_options['fields']['tc_field_tags']['delta_offset'] = '0';
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
    'tapascollection_project' => 'tapascollection_project',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-all-projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List All Projects';
  $export['list_all_projects'] = $view;

  $view = new view();
  $view->name = 'proj_and_coll';
  $view->description = '';
  $view->tag = 'tapas, structure';
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
  /* Field: Content: Parent Project */
  $handler->display->display_options['fields']['og_collection_to_project_ref']['id'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['field'] = 'og_collection_to_project_ref';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['label'] = '';
  $handler->display->display_options['fields']['og_collection_to_project_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_collection_to_project_ref']['element_label_colon'] = FALSE;
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
    'tapascollection_collection' => 'tapascollection_collection',
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
