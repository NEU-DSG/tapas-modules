<?php
/**
 * @file
 * tapas_ct_project.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_ct_project_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:tapas_project:add user'
  $permissions['node:tapas_project:add user'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project moderator' => 'project moderator',
    ),
  );

  // Exported og permission: 'node:tapas_project:administer group'
  $permissions['node:tapas_project:administer group'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
    ),
  );

  // Exported og permission: 'node:tapas_project:approve and deny subscription'
  $permissions['node:tapas_project:approve and deny subscription'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project moderator' => 'project moderator',
    ),
  );

  // Exported og permission: 'node:tapas_project:create tapas_collection content'
  $permissions['node:tapas_project:create tapas_collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:create tapas_record content'
  $permissions['node:tapas_project:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:delete any tapas_collection content'
  $permissions['node:tapas_project:delete any tapas_collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:delete any tapas_record content'
  $permissions['node:tapas_project:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:delete own tapas_collection content'
  $permissions['node:tapas_project:delete own tapas_collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:delete own tapas_record content'
  $permissions['node:tapas_project:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:manage members'
  $permissions['node:tapas_project:manage members'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project moderator' => 'project moderator',
    ),
  );

  // Exported og permission: 'node:tapas_project:manage permissions'
  $permissions['node:tapas_project:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:manage roles'
  $permissions['node:tapas_project:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:subscribe'
  $permissions['node:tapas_project:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:tapas_project:subscribe without approval'
  $permissions['node:tapas_project:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:unsubscribe'
  $permissions['node:tapas_project:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
      'project editor' => 'project editor',
      'project moderator' => 'project moderator',
    ),
  );

  // Exported og permission: 'node:tapas_project:update any tapas_collection content'
  $permissions['node:tapas_project:update any tapas_collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:update any tapas_record content'
  $permissions['node:tapas_project:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_project:update group'
  $permissions['node:tapas_project:update group'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:update own tapas_collection content'
  $permissions['node:tapas_project:update own tapas_collection content'] = array(
    'roles' => array(
      'project administrator' => 'project administrator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:tapas_project:update own tapas_record content'
  $permissions['node:tapas_project:update own tapas_record content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
