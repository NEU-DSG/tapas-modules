<?php
/**
 * @file
 * IteratorTest.php
 *
 * Unit tests for the custom Iterator classes.
 */

include_once('offlineunit/commonunit.php');

abstract class Tapascontent_Iterator_TestCase
extends Tapascontent_UnitTestCase
{
	protected abstract function get_valid_iterator();
	protected abstract function get_valid_array();
	protected abstract function get_valid_first_value();
	protected abstract function get_valid_second_value();
	protected abstract function get_expected_length();

	protected function get_needs_rewind_iterator()
	{
		$iterator = $this->get_valid_iterator();
		while ($iterator->valid()) { $iterator->next(); }
		return $iterator;
	}


	public function test_as_array()
	{
		$iterator = $this->get_valid_iterator();
		$array = $this->get_valid_array();
		$this->AssertEquals($array, $iterator->as_array());
	}

	public function test_as_array_works_when_needs_rewind()
	{
		$iterator = $this->get_needs_rewind_iterator();
		$array = $this->get_valid_array();
		$this->AssertEquals($array, $iterator->as_array());
	}

	public function test_current()
	{
		$iterator = $this->get_valid_iterator();
		$result = $this->get_valid_first_value();
		$this->AssertEquals($result, $iterator->current());
	}

	public function test_next()
	{
		$iterator = $this->get_valid_iterator();
		$iterator->next();
		$next = $iterator->current();
		$result = $this->get_valid_second_value();
		$this->AssertEquals($result, $next);
	}

	public function test_valid()
	{
		$iterator = $this->get_valid_iterator();
		$length = $this->get_expected_length();
		
		for($i=0; $i < $length; $i++)
		{
			$this->assertTrue($iterator->valid());
			$iterator->next();
		}

		$this->assertFalse($iterator->valid());
	}

	public function test_rewind()
	{
		$iterator = $this->get_valid_iterator();
		$length = $this->get_expected_length();
		$value = $this->get_valid_first_value();

		$this->assertEquals($value, $iterator->current());
		
		for($i=0; $i<$length; $i++)
		{
			$iterator->next();
		}
		
		$this->assertFalse($iterator->valid());
		$iterator->rewind();
		$this->assertTrue($iterator->valid());
		$this->assertEquals($value, $iterator->current());
	}

	public function test_key()
	{
		$iterator = $this->get_valid_iterator();
		$length = $this->get_expected_length();

		$this->assertEquals(0, $iterator->key());

		$zero_based = $length - 1;
		for($i=0; $i<($zero_based); $i++)
		{
			$iterator->next();
		}

		$this->assertEquals($zero_based, $iterator->key());
	}

}



