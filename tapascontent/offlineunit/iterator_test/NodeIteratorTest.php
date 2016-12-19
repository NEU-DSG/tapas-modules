<?php

include_once('offlineunit/iterator_test/IteratorTest.php');

class Tapascontent_NodeIterator_TestCase
extends Tapascontent_Iterator_TestCase
{
	
	private $nodes = array();

	public function setUp()
	{
		global $project_node;
		global $collection_node;
		global $shared_node;
		global $record_node;

		$this->nodes = [
			$project_node,
			$collection_node,
			$shared_node,
			$record_node];
	}

	public function test_current() // Overrides parent test_current
	{
		$iterator = $this->get_valid_iterator();
		$expected_first = $this->get_valid_first_value();
		$actual_first = $iterator->current()->nid;
		$this->assertEquals($expected_first, $actual_first);

	}

	public function test_next() // Overrides parent test_ndex
	{
		$iterator = $this->get_valid_iterator();
		$expected_second = $this->get_valid_second_value();
		$iterator->next();
		$actual_second = $iterator->current()->nid;
		$this->assertEquals($expected_second, $actual_second);
	}

	public function test_rewind() // Overrides parent test_rewind
	{
		$iterator = $this->get_valid_iterator();
		$length = $this->get_expected_length();
		$first_value = $this->get_valid_first_value();

		$this->assertEquals($first_value, $iterator->current()->nid);

		//TODO: implement an actual public length() function in parent.
		for ($i = 0; $i < $length; $i++)
		{
			$iterator->next();
		}

		$this->assertFalse($iterator->valid());
		$iterator->rewind();
		$this->assertTrue($iterator->valid());
		$this->assertEquals($first_value, $iterator->current()->nid);
	}

	protected function get_valid_iterator()
	{
		$iterator = new Tapascontent_NodeIterator($this->nodes);
		return $iterator;
	}

	protected function get_valid_array() 
	{
		return [443, 444, 544, 602];
	}
	protected function get_valid_first_value() { return 443; }
	protected function get_valid_second_value() { return 444; }
	protected function get_expected_length() { return 4; }
}
