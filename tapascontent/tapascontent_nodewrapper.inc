<?php

include_once('tapascontent_common.inc');
include_once('tapascontent_drupalcalls.inc');
include_once('tapascontent_repo.inc');
include_once('tapascontent_forms.inc');
include_once('tapascontent_solr_indexing.inc');


//TODO: node_object_prepare() when creating node.


//=====================================================================
// Interfaces implemented in this file
//=====================================================================




interface Tapascontent_iNodeWrapper
{
	function presave();
	function upsert();
	function delete();
	// TODO: 'Retrieve' is still in the _recordview file, and we probably
	//   want to add it to one of the subclasses, rather than here.
	function is_valid();

	function get_field_values($fieldname, $column='value');
	function set_field($fieldname, $value, $column='value');
	function get_thumbnail();
	function get_repo_data();
	function get_type();

	function generate_node();
}


interface Tapascontent_iGroupNodeWrapper
{
	function members();
	//function roles();

	function get_node_privacy();
}




//=======================================================================
// NodeWrapper Base Classes
//=======================================================================

/**
 * @class
 * Tapascontent_aNodeWrapper
 */

abstract class Tapascontent_aNodeWrapper  
extends Tapascontent_aWrapper
implements Tapascontent_iNodeWrapper
{

	private $repo;
	private $factory;
	private $node;

	//-----------------------------------------------------------
	// Unimplemented functions from iNodeWrapper
	//-----------------------------------------------------------
	public abstract function presave();
	public abstract function upsert();
	public abstract function delete();
	public abstract function get_type();

	//-----------------------------------------------------------
	// Implemented functions from iNodeWrapper
	//-----------------------------------------------------------


	/**
	 * @function get_field_values()
	 */
	public function get_field_values($fieldname, $column='value') {
		$drupal_connector = $this->drupal();
		return $drupal_connector->get_field_values($this->node(), $fieldname, $column);
	}

	/**
	 * @function set_field()
	 */
	public function set_field($fieldname, $value, $column='value', $delta=0) {
		$drupal_connector = $this->drupal();
		$node = $this->node();// If I try to inline this inside of set_field, it complains that "only variables should be passed by reference".
		$new_node = $drupal_connector->set_field($node, $value, $fieldname, $column, $delta);
		$this->node = $new_node;
	
	}

	/**
	 * @function get_thumbnail()
	 */
	public function get_thumbnail() {
		$fid = $this->get_field_values('field_tapas_thumbnail')->current('fid');
		return $this->drupal()->path_from_fid($fid);
	}

	/**
	 * @function get_repo_data()
	 */

	public function get_repo_data() {
		$data = array(
			'uniquid' => $this->node()->uuid,
			'depositor' => $this->node()->uid
		);
		return $data;
	}

	/**
	 * @function is_valid()
	 * Based on Drupal's node_validate() function
	 */

	public function is_valid()
	{
		$node = $this->node;

		if (!isset($this->node->nid)) { return FALSE; }

		//TODO: add user_load_by_name to drupal calls, so that we can do this check in the non-mock connector.
		//// Validate the "authored by" field.
		//if (!empty($this->node->name) && !($account = user_load_by_name($node->name))) {
			//// The use of empty() is mandatory in the context of usernames
			//// as the empty string denotes the anonymous user. In case we
			//// are dealing with an anonymous user we set the user ID to 0.
			
			////TODO: should we put the reason for failure into a member field that can be checked?
			//return FALSE; //The author is a user that doesn't exist.
		//}

		// Validate the "authored on" field.
		if (!empty($this->node->date) && strtotime($this->node->date) === FALSE) {
			return FALSE; //node needs a valid date
		}

		//TAPAS nodes should have titles
		if (!isset($node->title)) { return FALSE; }

		return TRUE;
	}

	/**
	 * @function generate_node()
	 */

	public function generate_node()
	{
		return $this->drupal()->create_node($this->get_type());
	}

	//-----------------------------------------------------------
	// Functions not defined in an interface
	//-----------------------------------------------------------

	public function __construct($factory, $node=NULL)
	{
		Tapascontent_aWrapper::__construct($factory->drupal());
		$this->factory = $factory;
		$this->repo = $factory->repo();
		$this->node = $node?:$this->generate_node();
	}

	protected function repo() { return $this->repo; }
	protected function factory() { return $this->factory; }
	public function node() { return $this->node; }

	protected function handle_upsert_return_code($code) // TODO
	{
		// Set the in-status field
	}

	protected function handle_delete_return_code($code) // TODO
	{
		//notifiy if there was a problem
	}
}

/**
 * @class
 * Tapascontent_GroupNodeWrapper
 */

abstract class Tapascontent_GroupNodeWrapper
extends Tapascontent_aNodeWrapper 
implements Tapascontent_iGroupNodeWrapper
{
	//-----------------------------------------------------------
	// Functions defined in iNodeWraper
	//-----------------------------------------------------------

	public function get_repo_data()
	{
		$data = parent::get_repo_data(); 
		$data = $data + array(
			'title' => $this->node()->title,
			'description' => $this->drupal()->get_field_values('field_tapas_description')->current(),

			'access' => $this->get_node_privacy(),
			'thumb_file' => $this->get_thumbnail()
		);
		return $data;
	}

	public function is_valid()
	{
		if (!parent::is_valid()) { return FALSE; }

		//TODO: check for group fields

		return TRUE;
	}

	//-----------------------------------------------------------
	// Functions defined in iGroupNodeWrapper
	//-----------------------------------------------------------

	public function members() {
		return $this->drupal()->user_members_of_this_group($this->node()->nid);
	}

	public function get_node_privacy() {
		$private = $this->get_field_values('group_access')->current();
		return $private?'private':'public';
	}

	//-----------------------------------------------------------
	// Functions not defined in an interface
	//-----------------------------------------------------------


	protected function send_upsert($type) 
	{
		$query = new Tapascontent_UpsertQuery($this->get_repo_data(), $type);
		$result = $this->repo()->send_query($query);
		return $this->handle_upsert_result($result);
	}
	
	protected function send_delete($type)
	{
		$query = new Tapascontent_DeleteQuery($this->node()->uuid, $type);
		$result = $this->repo()->send_query($query);
		return $this->handle_upsert_result($result);
	}

}

//=======================================================================
// NodeWrapper type-specific classes
//=======================================================================

class Tapascontent_ProjectNodeWrapper
extends Tapascontent_GroupNodeWrapper 
{

	private $my_type = Tapascontent_aHydraConnector::TYPE_COMMUNITY;

	//-----------------------------------------------------------
	// Functions defined in iNodeWraper
	//-----------------------------------------------------------

	public function presave() {}
	public function upsert() { $this->send_upsert($this->my_type); }
	public function delete() { $this->send_delete($this->my_type); }

	public function get_repo_data() 
	{
		$data = parent::get_repo_data();
		$data += array(
			'members' => $this->members()
		);

		return $data;
	}

	public function get_type() { return 'tapas_project'; }
}

class Tapascontent_CollectionNodeWrapper
extends Tapascontent_GroupNodeWrapper
{

	private $my_type = Tapascontent_aHydraConnector::TYPE_COLLECTION;
	public function upsert() { return $this->send_upsert($this->my_type); }
	public function delete() { return $this->send_delete($this->my_type); }

	//-----------------------------------------------------------
	// Functions defined in iNodeWraper
	//-----------------------------------------------------------
	public function presave()
	{

		$project = $this->drupal()->parent_nodes_by_type(TAPAS_PROJECT)->current();

		if ($project) {
			$parent_slug = $project->get_field_values('field_tapas_slug')->current('safe_value');
			$this->set_field('field_tapas_parent_slug', $parent_slug);
			$this->set_field('field_tapas_parent_slug', $parent_slug, 'safe_value');
		} else
		{
			throw new Exception("Unable to find parent project for this collection (" . $this->node()->nid . ")");
		}
	}
	
	public function get_repo_data()
	{
		// broken into separate lines for troubleshooting
		$data = parent::get_repo_data();
		$drupal_connector = $this->drupal();
		$node_list = $drupal_connector->parent_nodes_by_type($this->node(), TAPAS_PROJECT);
		$first_node = $node_list->current();
		$unwrapped = isset($unwrapped)&&$unwrapped?$first_node->node():NULL;
		$uuid = $unwrapped?$unwrapped->uuid():NULL;
		$did = $uuid?:'not_found'; //TODO: better error checking. This is for troubleshooting.

		$data += array( 'project_did' => $did,);

		return $data;
	}

	public function is_valid()
	{
		if (!parent::is_valid()) { return FALSE; }

		//TODO: verify project
		//TODO: verify audience field

		return TRUE;
	}

	//TODO: This is partially redundant with the $my_type, above.
	public function get_type() { return 'tapas_collection';}
}

class Tapascontent_SharedNodeWrapper
extends Tapascontent_GroupNodeWrapper
{
	//-----------------------------------------------------------
	// Functions defined in iNodeWraper
	//-----------------------------------------------------------

	// TODO: bring upsert repo commands up-to-date. (Then finish adding calls to handle_upsert_return_code and handle_delete_return_code)
	public function upsert()
	{
		$as_community = Tapascontent_aHydraWraper::TYPE_COMMUNITY;
		$as_collection = Tapascontent_aHydraConnector::TYPE_COLLECTION;	
		$community_result = $this->send_upsert($as_community);
		$collection_result = $this->send_upsert($as_collection);

		return $community_result?:$collection_result;
	}

	public function delete()
	{
		$as_collection = Tapascontent_aHydraConnector::TYPE_COLLECTION;
		$as_community = Tapascontent_aHydraConnector::TYPE_COMMUNITY;

		$collection_result = $this->send_upsert($as_collection);
		$community_result = $this->send_upsert($as_community);

		return $collection_result?:$community_result;
	}

	public function presave() {}

	public function get_repo_data() {
		$data = parent::get_repo_data();

		$data += ['project_did' => $this->node->uuid];
	
		return $data;

	}

	public function get_type() { return 'tapas_shared';}
}

class Tapascontent_RecordNodeWrapper
extends Tapascontent_aNodeWrapper
{

	private $my_type = Tapascontent_aHydraConnector::TYPE_TEI;
	public function upsert() { return $this->send_upsert($this->my_type);}
	public function delete() { return $this->send_upsert($this->my_type);}

	//-----------------------------------------------------------
	// Functions defined in iNodeWraper
	//-----------------------------------------------------------

	public function presave() {
		$first_collection = $this->drupal()->parent_nodes_by_type(TAPAS_COLLECTION)->current();

		if ($first_collection) 
		{
			$pid = $this->get_field_values('og_tapas_c_to_p', 'target_id')->current();
			$project = $this->drupal()->node_load($pid);
			if ($project) 
			{
				$proj = $this->factory->wrap($project);
				$proj_slug = $proj->get_field_values('field_tapas_slug', 'safe_value');
				$this->set_field('field_tapas_parent_slug', $proj_slug);
				$this->set_field('field_tapas_parent_slug', $proj_slug, 'safe_value');
			} else {
				throw new Exception("Can't find project for Record");
			}
		} else {
			throw new Exception("Can't find collection for Record");
		}
	}

	public function get_repo_data()
	{

		// Broken into multiple lines for troubleshooting.
		$drupal = $this->drupal();
		$nid = $this->node()->nid;

		$parent_nodes = $drupal->parent_nodes_by_type($nid, TAPAS_COLLECTION);
		$collection_dids = $parent_nodes->nids_as_array();

		$tei_field_value_list = $this->get_field_values('field_tapas_tei_file', 'fid');
		$tei_field_value = $tei_field_value_list->current();
		$tei_fullpath = $drupal->path_from_fid($tei_field_value);

		$support_files = $this->zip_support_files();
		
		$ography_types = $this->get_field_values('field_tapas_record_ography_types');
		$ography_array = $ography_types->as_array();

		$display_date = $this->get_field_values('field_tapas_display_date');
		$date_array = $display_date->as_array();

		$display_authors = $this->get_field_values('field_tapas_display_auth');
		$author_array = $display_authors->as_array();

		$display_contrib = $this->get_field_values('field_tapas_display_contrib');
		$contrib_array = $display_contrib->as_array();


		$display_title = $this->node()->title;

		$data = parent::get_repo_data();
		$data += array(
			'display_title' => $display_title,
			'collection_dids' => $collection_dids,
			'tei' => $tei_fullpath,
			'support_files' => $support_files,
			'ography_types' => $ography_array,
			'display_date' => $date_array,
			'display_authors' => $author_array,
			'display_contributors' => $contrib_array
		);
	}

	public function is_valid()
	{
		if (!parent::is_valid()) { return FALSE; }

		// TODO Check audience fields
		// TODO Check collections
		// TODO Check project

		return TRUE;
	}

	public function get_type() { return 'tapas_record'; }

	//-----------------------------------------------------------
	// Functions not defined in an interface
	//-----------------------------------------------------------

	private function zip_support_files() {
		$files = $this->get_field_values('field_tapas_attatchments', 'fid');
		if(empty($files)) { return '';}

		$paths = [];
		foreach($files as $fid) { $paths[] = $this->drupal()->fullpath($fid);}


		$zip = new ZipArchive();
		$name = $this->drupal()->public_path($this->node()->nid . '_zip.zip');
		$status = $zip->open($name, ZipArchive::OVERWRITE);

		
		if ($status !== TRUE) {
			$err = "Failed to create zipfile. Error returned:" . $zip->getStatusString();
			throw new Exception($err);
		}

		foreach($files as $file) {
			$path = "$name/page_images/" . basename($file);
			$zip->addFile($file, $path);
		}

		$zip->close();
		return '@' . $this->drupal()->public_path($name);

	}

}

//TODO: create node objects by passing the factory a bundle object.
//TODO: Connect the node-wrapper to the bundle-wrapper
