<?php

/**
 * @file
 * DrupalConnectorTest.php
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

	public function  test_create_record()
	{
		$this->markTestIncomplete();
	}
}
