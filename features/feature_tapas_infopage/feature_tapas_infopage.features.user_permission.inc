<?php
/**
 * @file
 * feature_tapas_infopage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_infopage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_infopage content'.
  $permissions['create tapas_infopage content'] = array(
    'name' => 'create tapas_infopage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_infopage content'.
  $permissions['delete any tapas_infopage content'] = array(
    'name' => 'delete any tapas_infopage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_infopage content'.
  $permissions['delete own tapas_infopage content'] = array(
    'name' => 'delete own tapas_infopage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_infopage content'.
  $permissions['edit any tapas_infopage content'] = array(
    'name' => 'edit any tapas_infopage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_infopage content'.
  $permissions['edit own tapas_infopage content'] = array(
    'name' => 'edit own tapas_infopage content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
