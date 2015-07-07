<?php
/**
 * @file
 * tapas_feature_context_discover.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_discover_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'discover';
  $context->description = 'content for discover page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'discover' => 'discover',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-featured_project_gallery-block' => array(
          'module' => 'views',
          'delta' => 'featured_project_gallery-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-6bfbde3df9852e23de548e1e0bf2a66d' => array(
          'module' => 'views',
          'delta' => '6bfbde3df9852e23de548e1e0bf2a66d',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-0d23e2ff80bba7e923d73b45beef2adc' => array(
          'module' => 'views',
          'delta' => '0d23e2ff80bba7e923d73b45beef2adc',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('content for discover page');
  $export['discover'] = $context;

  return $export;
}
