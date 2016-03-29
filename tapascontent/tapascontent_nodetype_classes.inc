<?php
/**
 * @file
 * tapascontent_nodetype_classes
 *
 * Class definitions for TAPAS content/node types.
 */


/**
 * @class TapasContent_OgRole
 *
 * Provides object to grant and revoke OG permissions.
 */


class TapasContent_OgRole {
	private $role_group;
	private $role_name;
	private $rid;

	const MEMBER_ROLE = 'member'; // must match og module builtin.

	/**
	 * Constructor
	 *
	 * If $name is left null, an object will be created
	 * around the built-in 'member' role for the specified
	 * group. Otherwise, a roll named $name will be created,
	 * and the object will be created around that.
	 */
	public function __construct($group, $name=NULL) {

		$this->role_group = $group;

		if ($name) {
			drupal_set_message("Creating new role called $name for $group");
			$role = og_role_create($name, 'node', NULL, $group);
			og_role_save($role);
			$this->role_name = $name;
			$this->rid =  $role->rid;
			drupal_set_message("Role $this->rid Created.");
		} else {
			drupal_set_message("Editing built-in " . self::MEMBER_ROLE . " role for group $group");
			$all_roles = og_roles('node', $group);
			$this->rid = array_search(self::MEMBER_ROLE, $all_roles);
			$this->role_name = self::MEMBER_ROLE;
		}
	}

	public function edit_own($bundle) {
		og_role_grant_permissions($this->rid, $this::_edit_own_array($bundle));
		og_role_save(og_role_load($this->rid));
	}

	public function edit_any($bundle) {
		drupal_set_message("Granting role $this->rid permission to edit any $bundle");
		og_role_grant_permissions($this->rid, $this::_edit_any_array($bundle));
		drupal_set_message("Saving updated role.");
		og_role_save(og_role_load($this->rid));
		drupal_set_message("Role save complete.");
	}

	public function edit_admin() {
		og_role_grant_permissions($this->rid, $this::_edit_admin_array());
		og_role_save(og_role_load($this->rid));
	}
	
	public function _edit_any_array($bundle) {
		return array(
			"create $bundle content",
			"edit own $bundle content",
			"edit any $bundle content",
			"delete own $bundle content",
			"delete any $bundle content",
		);
	}

	public function _edit_own_array($bundle) {
		return  array(
			"create $bundle content",
			"edit own $bundle content",
			"delete own $bundle content");

	}

	public function _edit_admin_array() {
		return array(
			'add user',
			'administer group',
			'approve and deny subscription',
			'manage memners',
			'update_group',
		);
	}
}

class TapasContent_OgBundle {

	private $roles = array();
	private $bundle;
	private $audience = array();
	
	public function __construct($bundle) {
		$this->bundle = $bundle;
	}

	public function create_role($name) {
		drupal_set_message("Object for $this->bundle object recieved request to create $name role.");
		$this->roles[$name] = new TapasContent_OgRole($this->bundle, $name);		
		return $this->roles[$name];
	}

	public function get_role($role_name = NULL) {
		return $this->roles[$role_name?$role_name:TapasContent_OgRole::MEMBER_ROLE];
	}

	public function make_group() {
		og_create_field(OG_GROUP_FIELD, 'node', $this->bundle);
		og_create_field(OG_DEFAULT_ACCESS_FIELD, 'node', $this->bundle);

		$member_role = TapasContent_OgRole::MEMBER_ROLE;
		$this->roles[$member_role] = new TapasContent_OgRole($this->bundle);

	}

	public function give_audience($group, $audience_fieldname) {
		$audience_field = og_fields_info(OG_AUDIENCE_FIELD);
		$audience_field['field']['settings']['target_type'] = 'node';
		$audience_field['field']['settings']['handler_settings']['target_bundle'] = array($group);
		og_create_field($audience_fieldname, 'node', $group, $audience_field);
		$this->audience[$group] = $audience_field;
	}

}
