<?php
/**
 * @file
 * tapas_ct_project.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function tapas_ct_project_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:tapas_project:project administrator'.
  $roles['node:tapas_project:project administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'tapas_project',
    'name' => 'project administrator',
  );

  // Exported OG Role: 'node:tapas_project:project editor'.
  $roles['node:tapas_project:project editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'tapas_project',
    'name' => 'project editor',
  );

  // Exported OG Role: 'node:tapas_project:project moderator'.
  $roles['node:tapas_project:project moderator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'tapas_project',
    'name' => 'project moderator',
  );

  return $roles;
}
