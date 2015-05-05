<?php
/**
 * @file
 * feature_tapas_tapasrecord_as_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_tapasrecord_as_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tapasrecordnode content'.
  $permissions['create tapasrecordnode content'] = array(
    'name' => 'create tapasrecordnode content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tapasrecordnode content'.
  $permissions['delete any tapasrecordnode content'] = array(
    'name' => 'delete any tapasrecordnode content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tapasrecordnode content'.
  $permissions['delete own tapasrecordnode content'] = array(
    'name' => 'delete own tapasrecordnode content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tapasrecordnode content'.
  $permissions['edit any tapasrecordnode content'] = array(
    'name' => 'edit any tapasrecordnode content',
    'roles' => array(
      'administrator' => 'administrator',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tapasrecordnode content'.
  $permissions['edit own tapasrecordnode content'] = array(
    'name' => 'edit own tapasrecordnode content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'paid member' => 'paid member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
