<?php
/**
 * @file
 * tapas_feature_block_community.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_block_community_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Community block for Commons';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'commons_community_block';
  $fe_block_boxes->body = '<ul><li>Members</li><li>Institutions</li><li>Partners</li></ul>';

  $export['commons_community_block'] = $fe_block_boxes;

  return $export;
}
