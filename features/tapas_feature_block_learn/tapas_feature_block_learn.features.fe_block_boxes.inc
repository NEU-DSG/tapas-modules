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
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'commons_learn_block';
  $fe_block_boxes->body = '<a name="learn"></a>

<div class="row">
<div class="col-md-6">
<p>Do you have questions about the TEI? Are you looking to learn more about best practices and developments in markup, schema development, metadata, Ography and support files management? Check out our available TAPAS | Learn services below:</p>
</div>
<div class="col-md-4">
<p>
</p>
</div>
</div>
';

  $export['commons_learn_block'] = $fe_block_boxes;

  return $export;
}
