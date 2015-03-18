<?php
/**
 * @file
 * tapas_institution.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_institution_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create institution content'.
  $permissions['create institution content'] = array(
    'name' => 'create institution content',
    'roles' => array(
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any institution content'.
  $permissions['delete any institution content'] = array(
    'name' => 'delete any institution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own institution content'.
  $permissions['delete own institution content'] = array(
    'name' => 'delete own institution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in institution_names'.
  $permissions['delete terms in institution_names'] = array(
    'name' => 'delete terms in institution_names',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any institution content'.
  $permissions['edit any institution content'] = array(
    'name' => 'edit any institution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own institution content'.
  $permissions['edit own institution content'] = array(
    'name' => 'edit own institution content',
    'roles' => array(
      'site member' => 'site member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in institution_names'.
  $permissions['edit terms in institution_names'] = array(
    'name' => 'edit terms in institution_names',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
