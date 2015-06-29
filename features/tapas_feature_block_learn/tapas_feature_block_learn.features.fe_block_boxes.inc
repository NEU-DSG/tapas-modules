<?php
/**
 * @file
 * tapas_feature_block_learn.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_block_learn_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'learn block for commons page';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'commons_learn_block';
  $fe_block_boxes->body = '<ul>
<li>Workshops</li>
<li>Resource Guides</li>
<li>Code Alongs</li>
</ul>';

  $export['commons_learn_block'] = $fe_block_boxes;

  return $export;
}
