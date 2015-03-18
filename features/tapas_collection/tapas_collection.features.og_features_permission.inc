<?php
/**
 * @file
 * tapas_collection.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_collection_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:collection:add user'
  $permissions['node:collection:add user'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
    ),
  );

  // Exported og permission: 'node:collection:administer group'
  $permissions['node:collection:administer group'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:approve and deny subscription'
  $permissions['node:collection:approve and deny subscription'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
    ),
  );

  // Exported og permission: 'node:collection:create collection content'
  $permissions['node:collection:create collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:delete any collection content'
  $permissions['node:collection:delete any collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:delete own collection content'
  $permissions['node:collection:delete own collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:manage members'
  $permissions['node:collection:manage members'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
    ),
  );

  // Exported og permission: 'node:collection:manage permissions'
  $permissions['node:collection:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collection:manage roles'
  $permissions['node:collection:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collection:subscribe'
  $permissions['node:collection:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:collection:subscribe without approval'
  $permissions['node:collection:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collection:unsubscribe'
  $permissions['node:collection:unsubscribe'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collection:update any collection content'
  $permissions['node:collection:update any collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:update group'
  $permissions['node:collection:update group'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:collection:update own collection content'
  $permissions['node:collection:update own collection content'] = array(
    'roles' => array(
      'collection administrator' => 'collection administrator',
      'collection editor' => 'collection editor',
    ),
  );

  return $permissions;
}
