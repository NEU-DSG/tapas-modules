<?php

/**
 * @file
 * tapascontent_wrapper_bundle.inc
 */

interface Tapascontent_iBundleWrapper {
	function __construct($bundle, $drupal_connector=NULL);
	function add_field($field_name, $field_data);
	function create_role();
	function get_role();
	function make_group();
	function give_audiencec($group_bundle);

}


class Tapascontent_BundleWrapper {

	private $bundle;
	private $drupal_connector;
	private $roles = [];

	public function __construct($bundle, $drupal_connector=NULL) {
		
		$this->bundle = $bundle;

		if ($drupal_connector) {
			$this->drupal_connector = $drupal_connector;
		} else {
			$this->drupal_connector = new Tapascontent_ProductionDrupalConnector();	
		}

	}

	public function create_role($name) {
		$role = new Tapascontent_OgRole($this->bundle, $name, $this->drupal_connector);
		$this->roles[$name] = $role;
		return $role;
	}

	public function get_role($role_name = NULL) {
		return $this->roles[$role_name?$role_name:Tapascontent_OgRole::MEMBER_ROLE];
	}

	public function make_group() {
		$this->drupal_connector->add_group_fields($this->bundle);
		$member_role = Tapascontent_OgRole::MEMBER_ROLE;
		$this->roles[$member_role] = new Tapascontent_OgRole($this->bundle);
	}

	public function give_audience($group, $fieldname) {
		$this->drupal_connector($fieldname, $this->bundle, $group);
	}

	public function attatch_field($fieldinfo) {

	}

}


