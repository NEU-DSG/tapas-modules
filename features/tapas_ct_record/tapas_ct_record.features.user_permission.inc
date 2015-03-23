<?php
/**
 * @file
 * tapas_ct_record.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_ct_record_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_record content'.
  $permissions['create tapas_record content'] = array(
    'name' => 'create tapas_record content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_record content'.
  $permissions['delete any tapas_record content'] = array(
    'name' => 'delete any tapas_record content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_record content'.
  $permissions['delete own tapas_record content'] = array(
    'name' => 'delete own tapas_record content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_record content'.
  $permissions['edit any tapas_record content'] = array(
    'name' => 'edit any tapas_record content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_record content'.
  $permissions['edit own tapas_record content'] = array(
    'name' => 'edit own tapas_record content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
