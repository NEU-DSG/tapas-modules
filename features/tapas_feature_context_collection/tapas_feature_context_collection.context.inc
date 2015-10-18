<?php
/**
 * @file
 * tapas_feature_context_collection.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_collection_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collections';
  $context->description = 'Collections';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tapas_collection' => 'tapas_collection',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ece40a341bd3abd96179414c41afa18d' => array(
          'module' => 'views',
          'delta' => 'ece40a341bd3abd96179414c41afa18d',
          'region' => 'content',
          'weight' => '-39',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Collections');
  $export['collections'] = $context;

  return $export;
}
