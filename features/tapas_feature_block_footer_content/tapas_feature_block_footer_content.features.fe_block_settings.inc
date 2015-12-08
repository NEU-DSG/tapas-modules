<?php
/**
 * @file
 * tapas_feature_block_footer_content.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tapas_feature_block_footer_content_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_content'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'footer_content',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'garland' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'garland',
        'weight' => -16,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'tapas_redesign' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tapas_redesign',
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
