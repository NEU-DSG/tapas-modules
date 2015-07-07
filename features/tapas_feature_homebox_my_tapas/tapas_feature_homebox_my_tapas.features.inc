<?php
/**
 * @file
 * tapas_feature_homebox_my_tapas.features.inc
 */

/**
 * Implements hook_homebox().
 */
function tapas_feature_homebox_my_tapas_homebox() {
  $homeboxes = array();

  $homeboxes['my_tapas'] = array(
    'regions' => 2,
    'cache' => 0,
    'color' => 0,
    'colors' => array(
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => array(
      'views_my-block' => array(
        'module' => 'views',
        'delta' => 'my-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'My Projects',
        'weight' => -21,
      ),
      'views_my-block_1' => array(
        'module' => 'views',
        'delta' => 'my-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -22,
      ),
      'views_my-block_2' => array(
        'module' => 'views',
        'delta' => 'my-block_2',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -22,
      ),
    ),
    'widths' => array(),
    'title' => 'My Tapas',
    'path' => 'my_tapas',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => array(
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
