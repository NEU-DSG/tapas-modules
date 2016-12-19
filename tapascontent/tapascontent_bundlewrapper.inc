<?php

/**
 * @file
 * tapascontent_bundle_wrapper
 *
 */



class Tapascontent_aOgBundleWrapper
{

	private $og_commands;
	private $bundle_name;

	protected function og() { return $this->og_commands; } 
	protected function bundle() { return $this->bundle; }

	protected function __construct(
		$og_commands,
		$bundle_name) 
	{
		$this->og_commands = $og_commands;	
		$this->bundle_name = $bundle_name;
	}

	//TODO: 'attatch' rather than 'add' to avoid confusion with constructing a node.
	public function add_audience_fields($fieldname, $parents=array())
	{
		$audience_field = $this->og()->og_fields_info(OG_AUDIENCE_FIELD);
		$audience_field['field']['settings']['target_type'] = 'node';
		$audience_field['field']['settings']['handler_settings']['target_bundle'] = $parents;
		$this->og()->og_create_field($fieldname, 'node', $this->bundle, $audience_field);
	}


}


class Tapascontent_aOgBundleGroupWrapper
extends Tapascontent_aOgBundleWrapper
{
	private $roles = [];

	// TODO: refactor role stuff out of buildtapas

	const MEMBER_ROLE = 'member';
	const EDITOR_ROLE = 'group_editor';
	const ADMIN_ROLE = 'group_administrator';

	protected function get_role($role_name)
	{
		return $this->roles[$role_name];
	}

	protected function __construct($og_commands)
	{
		parent::__construct($og_commands);

		$this->roles[self::MEMBER_ROLE] = 
			$this->modify_member_role();

		$this->roles[self::EDITOR_ROLE] =
			$this->create_role(self::EDITOR_ROLE);

		$admin_role = $this->create_role(self::ADMIN_ROLE);
		$admin_role->grant_admin();
		$admin_role->grant_edit_own($this->bundle());
		$this->roles[self::ADMIN_ROLE] = $admin_role;
	}	

	private function modify_member_role()
	{
		$og = $this->og();
		$member_rid = $og->get_rid(self::MEMBER_ROLE);
		return $this->wrap_role($member_rid);
	}

	private function create_role($name)
	{
		$og = $this->og();
		$new_rid = $og->create_new_role($name);
		return $this->wrap_role($new_rid);
	}

	private function wrap_role($rid) //TODO
	{
		
	}

	private function update_roles($bundle=[])
	{

	}
}

class Tapascontent_OgProjectGroupWrapper
extends Tapascontent_aOgBundleGroupWrapper
{
	public function __construct($og_commands)
	{
		parent::__construct($og_commands);
	}

	public function update_roles(
		$collection_bundle,
		$record_bundle)
	{
		$admin = $this->get_role[self::ADMIN_ROLE];
		$admin->grant_edit_any($collection_bundle);
		$admin->grant_edit_any($record_bundle);

		$editor = $this->get_role[self::EDITOR_ROLE];
		$editor->grant_edit_any($collection_bundle);
		$editor->grant_edit_any($record_bundle);
	}


}

class Tapascontent_OgCollectionGroupWrapper
extends Tapascontent_aOgBundleGroupWrapper
{
	public function __construct($og_commands, $project_bundle)
	{
		parent::__construct($og_commands);
		$this->add_audience_fields(TAPAS_C_TO_P, array($project_bundle));
	}

	public function update_roles($record_bundle)
	{
		$admin = $this->get_role[self::ADMIN_ROLE];
		$admin->grant_edit_any($record_bundle);

		$editor = $this->get_role[self::EDITOR_ROLE];
		$editor->grant_edit_any($record_bundle);
	}
}

class Tapascontent_OgSharedGroupWrapper
extends Tapascontent_aOgBundleGroupWrapper
{
	public function __construct($og_commands)
	{
		parent::__construct($og_commands);
	}

	public function update_roles($record_bundle)
	{
		$admin = $this->get_role[self::ADMIN_ROLE];
		$admin->grant_edit_any($record_bundle);

		$editor = $this->get_role[self::EDITOR_ROLE];
		$editor->grant_edit_any($record_bundle);
	}
}

class Tapascontent_OgRecordBundleWrapper
extends Tapascontent_aOgBundleWrapper
{
	public function __construct($og_commands, $collection_bundle, $shared_bundle)
	{
		parent::__construct($og_commands);
		$this->add_audience_fields(TAPAS_R_TO_C, array($collection_bundle));
		$this->add_audience_fields(TAPAS_R_TO_S, array($shared_bundle));
	}
}
