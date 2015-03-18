<?php
/**
 * @file
 * tapas_collection.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function tapas_collection_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:collection:collection administrator'.
  $roles['node:collection:collection administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'collection',
    'name' => 'collection administrator',
  );

  // Exported OG Role: 'node:collection:collection editor'.
  $roles['node:collection:collection editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'collection',
    'name' => 'collection editor',
  );

  return $roles;
}
