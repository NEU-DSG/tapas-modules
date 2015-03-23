<?php
/**
 * @file
 * tapas_ct_collection.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function tapas_ct_collection_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:tapas_collection:collection editor'.
  $roles['node:tapas_collection:collection editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'tapas_collection',
    'name' => 'collection editor',
  );

  // Exported OG Role: 'node:tapas_collection:collection moderator'.
  $roles['node:tapas_collection:collection moderator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'tapas_collection',
    'name' => 'collection moderator',
  );

  return $roles;
}
