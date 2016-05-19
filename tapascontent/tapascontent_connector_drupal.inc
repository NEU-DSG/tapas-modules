<?php

/**
 * @file
 * tapascontent_wrapper_drupal.inc
 *
 * Abstracts calls that access the Drupal database, so
 * that a mock instance can be used.
 */

interface Tapascontent_iDrupalConnector {
	function __construct($node);
	function get_fieldval($fieldname, $column='value');
	function set_fieldval($fieldname, $value, $column='value');
	function path_from_fid($fid);
	function parent_uuids_by_type($type);
	function get_og_user_members();
	function node_load($nid);
	function drupal_realpath($filename);
}

class Tapascontent_DrupalConnector 
implements Tapascontent_iDrupalConnector {
	
	private $node;

	public function __construct($node) {
		$this->node = $node;
	}

	public function get_fieldval($fieldname, $column='value') {
		$raw = field_get_items($this->node, node, $fieldname);

		$values = [];
		foreach($raw as $rawfield) {
			$values[] = $rawfield[LANG_NONE][0][$column];
		}
	}

	public function set_fieldval($fieldname, $value, $column='value') {
		// TODO
	}

	public function path_from_fid($fid) {
		return drupal_realpath($fid);	
	}

	public function parent_uuids_by_type() {
		$parent_ids = og_get_entity_groups('node', $this->node);

		if (! $parent_ids) { return FALSE; }

		$parents = [];
		foreach($parent_ids['node'] as $node) {
			$parents[node_type_get_name($node)] = $node->uuid;
		}
		//TODO: since I generally seem to use this to immediaely load the node,
		// perhaps I should just return a list of nodes rather than ids?

		return $parents;
	}

	public function get_og_user_members() {
		return og_get_group_members_properties($this->node, [], OG_STTE_ACTIVE, 'node');
	}

	public function node_load($id) {
		return Tapascontent_NodeWrapper::wrap_node(node_load($id));
	}

	public function drupal_realpath($uri) {
		return drupal_realpath($uri);
	}
}

class Tapascontent_MockDrupalConnector
implements Tapascontent_iDrupalConnector 
{


}

 
