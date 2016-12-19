<?php

$input_folder = $argv[0];
$collection = $argv[1];
$uid = $argv[2];
$file_list = scandir($input_folder);
$form_id = 'tapas_record_node_form';

foreach ($file_list as $xml_file) 
{
	
	$form_state = array();
	$form_state['redirect'] = FALSE;
	$form_state['values'] = get_form_values();
	

	$new_record = new stdClass;
	$stdClass->type = 'tapas_record';
	node_object_prepare($new_record);


}

function get_form_values()
{
	$form_values = array();
	return $form_values;
}
