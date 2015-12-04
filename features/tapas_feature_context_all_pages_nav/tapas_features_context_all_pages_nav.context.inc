<?php
/**
 * @file
 * tapas_features_context_all_pages_nav.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_features_context_all_pages_nav_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_nav';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'default' => array(
      'values' => array(
        'context_condition_default' => 'context_condition_default',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-primary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-primary-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'navigation',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['all_pages_nav'] = $context;

  return $export;
}
