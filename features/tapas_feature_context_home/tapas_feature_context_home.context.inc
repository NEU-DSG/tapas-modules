<?php
/**
 * @file
 * tapas_feature_context_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'content',
          'weight' => '-29',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'content',
          'weight' => '-28',
        ),
        'views-cd1d5d6b17b5126bba6f68dcf7e7f704' => array(
          'module' => 'views',
          'delta' => 'cd1d5d6b17b5126bba6f68dcf7e7f704',
          'region' => 'content',
          'weight' => '-27',
        ),
        'views-8bf387fd211654913ca983670a71686b' => array(
          'module' => 'views',
          'delta' => '8bf387fd211654913ca983670a71686b',
          'region' => 'content',
          'weight' => '-26',
        ),
        'views-385d1f51662c3263fd6db0df10d87e32' => array(
          'module' => 'views',
          'delta' => '385d1f51662c3263fd6db0df10d87e32',
          'region' => 'content',
          'weight' => '-25',
        ),
        'views-news-block_2' => array(
          'module' => 'views',
          'delta' => 'news-block_2',
          'region' => 'content',
          'weight' => '-24',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content',
          'weight' => '-23',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['home'] = $context;

  return $export;
}
