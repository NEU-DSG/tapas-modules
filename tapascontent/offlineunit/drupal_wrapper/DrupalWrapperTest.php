<?php

/**
 * @file
 * DrupalWrapperTest.php
 *
 * Offline user tests for the non-mocked portions of the Drupal wrapper.
 */

include_once('offlineunit/commonunit.php');

class Tapascontent_DrupalWrapper_TestCase
extends Tapascontent_UnitTestCase
{

	private $factory;
	private $drupal;

	public function setUp()
	{
		/**
		 * DrupalConnector is usually made within the WrapperFactory,
		 * and also requires the factory to already exist so it 
		 * can recieve a pointer to it in the constructor. Therefore,
		 * the only practial way to build it here is by initializing
		 * a WrapperFactory.
		 */

		 $this->factory = new Tapascontent_MockWrapperFactory();
		 $this->drupal = $this->factory->drupal();
	
	}

	/**
	 * Most class functions not testable without Drupal bootstrap
	 *
	 * The "offline unit tests" test suite is only able to test a few 
	 * things about the drupal_connector, since it's essentially a wrapper around
	 * drupal calls that allows us to create a Mock version to use in offline testing.
	 */

	public function test_factory_getter()
	{
		$this->AssertInstanceOf(
			'Tapascontent_aWrapperFactory',
			$this->factory
		);
	}

	public function test_get_field_values()
	{
		global $project_node;

		$values = $this->drupal->get_field_values(
			$project_node, 
			'field_tapas_links',
			'url'
		);

		$expected_first = 	"http://www.victorianweb.org/authors/craik/mitchell/1.html";
		$expected_second = "http://www.example.com";

		$actual_first = $values->current('url');
		$values->next();
		$actual_second = $values->current('url');

		$this->assertEquals($expected_first, $actual_first);
		$this->assertEquals($expected_second, $actual_second);
	}

	//public function test_set_field()
	//{
		//$this->markTestIncomplete();

		//global $project_node;
		//$new_value = "Changed title for dummy link to test set_field";

		//$this->drupal->set_field(
			//$project_node,
			//$new_value,
			//'field_tapas_links',
			//'url',
			//2);
	//}

	public function test_set_field_using_defaults()
	{
		global $project_node;
		$node = $project_node; // so as not to change the global
		$new_value = "changed_slug_to_test_set_function";

		$this->drupal->set_field(
			$node,
			$new_value,
			'field_tapas_slug'
		);

		$values = $this->drupal->get_field_values(
			$node,
			'field_tapas_slug'
		);

		$this->assertEquals($new_value, $values->current());

	}

	public function test_set_field_custom_column()
	{
		global $project_node;
		$node = $project_node; // so as not to change the global
		$new_value = 99;

		$this->drupal->set_field(
			$node,
			$new_value,
			'field_tapas_thumbnail',
			'fid'
		);

		$values = $this->drupal->get_field_values(
			$node,
			'field_tapas_thumbnail'
		);

		$this->assertEquals($new_value, $values->current('fid'));
	}

	public function test_set_field_custom_delta()
	{
		global $project_node;
		$node = $project_node; // so as not to change the global.
		$new_second_value = 'Different dummy for different test';

		$this->drupal->set_field(
			$node,
			$new_second_value,
			'field_tapas_links',
			'title',
			1
		);

		$values = $this->drupal->get_field_values(
			$node,
			'field_tapas_links',
			'title'
		);

		$first_value =  "Sally Mitchell's Dinah Mulock Craik on the Victorian Web";

		$this->assertEquals($first_value, $values->current());
		$values->next();
		$this->assertEquals($new_second_value, $values->current());

		// also test with the by_index function
		$values->rewind();
		$this->assertEquals($new_second_value, $values->by_index(1));

	}


	public function  test_create_record()
	{
		$this->markTestIncomplete();
	}

	public function test_groups_this_user_is_in()
	{
		$this->markTestIncomplete();
	}

	public function test_roles_this_user_has()
	{
		$this->markTestIncomplete();
	}

	public function test_user_memebers_of_this_group()
	{
		$this->markTestIncomplete();
	}

	public function test_ungroup_node()
	{
		$this->markTestIncomplete();
	}

	public function test_parent_nodes_by_tye()
	{
		$this->markTestIncomplete();
	}
}
