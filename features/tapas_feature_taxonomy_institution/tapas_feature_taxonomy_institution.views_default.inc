<?php
/**
 * @file
 * tapas_feature_taxonomy_institution.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tapas_feature_taxonomy_institution_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_all_institutions';
  $view->description = '';
  $view->tag = 'tapas, structure';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'List All Institutions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Institutions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_term' => 'edit_term',
    'field_institution_image' => 'field_institution_image',
    'name' => 'name',
    'field_institution_url' => 'field_institution_url',
    'description' => 'description',
    'name_1' => 'name_1',
    'og_user_node1' => 'og_user_node1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_term' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_user_node1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Taxonomy term: Profile using profile-institution */
  $handler->display->display_options['relationships']['reverse_field_profile_institution_profile2']['id'] = 'reverse_field_profile_institution_profile2';
  $handler->display->display_options['relationships']['reverse_field_profile_institution_profile2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_profile_institution_profile2']['field'] = 'reverse_field_profile_institution_profile2';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'reverse_field_profile_institution_profile2';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['group_type'] = 'count';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['label'] = 'Edit';
  /* Field: Taxonomy term: Institution_image */
  $handler->display->display_options['fields']['field_institution_image']['id'] = 'field_institution_image';
  $handler->display->display_options['fields']['field_institution_image']['table'] = 'field_data_field_institution_image';
  $handler->display->display_options['fields']['field_institution_image']['field'] = 'field_institution_image';
  $handler->display->display_options['fields']['field_institution_image']['label'] = 'Image';
  $handler->display->display_options['fields']['field_institution_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_institution_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Institution URL */
  $handler->display->display_options['fields']['field_institution_url']['id'] = 'field_institution_url';
  $handler->display->display_options['fields']['field_institution_url']['table'] = 'field_data_field_institution_url';
  $handler->display->display_options['fields']['field_institution_url']['field'] = 'field_institution_url';
  $handler->display->display_options['fields']['field_institution_url']['label'] = 'URL';
  $handler->display->display_options['fields']['field_institution_url']['click_sort_column'] = 'url';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Description';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'user';
  $handler->display->display_options['fields']['name_1']['label'] = 'Users';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: User: Group membership */
  $handler->display->display_options['fields']['og_user_node1']['id'] = 'og_user_node1';
  $handler->display->display_options['fields']['og_user_node1']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_user_node1']['field'] = 'og_user_node1';
  $handler->display->display_options['fields']['og_user_node1']['relationship'] = 'user';
  $handler->display->display_options['fields']['og_user_node1']['label'] = 'Projects';
  $handler->display->display_options['fields']['og_user_node1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_user_node1']['type'] = 'og_list_default';
  $handler->display->display_options['fields']['og_user_node1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_user_node1']['delta_offset'] = '0';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tapas_institution' => 'tapas_institution',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-institutions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List All Institutions';
  $export['list_all_institutions'] = $view;

  return $export;
}
