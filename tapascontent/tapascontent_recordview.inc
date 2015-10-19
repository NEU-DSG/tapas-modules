<?php

/**
 * @file 
 * tapascontent_recordview.inc
 *
 * Rendering information for the TAPAS_RECORD content type.
 * 
 * @author Linda Moss (GitHub LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

include_once('tapascontent_constants.inc'); // for TAPAS_FILED_PREFIX
define ('TAPAS_VFIELD_PREFIX', 'tapas_vf_');
define ('TAPAS_READERTAB_DROPDOWN_DESC', t('Choose a stylesheet with which you would like to render the TEI.'));
define ('TAPAS_SELECTBUTTON_CALLBACK', '_tapas_selectbutton_callback');
define ('TAPAS_CHOOSE_STYLESHEET_MESSAGE', t('Please pick a stylesheet with which to render the TEI.'));

define ('TAPAS_TABGROUP', 'tapas_reader_tabs');
define ('TAPAS_READERTAB', 'tapas_tab_reader');
define ('TAPAS_METATAB', 'tapas_tab_meta');
define ('TAPAS_FILETAB', 'tapas_tab_files');

define ('TAPAS_READERTAB_TITLE', t('Rendered TEI'));
define ('TAPAS_METATAB_TITLE', t('Metadata'));
define ('TAPAS_FILETAB_TITLE', t('Files'));
/**
 * Provides render array for record view.
 *
 * @param node The node being rendered.
 */

function tapascontent_view_tei_record($node) {

	$node['content'][TAPAS_TABGROUP] = _tapascontent_alltabs();
	$node['content'][TAPAS_READERTAB] = _tapascontent_readertab();
	$node['content'][TAPAS_METATAB] = _tapascontent_metatab();
	$node['content'][TAPAS_FILETAB] - _tapascontent_filetab();
	
	$groupsets = array(
		'description' => TAPAS_METATAB,
		'tei_file' => TAPAS_FILETAB,
		'attatchments' => TAPAS_FILETAB,
		'display_auth' => TAPAS_METATAB,
		'display_contrib' => TAPAS_METATAB,
		'display_date' => TAPAS_METATAB
	);

	foreach ($groupsets as $field => $group) {
		$node['content'][TAPAS_FIELD_PREFIX . $field]['#group'] = $group;
	}

}


/**
 * Provides the render information for the tabset.
 */

function tapascontent_alltabs($node) {

	$tabset = array(
		'#prefix' => '<div class="tapas_tabset">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
	);
}

/**
 * @internal. Provides render array for reader tab of records.
 *
 * @param array $choices: an array with the tei type names.
 * @return array The render array.
 */
function tapascontent_record_readertab($choices, $did) {

	$styledrop = _tapas_stylesheet_dropdown($choices);
	$content = _tapas_readertab_content();
	$go_button = _tapas_readertab_gobutton(TAPAS_SELECTBUTTON_CALLBACK);

	$readingtab = array(
		'#prefix' => '<div class="tapas_readertab">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
		'#title' => TAPAS_READERTAB_TITLE,
		'#collapsible' => TRUE,
		'#group' => TAPAS_TABSET,
		TAPAS_VFIELD_PREFIX . 'styledrop' => $styledrop,
		TAPAS_VFIELD_PREFIX . 'gobutton' => $gobutton,
		TAPAS_VFIELD_PREFIX . 'content' => tapas_readertab_content($did),
	);

	return $readingtab;
}

/** @internal. Provides the style drop-down on the rendered tei view.
*
* @param array An array of valid stylesheet choices.
* @param string The callback function for the 'go' button
*
* @return array A render array for the dropdown.
*/

function _tapas_readertab_dropdown($choices, $callback) {

	return array (
			'#type' => 'select',
			'#title' => t('Choose Stylesheet'),
			'#options' => $choices,
			'#required' => TRUE,
			'#description' => TAPAS_READERTAB_DROPDOWN_DESC,
	);

}

/**
 * @internal. Renter array for the rendered TEI on the reading interface tab.
 */

function _tapas_readertab_content($did, $type=NULL) {

	$msg = TAPAS_CHOOSE_STYLESHEET_MESSAGE;

	$content = $type?tapashydra_get_tei($did, $type):$msg;

	return array(
		'#markdown' => $content,
	);
}

function _tapas_readertab_gobutton($callback) {

}

/**
 * @internal Provides the array for the metadata view tab.
 *
 * @return array The render array for the metadata tab.
 */
function _tapas_metatab() {

	$metatab = array(
		'#prefix' => '<div class="tapas_metatab">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
		'#title' => TAPAS_METADATA_TAB,
		'#collapsible' => TRUE,
		'#group' => TAPAS_TABSET,
	);

	$metatab[TAPAS_VIEW_FIELD . 'rend_meta'] = array(
		'#markup' => '<h2>metadata tab</h2>',
	);

	$metatab[TAPAS_FIELD_PREFIX . 'display_contrib']['#group'] = TAPAS_DTAB;
	$metatab[TAPAS_FIELD_PREFIX . 'display_auth']['#group'] = TAPAS_DTAB;
	$metatab[TAPAS_FIELD_PREFIX . 'display_date']['#group'] = TAPAS_DTAB;
}


/**
 * @internal Provids the array for the fileview tab.
 */

function _tapas_filetab() {


}
