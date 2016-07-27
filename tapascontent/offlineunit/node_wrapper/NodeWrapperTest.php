<?php
/**
 * @file
 * NodeWrapperTest.php
 *
 * Offline unit tests for the NodeWrapper classes.
 */

include_once('offlineunit/commonunit.php');

abstract class Tapascontent_NodeWrapper_TestCase
extends Tapascontent_UnitTestCase
{

	private $factory;
	private $unwrapped;
	private $wrapped;

	protected function factory() {
		return $this->factory;
	}

	protected function set_node($node)
	{
		$this->unwrapped = $node;
		$this->wrapped = $this->factory()->wrap_node($node);

	}

	protected function get_unwrapped() { return $this->unwrapped; }
	protected function get_wrapped() { return $this->wrapped; }

	public function setUp() {
		$this->factory = new Tapascontent_MockWrapperFactory();
	}

	/**
	 * @function
	 * test_drupal_getter()
	 *
	 * Checks that the drupal_connector was created. 
	 *
	 * the drupal() function is defined in the iWrapper interface,
	 * and implemented in the aWrapper abstract class. Testing it
	 * with the sub-classes is actually testing whether the 
	 * connector class was created and assigned properly internally
	 * to the wrapper.
	 */

	public function test_drupal_getter()
	{
		$wrapped = $this->get_wrapped();
		$this->assertInstanceOf('Tapascontent_aWrapper', $wrapped);
		$drupal_connector = $wrapped->drupal();
		$this->assertInstanceOf('Tapascontent_aDrupalConnector', $drupal_connector);
	}

	public function test_presave()
	{
		$this->markTestIncomplete();
	}

	public function test_upsert()
	{

		$this->markTestIncomplete();

	}

	public function test_delete()
	{
		$this->markTestIncomplete();
	}

	protected abstract function test_get_field_values();
	protected abstract function test_set_field();

	protected abstract function thumbnail_expected_value();
	public function test_get_thumbnail()
	{

		$this->markTestIncomplete();

	}

	protected abstract function repo_data_expected_value();
	public function test_get_repo_data()
	{

		$this->markTestIncomplete();

	}

}


class Tapascontent_ProjectNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	public function setUp()
	{
		parent::setUp();
		global $project_node;
		$this->set_node($project_node);
	}

	public function test_get_field_values()
	{
		$this->markTestIncomplete();
	}
	public function test_set_field()
	{
		$this->markTestIncomplete();
	}

	public function test_parent_get_node_privacy() {
		$this->assertEquals('public', $this->get_wrapped()->get_node_privacy());
	}

	protected function thumbnail_expected_value()
	{

	}
	protected function repo_data_expected_value()
	{

	}
}

class Tapascontent_CollectionNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	
	public function setUp()
	{
		parent::setUp();
		global $collection_node;
		$this->set_node($collection_node);
	}

	public function test_get_field_values()
	{
		$expected_first = 	"http://www.victorianweb.org/authors/craik/mitchell/1.html";
		$expected_second = "http://www.example.com";
		$values = $this->get_wrapped()->get_field_values('field_tapas_links', 'url');
		var_dump($values);

		$actual_first = $values->current();
		$values->next();
		$actual_second = $values->current();

		$this->assertEquals($expected_first, $actual_first);
		$this->assertEquals($expected_second, $actual_second);
	}

	public function test_set_field()
	{
		$this->markTestIncomplete();

		$new_value = "Changed Filename to Test Set_Field()";

	}

	protected function thumbnail_expected_value()
	{
	}
	protected function repo_data_expected_value()
	{
	}
}

class Tapascontent_SharedNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	
	public function setUp()
	{
		parent::setUp();
		global $shared_node;
		$this->set_node($shared_node);
	}
	public function test_get_field_values()
	{
		$this->markTestIncomplete();
	}
	public function test_set_field()
	{
		$this->markTestIncomplete();
	}

	protected function thumbnail_expected_value()
	{
	}
	protected function repo_data_expected_value()
	{
	}
}

class Tapascontent_RecordNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{

	public function setUp()
	{
		parent::setUp();
		global $record_node;
		$this->set_node($record_node);
	}
	public function test_get_field_values()
	{
		$this->markTestIncomplete();
	}
	public function test_set_field()
	{
		$this->markTestIncomplete();
	}

	protected function thumbnail_expected_value()
	{
	}
	protected function repo_data_expected_value()
	{
	}
}
