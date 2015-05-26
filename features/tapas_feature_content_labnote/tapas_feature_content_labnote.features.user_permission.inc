<?php
/**
 * @file
 * tapas_feature_content_labnote.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_feature_content_labnote_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create lab_note content'.
  $permissions['create lab_note content'] = array(
    'name' => 'create lab_note content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any lab_note content'.
  $permissions['delete any lab_note content'] = array(
    'name' => 'delete any lab_note content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own lab_note content'.
  $permissions['delete own lab_note content'] = array(
    'name' => 'delete own lab_note content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any lab_note content'.
  $permissions['edit any lab_note content'] = array(
    'name' => 'edit any lab_note content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own lab_note content'.
  $permissions['edit own lab_note content'] = array(
    'name' => 'edit own lab_note content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
