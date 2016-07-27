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

		while ($iterator->valid())
		{
			$iterator->next();
		}

		return $iterator;
	}


	public function test_as_array()
	{
		echo '
..... test_as_array
';
		$iterator = $this->get_valid_iterator();
		$array = $this->get_valid_array();
		$this->AssertEquals($array, $iterator->as_array());
		echo '
..... finished test_as_array
';
	}

	public function test_as_array_works_when_needs_rewind()
	{
		echo '
..... test_as_array_works_when_needs_rewind
';
		$iterator = $this->get_needs_rewind_iterator();
		$array = $this->get_valid_array();
		$this->AssertEquals($array, $iterator->as_array());
	}

	public function test_current()
	{
		echo '
..... test_current
';
		$iterator = $this->get_valid_iterator();
		$result = $this->get_valid_first_value();

		$this->AssertEquals($result, $iterator->current());
	}

	public function test_next()
	{
		echo '
..... test_next
';
		$iterator = $this->get_valid_iterator();
		$iterator->next();
		$next = $iterator->current();
		$result = $this->get_valid_second_value();
		$this->AssertEquals($result, $next);
	}

	public function test_valid()
	{
		echo '
..... test_valid
';
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
		echo '
..... test_rewind
';
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
		echo '
..... test_key
';
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

class Tapascontent_FieldValueIterator_TestCase
extends Tapascontent_Iterator_TestCase
{
	private $field;

	public function setUp()
	{
		echo '
beginning FieldValueIterator_TestCase
';
		$this->field = [
			'und' => [
				'0' => [
					'value' => 'digitaldinahcraik',
					'safe_value' => 'digitaldinahcraik'
				 ], // '0'
				'1' => [
					'value' => 'dummysecondvalue',
					'safe_value' => 'dummysecondvalue'
				 ] // '1'
			] // 'und'
		];
	}

	protected function get_valid_iterator()
	{
		return new Tapascontent_FieldValueIterator($this->field);
	}

	protected function get_valid_array() { return ['digitaldinahcraik', 'dummysecondvalue']; }
	protected function get_valid_first_value() { return 'digitaldinahcraik'; }
	protected function get_valid_second_value() { return 'dummysecondvalue'; }
	protected function get_expected_length() { return 2; }


}


class Tapascontent_NodeIterator_TestCase
extends Tapascontent_Iterator_TestCase
{
	
	private $nodes = array();

	public function setUp()
	{
		echo '
beginning NodeIterator_TestCase
';

		global $project_node;
		global $collection_node;
		global $shared_node;
		global $record_node;

		$this->nodes = [
			$project_node,
			$collection_node,
			$shared_node,
			$record_node];
	
		echo '
finished with setUp() (of NodeIterator_TestCase)
';
	}

	public function test_true()
	{
		$this->assertTrue(TRUE);
	}

	protected function get_valid_iterator()
	{
		echo '
--------------- begining get_valid_iterator in NodeIterator_TestCase
';
		return new Tapascontent_NodeIterator($this->nodes);
		echo '
--------------- finished get_valid_iterator in NodeIterator_TestCase
';
	}

	protected function get_valid_array() { return ['x']; }
	protected function get_valid_first_value() { return 'munge'; }
	protected function get_valid_second_value() { return 'munge'; }
	protected function get_expected_length() { return 10; }
}

class Tapascontent_WhyIsUnitTestHanging_TestCase
{
	function setUp()
	{
		echo '
Beginning Why-Is-Unit-Test-Hagining_TestCase
';
	}

	function test_true()
	{
		assertTrue(TRUE);
	}

}
