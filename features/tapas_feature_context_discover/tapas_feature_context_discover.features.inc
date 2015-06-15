<?php
/**
 * @file
 * tapas_feature_context_discover.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tapas_feature_context_discover_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
