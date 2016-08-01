<?php

/**
 * @file
 * tapascontent_recordview.inc
 *
 * Rendering information for the TAPAS_RECORD content type.
 *
 * @author Linda Moss (GitHub LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.1
 */

include_once('tapascontent_constants.inc'); // for TAPAS_FILED_PREFIX
define ('TAPAS_VFIELD_PREFIX', 'tapas_vf_');
define ('TAPAS_READERTAB_DROPDOWN_DESC', t('Choose a stylesheet with which you would like to render the TEI.'));
define ('TAPAS_SELECTBUTTON_CALLBACK', '_tapas_selectbutton_callback');
define ('TAPAS_CHOOSE_STYLESHEET_MESSAGE', t('Please pick a stylesheet with which to render the TEI.'));

define ('TAPAS_READERTAB', 'tapas_tab_reader');
define ('TAPAS_METATAB', 'tapas_tab_meta');

define ('TAPAS_TEI_LABEL', t('XML View'));
define ('TAPAS_TEIBP_LABEL', t('TEI Boilerplate'));
define ('TAPAS_GENERIC_LABEL', t('TAPAS Generic'));
/**
 * Provides render array for record view.
 *
 * @param node The node being rendered.
 */


function tapascontent_view_tei_record($node) {
	$theme_path = drupal_get_path('theme', variable_get('theme_default', NULL));
	drupal_add_js($theme_path.'/assets/js/record.js', array('type'=>'file', 'requires_jquery'=>true));
	drupal_add_js($theme_path.'/assets/js/ace.js', array('type'=>'file', 'requires_jquery'=>true));
	drupal_add_library('system','ui.dialog');
	drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/teibp/js/teibp.js', array('type'=>'file'));
	if (isset($node->field_tapas_record_ography_type['und'][0]['value'])){
		$ography = true;
	} else {
		$ography = false;
		drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/jquery/plugins/jquery.blockUI.js', array('type'=>'file'));
		drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/contextualItems.js', array('type'=>'file'));
		drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/tapas-generic.js', array('type'=>'file'));
	}
	$uuid = $node->uuid;
	$node->content[TAPAS_READERTAB][0] = _tapascontent_readertab($uuid, $ography);
	$node->content[TAPAS_METATAB][0] = _tapascontent_metatab($uuid);
}

/**
 * @internal. Provides render array for reader tab of records.
 */
function _tapascontent_readertab($uuid, $ography) {

	$styledrop = _tapas_readertab_dropdown($ography);
	$tei = tapashydra_get_tei($uuid, 'tei');
	$xml_helper_fields = "<div class='row'><div class='checkbox'><label for='toggle_word_wrap'><input type='checkbox' id='toggle_word_wrap' name='toggle_word_wrap'/>Toggle Soft Wrap</label></div><div class='checkbox'><label for='toggle_invisibles'><input type='checkbox' id='toggle_invisibles' name='toggle_invisibles'/>Toggle Invisibles</label></div></div>";
	$tapas_generic = tapashydra_get_tei($uuid, 'tapas_generic');
	$teibp = tapashydra_get_tei($uuid, 'teibp');
	$markup = '<div class="reader_teibp">'.$teibp.'</div><div class="reader_tei">'.$xml_helper_fields.'<pre>'.htmlentities($tei).'</pre></div>';
	if (!$ography){
		$markup .= '<div class="reader_tapas_generic">'.$tapas_generic.'</div>';
	}

	$readingtab = array(
		"#type" => "text",
		TAPAS_VFIELD_PREFIX . 'styledrop' => $styledrop,
		TAPAS_VFIELD_PREFIX . 'content' => array(
			'#prefix' => '<div class="reading">',
			'#suffix' => '</div>',
			'#markup' => $markup,
		),
	);

	return $readingtab;
}

/**
 * @internal. Provides the style drop-down on the rendered tei view.
 */

function _tapas_readertab_dropdown($ography) {
	$options = array();
	if (!$ography){
		$options['tapas_generic'] = TAPAS_GENERIC_LABEL;
	}
	$options['teibp'] = TAPAS_TEIBP_LABEL;
	$options['tei'] = TAPAS_TEI_LABEL;


	return array (
			'#name'=>'reading_selector',
			'#type' => 'select',
			'#title' => t('Choose Stylesheet'),
			'#description' => TAPAS_READERTAB_DROPDOWN_DESC,
			'#options' => $options,
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
