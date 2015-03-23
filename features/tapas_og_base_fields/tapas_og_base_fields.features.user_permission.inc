<?php
/**
 * @file
 * tapas_og_base_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tapas_og_base_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'og',
  );

  return $permissions;
}
