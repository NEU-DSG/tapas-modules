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
	//TODO - pass the node default view and the collection preferred view to the reader tab?
	$uuid = $node->uuid;
	$node->content[TAPAS_READERTAB][0] = _tapascontent_readertab($uuid);
	$node->content[TAPAS_METATAB][0] = _tapascontent_metatab($uuid);
}

/**
 * @internal. Provides render array for reader tab of records.
 */
function _tapascontent_readertab($uuid) {
	$url = TAPAS_BASE_API_URL . "/api/view_packages";
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'GET');
	$response = _tapashydra_curlcall($url, $curl_options, true);
	$view_markup = array();
	// TODO reach out here to the API for view_packages rails_api.localhost:8080/api/view_packages to get back JSON of all of the available view packages then loop through to do tapashydra_get_tei for each one, also do drupal_add_js based on the js files which are included in the json, and add the css as data params in the html so it can be picked up by the record.js file
	if ($response[1] == 200){
		$view_packages = json_decode($response[0]);

		foreach($view_packages as $view){
			// dpm($view->machine_name);
			$view_html = tapashydra_get_tei($uuid, $view->machine_name);
			$view_markup[] = '<div class="reader_'.$view->machine_name.'">'.$view_html.'</div>';
			//TODO enqueue the right js here based on thew $view->js_dir
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/teibp/js/teibp.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/jquery/plugins/jquery.blockUI.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/contextualItems.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/tapas-generic.js', array('type'=>'file'));
			// TODO add the right css here based on the $view->css_dir to data attributes in the markup so they can be processed by the record.js file
		}
	} else {
		$view_packages = NULL;
	}

	$styledrop = _tapas_readertab_dropdown($view_packages);
	$tei = tapashydra_get_tei($uuid, 'tei');
	$xml_helper_fields = "<div class='row'><div class='checkbox'><label for='toggle_word_wrap'><input type='checkbox' id='toggle_word_wrap' name='toggle_word_wrap'/>Toggle Soft Wrap</label></div><div class='checkbox'><label for='toggle_invisibles'><input type='checkbox' id='toggle_invisibles' name='toggle_invisibles'/>Toggle Invisibles</label></div></div>";
	$markup = '<div class="reader_tei">'.$xml_helper_fields.'<pre>'.htmlentities($tei).'</pre></div>';
	foreach($view_markup as $this_markup){
		$markup .= $this_markup;
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

function _tapas_readertab_dropdown($view_packages) {
	$options = array();
	//TODO will need to determine order based on preferred collection and default record views
	foreach($view_packages as $view){
		$options[$view->machine_name] = $view->human_name;
	}
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
