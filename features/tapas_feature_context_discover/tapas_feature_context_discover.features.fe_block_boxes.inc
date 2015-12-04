<?php
/**
 * @file
 * tapas_feature_context_discover.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_context_discover_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Data commons block for discover page';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'data_commons';
  $fe_block_boxes->body = 'Danish caramels danish jujubes toffee chocolate bar. Danish croissant tart bear claw chocolate cake. Danish pastry pie cookie. Pudding lollipop marzipan biscuit donut chocolate. Sesame snaps marzipan wafer candy cake liquorice liquorice. Sweet tootsie roll powder candy dessert bear claw cake. Sweet cake sesame snaps jujubes donut macaroon oat cake. Caramels biscuit cheesecake carrot cake cheesecake tiramisu sesame snaps muffin. Fruitcake lemon drops croissant chocolate cake sugar plum cheesecake chupa chups.';

  $export['data_commons'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Discover Intro Text';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'discover_intro_text';
  $fe_block_boxes->body = '<h2>Welcome to the TAPAS research page!</h2>

Discover <a href="#featured">featured</a> projects, collections, and items in the archive. Query the TAPAS repository through the advanced search form below, or analyze data from the TAPAS Data Commons. ';

  $export['discover_intro_text'] = $fe_block_boxes;

  return $export;
}
