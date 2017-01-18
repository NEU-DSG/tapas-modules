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
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Support File Type */
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Updated date';
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );

  /* Display: Records */
  $handler = $view->new_display('page', 'Records', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'grid-view';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_records_list" class="btn btn-default"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_records" class="btn btn-default active"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Support File Type */
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['title']['element_class'] = 'text-center [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Collections */
  $handler->display->display_options['fields']['og_tapas_r_to_c']['id'] = 'og_tapas_r_to_c';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['field'] = 'og_tapas_r_to_c';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['label'] = '';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_tapas_r_to_c']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_tapas_r_to_c']['element_wrapper_class'] = 'grid-hover';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_tapas_r_to_c']['delta_offset'] = '0';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_tapas_display_auth']['id'] = 'field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['table'] = 'field_data_field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['field'] = 'field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['label'] = 'Author(s)';
  $handler->display->display_options['fields']['field_tapas_display_auth']['element_wrapper_class'] = 'grid-hover';
  $handler->display->display_options['fields']['field_tapas_display_auth']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['element_wrapper_class'] = 'grid-hover';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
    'tapas_record' => 'tapas_record',
  );
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_records';

  /* Display: Collections */
  $handler = $view->new_display('page', 'Collections', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Collections';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'grid-view';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_collections_list" class="btn btn-default"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_collections" class="btn btn-default active"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_collections';

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'grid-view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_projects_list" class="btn btn-default"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_projects" class="btn btn-default active"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_projects';

  /* Display: Records-List */
  $handler = $view->new_display('page', 'Records-List', 'page_3');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'list-view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_records_list" class="btn btn-default active"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_records" class="btn btn-default"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Support File Type */
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['title']['element_class'] = 'inline-block [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Collections */
  $handler->display->display_options['fields']['og_tapas_r_to_c']['id'] = 'og_tapas_r_to_c';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['field'] = 'og_tapas_r_to_c';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['label'] = '';
  $handler->display->display_options['fields']['og_tapas_r_to_c']['exclude'] = TRUE;
  $handler->display->display_options['fields']['og_tapas_r_to_c']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_tapas_r_to_c']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_tapas_r_to_c']['delta_offset'] = '0';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_tapas_display_auth']['id'] = 'field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['table'] = 'field_data_field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['field'] = 'field_tapas_display_auth';
  $handler->display->display_options['fields']['field_tapas_display_auth']['label'] = '';
  $handler->display->display_options['fields']['field_tapas_display_auth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tapas_display_auth']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
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
    'tapas_record' => 'tapas_record',
  );
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_records_list';

  /* Display: Collections-List */
  $handler = $view->new_display('page', 'Collections-List', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Collections';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'list-view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_collections_list" class="btn btn-default active"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_collections" class="btn btn-default"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['title']['element_class'] = 'inline-block [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_collections_list';

  /* Display: Projects-List */
  $handler = $view->new_display('page', 'Projects-List', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'list-view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="button-group"><a href="all_projects_list" class="btn btn-default active"><span class="fa fa-th-list">&nbsp; </span>List View</a><a href="all_projects" class="btn btn-default"><span class="fa fa-th">&nbsp; </span>Grid View</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h5';
  $handler->display->display_options['fields']['title']['element_class'] = 'inline-block [field_tapas_record_ography_type]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Group visibility (group_access) */
  $handler->display->display_options['filters']['group_access_value']['id'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['table'] = 'field_data_group_access';
  $handler->display->display_options['filters']['group_access_value']['field'] = 'group_access_value';
  $handler->display->display_options['filters']['group_access_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'all_projects_list';
  $export['all'] = $view;

  return $export;
}
