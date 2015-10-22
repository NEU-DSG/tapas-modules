<?php 

function tapascontent_form_tapas_collection_node_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = '_tapascontent_validate_collection_form';
}

function tapascontent_form_tapas_project_node_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = '_tapascontent_validate_project_form';
}

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

function _tapascontent_validate_collection_form($form, &$form_state) {
  $slug = _get_slug($form, $form_state);
}

function _get_slug($form, &$form_state) { 
  return $form_state['values']['field_tapas_slug'][LANGUAGE_NONE][0]['value'];
}
