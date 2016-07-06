<?php

include_once('tapascontent_common.inc');
include_once('tapascontent_drupalcalls.inc');
include_once('tapascontent_repo.inc');
include_once('tapascontent_forms.inc');
include_once('tapascontent_solr_indexing.inc');

//TODO: ensure all the dirived classes actually call the 'implements' function for their interface(s).

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

	function get_field_values($fieldname, $column='value');
	function set_field($fieldname, $value, $column='value');
	function get_thumbnail();
	function get_repo_data();
}


interface Tapascontent_iGroupNodeWrapper
{
	function members();
	//function roles();

	function get_node_privacy();
	//function set_if_present(&$array, $key, $value, $unset_if_empty=FALSE);
}




//=======================================================================
// NodeWrapper Base Classes
//=======================================================================

abstract class Tapascontent_aNodeWrapper  
extends Tapascontent_aWrapper
implements Tapascontent_iNodeWrapper
{

	private $repo;
	private $factory;
	private $node;

	public abstract function presave();
	public abstract function upsert();
	public abstract function delete();

	protected function repo() { return $this->repo; }
	protected function factory() { return $this->factory; }
	protected function node() { return $this->node; }

	public function __construct($drupal, $repo, $node, $factory) {
		Tapascontent_aWrapper::__construct($drupal);
		$this->repo = $repo;
		$this->factory = $factory;
		$this->node = $node;
	}

	public function get_field_values($fieldname, $column='value') {
		$drupal_connector = $this->drupal();
		return $drupal_connector->get_field_values($this->node()->nid, $fieldname, $column);
	}

	public function set_field($fieldname, $value, $column='value') {
		$drupal_connector = $this->drupal();
		$drupal_connector->set_field($this->node()->nid, $fieldname, $value, $column);
	}

	public function get_thumbnail() {
		$fid = $this->get_field_values('field_tapas_thumbnail')->current('fid');
		return $this->drupal()->path_from_fid($fid);
	}

	public function get_repo_data() {
		$data = array(
			'uniquid' => $this->node()->uuid,
			'depositor' => $this->node()->uid
		);
		return $data;
	}

	protected function handle_upsert_return_code($code) // TODO
	{
		// Set the in-status field
	}

	protected function handle_delete_return_code($code) // TODO
	{
		//notifiy if there was a problem
	}
}

abstract class Tapascontent_GroupNodeWrapper
extends Tapascontent_aNodeWrapper 
implements Tapascontent_iGroupNodeWrapper
{
	public function members() {
		return $this->drupal()->user_members_of_this_group($this->node()->nid);
	}

	public function get_node_privacy() {
		$private = $this->get_field_values('group_access')->current();
		return $private?'private':'public';
	}

	public function get_repo_data()
	{
		$data = parent::get_repo_data()?:array();
		$data = $data + array(
			'title' => $this->node()->title,
			'description' => "description", // TODO: fix field iterator stuff. $this->drupal()->get_field_values('field_tapas_descrption')->current(),
			'access' => $this->get_node_privacy(),
			'thumb_file' => $this->get_thumbnail()
		);
	}

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

	public function presave() {}
	public function upsert() { $this->send_upsert($this->my_type); }
	public function delete() { $this->send_delete($this->my_type); }

	public function get_repo_data() 
	{
		$data = parent::get_repo_data()?:array();
		$data += array(
			'members' => $this->members()
		);

		return $data;

	}

}

class Tapascontent_CollectionNodeWrapper
extends Tapascontent_GroupNodeWrapper
{

	private $my_type = Tapascontent_aHydraConnector::TYPE_COLLECTION;
	public function upsert() { return $this->send_upsert($this->my_type); }
	public function delete() { return $this->send_delete($this->my_type); }

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
		$data = parent::get_repo_data()?:array();
		$drupal_connector = $this->drupal();
		$node_list = $drupal_connector->parent_nodes_by_type($this->node(), TAPAS_PROJECT);
		$first_node = $node_list->current();
		$unwrapped = isset($unwrapped)&&$unwrapped?$first_node->node():NULL;
		$uuid = $unwrapped?$unwrapped->uuid():NULL;
		$did = $uuid?:'not_found'; //TODO: better error checking. This is for troubleshooting.

		$data += array( 'project_did' => $did,);

		return $data;
	}

}

class Tapascontent_SharedNodeWrapper
extends Tapascontent_GroupNodeWrapper
{
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

}

class Tapascontent_RecordNodeWrapper
extends Tapascontent_aNodeWrapper
{

	private $my_type = Tapascontent_aHydraConnector::TYPE_TEI;
	public function upsert() { return $this->send_upsert($this->my_type);}
	public function delete() { return $this->send_upsert($this->my_type);}

	private function node_load($nid) { //TODO: why is this here?
		return $this->drupal()->node_load($nid);
	}

	public function presave() {
		$first_collection = $this->drupal()->parent_nodes_by_type(TAPAS_COLLECTION)->current();

		if ($first_collection) 
		{
			$pid = $this->get_field_values('og_tapas_c_to_p', 'target_id')->current();
			$project = $this->node_load($pid);
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

