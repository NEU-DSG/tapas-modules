<?php
/**
 * @file
 * feature_tapas_newsitem.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_newsitem_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_newsitem content'.
  $permissions['create tapas_newsitem content'] = array(
    'name' => 'create tapas_newsitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_newsitem content'.
  $permissions['delete any tapas_newsitem content'] = array(
    'name' => 'delete any tapas_newsitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_newsitem content'.
  $permissions['delete own tapas_newsitem content'] = array(
    'name' => 'delete own tapas_newsitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_newsitem content'.
  $permissions['edit any tapas_newsitem content'] = array(
    'name' => 'edit any tapas_newsitem content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_newsitem content'.
  $permissions['edit own tapas_newsitem content'] = array(
    'name' => 'edit own tapas_newsitem content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
