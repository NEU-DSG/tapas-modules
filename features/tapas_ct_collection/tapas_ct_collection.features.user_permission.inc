<?php
/**
 * @file
 * tapas_ct_collection.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_ct_collection_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_collection content'.
  $permissions['create tapas_collection content'] = array(
    'name' => 'create tapas_collection content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_collection content'.
  $permissions['delete any tapas_collection content'] = array(
    'name' => 'delete any tapas_collection content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_collection content'.
  $permissions['delete own tapas_collection content'] = array(
    'name' => 'delete own tapas_collection content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_collection content'.
  $permissions['edit any tapas_collection content'] = array(
    'name' => 'edit any tapas_collection content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_collection content'.
  $permissions['edit own tapas_collection content'] = array(
    'name' => 'edit own tapas_collection content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
