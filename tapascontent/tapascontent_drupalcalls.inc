<?php
/**
 * @file
 * tapascontent_connectors.inc
 */

//=======================================================================
// Interfaces implemented in this file
//=======================================================================

// Yes, this is only half-following "code to the interface, not
// to the implementation", since the interface is just a passthrough
// to the Drupal implementation (which we know we will be getting
// rid of). However, it's not a good use of time at the moment to 
// design a more transportable interface, especially since we will
// be changing away from PHP to Ruby soon as well.


interface Tapascontent_iDrupalConnector
{
	// Can I just say, PHP's lack of proper strongly-typed constructor (and other function) polymorphism is a real hassle.
	function __construct($factory);

	function path_from_fid($fid);
	function public_path($name);
	function verify_slug_unique($slug, $nid=NULL);
	function activate_honeypot(&$form, &$form_state, $params);
	function node_load($nid);

	function groups_this_user_is_in($uid);
	function roles_this_user_has($uid, $gid, $include=TRUE);
	function user_members_of_this_group($gid);
	function ungroup_node($gid);
	

	function get_field_values($node, $fieldname, $column='value'); 
	function set_field($node, $fieldname, $value, $column='value'); 
	function parent_nodes_by_type($nid, $type);
	function create_record();

	function form_set_error($fieldname, $msg);
}

//=======================================================================
// Drupal Connectors
//=======================================================================

abstract class Tapascontent_aDrupalConnector
implements Tapascontent_iDrupalConnector
{

	public function create_record() {} // TODO

	private $factory;
	public function __construct($factory)
	{
		$this->factory = $factory;
	}
	protected function factory() { return $this->factory;}
	protected function query_base($nid)
	{
		$query_base = 'SELECT COUNT(*) from field_data_field_tapas_slug WHERE' . 
			' field_tapas_slug_value = :value AND bundle = :bundle';

		$query_base .= $nid?' AND entity_id != :nid':'';
		return $query_base;
	}
	protected function build_query($slug, $nid)
	{
		if ($nid)
		{
			$query_array = [
				':value' => $slug, 
				':bundle' => 'tapas_project', 
				':nid' => $form['#node']->nid
			];
		} else {
			$query_array = [
				':value' => $slug, 
				':bundle' => 'tapas_project'
			];
		}
		return $count_array;
	
	}
}

class Tapascontent_DrupalConnector
extends Tapascontent_aDrupalConnector
{
	public function path_from_fid($fid)  
	{
		return drupal_realpath($fid);
	}

	public function public_path($name) 
	{ 
		return drupal_realpath("public://$name"); 
	}

	public function ungroup_node($gid) 
	{
		return og_ungroup('node', $gid); 
	}

	public function roles_this_user_has($uid, $gid, $include=TRUE) 
	{ 
		return og_get_user_roles('node', $gid, $uid, $include); 
	}

	public function node_load($nid) 
	{
		return new Tapascontent_NodeWrapper(node_load($id));
	}
	
	public function groups_this_user_is_in($uid)
	{ 
		// TODO: why is this NULL? How to add $uid?
		// TODO: should return node iterator?
		return og_get_groups_by_user(NULL, "node");
	}

	public function user_members_of_this_group($gid) 
	{
		// TODO: return user iterator
		return og_get_group_members_properties($gid, [], OG_STATE_ACTIVE, 'node');
	}

	public function activate_honeypot(&$form, &$form_state, $params) {
		honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
	}

	function verify_slug_unique($slug, $nid=NULL)
  {
		$query_base = $this->query_base($nid);
		$query_array = $this->build_query($slug, $nid);
		return db_query($query_base, $count_array)->fetchField();
	}

	public function set_field($node, $fieldname, $value, $column='value') 
	{ 
		$node->field_fieldname[LANG_NONE][0][$column] = $value;
	} 

	public function get_field_values($node, $fieldname, $column='value') {
		$field = field_get_items($node->nid, 'node', $fieldname);
		return new Tapascontent_FieldValueIterator($field);
	}

	public function parent_nodes_by_type($nid, $type)
	{
		// Returns array with the 'type' as the key, and the value is another
		//   array with the OG Membership ID as key and the group ID as the value.
		//   (or an empty array, if nothing is found.)

		$parents = og_get_entity_groups('node', $nid)[$type];
		return new Tapascontent_NodeIterator($parents?$parents['node']:array(), $this);
	}

	public function form_set_error($field, $msg) {
		set_form_error($field, $msg);
	}
}

class Tapascontent_MockDrupalConnector
extends Tapascontent_aDrupalConnector
{
	public function path_from_fid($fid) { return("./$fid"); }
	public function public_path($name) { return $name; }

	public function verify_slug_unique($slug, $nid=NULL)
	{
		$query_base = $this->query_base($nid);
		$query_array = $this->build_query($slug, $nid);
	}

	public function activate_honeypot(&$form, &$form_state, $params) {}
	public function node_load($nid){ return array(); }

	// TODO: shoudl return node iterator?
	public function groups_this_user_is_in($uid) { return $uid;}

	public function roles_this_user_has($uid, $gid, $include=TRUE) { return  $uid;}

	// TODO: should return user iterator?
	public function user_members_of_this_group($gid) { return $gid; }

	public function ungroup_node($gid) { return TRUE; }



	public function set_field($node, $fieldname, $value, $column='value') 
	{ assert(FALSE); } // TODO: write set_fieldval function 

	public function get_field_values($node, $fieldname, $column='value') {
		return new Tapascontent_FieldValueIterator($node[$fieldname]['und'][0][$column]);
	}
	public function parent_nodes_by_type($nid, $type)
	{
		return new Tapascontent_NodeIterator([1,2,3], $this);
	}

	public function form_set_error($field, $msg) {}
}


