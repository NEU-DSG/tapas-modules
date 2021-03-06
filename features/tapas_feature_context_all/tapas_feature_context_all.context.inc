<?php
/**
 * @file
 * tapas_feature_context_all.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_all_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'menu-menu-tools-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-tools-menu',
          'region' => 'toolbar',
          'weight' => '-10',
        ),
        'views-news-block_3' => array(
          'module' => 'views',
          'delta' => 'news-block_3',
          'region' => 'toolbar',
          'weight' => '-9',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'toolbar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['all_pages'] = $context;

  return $export;
}
