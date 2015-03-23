<?php
/**
 * @file
 * tapas_ct_institution.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_ct_institution_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:tapas_institution:add user'
  $permissions['node:tapas_institution:add user'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:administer group'
  $permissions['node:tapas_institution:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:approve and deny subscription'
  $permissions['node:tapas_institution:approve and deny subscription'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:create tapas_collection content'
  $permissions['node:tapas_institution:create tapas_collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:create tapas_record content'
  $permissions['node:tapas_institution:create tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:delete any tapas_collection content'
  $permissions['node:tapas_institution:delete any tapas_collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:delete any tapas_record content'
  $permissions['node:tapas_institution:delete any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:delete own tapas_collection content'
  $permissions['node:tapas_institution:delete own tapas_collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:delete own tapas_record content'
  $permissions['node:tapas_institution:delete own tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:manage members'
  $permissions['node:tapas_institution:manage members'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:manage permissions'
  $permissions['node:tapas_institution:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:manage roles'
  $permissions['node:tapas_institution:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:subscribe'
  $permissions['node:tapas_institution:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:subscribe without approval'
  $permissions['node:tapas_institution:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:unsubscribe'
  $permissions['node:tapas_institution:unsubscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:update any tapas_collection content'
  $permissions['node:tapas_institution:update any tapas_collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:update any tapas_record content'
  $permissions['node:tapas_institution:update any tapas_record content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:update group'
  $permissions['node:tapas_institution:update group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:update own tapas_collection content'
  $permissions['node:tapas_institution:update own tapas_collection content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapas_institution:update own tapas_record content'
  $permissions['node:tapas_institution:update own tapas_record content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
