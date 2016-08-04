<?php

include_once('IteratorTest.php');

class Tapascontent_FieldValueIterator_TestCase
extends Tapascontent_Iterator_TestCase
{
	private $field;
	private $other_field;

	public function setUp()
	{
		$this->field = [
			'und' => [
				'0' => [
					'value' => 'digitaldinahcraik',
					'safe_value' => 'digitaldinahcraik',
					'dummy_column' => 'alpha'
				 ], // '0'
				'1' => [
					'value' => 'dummysecondvalue',
					'safe_value' => 'dummysecondvalue',
					'dummy_column' => 'beta'
				 ] // '1'
			] // 'und'
		];

		$this->other_field = [
			'und' => [
				'0' => [
					'fid' => 153,
					'uid' => 162,
					'filename' => 'Digital Dinah Craik-logo (1)_0.png',
					'uri' => 'public://Digital Dinah Craik-logo (1)_0.png',
					'filemime' => 'image/png',
					'filesize' => 8175,
					'status' => 1,
					'timestamp' => 1445262348,
					'uuid' => '64c2b6aa-b070-413b-80bf-43868c363032',
					'rdf_mapping' => [],
					'width' => 220,
					'height' => 180,
				] // '0'
			] // 'und'
		];
	}

	protected function get_valid_iterator()
	{
		return new Tapascontent_FieldValueIterator($this->field);
	}

	protected function get_valid_array() 
	{ 
		return ['digitaldinahcraik', 'dummysecondvalue']; 
	}

	protected function get_valid_first_value() 
	{ 
		return 'digitaldinahcraik'; 
	}

	protected function get_valid_second_value() 
	{ 
		return 'dummysecondvalue'; 
	}

	protected function get_expected_length() { 
		return 2; 
	}

	public function test_current_with_custom_column_name()
	{
		$iterator = new Tapascontent_FieldValueIterator($this->other_field);
		$this->assertEquals(153, $iterator->current('fid'));
	}

	public function test_create_with_custom_default_column()
	{
		$iterator = new Tapascontent_FieldValueIterator($this->other_field, 'fid');
		$this->assertEquals(153, $iterator->current());


	}

	public function test_as_array_with_custom_default_column() 
	{
		$iterator = new Tapascontent_FieldValueIterator($this->field, 'dummy_column');
		$as_array = $iterator->as_array();

		$this->assertEquals(['alpha', 'beta'], $as_array);
	}

	public function test_get_by_index_custom_default_column()
	{
		$iterator = new Tapascontent_FieldValueIterator($this->field, 'dummy_column');
		
		$this->assertEquals('beta', $iterator->by_index(1));
	}

	public function test_get_by_index_custom_current_column()
	{
		$iterator = new Tapascontent_FieldValueIterator($this->field);
		$this->assertEquals('beta', $iterator->by_index(1, 'dummy_column'));
	}
}
