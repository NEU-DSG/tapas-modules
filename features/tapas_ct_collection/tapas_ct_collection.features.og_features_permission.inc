<?php
/**
 * @file
 * tapas_ct_collection.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_ct_collection_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:tapas_collection:add user'
  $permissions['node:tapas_collection:add user'] = array(
    'roles' => array(
      'collection moderator' => 'collection moderator',
    ),
  );

  // Exported og permission: 'node:tapas_collection:administer group'
  $permissions['node:tapas_collection:administer group'] = array(
    'roles' => array(
      'collection moderator' => 'collection moderator',
    ),
  );

  // Exported og permission: 'node:tapas_collection:approve and deny subscription'
  $permissions['node:tapas_collection:approve and deny subscription'] = array(
    'roles' => array(
      'collection moderator' => 'collection moderator',
    ),
  );

  // Exported og permission: 'node:tapas_collection:create tapas_collection content'
  $permissions['node:tapas_collection:create tapas_collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:create tapas_record content'
  $permissions['node:tapas_collection:create tapas_record content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:delete any tapas_collection content'
  $permissions['node:tapas_collection:delete any tapas_collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:delete any tapas_record content'
  $permissions['node:tapas_collection:delete any tapas_record content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:delete own tapas_collection content'
  $permissions['node:tapas_collection:delete own tapas_collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:delete own tapas_record content'
  $permissions['node:tapas_collection:delete own tapas_record content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:manage members'
  $permissions['node:tapas_collection:manage members'] = array(
    'roles' => array(
      'collection moderator' => 'collection moderator',
    ),
  );

  // Exported og permission: 'node:tapas_collection:manage permissions'
  $permissions['node:tapas_collection:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_collection:manage roles'
  $permissions['node:tapas_collection:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_collection:subscribe'
  $permissions['node:tapas_collection:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:tapas_collection:subscribe without approval'
  $permissions['node:tapas_collection:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_collection:unsubscribe'
  $permissions['node:tapas_collection:unsubscribe'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
      'collection moderator' => 'collection moderator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapas_collection:update any tapas_collection content'
  $permissions['node:tapas_collection:update any tapas_collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:update any tapas_record content'
  $permissions['node:tapas_collection:update any tapas_record content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:update group'
  $permissions['node:tapas_collection:update group'] = array(
    'roles' => array(
      'collection moderator' => 'collection moderator',
    ),
  );

  // Exported og permission: 'node:tapas_collection:update own tapas_collection content'
  $permissions['node:tapas_collection:update own tapas_collection content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  // Exported og permission: 'node:tapas_collection:update own tapas_record content'
  $permissions['node:tapas_collection:update own tapas_record content'] = array(
    'roles' => array(
      'collection editor' => 'collection editor',
    ),
  );

  return $permissions;
}
