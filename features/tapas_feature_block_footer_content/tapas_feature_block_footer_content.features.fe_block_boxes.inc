<?php
/**
 * @file
 * tapas_feature_block_footer_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_block_footer_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer content';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_content';
  $fe_block_boxes->body = '<div class="row"><div class="col-lg-6"><p>&copy; 2015 Tapas Project  &middot;   &middot;  <a href="mailto:info@tapasproject.org">info@tapasproject.org</a> </p></div><div class="col-lg-4"><a href="facebook"><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-facebook fa-stack-1x fa-inverse"></i></span></a><a href="twitter"><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-twitter fa-stack-1x fa-inverse"></i></span></a></div><div class="col-lg-2"><a href="http://northeastern.edu"><img src="http://www.northeastern.edu/neuhome/images/logo-footer.png"></a></div> </div>';

  $export['footer_content'] = $fe_block_boxes;

  return $export;
}
