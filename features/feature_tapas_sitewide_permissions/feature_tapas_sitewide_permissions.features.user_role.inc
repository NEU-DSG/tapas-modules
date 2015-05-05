<?php
/**
 * @file
 * feature_tapas_sitewide_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_tapas_sitewide_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: paid member.
  $roles['paid member'] = array(
    'name' => 'paid member',
    'weight' => 2,
  );

  return $roles;
}
