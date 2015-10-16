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
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'commons_community_block';
  $fe_block_boxes->body = '<dl>
sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample text ...sample text ... sample 
<dt>Members</dt>
 							 <dd>View a list of all members of the TAPAS community</dd>


</di>';

  $export['commons_community_block'] = $fe_block_boxes;

  return $export;
}
