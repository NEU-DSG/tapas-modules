<?php
/**
 * @file
 * features_tapas_og_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function features_tapas_og_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(),
    'module' => 'og',
  );

  return $permissions;
}
