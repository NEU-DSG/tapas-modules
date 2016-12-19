<?php
/**
 * @file
 * tapascontent_repo.inc
 */


//=====================================================================
// Interfaces to classes defined in this file
//=====================================================================

interface Tapascontent_iRepoConnector
{
	function send_query($query_struct);
}

interface Tapascontent_iQuery
{
	function build_url($base_url);
}
//=====================================================================
// Repository Connector
//=====================================================================


abstract class Tapascontent_aHydraConnector
implements Tapascontent_iRepoConnector
{
	const TYPE_COMMUNITY = '/communities';
	const TYPE_COLLECTION = '/collection';
	const TYPE_TEI = '/files';

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
	{
		return variable_get('tapas_rails_api_url', 'http://rails_api.localhost:8080');
	}

	public function get_token()
	{
		return variable_get('tapas_rails_api_key', 'tapas12345');
	}

	public function make_call($url, $curl_query)
	{
		$curl = curl_init($url);

		if (!curl_setopt_array($curl, $curl_query))
		{
			throw new Exception("Problem setting CURL options.");
		}

		$result = curl_exec($curl);
		$curl_close($curl);

		return $result;
	}
}

class Tapascontent_MockHydraConnector
extends Tapascontent_aHydraConnector
{
	public function get_base_url() 
	{ 
		return "http://rails_api.localhost:8080";
	}
	public function get_token() 
	{
		return "tapas12345";
	}
	public function make_call($url, $curl_query) { assert(FALSE); } // TODO
}

//=====================================================================
//
//=====================================================================

abstract class Tapascontent_aQuery
implements Tapascontent_iQuery
{

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
	{
		return $url_base . $this->record_type;
	}
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
	{
		return $url_base . $this->record_type . "/$this->uuid";
	}
}

class Tapascontent_GetTeiQuery
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
	{
		return $base_url . parent::TYPE_TEI . "/$uuid/$this->tei_type";
	
	}
}

