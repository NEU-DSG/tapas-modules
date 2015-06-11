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
  $handler->display->display_options['title'] = 'List All Institutions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
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
    'image_style' => 'tapas_tiny',
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
  /* Field: Taxonomy term: Institution_address */
  $handler->display->display_options['fields']['field_institution_address']['id'] = 'field_institution_address';
  $handler->display->display_options['fields']['field_institution_address']['table'] = 'field_data_field_institution_address';
  $handler->display->display_options['fields']['field_institution_address']['field'] = 'field_institution_address';
  $handler->display->display_options['fields']['field_institution_address']['label'] = 'Address';
  /* Field: Taxonomy term: Institution Latitude */
  $handler->display->display_options['fields']['field_institution_latitude']['id'] = 'field_institution_latitude';
  $handler->display->display_options['fields']['field_institution_latitude']['table'] = 'field_data_field_institution_latitude';
  $handler->display->display_options['fields']['field_institution_latitude']['field'] = 'field_institution_latitude';
  $handler->display->display_options['fields']['field_institution_latitude']['label'] = 'Lat';
  $handler->display->display_options['fields']['field_institution_latitude']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 0,
  );
  /* Field: Taxonomy term: Institution Longitude */
  $handler->display->display_options['fields']['field_institution_longitude']['id'] = 'field_institution_longitude';
  $handler->display->display_options['fields']['field_institution_longitude']['table'] = 'field_data_field_institution_longitude';
  $handler->display->display_options['fields']['field_institution_longitude']['field'] = 'field_institution_longitude';
  $handler->display->display_options['fields']['field_institution_longitude']['label'] = 'Long';
  $handler->display->display_options['fields']['field_institution_longitude']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 0,
  );
  /* Field: Taxonomy term: Institution Official Flag */
  $handler->display->display_options['fields']['field_institution_official_flag']['id'] = 'field_institution_official_flag';
  $handler->display->display_options['fields']['field_institution_official_flag']['table'] = 'field_data_field_institution_official_flag';
  $handler->display->display_options['fields']['field_institution_official_flag']['field'] = 'field_institution_official_flag';
  $handler->display->display_options['fields']['field_institution_official_flag']['label'] = 'Official';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tapas_institution' => 'tapas_institution',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'list-all-institutions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List All Institutions';
  $export['list_all_institutions'] = $view;

  return $export;
}
