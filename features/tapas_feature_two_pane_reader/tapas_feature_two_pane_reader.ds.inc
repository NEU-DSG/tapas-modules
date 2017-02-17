<?php
/**
 * @file
 * tapas_feature_two_pane_reader.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function tapas_feature_two_pane_reader_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'reader_pane';
  $ds_view_mode->label = 'Reader pane';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['reader_pane'] = $ds_view_mode;

  return $export;
}
