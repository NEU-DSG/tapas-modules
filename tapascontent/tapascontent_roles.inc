<?php


//=====================================================================
// Interfaces 
//=====================================================================


interface Tapascontent_iRoleWrapper
{
	function __construct($rid);
	function grant_edit_own($bundle_list=[]);
	function grant_edit_any($bundle_list=[]);
	function revoke_edit_own($bundle_list=[]);
	function revoke_edit_any($bundle_list=[]);
	function rid();
	function find_rid($role_name);
}

interface Tapascontent_iOgRoleWrapper
extends Tapascontent_iRoleWrapper
{
	function grant_admin();
	function revoke_admin();
}


// ==============================================================
// NEW Abstract parent class
// ==============================================================

abstract class Tapascontent_aRoleWrapper
implements Tapascontent_iRoleWrapper
{
	private $rid;

	public function rid() { return $this->rid; }

	// Why, oh why, doesn't PHP offer proper polymorphism, neccessitating
	// hacks like $is_rid=TRUE below? A proper strongly-typed language would
	// allow me to define two constructors -- one accepting a string, the other
	// accepting an int -- and it would know which to run based on the data
	// type passed in.
	protected function __construct($rid_or_name, $is_rid=TRUE)
	{

	}

	protected abstract function grant($permission_list);
	protected abstract function revoke($permission_list);
	protected abstract function get_all_roles();

	public function grant_edit_own($bundle_list=[])
	{
		$this->grant($this->edit_own($bundle_list));
	}

	public function grant_edit_any($bundle_list=[])
	{
		$this->grant(
			$this->edit_own($bundle_list) +
			$this->edit_any($bundle_list)
		);
	}

	public function revoke_edit_own($bundle_list=[])
	{
		$this->revoke(
			$this->edit_any($bundle_list) +
			$this->edit_own($bundle_list)
		);
	}

	public function revoke_edit_any($bundle_list=[])
	{
		$this->revoke($this->edit_any($bundle_list));
	}

	protected function edit_own($bundle_list=[])
	{
		$array = [];
		foreach($bundle_list as $bundle)
		{
			$array += [
				"create $bundle content",
				"edit own $bundle content",
				"delete own $bundle content"];
		}
		return $array;
	}

	protected function edit_any($bundle_list=[])
	{
		{
			$array += [
				"edit any $bundle content",
				"delete any $bundle content"];
		}
		return $array;
	}

	public function find_rid($role_name)
	{
		$all_roles = $this->get_all_roles();
		$rid = array_search($role_name, $all_roles);
		return $rid;
	}

}

// ==============================================================
// NEW Sitewide Roles
// ==============================================================

class Tapascontent_SitewideRoleWrapper
extends Tapascontent_aRoleWrapper
{
	protected function grant($permission_list)
	{
		user_role_grant_permissions($this->rid(), $permission_list);
	}

	protected function revoke($permission_list)
	{
		user_role_revoke_permissions($this->rid(), $permission_list);
	}

	protected function get_all_roles()
	{
		return user_roles();
	}

}

class Tapascontent_MockSitewideRoleWrapper
extends Tapascontent_aRoleWrapper
{
	protected function grant($permission_list)
	{
		//TODO
	}

	protected function revoke($permission_list)
	{
		//TODO
	}

	public function get_all_roles()
	{
		//TODO
	}

}

// ==============================================================
// NEW Organic Group Roles
// ==============================================================


abstract class Tapascontent_aOgRoleWrapper
extends Tapascontent_aRoleWrapper
implements Tapascontent_iOgRoleWrapper
{
	private $bundle;


	public function __construct($rid, $bundle)
	{
		parent::__construct($rid);
		$this->bundle = $bundle;
	}

	protected function admin_perms()
	{
		return array(
			'add user',
			'administer group',
			'approve and deny subscription',
			'manage memners',
			'update_group',
		);
	}

	public function grant_admin()
	{
		$this->grant($this->admin_perms());
	}

	public function revoke_admin()
	{
		$this->revoke($this->admin_perms());
	}
}

class Tapascontent_OgRoleWrapper
extends Tapascontent_aOgRoleWrapper
{
	protected function create($rid=NULL)
	{
		if (!$rid) { 
			$rid = og_role_save(og_create_role);
		}
		parent::__construct($rid);

	}

	protected function grant($permission_list)
	{
		og_role_grant_permissions($this->rid(), $permission_list);
	}

	protected function revoke($permission_list)
	{
		og_role_revoke_permissions($this->rid(), $permission_list);
	}

	protected function get_all_roles()
	{
		return og_roles('node', $this->bundle);
	}
}



class Tapascontent_MockOgRoleWrapper
extends Tapascontent_aOgRoleWrapper
{
	protected function grant($permission_list)
	{

	}

	protected function revoke($permission_list)
	{

	}

	public function find_rid($role_name)
	{

	}
}







//=====================================================================
// Abstract parent class
//=====================================================================


abstract class Tapascontent_aRoleWrapper
implements Tapascontent_iRoleWrapper
{

	private $rid;

	protected abstract function grant($perms=[]);
	protected abstract function revoke($perms=[]);
	public abstract function find_rid($role_name);

	//if only PHP had proper poymorphism...
	protected function __construct($rid_or_name, $is_rid=TRUE) 
		{
			if($is_rid) { $rid = $rid_or_name; }
			else { $rid  = $this->find_rid($role_name); }

			$this->rid = $rid;
		}
	
	public function rid() {return $this->rid;}

	public function grant_edit_own($bundle_list=[])
	{ $this->grant($this->_edit_own_perms($bundle_list)); }

	public function grant_edit_any($bundle_list=[])
	{ $this->grant($this->_edit_any_perms($bundle_list));}

	public function revoke_edit_own($bundle_list=[])
	{ $this->revoke($this->_edit_own_perms($bundle_list)); }

	public function revoke_edit_any($bundle_list=[])
	{ $this->revoke($this->_edit_any_perms($bundle_list)); }


	protected function _edit_own_perms($bundle_list=[])
	{
		$array = [];
		foreach($bundle_list as $bundle)
		{
			$array += [
				"create $bundle content",
				"edit own $bundle content",
				"delete own $bundle content"];
		}
		return $array;
	}

	protected function _edit_any_perms($bundle_list=[])
	{
		$array = $this->_edit_own_perms($bundle_list);
		foreach($bundle_list as $bundle) 
		{
			$array += [
				"edit any $bundle content",
				"delete any $bundle content"];
		}
		return $array;
	}
}
// ==============================================================
// Organic Groups Role Concrete Clases
// ==============================================================
class Tapascontent_OgRoleWrapper
extends Tapascontent_aRoleWrapper
implements Tapascontent_iOgRoleWrapper
{
	private $bundle;

	public function __construct($rid, $bundle)
	{
		parent::__construct($rid);
		$this->bundle = $bundle;
	}

	public function grant_admin()
	{ $this->grant($this->rid(), $this->_admin_perms()); }

	public function revoke_admin()
	{ $this->revoke($this->rid(), $this->_admin_perms());}

	private function _admin_perms()
	{
		return array(
			'add user',
			'administer group',
			'approve and deny subscription',
			'manage memners',
			'update_group',
		);
	}

	public function find_rid($role_name)
	{
			$all_roles = og_roles('node', $this->bundle);
			$rid = array_search($role_name, $all_roles);
			return $rid;
	}

	public function grant($rid, $perms=[])
	{
		og_role_grant_permissions($rid, $perms=[]);
		og_role_save($role);
	}

	public function revoke($rid, $perms)
	{
		og_role_revoke_permissions($rid, $perms);
		og_role_save($role);
	}

}

//=====================================================================
// TODO: Orphaned Connector Commands
//=====================================================================

class Tapasconetnt_OGRoleConnector
implements Tapascontent_iOgRoleConnector
{

	public function add_audience_fields($fieldname, $parent_bundle) {
		$audience_field = og_fields_info(OG_AUDIENCE_FIELD);
		$audience_field['field']['settings']['target_type'] = 'node';
		$audience_field['field']['settings']['handler_settings']['target_bundle'] = array($parent_bundle);
		og_create_field($fieldname, 'node', $this->bundle, $audience_field);
	}

	public function create_new_role($name) {
			$role = og_role_create($name, 'node', NULL, $this->bundle);
			return og_role_save($role);
	}
}
// ==============================================================
// RoleFactory
// ==============================================================

interface Tapascontent_iRoleFactory
{
	function create_sitewide_role();
	function create_og_role($role_name, $bundle);
	function wrap_sitewide_role($rid_or_name, $is_rid=TRUE);
	function wrap_og_role($rid);
}

abstract class Tapascontent_aRoleFactory
implements Tapascontent_iRoleFactory
{
	public function create_og_role($role_name, $bundle)
	{
		$rid = $this->_og_create($role_name, $bundle);
		$this->wrap_og_role($rid);
	}

	public function create_sitewide_role()
	{

	}

}

class Tapascontent_RoleFactory
extends Tapascontent_aRoleFactory
{
	public function _og_create($role_name, $bundle)
	{
		$role = og_create_role($role_name, 'node', 0, $bundle);
		$rid = og_role_save($role);
		return $rid;
	}

	public function wrap_og_role($rid)
	{
		return new Tapasconent_OgRoleWrapper($rid);
	}

}


class Tapascontent_MockRoleFactory
extends Tapascontent_aRoleFactory
{

	public function create_og_role($role_name, $bundle)
	{
		// (TODO): creating the role
		$this->wrap_og_role($rid);
	}

	public function wrap_og_role($rid)
	{
		return new Tapasconent_OgRoleWrapper($rid);
	}


}


