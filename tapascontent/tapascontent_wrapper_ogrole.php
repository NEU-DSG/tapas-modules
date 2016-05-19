<?php

/*
 * @class TapasContent_OgRole
 *
 * Provides object to grant and revoke OG permissions.
 */

class Tapascontent_OgRole {
	private $role_group;
	private $role_name;
	private $rid;
	private $ogh;

	const MEMBER_ROLE = 'member'; // must match og module builtin.

	/**
	 * Constructor
	 *
	 * If $name is left null, an object will be created
	 * around the built-in 'member' role for the specified
	 * group. Otherwise, a roll named $name will be created,
	 * and the object will be created around that.
	 */
	public function __construct($group, $ogHandler=NULL, $name=NULL) {

		if (!$ogHandler) {
			$ogHandler = new Tapascontent_OgProductionHandler();
		}

		$this->ogh = $ogHandler;
		$this->role_group = $group;

		if ($name) {
			$ogHandler->create_new_role($name, $group);
			$this->role_name = $name;
			$this->rid =  $role->rid;
		} else {
			$this->rid = $ogHandler->get_existing_rid(self::MEMBER_ROLE, $group);
			$this->role_name = self::MEMBER_ROLE;
		}
	}


	public function edit_own($bundle) {
		$ogf = $this->ogh;
		$ogf->grant_permissions($this->rid, $this::_edit_own_array($bundle));
	}

	public function edit_any($bundle) {
		$ogf = $this->ogh;
		$ogf->grant_permissions($this->rid, $this::_edit_any_array($bundle));
	}

	public function edit_admin() {
		$ogf = $this->ogh;
		$ogf->grant_permissions($this->rid, $this::_edit_admin_array());
	}
	
	private function _edit_any_array($bundle) {
		return array(
			"create $bundle content",
			"edit own $bundle content",
			"edit any $bundle content",
			"delete own $bundle content",
			"delete any $bundle content",
		);
	}

	private function _edit_own_array($bundle) {
		return  array(
			"create $bundle content",
			"edit own $bundle content",
			"delete own $bundle content");

	}

	private function _edit_admin_array() {
		return array(
			'add user',
			'administer group',
			'approve and deny subscription',
			'manage memners',
			'update_group',
		);
	}
}

/**
 * @class Tapascontent_OgBundle
 */

class Tapascontent_OgBundle {

	private $roles = array();
	private $bundle;
	private $audience = array();
	private $ogh;
	
	public function __construct($bundle, $ogHandler) {
		$this->bundle = $bundle;
		$this->ogh = $ogHandler;
	}

	public function create_role($name) {
		$role = new Tapascontent_OgRole($this->bundle, $name, $this->ogh);
		$this->roles[$name] = $role;
		return $role;
	}

	public function get_role($role_name = NULL) {
		return $this->roles[$role_name?$role_name:Tapascontent_OgRole::MEMBER_ROLE];
	}

	public function make_group() {
		$ogf = $this->ogf;
		$ogf->add_group_fields($this->bundle);


		$member_role = Tapascontent_OgRole::MEMBER_ROLE;
		$this->roles[$member_role] = new Tapascontent_OgRole($this->bundle);

	}

	public function give_audience($group, $audience_fieldname) {
		$ogf = $this->ogf;
		$ogf->add_audience_fields($audience_fieldname, $this->bundle, $group);
	}


}

/**
 * @class Tapascontent_OgHandler
 * abstracts the calls to OG, so that we can swap in mock calls for unittesting.
 */

abstract class Tapascontent_OgHandler {
	public abstract function add_group_fields($bundle);
	public abstract function add_audience_fields($fieldname, $bundle, $group);
	public abstract function create_new_role($name, $group);
	public abstract function get_existing_rid($name, $group);
	public abstract function grant_permissions($rid, $permissions);
}


class Tapascontent_OgProductionHandler extends Tapascontent_OgHandler{


	public function add_group_fields($bundle) {
		og_create_field(OG_GROUP_FIELD, $bundle);
		og_create_field(OG_DEFAULT_ACCESS_FIELD, $bundle);
	}

	public function add_audience_fields($fieldname, $bundle, $group) {
		$audience_field = og_fields_info(OG_AUDIENCE_FIELD);
		$audience_field['field']['settings']['target_type'] = 'node';
		$audience_field['field']['settings']['handler_settings']['target_bundle'] = array($group);
		og_create_field($fieldname, 'node', $bundle, $audience_field);
	}

	public function create_new_role($name, $group) {
			$role = og_role_create($name, 'node', NULL, $group);
			return og_role_save($role);
	}


	public function get_existing_rid($rolename, $group) {
			$all_roles = og_roles('node', $group);
			$rid = array_search($rolename, $all_roles);
			return $rid;
	}

	public function grant_permissions($rid, $perms) {
		og_role_grant_permissions($rid, $perms);
		og_role_save(og_role_load($rid));
	}

}

class Tapascontent_OgMockHandler extends Tapascontent_OgHandler {

	public function add_group_fields($bundle) {}
	public function add_audience_fields($fieldname, $bundle, $group) {}
	public function create_new_role($name, $group) {}
	public function get_existing_rid($name, $group) {}
	public function grant_permissions($rid, $permissions) {}
}
