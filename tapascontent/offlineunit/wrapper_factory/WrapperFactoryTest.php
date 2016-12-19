<?php

/**
 * @file
 * WrapperFactoryTest.php
 *
 * Offline unit tests for the WrapperFactory classes
 *
 * Unit tests which are not dependent on Drupal or Hydra being
 * set up or reachable.
 */

// TODO: Unit tests for drupal connector.
// TODO: figure out what order the unit test files should run in, and rename so they will fire in that order.
include_once('offlineunit/commonunit.php');
include_once('tapascontent_nodewrapper.inc');

abstract class Tapascontent_aWrapperFactory_TestCase
extends Tapascontent_UnitTestCase
{
	protected $factory;

	public function setUp()
	{
		$this->factory = new Tapascontent_MockWrapperFactory();
	}

	public function test_drupal_getter()
	{
		$drupal = $this->factory->drupal();
		$this->assertInstanceOf('Tapascontent_aDrupalConnector', $drupal);
	}

	public function test_repo_getter()
	{
		$repo = $this->factory->repo();
		$this->assertInstanceOf('Tapascontent_aHydraConnector', $repo);
	}
}

class Tapascontent_FactoryUserWrapper_TestCase
extends Tapascontent_aWrapperFactory_TestCase
{
	public function test_wrap_user()
	{
		$this->markTestIncomplete();
	}

}

class Tapascontent_FactoryFormWrapper_TestCase
extends Tapascontent_aWrapperFactory_TestCase
{
	public function test_wrap_form()
	{
		$this->markTestIncomplete();
	}

}

class Tapascontent_FactoryNodeWrapper_TesstCase
extends Tapascontent_aWrapperFactory_TestCase
{

	public function test_wrap_node_ids()
	{
		$this->markTestIncomplete();
	}

	public function test_wrap_project_node()
	{
		global $project_node;
		$project = $this->factory->wrap_node($project_node);

		$this->assertInstanceOf(
			'Tapascontent_ProjectNodeWrapper',
			$project
		);
	}

	public function test_wrap_collection_node()
	{
		global $collection_node;
		$collection = $this->factory->wrap_node($collection_node);

		$this->assertInstanceOf(
			'Tapascontent_CollectionNodeWrapper',
			$collection
		);
	}

	public function test_wrap_shared_node()
	{
		global $shared_node;
		$shared = $this->factory->wrap_node($shared_node);
		
		$this->assertInstanceOf(
			'Tapascontent_SharedNodeWrapper',
			$shared
		);
	}

	public function test_wrap_record_node()
	{
		global $record_node;
		$record = $this->factory->wrap_node($record_node);

		$this->assertInstanceOf(
			'Tapascontent_RecordNodeWrapper',
			$record
		);
	}



	public function test_create_basic_record_node_no_tei()
	{
		$record_node = $this->factory->create_record_node(
			'Sample record title no tei'
		);	
		$this->assertTrue($record_node->validate());
	}

	public function test_create_basic_record_node_with_tei()
	{
		$this->markTestIncomplete();
		//TODO: Need get_sample_tei() type function
		$tei = '$this->get_sample_tei()';
		$record_node = $this->factory->create_record_node(
			'Sample record with tei',
			$tei
		);
		$this->assertTrue($record_node->validate());
	}

	//public function test_create_record_with_attatchments() //TODO
	//public function test_create_record_with_ography_links() //TODO
	//public function test_create_record_with_attatchments_and_ography() //TODO
	public function test_create_shared_node()
	{

		$this->markTestIncomplete();
	}

	public function test_create_project_node()
	{

		$this->markTestIncomplete();
	}

	public function test_create_collection_node()
	{

		$this->markTestIncomplete();
	}

}


