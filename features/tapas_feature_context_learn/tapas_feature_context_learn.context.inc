<?php
/**
 * @file
 * tapas_feature_context_learn.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_learn_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'learnnews';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['learnnews'] = $context;

  return $export;
}
