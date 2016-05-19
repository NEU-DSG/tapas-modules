<?php
/**
 * @file
 * tapascontent_wrapper_node.php
 */

interface Tapascontent_iNodeWrapper 
{

	function __construct($node);

	function upsert();
	function delete();
	function presave();

	function get_fieldval($fieldname, $column='value');
	function set_fieldval($fieldname, $value, $column='value');
	
	function get_hydradata();
	function get_base_curl_url();
}


abstract class Tapascontent_NodeWrapper 
implements Tapascontent_iNodeWrapper
{
	protected $node;
	protected $drupal_connector;
	protected $repo_connector;

	public static function wrap_node($node, $dc=NULL, $hc=NULL)
	{
		switch($node->type) {
			case TAPAS_PROJECT:
				return new Tapascontent_ProjectNodeWrapper($node, $dc, $hc);
				break;
			case TAPAS_SHARED:
				return new Tapascontent_SharedNodeWrapper($node, $dc, $hc);
				break;
			case TAPAS_COLLECTION:
				return new Tapascontent_CollectionNodeWrapper($node, $dc, $hc);
				break;
			case TAPAS_RECORD:
				return new Tapascontent_RecordNodeWrapper($node, $dc, $hc);
				break;
			}
	}

	public function __construct($node, $drupal_connector=NULL, $repo_connector=NULL)
	{
		$this->node = $node;
		$this->drupal_connector = $drupal_connector?: new Tapascontent_DrupalConnector();
		$this->repo_connector = $repo_connector?: $this->default_repo_connector();
	}

	public function get_fieldval($fieldname, $column='value') {
		$this->drupal_connector->get_fieldval($fieldname, $coulmn);
	}

	public function set_fieldval($fieldname, $value, $column='value') {
		$this->drupal_connector->set_fieldval($fieldname, $value, $column);
	}

	protected function default_repo_connector()
	{
		return new Tapascontent_HydraRepositoryConnector(
			$this->node->uuid,
			$this->get_hydradata());
	}


	public function filepaths_from_field($fieldname) 
	{
		$fids = $this->get_fieldval($fieldname, 'fid');
		if ($fids) {
			$filepaths = [];
			foreach($fids as $delta => $fid) {
				$filepaths[] = $this->drupal_connector->path_from_fid($fid);
			}
			return $filepaths;
		}

	}

	public function get_node_privacy()
	{
		$dc = $this->drupal_connector;
		return $dc->get_fieldval('group_access')?'private':'public';
	}

	public function get_thumbnail() 
	{
		$dc = $this->drupal_connector;
		$thumb_fid = $dc->get_fieldval('field_tapas_thumbnail', 'fid');
		return $dc->path_from_fid($fid);
	}
	
	public function set_if_present(&$array, $key, $value, $unset_if_empty=FALSE) {
		if ($value) {
			$array[$key] = $value;
		} elseif ($unset_if_empty) {
			unset($array[$key]);
		}
	}

	public abstract function presave();
	public abstract function get_hydradata();
}

class Tapascontent_ProjectNodeWrapper
extends Tapascontent_NodeWrapper {


	public function presave() {}

	public function upsert()
	{
		return $this->repo_connector->upsert(AS_COMMUNITY);
	}

	public function delete() 
	{
		$this->repo_connector->delete(AS_COMMUINITY);
	}
	public function get_hydradata()
	{
		$data = array(
			'uniqueid' => $this->node->uuid,
			'depositor' => $this->node->uid,
			'title' => $this->node->title,
			'description' => $this->get_fieldval('field_tapas_description'),
			'access' => $this->get_node_privacy(),
			'members' => $this->drupal_conector->get_og_user_members()
		);

		$this->set_if_present($data['thumb_file'], $get_thumbnail);

		return $data;
	}

}

class Tapascontent_CollectionNodeWrapper 
extends Tapascontent_NodeWrapper
{
	public function upsert()
	{
		return $this->repo_connector->upsert(AS_COLLECTION);
	}
	public function delete()
	{
		$this->repo_connector->delete(AS_COLLECTION);
	}

	public function presave() {

		$parent_proj_id = $this->drupal_connector->parent_uuids_by_type(TAPAS_PROJECT)[0];
		$project = $this->drupal_connector->node_load($parent_proj_id);

		if ($project) {
			$parent_slug = $project->get_fieldval('field_tapas_slug');
			$this->set_fieldval('field_tapas_parent_slug', $parent_slug);
			$this->set_fieldval('field_tapas_parent_slug', $parent_slug, 'safe_value');
		} else {
			throw new Exception("Unable to find parent project for collection.");
		}
	}

	public function get_hydradata() {
		$description = $this->get_fieldval('field_tapas_description');

		$data = array(
			'uniqueid' => $node->uuid,
			'depositor' => $node->uid,
			'title' => $node->title,
			'description' => $description,
			'accesss' => $this->get_node_privacy(),
			'project_did' => $this->drupal_connector->get_parent_uuids(TAPAS_PROJECT)[0]
		);

		$this->set_if_present($data['thumbnail'], $this->get_thumbnail());

		return $data;
	}

}

class Tapascontent_SharedNodeWrapper
extends Tapascontent_NodeWrapper
{
		
	function upsert() {
		return $this->repo_connector->upsert(AS_PROJECT);
		return $this->repo_connector->upsert(AS_COLLECTION);
	}

	function delete() {
		$this->repo_connector->delete(AS_COLLECTION);
		$this->repo_connector->delete(AS_PROJECT);
	}

	function presave() {}

	function get_hydra_data() {

		$description = $this->get_fieldval('field_tapas_description');

		$data = array(
			'uniqueid' => $this->node->uuid,
			'depositor' => $this->node->uid,
			'title' => $this->node->title,
			'description' => $description,
			'access' => $this->get_node_privacy(),
			'project_did' => $this->node->uuid,
			'members' => $this->drupal_conector->get_og_user_members()
		);

		$this->set_if_present($data['thumb_file'], $get_thumbnail);

		return $data;
	}
}

class Tapascontent_RecordNodeWrapper
extends Tapascontent_NodeWrapper
{
	function upsert() {
		return $this->repo_connector->upsert(AS_TEI);
	}

	function delete() {
		$this->repo_connector->delete(AS_TEI);
	}

	function presave() {
		$dc = $this->drupal_connector;
		
		$collection_uuids = $dc->parent_uuids_by_type(TAPAS_COLLECTION);
		$first_collection = $dc->drupal_connector->node-load($collection_uuids[0]);

		if ($first_collection) {
			$project = $dc->node_load($dc->get_fieldval('og_tapas_c_to_p', 'target_id')[0]);
			if ($project) {
				$this->set_parent_slug_to($project);
			} else {
				throw new Exception("Can't find Project for Record");
			}

		} else {
			throw new Exception("Can't find Collection for Record.");
		}

	}

	private function set_parent_slug_to($project) {
			$project_slug = $project->get_fieldval('field_tapas_slug', 'safe_value');
			$this->set_fieldval('field_tapas_parent_slug', $project_slug);
			$this->set_fieldval('field_tapas_parent_slug', $project_slug, 'safe_value');
	}

	public function get_hydradata() {

		$collection_uuids = $this->drupal_connector->parent_uuids_by_type(TAPAS_COLLECTION);

		$data = array(
			'uniqeid' => $this->node->uuid,
			'depositor' => $this->node->uid,
			'display_title' => $this->node->title,
			'collection_dids' => $collection_uuids,
		);

		$tei_path = $this->filepaths_from_field('field_tapas_tei_file')[0];
		$this->set_if_present($data, 'tei', $tei_path);

		$sfs = $this->zip_support_files();
		$this->set_if_present($data, 'support_files', $sfs);

		$ography_types = $this->get_fieldval('field_tapas_record_ography_types');
		$this->set_if_present($data, 'file_types', $ography_types?:[null], TRUE);

		$other_fields = array (
			'display_date' => 'field_tapas_display_date',
			'disblay_authors' => 'field_tapas_display_auth',
			'display_contributors' => 'field_tapas_display_contrib'
		);
		foreach ($other_fields as $param => $field) {
				$this->set_if_present($data, $param, get_fieldval($field));
		}
		return $data;
	}

	public function filepaths_from_field($fieldname) {
		$fid_list = $this->get_fieldval($fieldname, 'fid');
		$pathlist = [];

		foreach($fid_list as $fid) {
			$pathlist[] = $this->drupal_connector->path_from_fid($fid);
		}

		return $pathlist;
	}

	private function zip_support_files() {
		$files = $this->filepaths_from_field('field_tapas_attatchments');

		if(empty($files)) {
			return '';
		}

		$zip = new ZipArchive();
		$name = $this->node->nid . "_zip.zip";
		$fullname = $this->drupal_connector->drupal_realpath("public://$name");
		$status = $zip->open($fullname, ZipArchive::OVERWRITE);

		if ($status !== TRUE) {
			$err = "Failed to create zipfile. Error returned:" . $zip->getStatusString();
			throw new Exception($err);
		}

		foreach($files as $file) {
			$path = "$name/page_images/" . basename($file);
			$zip->addFile($file, $path);
		}

		$zip->close();
		return '@' . $fullname;

	}
}
