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

define ('TAPAS_READERTAB', 'tapas_tab_reader');
define ('TAPAS_METATAB', 'tapas_tab_meta');

define ('TAPAS_TEI_LABEL', t('TEI'));
define ('TAPAS_TEIBP_LABEL', t('TEI Boilerplate'));
define ('TAPAS_GENERIC_LABEL', t('TAPAS Generic'));
/**
 * Provides render array for record view.
 *
 * @param node The node being rendered.
 */


function tapascontent_view_tei_record($node) {
	$uuid = $node->uuid;
	$node->content[TAPAS_READERTAB][0] = _tapascontent_readertab($uuid);
	$node->content[TAPAS_METATAB][0] = _tapascontent_metatab($uuid);
}

/**
 * @internal. Provides render array for reader tab of records.
 */
function _tapascontent_readertab($uuid) {

	$styledrop = _tapas_readertab_dropdown();
	$tei = tapashydra_get_tei($uuid, 'tei');
	$tapas_generic = tapashydra_get_tei($uuid, 'tapas_generic');
	$teibp = tapashydra_get_tei($uuid, 'teibp');


	$readingtab = array(
		"#type" => "text",
		TAPAS_VFIELD_PREFIX . 'styledrop' => $styledrop,
		TAPAS_VFIELD_PREFIX . 'content' => array(
			'#prefix' => '<div class="reading">',
			'#suffix' => '</div>',
			'#markup' => '<div class="reader_teibp">'.$teibp.'</div><div class="reader_tei"><pre>'.htmlentities($tei).'</pre></div><div class="reader_tapas_generic">'.$tapas_generic.'</div>',
			// '#markup' => '<div class="reader_tei">'.$tei.'</div>',
		),
	);

	return $readingtab;
}

/**
 * @internal. Provides the style drop-down on the rendered tei view.
 */

function _tapas_readertab_dropdown() {

	return array (
			'#name'=>'reading_selector',
			'#type' => 'select',
			'#title' => t('Choose Stylesheet'),
			'#required' => TRUE,
			'#description' => TAPAS_READERTAB_DROPDOWN_DESC,
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
function _tapascontent_metatab($uuid) {
	$mods = tapashydra_get_tei($uuid, 'mods');

	return array(
		'#type' => 'text',
		TAPAS_VFIELD_PREFIX . 'content' => array(
			'#markup' => '<div class="mods">'.$mods.'</div>',
		),
	);
}