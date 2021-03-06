<?php
/**
 * @file
 * tapas_feature_context_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tapas_feature_context_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects';
  $context->description = 'Projects';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tapas_project' => 'tapas_project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-collections_in_project-block' => array(
          'module' => 'views',
          'delta' => 'collections_in_project-block',
          'region' => 'content',
          'weight' => '-39',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Projects');
  $export['projects'] = $context;

  return $export;
}
