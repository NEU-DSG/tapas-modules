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

define ('TAPAS_TABGROUP', 'tapas_readertabs');
define ('TAPAS_READERTAB', 'tapas_tab_reader');
define ('TAPAS_METATAB', 'tapas_tab_meta');
define ('TAPAS_FILETAB', 'tapas_tab_files');

define ('TAPAS_READERTAB_TITLE', t('Rendered TEI'));
define ('TAPAS_METATAB_TITLE', t('Metadata'));
define ('TAPAS_FILETAB_TITLE', t('Files'));

define ('TAPAS_TEI_LABEL', t('TEI'));
define ('TAPAS_TEIBP_LABEL', t('TEI Boilerplate'));
define ('TAPAS_GENERIC_LABEL', t('TAPAS Generic'));
/**
 * Provides render array for record view.
 *
 * @param node The node being rendered.
 */

function tapascontent_view_tei_record($node) {

	$node['content'][TAPAS_TABGROUP] = array(
		'#prefix' => '<div class="tapas_tabset">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
	);

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
 * @internal. Provides render array for reader tab of records.
 *
 * @param array $choices: an array with the tei type names.
 * @return array The render array.
 */
function tapascontent_record_readertab($choices, $did) {

	$styledrop = _tapas_stylesheet_dropdown($choices);

	$readingtab = array(
		'#prefix' => '<div class="tapas_readertab">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
		'#title' => TAPAS_READERTAB_TITLE,
		'#collapsible' => TRUE,
		'#group' => TAPAS_TABGROUP,
		TAPAS_VFIELD_PREFIX . 'styledrop' => $styledrop,
		TAPAS_VFIELD_PREFIX . 'content' => array(
			'#prefix' => '<div class="tapas_readercontent">',
			'#suffix' => '</div>'
		),
	);

	return $readingtab;
}

/** 
 * @internal. Provides the style drop-down on the rendered tei view.
 */

function _tapas_readertab_dropdown() {

	return array (
			'#type' => 'select',
			'#title' => t('Choose Stylesheet'),
			'#required' => TRUE,
			'#description' => TAPAS_READERTAB_DROPDOWN_DESC,
			'#group' => TAPAS_READERTAB,
			'#options' => array(
				'teibp' => TAPAS_TEIBP_LABEL,
				'tei' => TAPAS_TEI_LABEL,
				'tapas_generic' => TAPAS_GENERIC_LABEL,
			),
	);

}

/**
 * @internal Provides the array for the metadata view tab.
 *
 * @return array The render array for the metadata tab.
 */
function _tapas_metatab() {

	return array(
		'#prefix' => '<div class="tapas_metatab">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
		'#title' => TAPAS_METATAB_TITLE,
		'#group' => TAPAS_TABGROUP,
		TAPAS_VFIELD_PREFIX . 'mods' => array(
			'#markup' => 'MODS will go here.'
		),
			
	);
}


/**
 * @internal Provids the array for the fileview tab.
 */

function _tapas_filetab() {

	return array(
		'#prefix' => '<div class="tapas_filetab">',
		'#suffix' => '</div>',
		'#type' => 'fieldset',
		'#title' => TAPAS_FILETAB_TITLE,
		'#group' => TAPAS_TABGROUP,
	);

}
