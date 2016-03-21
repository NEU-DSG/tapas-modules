<?php 
/**
 * @file
 * tapascontent_forms_inc
 */

define('TAPASCONTENT_CREATE_PROJ_FIRST_HEADER', t("Please create a project first, or use the Commons."));
define('TAPASCONTENT_CREATE_PROJ_FIRST_TEXT', t("Creating a Collection requires having a Project to attach it to (either a project that you created, or one to which the owner has given you editing privledges). You don't currently seem to be an editing member of any Projects; please create a project first! Alternately, you can upload TEI directly to the Common Repository without creating any projects or collections."));

//=============================================================
// Form Overrides
//=============================================================

/**
 * Implements hook_form_alter().
 *
 * Invokes the Honeypot module's spam-prevention.
 */

function tapascollection_form_alter(&$form, &$form_state, $form_id) {
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
}

/**
 * Implements hook_form_BASE_ID_alter().
 * all NODE forms
 */
function tapascontent_form_node_form_alter(&$form, &$form_state, $form_id) {

	if(isset($form['field_tapas_upload_status'])) {
		$form['field_tapas_upload_status']['#access'] = FALSE;
	}

}

/**
 * implements hook_form_FORM_ID_form_alter
 * PROJECT form
 */
function tapascontent_form_tapas_project_node_form_alter(&$form, &$form_state, $form_id) {
	drupal_set_message("Project form called.");
  $form['#validate'][] = '_tapascontent_validate_project_form';
}


/**
 * implements hook_form_FORM_ID_form_alter
 * COLLECTION form
 */
function tapascontent_form_tapas_collection_node_form_alter(&$form, &$form_state, $form_id) {

  $form['#validate'][] = '_tapascontent_validate_collection_form';
	_tapascontent_collection_form_check($form);
}

/**
 * Verify (valid) group membership, display form
 *
 * In theory, if the user is not currently a member of any groups, the
 * $user_groups array should be empty. However, during testing I encountered
 * situations where deleted groups were not always removed properly from the
 * user. In these cases, the $user_groups array would be non-empty, but the
 * gid(s) in it would be invalid, and throw exceptions when used in any function
 * acceptng a gid. This recursive function tries to check for this, clean up,
 * and then try again to check for valid groups.
 */

function _tapascontent_collection_form_check(&$form) {

	$user_groups = og_get_groups_by_user(NULL, "node");

	if(empty($user_groups)) {
		_tapascontent_disable_collection_form($form); 
	} else {
		try {
			foreach($user_groups as $gid) {
				$roles = og_get_user_roles('node', $gid);
				foreach($roles as $role) {
					drupal_set_message("For gid $gid, User has a role of $role");
				}
			}
		} catch (Exception $e) {
			try {
				og_ungroup('node', $gid);
			}
			catch (Exception $e) {
				drupal_set_message("We seem to be experiencing a problem. Please open a support ticket, and copy this message in. (Unable to remove invalid group $gid.)");
			}
			_tapascontent_collection_form_check($form);
		} 

	}

}


/**
 * Helper function to alter collection form when no projects.
 */

function _tapascontent_disable_collection_form(&$form) {

		
		$form['field_tapas_description']['#access'] = FALSE;
		$form['field_tapas_thumbnail']['#access'] = FALSE;
		$form['field_tapas_slug']['#access'] = FALSE;
		$form['group_group']['#access'] = FALSE;
		$form['group_access']['#access'] = FALSE;
		$form['og_tapas_c_to_p']['#access'] = FALSE;
		$form['title']['#disabled'] = TRUE;

		unset($form['actions']['submit']);
		unset ($form['preview']);
		unset($form['additional_settings']);
		foreach ($form as $key => $value) {
			if (is_array($form[$key]) && isset($form[$key]['#group'])) {
				unset($form[$key]);
			}
		}
		$form['title']['#prefix'] = 
			"<h2>" . TAPASCONTENT_CREATE_PROJ_FIRST_HEADER . "</h2>" . 
			TAPASCONTENT_CREATE_PROJ_FIRST_TEXT;
}



//=============================================================
// Form Validation
//=============================================================

/**
 * Callback validation function for the Project form.
 */

function _tapascontent_validate_project_form($form, &$form_state) {
  $slug = _get_slug($form, $form_state);

  $query_base = 'SELECT COUNT(*) from field_data_field_tapas_slug WHERE' . 
    ' field_tapas_slug_value = :value AND bundle = :bundle';

  if (isset($form['#node']->nid)) { 
    $query_base .= ' AND entity_id != :nid';
    $count = db_query($query_base, [':value' => $slug, ':bundle' => 'tapas_project', 
      ':nid' => $form['#node']->nid])->fetchField();
  } else {
    $count = db_query($query_base, [':value' => $slug, ':bundle' => 'tapas_project'])
      ->fetchField();
 }

  // Attach an error if other projects are using this slug
  if ($count > 0) { 
    $error = 'You must select a project slug that is not already in use.';
    form_set_error('field_tapas_slug', $error);
  }
}



/**
 * Callback validation function for the Collection form.
 */

function _tapascontent_validate_collection_form($form, &$form_state) {
  //$slug = _get_slug($form, $form_state);
}


//=============================================================
// Helper functions
//=============================================================

/**
 * syntactic sugar to get the slug value.
 */
function _get_slug($form, &$form_state) { 
  return $form_state['values']['field_tapas_slug'][LANGUAGE_NONE][0]['value'];
}

