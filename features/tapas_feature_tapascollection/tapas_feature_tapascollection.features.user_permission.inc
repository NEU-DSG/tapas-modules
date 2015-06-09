<?php
/**
 * @file
 * tapas_feature_tapascollection.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_feature_tapascollection_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapascollection_collection content'.
  $permissions['create tapascollection_collection content'] = array(
    'name' => 'create tapascollection_collection content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create tapascollection_project content'.
  $permissions['create tapascollection_project content'] = array(
    'name' => 'create tapascollection_project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapascollection_collection content'.
  $permissions['delete any tapascollection_collection content'] = array(
    'name' => 'delete any tapascollection_collection content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapascollection_project content'.
  $permissions['delete any tapascollection_project content'] = array(
    'name' => 'delete any tapascollection_project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapascollection_collection content'.
  $permissions['delete own tapascollection_collection content'] = array(
    'name' => 'delete own tapascollection_collection content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapascollection_project content'.
  $permissions['delete own tapascollection_project content'] = array(
    'name' => 'delete own tapascollection_project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapascollection_collection content'.
  $permissions['edit any tapascollection_collection content'] = array(
    'name' => 'edit any tapascollection_collection content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapascollection_project content'.
  $permissions['edit any tapascollection_project content'] = array(
    'name' => 'edit any tapascollection_project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapascollection_collection content'.
  $permissions['edit own tapascollection_collection content'] = array(
    'name' => 'edit own tapascollection_collection content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapascollection_project content'.
  $permissions['edit own tapascollection_project content'] = array(
    'name' => 'edit own tapascollection_project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
