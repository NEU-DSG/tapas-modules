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
	$uuid = $node->uuid;
	$default_view = "tapas_generic";
	if (isset($node->field_tapas_default_view['und'][0]['value'])){ //node default view set
		$default_view = $node->field_tapas_default_view['und'][0]['value'];
	} elseif (isset($node->og_tapas_r_to_c['und'][0]['target_id'])){ //no node default view but collection is set
		$collection = $node->og_tapas_r_to_c['und'][0]['target_id'];
		$collection = node_load($collection);
		if (isset($collection->field_tapas_preferred_view['und'][0]['value'])){ // collection preferred view is set
			$default_view = $collection->field_tapas_preferred_view['und'][0]['value'];
		}
	}
	$node->content[TAPAS_READERTAB][0] = _tapascontent_readertab($uuid, $default_view);
	$node->content[TAPAS_METATAB][0] = _tapascontent_metatab($uuid);
}

/**
 * @internal. Provides render array for reader tab of records.
 */
function _tapascontent_readertab($uuid, $default_view) {
	$view_packages = _tapascontent_get_view_packages();
	$view_markup = array();
	if ($view_packages != NULL){
		foreach($view_packages as $view){
			$view_html = tapashydra_get_tei($uuid, $view->machine_name);
			$view_markup[] = '<div class="reader_'.$view->machine_name.'">'.$view_html.'</div>';
			//TODO enqueue the right js here based on thew $view->js_dir
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/teibp/js/teibp.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/jquery/plugins/jquery.blockUI.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/contextualItems.js', array('type'=>'file'));
			drupal_add_js('/profiles/buildtapas/themes/tapas-themes/tapas_redesign/lib/tapas-generic/js/tapas-generic.js', array('type'=>'file'));
			// TODO add the right css here based on the $view->css_dir to data attributes in the markup so they can be processed by the record.js file
		}
	}

	$styledrop = _tapas_readertab_dropdown($view_packages, $default_view);
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

/* @internal. provides the available view packages from teh RAILS API
*
*/
function _tapascontent_get_view_packages(){
	$url = TAPAS_BASE_API_URL . "/api/view_packages";
	$curl_options = array(CURLOPT_CUSTOMREQUEST => 'GET');
	$response = _tapashydra_curlcall($url, $curl_options, true);
	if ($response[1] == 200){
		return json_decode($response[0]);
	} else {
		return NULL;
	}
}

/**
 * @internal. Provides the style drop-down on the rendered tei view.
 */

function _tapas_readertab_dropdown($view_packages, $default_view) {
	$options = array();
	$options[$default_view] = "Default";
	foreach($view_packages as $view){
		if ($view->machine_name == $default_view){
			$options[$view->machine_name] = $view->human_name . " (Default view)";
		} else {
			$options[$view->machine_name] = $view->human_name;
		}
	}
	$options['tei'] = TAPAS_TEI_LABEL;
	if ($options[$default_view] == "Default"){
		//it wasn't in the list of view packages so it must not be valid anymore, lets remove it from the options;
		unset($options[$default_view]);
	}

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
