<?php


//=====================================================================
// Role Wrapper
//=====================================================================

interface Tapascontent_iRoleWrapper
{
	function __construct($rid);
	function grant_edit_own($bundle_list=[]);
	function grant_edit_any($bundle_list=[]);
	function revoke_edit_own($bundle_list=[]);
	function revoke_edit_any($bundle_list=[]);
	function rid();
}

interface Tapascontent_iOgRoleWrapper
extends Tapascontent_iRoleWrapper
{
	function grant_admin();
	function revoke_admin();
}

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
				"create $bunle content",
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

class Tapascontent_MockRoleWrapper
extends Tapascontent_aRoleWrapper
{
	public function find_rid($role_name) { assert(FALSE); } // TODO
	protected function grant($perms=[]) { assert(FALSE); } // TODO
	protected function revoke($perms=[]) { assert(FALSE); } // TODO
}

class Tapascontent_SitewideRoleWrapper
extends Tapascontent_aRoleWrapper
{
	protected function grant($perms=[])
	{ user_role_grant_permissions($this->rid(), $perms); }

	protected function revoke($perms=[])
	{ user_role_revoke_permissions($this->rid(), $perms); }

	public function find_rid($role_name)
	{ return array_search($name, user_roles());}
}

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

class Tapascontent_MockOgRoleWrapper
extends Tapascontent_MockRoleWrapper
implements Tapascontent_iOgRoleWrapper
{
	public function grant_admin() {assert(FALSE);} // TODO
	public function revoke_admin() {assert(FALSE);} // TODO
}


//=====================================================================
// Repository Wrapper
//=====================================================================

//define ('TAPASHYDRA_AUTH_TOKEN', (variable_get('tapas_rails_api_key', 'tapas12345')));
interface Tapascontent_iRepoWrapper
{
	function send_query($query_struct);
	function get_base_url();
}

abstract class Tapascontent_aHydraConnector
implements Tapascontent_iRepoWrapper
{
	protected abstract function get_token();
	protected abstract function get_base_url();
	protected abstract function make_call($url, $curl_query);

	protected function get_header()
	{
		return ['Authorization: Token token=' . $this->get_token()];
	}

	public function send_query($query_struct)
	{
		$header = $this->get_header();
		$curl_query = $header + $query_struct->options;

		$curl_query[CURLOPT_URL] = $query_struct->get_url($this->get_base_url());

		if ($query_struct->postfields)
		{
			$postfields = $this->httpize_subarrays($query_struct->postfields);
			$curl_query[CURLOPT_POST_FIELDS] = $query_struct->postfields;
		} else {
			unset($curl_query[CURLOPT_POST_FIELDS]);
		}

		
		$result = $this->curl_call($curl_query[CURLOPT_URL], $curl_query);
		return $this->translate_result($result);
	}

	private function translate_result($result)
	{
		assert(FALSE); //TODO
	}

	private function httpize_subarrays($array)
	{
		foreach($data as $key => $value) {
			if (is_array($value)) {
				$data += $self::transform_array($key, $value);
				unset($data[$key]);
			}
		}
	}

	private function httpize_array($name, $array) {

		$data = array();
		foreach($array as $key => $value) {
			$data[$name.'['.$key.']'] = $value;
		}
		return $data;
	}
}

class Tapascontent_HydraConnector
extends Tapascontent_aHydraConnector
{
	public function get_base_url()
	{ return variable_get('tapas_rails_api_url', 'http://rails_api.localhost:8080'); }

	public function get_token()
	{ return variable_get('tapas_rails_api_key', 'tapas12345'); }

	public function curl_call($url, $curl_query)
	{
		$curl = curl_init($url);

		if (!curl_setopt_array($curl, $curl_query))
		{ throw new Exception("Problem setting CURL options."); }

		$result = curl_exec($curl);
		$curl_close($curl);

		return $result;
	}
}

class Tapascontent_MockHydraConnector
extends Tapascontent_aHydraConnector
{
	public function get_base_url() 
	{ return "http://rails_api.localhost:8080";}

	public function get_token() 
	{ return "tapas12345";}

	public function make_call($url, $curl_query) { assert(FALSE); } // TODO
}

//=====================================================================
//
//=====================================================================

abstract class Tapascontent_aQuery
{
	const TYPE_COMMUNITY = '/communities';
	const TYPE_COLLECTION = '/collection';
	const TYPE_TEI = '/files';

	public $options=[];
	public $postfields=[];
	public $record_type;

	public abstract function build_url($url_base);

	protected function debug_options()
	{
		return array(
			CURLOPT_RETURNTRANSFER => TRUE,
			CURLOPT_VERBOSE => TRUE,
			CURLINFO_HEADER_OUT => TRUE,
			CURLOPT_HEADER => TRUE,
		);
	}
}

class Tapascontent_UpsertQuery
extends Tapascontent_aQuery
{

	public function __construct($postfields, $record_type, $debug=FALSE)
	{
		$this->postfields = $postfields;
		$this->record_type = $record_type;
		$this->options = $debug?$this->debug_options():[];
	}

	public function build_url($url_base) 
	{ return $url_base . $this->upsert_type;}
}

class Tapascontent_DeleteQuery
extends Tapascontent_aQuery
{
	private $uuid;

	public function __construct($record_type, $uuid, $debug=FALSE)
	{
		$this->uuid = $uuid;
		$this->record_type = $record_type;

		$this->options[CURLOPT_CUSTOMREQUEST] = 'DELETE';
		if ($debug) {$this->options += $this->debug_options();}
	}

	public function build_url($url_base)
	{ return $url_base . $this->record_type . "/$this->uuid"; }
}

class Tapascotent_GetTeiQuery
extends Tapascontent_aQuery
{
	const TEI_RAW = 'tei';
	const TEI_BP = 'teibp';
	const TEI_GENERIC = 'tapas_generic';

	private $uuid;
	private $tei_type;

	public function __construct($tei_type, $uuid, $debug=FALSE)
	{
		$this->tei_type = $tei_type;
		$this->uuid = $uuid;

		$this->options[CURLOPT_CUSTOMREQUEST] = 'GET';
		$this->options[CURLOPT_RETURNTRANSFER] = TRUE;

		if ($debug) {$this->options += $this->debug_options();}
	}

	public function build_url($url_base)
	{ return $base_url . parent::TYPE_TEI . "/$uuid/$this->tei_type"; }
}

class Tapascontent_GetTeiRawQuery
extends Tapascontent_GetTeiQuery
{
	public function __construct($uuid, $debug=FALSE)
	{ parent::__construct(parent::TEI_RAW, $uuid, $debug); }
}

class Tapascontent_GetTeiBpQuery
extends Tapascontent_GetTeiQuery
{
	public function __construct($uuid, $debug=FALSE)
	{ parent::__construct(parent::TEI_BP, $uuid, $debug);}
}

class Tapascontent_GetTeiGeneric
extends Tapascontent_GetTeiQuery
{
	public function __construct($uuid, $debug=FALSE)
	{ parent::__construct(parent::TEI_GENERIC, $uuid, $debug); }
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



