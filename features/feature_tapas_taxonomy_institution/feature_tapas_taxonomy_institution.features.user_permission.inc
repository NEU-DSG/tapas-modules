<?php
/**
 * @file
 * feature_tapas_taxonomy_institution.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_tapas_taxonomy_institution_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in institution'.
  $permissions['delete terms in institution'] = array(
    'name' => 'delete terms in institution',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in institution'.
  $permissions['edit terms in institution'] = array(
    'name' => 'edit terms in institution',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
