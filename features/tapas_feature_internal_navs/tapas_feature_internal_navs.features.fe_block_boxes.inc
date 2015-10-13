<?php
/**
 * @file
 * tapas_feature_internal_navs.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_internal_navs_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'About page internal nav';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'aboutnavigation';
  $fe_block_boxes->body = '  <ul class="nav nav-pills nav-stacked">
    <li class="active"><a href="#" class="page-scroll">Home</a></li>
    <li><a href="#people" class="page-scroll">People</a></li>
    <li><a href="#story" class="page-scroll">TAPAS Story</a></li>
<li><a href="#partners" class="page-scroll">Partners & Supporters</a></li>
    <li><a href="#explore" class="page-scroll">TAPAS | Explore</a></li>
 <li><a href="#accounts" class="page-scroll">Accounts & Memberships</a></li>
 <li><a href="#dev" class="page-scroll">TAPAS | Development</a></li>
  </ul>';

  $export['aboutnavigation'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'submenu navigation for community page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'communitynavigation';
  $fe_block_boxes->body = '  <ul class="nav nav-pills nav-stacked">
    <li class="active"><a href="#" class="page-scroll">Home</a></li>
<li><a href="#news" class="page-scroll">News</a></li>
<li><a href="#members" class="page-scroll">Members</a></li>
<li><a href="#activity" class="page-scroll">Activity</a></li>
<li class="divider"></li>
<li><a href="#learn" class="page-scroll">TAPAS | Learn</a></li>
    <li><a tabindex="-1" href="#workshops" class="page-scroll">Workshops</a></li>
    <li><a tabindex="-1" href="#codealong" class="page-scroll">Code-Alongs</a></li>
    <li><a tabindex="-1" href="#clinic" class="page-scroll">Clinics</a></li>
 <li><a tabindex="-1" href="#classroom" class="page-scroll">TAPAS | Classroom</a></li>
 <li><a tabindex="-1" href="#resources" class="page-scroll">TEI Resources</a></li>
 </ul>';

  $export['communitynavigation'] = $fe_block_boxes;

  return $export;
}
