<?php
/**
 * @file
 * NodeWrapperTest.php
 *
 * Offline unit tests for the NodeWrapper classes.
 */

include_once('offlineunit/commonunit.php');

/**
 * @class
 */

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


	// TODO: These need to be uncommented and written. 
	//public function test_presave() //TODO
	//{
		//$this->markTestIncomplete();
	//}

	//public function test_upsert() //TODO
	//{
		//$this->markTestIncomplete();
	//}

	//public function test_delete() //TODO
	//{
		//$this->markTestIncomplete();
	//}

	public function test_is_valid()
	{
		$node = $this->get_wrapped();
		$this->assertTrue($node->is_valid());

		//TODO: Test with an invalid node.
	}

	protected function do_test_get_fields($params)
	{
		$values = $params->node->get_field_values(
			$params->fieldname,
			$params->column_default
		);

		$this->assertEquals(
			$params->expected_first,
			$values ->current($params->column_current)
		);

		$values->next();

		$this->assertEquals(
			$params->expected_second,
			$values->current($params->column_current)
		);
	}

	protected function do_test_set_field($params)
	{
		$params->node->set_field(
			$params->fieldname,
			$params->new_value, 
			$params->column_default, 
			$params->delta
		);

		$after_values = $params->node->get_field_values(
			$params->fieldname,
			$params->column_default
		);

		$after_values->rewind();
		if ($params->delta) {
			$after_values->next();
			$this->assertEquals($params->new_value, $after_values->current($params->column_current));
			$after_values->rewind();
		} else {
			$this->assertEquals($params->new_value, $after_values->current($params->column_current));
		}

		$this->assertEquals(
			$params->new_value, 
			$after_values->by_index($params->delta?:0, $params->column_current)
		);

	}

	private function base_params()
	{
		$params = new StdClass();

		$params->node = $this->get_wrapped();
		$params->column_default = NULL;
		$params->column_current = NULL;
		$params->expected_first = NULL;
		$params->expected_second = NULL;
		$params->new_value = NULL;
		$params->delta = NULL;

		return $params;
	}

	protected function default_column_params() {
		return $this->base_params();
	}

	protected function custom_column_params() {
		return $this->base_params();
	}

	public function test_get_field_values_default() 
	{
		$params = $this->default_column_params();
		$this->do_test_get_fields($params);
	}

	public function test_get_field_values_custom_current() 
	{
		$params = $this->custom_column_params();
		$params->column_default = NULL;
		$this->do_test_get_fields($params);
	}

	public function test_get_field_values_custom_default() 
	{
		$params = $this->custom_column_params();
		$params->column_current = NULL;
		$this->do_test_get_fields($params);
	}

	public function test_set_field_values_default() 
	{
		$params = $this->default_column_params();
		$this->do_test_set_field($params);
	}

	public function test_set_field_values_custom_current() 
	{
		$params = $this->custom_column_params();
		$params->column_default = NULL;
	}

	public function test_set_field_values_custom_default() 
	{
		$params = $this->custom_column_params();
		$params->column_current = NULL;
		$this->do_test_set_field($params);
	}

	public function test_set_field_delta()
	{
		$params = $this->default_column_params();
		$params->delta = 1;
		$this->do_test_set_field($params);

	}

	public function test_set_field_delta_custom_column()
	{
		$params = $this->default_column_params();
		$params->delta = 1;
		$this->do_test_set_field($params);
	}

	public function test_append_field_item_proper_cardinality()
	{


	}

	public function test_append_field_item_singular_cardinality_error()
	{
		// verify the failure behavior if a value is appended to a field
		// that only allows singular values.
	
		$this->markTestIncomplete();
	}

	public function test_append_field_item_filled_cardinality_error()
	{
		// verify the failure behavior if a value is appended to a field
		// that, while it allows more than one value, only allows a finite
		// number of values and that limit had already been reached.

		$this->markTestIncomplete();
	}
}


/**
 * @class
 */
class Tapascontent_ProjectNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	public function setUp()
	{
		parent::setUp();
		global $project_node;
		$this->set_node($project_node);
	}

	public function test_parent_get_node_privacy() {
		$actual = $this->get_wrapped()->get_node_privacy();
		$this->assertEquals('public', $actual);
	}

	protected function default_column_params()
	{
		$params = parent::default_column_params();
		$params->fieldname = 'field_tapas_slug';
		$params->expected_first = 'digitaldinahcraik';
		$params->expected_second = 'dummy_second_slug_for_testing';
		$params->new_value = 'new-slug-for-test-set';

		return $params;
	}

	protected function custom_column_params()
	{
		$params = parent::custom_column_params();
		$params->fieldname = 'field_tapas_links';
		$params->column_default = 'title';
		$params->column_current = 'title';
		$params->expected_first = "Sally Mitchell's Dinah Mulock Craik on the Victorian Web";
		$params->expected_second = "Dummy second url title for testing";
		$params->new_value = "Changed title value to test set";

		return $params;
	}

	public function test_thumbnail()
	{
		$this->markTestIncomplete();
	}

	public function test_repo_data()
	{
		$this->markTestIncomplete();
	}
}

/**
 * @class
 */
class Tapascontent_CollectionNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	
	public function setUp()
	{
		parent::setUp();
		global $collection_node;
		$this->set_node($collection_node);
	}

	protected function default_column_params()
		{
		$params = parent::default_column_params();
		$params->fieldname = 'field_tapas_slug';
		$params->expected_first = 'parrishcollectionofvictoriannovelistsatprincetonuniversity';
		$params->expected_second = 'dummy_second_slug_for_testing';
		$params->new_value = 'new-slug-for-test-set';

		return $params;
	}

	protected function custom_column_params()
	{
		$params = parent::custom_column_params();
		$params->fieldname = 'field_tapas_thumbnail';
		$params->column_default = 'filename';
		$params->column_current = 'filename';
		$params->expected_first = 'Digital Dinah Craik-logo.png';
		$params->expected_second = 'dummy filename for testing.';
		$params->new_value = "Changed title value to test set";

		return $params;
	}
}

/**
 * @class
 */
class Tapascontent_SharedNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{
	
	public function setUp()
	{
		parent::setUp();
		global $shared_node;
		$this->set_node($shared_node);
	}

	protected function default_column_params()
	{
		$params = parent::default_column_params();
		$params->fieldname = 'field_tapas_slug';
		$params->expected_first = 'parrishcollection';
		$params->expected_second = 'dummy_second_slug_for_testing';
		$params->new_value = 'new-slug-for-test-set';

		return $params;
	}

	protected function custom_column_params()
	{
		$params = parent::custom_column_params();
		$params->fieldname = 'field_tapas_thumbnail';
		$params->column_default = 'filename';
		$params->column_current = 'filename';
		$params->expected_first = 'Digital Dinah Craik-logo.png';
		$params->expected_second = 'dummy filename for testing.';
		$params->new_value = "Changed title value to test set";

		return $params;
	}
}

/**
 * @class
 */
class Tapascontent_RecordNodeWrapper_TestCase
extends Tapascontent_NodeWrapper_TestCase
{

	public function setUp()
	{
		parent::setUp();
		global $record_node;
		$this->set_node($record_node);
	}

	protected function default_column_params()
	{
		$params = parent::default_column_params();
		$params->fieldname = 'field_tapas_display_auth';
		$params->expected_first = 'Craik, Dinah Mulock';
		$params->expected_second = 'dummy_second_author_for_testing';
		$params->new_value = 'Changed author name for testing.';

		return $params;
	}

	protected function custom_column_params()
	{
		$params = parent::custom_column_params();
		$params->fieldname = 'field_tapas_display_date';
		$params->column_default = 'timezone';
		$params->column_current = 'timezone';
		$params->expected_first = 'America/New_York';
		$params->expected_second = 'needed another fake for test.';
		$params->new_value = 'changed timezone for testing';

		return $params;
	}


	public function test_create_simple_record()
	{
		$factory = $this->factory();
		$new_node = new Tapascontent_RecordNodeWrapper($factory, NULL);
		$this->assertTrue($new_node->is_valid());
	}

	public function test_create_simple_record_title_from_hydra_from_tei()
	{
		$this->markTestIncomplete();
	}

	public function test_create_simple_record_with_hydra()
	{
		$this->markTestIncomplete();
	}

	public function test_create_record_with_attatchments()
	{
		$this->markTestIncomplete();
	}

	public function test_create_record_with_linked_ographies()
	{

		$this->markTestIncomplete();
	}

	public function test_create_record_with_attatchments_and_linked_ographies()
	{

		$this->markTestIncomplete();
	}

	private function get_sample_tei_file()
	{
		assert(FALSE);
	}
}
