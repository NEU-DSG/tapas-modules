<?php
/**
 * @file
 * tapas_institution.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_institution_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:institution:add user'
  $permissions['node:institution:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:administer group'
  $permissions['node:institution:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:approve and deny subscription'
  $permissions['node:institution:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:create collection content'
  $permissions['node:institution:create collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:create tapas_record content'
  $permissions['node:institution:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete any collection content'
  $permissions['node:institution:delete any collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete any tapas_record content'
  $permissions['node:institution:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete own collection content'
  $permissions['node:institution:delete own collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:delete own tapas_record content'
  $permissions['node:institution:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:manage members'
  $permissions['node:institution:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:manage permissions'
  $permissions['node:institution:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:manage roles'
  $permissions['node:institution:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:subscribe'
  $permissions['node:institution:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:institution:subscribe without approval'
  $permissions['node:institution:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:unsubscribe'
  $permissions['node:institution:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:institution:update any collection content'
  $permissions['node:institution:update any collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:update any tapas_record content'
  $permissions['node:institution:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:update group'
  $permissions['node:institution:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:institution:update own collection content'
  $permissions['node:institution:update own collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:institution:update own tapas_record content'
  $permissions['node:institution:update own tapas_record content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
