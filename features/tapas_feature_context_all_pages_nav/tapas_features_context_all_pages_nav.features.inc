<?php
/**
 * @file
 * tapas_features_context_all_pages_nav.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tapas_features_context_all_pages_nav_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
