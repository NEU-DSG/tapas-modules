<?php
/**
 * @file
 * tapas_record.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_record_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:collection:delete any tapas_record content'
  $permissions['node:collection:delete any tapas_record content'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:delete own tapas_record content'
  $permissions['node:collection:delete own tapas_record content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:update any tapas_record content'
  $permissions['node:collection:update any tapas_record content'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:update own tapas_record content'
  $permissions['node:collection:update own tapas_record content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:institution:create tapas_record content'
  $permissions['node:institution:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete any tapas_record content'
  $permissions['node:institution:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete own tapas_record content'
  $permissions['node:institution:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:update any tapas_record content'
  $permissions['node:institution:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:update own tapas_record content'
  $permissions['node:institution:update own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create tapas_record content'
  $permissions['node:project:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any tapas_record content'
  $permissions['node:project:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own tapas_record content'
  $permissions['node:project:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any tapas_record content'
  $permissions['node:project:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own tapas_record content'
  $permissions['node:project:update own tapas_record content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
