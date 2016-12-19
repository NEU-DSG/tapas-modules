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
	function set_field(&$node, $fieldname, $value, $column='value', $delta=0); 
	function parent_nodes_by_type($nid, $type);
	function create_node($type);
	function current_user_uid();

	function form_set_error($fieldname, $msg);
}

//=======================================================================
// Drupal Connectors
//=======================================================================

abstract class Tapascontent_aDrupalConnector
implements Tapascontent_iDrupalConnector
{

	private $factory;

	public function get_field_values(
			$node, 
			$fieldname, 
			$column='value') 
	{
		return new Tapascontent_FieldValueIterator($node->$fieldname, $column);
	}
	public function set_field(
			&$node, 
			$new_value, 
			$fieldname, 
			$column='value', 
			$delta=0)
	{
		// Needed because when NULL is passed, it overides the defauts.
		// TODO: Since NULL overrides the default, make it so we don't send NULL when we want a default, and take away the next two hacky lines. 
		$column = $column?:'value'; 
		$delta = $delta?:0;

		$field = $node->$fieldname;
		$field['und'][$delta][$column] = $new_value;
		$node->$fieldname = $field;

		return $node;
	}


	public function __construct($factory) { $this->factory = $factory; }

	protected function factory() { return $this->factory; }
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

	public function create_node($type) {
		$new_node = new stdClass();
		$new_node->type = $type;
		$new_node->uid = $this->current_user_uid();
		$new_node->created = strtotime('now');
		$new_node->changed = strtotime('now');
		return $new_node;
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
		return $this->factory()->wrap_node(node_load($id));
	}
	
	public function groups_this_user_is_in($uid)
	{ 
		// TODO: why is this NULL? How to add $uid?
		// TODO: should return node iterator
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
		$count_array = $this->build_query($slug, $nid);
		return db_query($query_base, $count_array)->fetchField();
	}

	public function parent_nodes_by_type($nid, $type)
	{
		// Returns array with the 'type' as the key, and the value is another
		//   array with the OG Membership ID as key and the group ID as the value.
		//   (or an empty array, if nothing is found.)

		$parents = og_get_entity_groups('node', $nid)[$type];
		$node_array = [];
		foreach($parents as $nid) 
		{
			$node_array[] = $nid;
		}
		return new Tapascontent_NodeIterator($node_array);
	}

	public function form_set_error($field, $msg) {
		set_form_error($field, $msg);
	}

	public function create_node($type) 
	{
		$new_node = parent::create_node($type);
		node_object_prepare($new_node);
		return $new_node;
	}

	public function current_user_uid()
	{
		global $user;
		return $user->uid;
	}

}

class Tapascontent_MockDrupalConnector
extends Tapascontent_aDrupalConnector
{
	public function path_from_fid($fid) { return $fid; }
	public function public_path($name) { return $name; }

	public function verify_slug_unique($slug, $nid=NULL)
	{
		assert(FALSE);
		// The other alternative is to always return 'TRUE', but I only
		// want to do that if I need to.
	}

	public function activate_honeypot(&$form, &$form_state, $params) {
		assert(FALSE);
		// Or else return NULL, but only want to do that if I need to.
	}
	public function node_load($nid)
	{
		switch($nid)
		{
			case 443:
			case '9756885e-1131-4494-adee-cf914dddf701':
				global $project_node;
				return $this->factory()->wrap_node($project_node);
				break;
			case 544:
			case 'xeb53f1c-bcac-41fb-84d4-f5cb97a1a46c':
				global $shared_node;
				return $this->factory()->wrap_node($project_node);
				break;
			case 444:
			case 'aeb53f1c-bcac-41fb-84d4-f5cb97a1a46c':
				global $collection_node;
				return $this->factory()->wrap_node($collection_node);
				break;
			case 602:
			case '66db1ec1-e708-4f17-b55d-3706c39ab13e':
				global $record_node;
				return $this->factory()->wrap_node($collection_node);
				break;
		}
	}


	// return node iterator
	public function groups_this_user_is_in($uid) 
	{ 
	}

	public function roles_this_user_has($uid, $gid, $include=TRUE)
	{
	}

	// return user iterator
	public function user_members_of_this_group($gid) 
	{ 
	}

	public function ungroup_node($gid) {
	}

	public function parent_nodes_by_type($nid, $type)
	{
		switch($type) {
			case 'tapas_project':
				global $tapas_project;
				$node = $tapas_project;
			case 'tapas_collection':
				global $tapas_collection;
				$node = $tapas_collection;
			case 'tapas_shared':
				global $tapas_shared;
				$node = $tapas_shared;
			case 'tapas_record':
				global $tapas_record;
				$node = $tapas_record;
			default:
				return NULL;
		}
		return new Tapascontent_NodeIterator([$node]);
	}

	public function form_set_error($field, $msg) {}

	public function create_node($type) {
		return parent::create_node($type);
	}

	public function current_user_uid() 
	{
		return 162;
	}
}


