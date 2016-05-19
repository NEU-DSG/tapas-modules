<?php

/**
 * @file
 * tapascontent_wrapper_hydra.inc
 */

//include_once('/var/www/hydratoken.php');
// define ('TAPAS_AUTH_TOKEN', HYDRA_API_KEY);
define ('TAPASHYDRA_AUTH_TOKEN', (variable_get('tapas_rails_api_key', 'tapas12345')));
define('TAPAS_BASE_API_URL', (variable_get('tapas_rails_api_url', 'http://rails_api.localhost:8080')));

define('TAPAS_POST_PROJECT_URL', TAPAS_BASE_API_URL . "/communities");
define('TAPAS_POST_COLLECTION_URL', TAPAS_BASE_API_URL . "/collections");
define('TAPAS_POST_TEI_URL', TAPAS_BASE_API_URL . "/files");

define('TAPAS_HYDRA_DEBUG_MODE', TRUE);

define('AS_COMMUNITY', 1);
define('AS_COLLECTION', 2);
define('AS_TEI', 3);

//=======================================================================
// Public Interfaces
//=======================================================================

interface Tapascontent_iRepositoryConnector {

	function __construct($uuid, $fields=array());

	function upsert($which);
	function get_tei($type);
	function delete($which);
}

interface Tapascontent_iCurlConnector {
	function __construct();
	function set_options($options);
	function set_fields($fields);
	function call($url);
}
//=======================================================================
// RespositoryConnector
//=======================================================================

class Tapascontent_HydraRepositoryConnector
implements Tapascontent_iRepositoryConnector {

	const RAW = 'tei';
	const BP = 'teibp';
	const GENERIC = 'tapas_generic';

	private $data;
	private $uuid;
	private $cc;

	public function __construct($uuid, $fields=array(), $curl_connector=NULL) {
		$this->data = $fields;
		$this->uuid = $uuid;

		$this->cc = $curl_connector?:new Tapascontent_CurlConnector();
	}

	public function upsert($which) {

		$url = $this->get_url($which);
		$this->cc->set_options($this->get_curl_header());
		$this->cc->set_fields($this->data);
		return $this->cc->call($url);
	}

	public function get_tei($type) {

		$curl_opts = get_curl_header();
		$curl_opts += array(
			CURLOPT_CUSTOMREQUEST => 'GET',
			CURLOPT_RETURNTRANSFER => TRUE);
		$this->cc->set_options($this->get_curl_header());
		$this->cc->set_fields(array());

		$url = TAPAS_POST_TEI_URL . "$this->uuid/$type";
		return $this->cc->call($url);
	}

	public function delete($which) {

		$baseurl = $this->get_url($which);
		$curlopts = get_curl_header();
		$curlopts += array(CURLOPT_CUSTOMREQUEST => 'DELETE');

		$this->cc->set_options($curlopts);
		$this->cc->set_fields(array());

		return $this->cc->call("$baseurl/" . $this->uuid);
	}

	private function get_url($which) {
		switch($witch) {
			case AS_COMMUNITY:
				return TAPAS_POST_PROJECT_URL;
				break;
			case AS_COLLECTION:
				return TAPAS_POST_COLLECTION_URL;
				break;
			case AS_TEI:
				return TAPAS_POST_TEI_URL;
				break;
			default:
				throw new Exception ("Unknown content type $which");
		}
	}

	private function get_curl_header() {
		return array('Authorization: Token token=' . TAPASHYDRA_AUTH_TOKEN);
	}

}


//=======================================================================
// CurlConnector
//=======================================================================


abstract class Tapascontent_AbstractCurlConnector
implements Tapascontent_iCurlConnector {

	var $querydata = array();

	public function __construct() {}

	public function set_options($curl_options) {
		$this->querydata = $curl_options;

		if (TAPAS_HYDRA_DEBUG_MODE) {
			$this->querydata += get_debug_opts();
		}
	}

	public function set_fields($fields) {
		if ($fields) {
			$transformed = $this->transform_sub_arrays($fields);
			$this->querydata[CURL_POST_FIELDS] = $transformed;
		} else {
			unset($this->querydata[CURL_POST_FIELDS]);
		}
	}

	public function call($url) {
		$options = $this->querydata;
		$options += array(CURLOPT_URL => $url);

		return $this->curl_call($url, $options);
	}

	private function transform_subarrays($data) {

		foreach($data as $key => $value) {
			if (is_array($value)) {
				$data += $self::transform_array($key, $value);
				unset($data[$key]);
			}
		}
	}

	private function transform_array($name, $array) {

		$data = array();
		foreach($array as $key => $value) {
			$data[$name.'['.$key.']'] = $value;
		}
		return $data;
	}

	private function get_debug_opts() {

		return array(
			CURLOPT_RETURNTRANSFER => TRUE,
			CURLOPT_VERBOSE => TRUE,
			CURLINFO_HEADER_OUT => TRUE,
			CURLOPT_HEADER => TRUE,
		);
	}

	protected abstract function curl_call($url, $options);
}


class Tapascontent_CurlConnector
extends Tapascontent_AbstractCurlConnector {

	protected function curl_call($url, $options) {
		$curl = curl_init($url);

		if(!curl_setopt_array($curl, $curlopt)) {
			throw new Exception("Problem setting CURL options.");
		}

		$result = curl_exec($curl);
		curl_close($curl);

		return $result;
	}
}

class Tapascontent_MockCurlConnector
extends Tapascontent_AbstractCurlConnector {


	protected function curl_call($url, $options) {
	}

}
