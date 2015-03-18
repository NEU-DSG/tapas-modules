<?php
/**
 * @file
 * tapas_project.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function tapas_project_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:project:project administrator'.
  $roles['node:project:project administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'project',
    'name' => 'project administrator',
  );

  // Exported OG Role: 'node:project:project editor'.
  $roles['node:project:project editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'project',
    'name' => 'project editor',
  );

  return $roles;
}
