<?php 
/**
 * @file
 * tapascontent_forms_inc
 */

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
//	$form['field_tapas_upload_status']['#access'] = FALSE;
}


/**
 * implements hook_form_FORM_ID_form_alter
 * COLLECTION form
 */
function tapascontent_form_tapas_collection_node_form_alter(&$form, &$form_state, $form_id) {

  $form['#validate'][] = '_tapascontent_validate_collection_form';
//	$form['field_tapas_upload_status']['#access'] = FALSE;
	$form['field_tapas_parent_slug']['#access'] = FALSE;
  

	$user_groups = og_get_groups_by_user(user_load( $account=NULL, array('tapas_project')));

	if(empty($user_groups)) {
		//drupal_set_message("You are NOT a member of any projects");
		
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
		$form['title']['#prefix']  = "<h2>Please create a project first, or use the Commons</h2> Creating a Collection requires having a Project to attach it to (either a project that you created, or one to which the owner has given you editing privledges). You don't currently seem to be an editing member of any Projects; please create a project first! Alternately, you can upload TEI directly to the Common Repository without creating any projects or collections.";
	} else {
		//drupal_set_message("You ARE a member of at least one project");
	}
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

