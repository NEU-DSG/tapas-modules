<?php
/**
 * @file
 * feature_tapas_collection.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_collection_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_collection content'.
  $permissions['create tapas_collection content'] = array(
    'name' => 'create tapas_collection content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_collection content'.
  $permissions['delete any tapas_collection content'] = array(
    'name' => 'delete any tapas_collection content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_collection content'.
  $permissions['delete own tapas_collection content'] = array(
    'name' => 'delete own tapas_collection content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_collection content'.
  $permissions['edit any tapas_collection content'] = array(
    'name' => 'edit any tapas_collection content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_collection content'.
  $permissions['edit own tapas_collection content'] = array(
    'name' => 'edit own tapas_collection content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
