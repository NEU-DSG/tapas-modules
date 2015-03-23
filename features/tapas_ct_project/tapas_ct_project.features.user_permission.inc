<?php
/**
 * @file
 * tapas_ct_project.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_ct_project_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapas_project content'.
  $permissions['create tapas_project content'] = array(
    'name' => 'create tapas_project content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapas_project content'.
  $permissions['delete any tapas_project content'] = array(
    'name' => 'delete any tapas_project content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapas_project content'.
  $permissions['delete own tapas_project content'] = array(
    'name' => 'delete own tapas_project content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapas_project content'.
  $permissions['edit any tapas_project content'] = array(
    'name' => 'edit any tapas_project content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapas_project content'.
  $permissions['edit own tapas_project content'] = array(
    'name' => 'edit own tapas_project content',
    'roles' => array(
      'site administrator' => 'site administrator',
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
