<?php
/**
 * @file
 * tapas_feature_base_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function tapas_feature_base_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 3,
  );

  // Exported role: Paid Member.
  $roles['Paid Member'] = array(
    'name' => 'Paid Member',
    'weight' => 2,
  );

  return $roles;
}
