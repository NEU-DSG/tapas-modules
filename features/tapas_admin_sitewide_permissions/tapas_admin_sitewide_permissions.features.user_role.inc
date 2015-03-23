<?php
/**
 * @file
 * tapas_admin_sitewide_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function tapas_admin_sitewide_permissions_user_default_roles() {
  $roles = array();

  // Exported role: site administrator.
  $roles['site administrator'] = array(
    'name' => 'site administrator',
    'weight' => 3,
  );

  // Exported role: site member.
  $roles['site member'] = array(
    'name' => 'site member',
    'weight' => 2,
  );

  return $roles;
}
