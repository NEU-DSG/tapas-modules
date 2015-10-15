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
        'views-news-block_4' => array(
          'module' => 'views',
          'delta' => 'news-block_4',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'user-new' => array(
          'module' => 'user',
          'delta' => 'new',
          'region' => 'content',
          'weight' => '-8',
        ),
        'user-online' => array(
          'module' => 'user',
          'delta' => 'online',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-community-block_1' => array(
          'module' => 'views',
          'delta' => 'community-block_1',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-community-block_2' => array(
          'module' => 'views',
          'delta' => 'community-block_2',
          'region' => 'content',
          'weight' => '-5',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-news-block_9' => array(
          'module' => 'views',
          'delta' => 'news-block_9',
          'region' => 'content',
          'weight' => '-3',
        ),
        'views-community-block_3' => array(
          'module' => 'views',
          'delta' => 'community-block_3',
          'region' => 'content',
          'weight' => '-2',
        ),
        'views-news-block_5' => array(
          'module' => 'views',
          'delta' => 'news-block_5',
          'region' => 'content',
          'weight' => '-1',
        ),
        'views-community-block_4' => array(
          'module' => 'views',
          'delta' => 'community-block_4',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-news-block_6' => array(
          'module' => 'views',
          'delta' => 'news-block_6',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-community-block_5' => array(
          'module' => 'views',
          'delta' => 'community-block_5',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-news-block_8' => array(
          'module' => 'views',
          'delta' => 'news-block_8',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-community-block_6' => array(
          'module' => 'views',
          'delta' => 'community-block_6',
          'region' => 'content',
          'weight' => '4',
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
