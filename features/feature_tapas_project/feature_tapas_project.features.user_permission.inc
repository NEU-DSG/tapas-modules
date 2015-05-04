<?php
/**
 * @file
 * feature_tapas_project.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_project_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete any tapas_project content'.
  $permissions['delete any tapas_project content'] = array(
    'name' => 'delete any tapas_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_project content'.
  $permissions['delete own tapas_project content'] = array(
    'name' => 'delete own tapas_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_project content'.
  $permissions['edit any tapas_project content'] = array(
    'name' => 'edit any tapas_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_project content'.
  $permissions['edit own tapas_project content'] = array(
    'name' => 'edit own tapas_project content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
