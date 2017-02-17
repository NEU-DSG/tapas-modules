<?php
/**
 * @file
 * tapas_feature_two_pane_reader.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_two_pane_reader_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'test_record_panes';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'compare' => 'compare',
        'compare/*' => 'compare/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-test_reader_pane-block' => array(
          'module' => 'views',
          'delta' => 'test_reader_pane-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-test_reader_pane-block_1' => array(
          'module' => 'views',
          'delta' => 'test_reader_pane-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['test_record_panes'] = $context;

  return $export;
}
