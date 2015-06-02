<?php
/**
 * @file
 * tapas_feature_tapascollection.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function tapas_feature_tapascollection_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:tapascollection_project:add user'
  $permissions['node:tapascollection_project:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:administer group'
  $permissions['node:tapascollection_project:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:approve and deny subscription'
  $permissions['node:tapascollection_project:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:create tapasrecordnode content'
  $permissions['node:tapascollection_project:create tapasrecordnode content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:delete any tapasrecordnode content'
  $permissions['node:tapascollection_project:delete any tapasrecordnode content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:delete own tapasrecordnode content'
  $permissions['node:tapascollection_project:delete own tapasrecordnode content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:manage members'
  $permissions['node:tapascollection_project:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:manage permissions'
  $permissions['node:tapascollection_project:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:manage roles'
  $permissions['node:tapascollection_project:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:subscribe'
  $permissions['node:tapascollection_project:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:subscribe without approval'
  $permissions['node:tapascollection_project:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:tapascollection_project:unsubscribe'
  $permissions['node:tapascollection_project:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:update any tapasrecordnode content'
  $permissions['node:tapascollection_project:update any tapasrecordnode content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:update group'
  $permissions['node:tapascollection_project:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:tapascollection_project:update own tapasrecordnode content'
  $permissions['node:tapascollection_project:update own tapasrecordnode content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
