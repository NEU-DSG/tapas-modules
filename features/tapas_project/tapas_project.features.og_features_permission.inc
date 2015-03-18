<?php
/**
 * @file
 * tapas_project.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_project_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:project:add user'
  $permissions['node:project:add user'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:administer group'
  $permissions['node:project:administer group'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:approve and deny subscription'
  $permissions['node:project:approve and deny subscription'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:create collection content'
  $permissions['node:project:create collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:create tapas_record content'
  $permissions['node:project:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any collection content'
  $permissions['node:project:delete any collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:delete any tapas_record content'
  $permissions['node:project:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own collection content'
  $permissions['node:project:delete own collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:delete own tapas_record content'
  $permissions['node:project:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:manage members'
  $permissions['node:project:manage members'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:manage permissions'
  $permissions['node:project:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:manage roles'
  $permissions['node:project:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:subscribe'
  $permissions['node:project:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:project:subscribe without approval'
  $permissions['node:project:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:unsubscribe'
  $permissions['node:project:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:update any collection content'
  $permissions['node:project:update any collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:project:update any tapas_record content'
  $permissions['node:project:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update group'
  $permissions['node:project:update group'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:update own collection content'
  $permissions['node:project:update own collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:project:update own tapas_record content'
  $permissions['node:project:update own tapas_record content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
