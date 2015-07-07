<?php
/**
 * @file
 * tapas_feature_context_commons.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_commons_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'commons';
  $context->description = 'Commons content';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'commons' => 'commons',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-community-block_1' => array(
          'module' => 'views',
          'delta' => 'community-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Commons content');
  $export['commons'] = $context;

  return $export;
}
