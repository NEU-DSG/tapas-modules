<?php

/**
 * @file
 * QueryTest.php
 *
 * Offline Unit Tests for Query subclasses.
 */

include_once('offlineunit/commonunit.php');

class Tapascontent_Query_TestCase
extends Tapascontent_UnitTestCase
{
	protected $factory;

	protected $project;
	protected $collection;
	protected $shared;
	protected $record;

	public function setUp()
	{
		$f = new Tapascontent_MockWrapperFactory();
		$this->factory = $f;

		global $project_node;
		global $collection_node;
		global $shared_node;
		global $record_node;

		$this->project = $f->wrap_node($project_node);
		$this->colelction = $f->wrap_node($collection_node);
		$this->shared = $f->wrap_node($shared_node);
		$this->record = $f->wrap_node($record_node);
	}

	protected function common_query_checks($query)
	{
		$this->assertInstanceOf('Tapascontent_aQuery', $query);

		$this->assertObjectHasAttribute('options', $query);
		$this->assertObjectHasAttribute('postfields', $query);
		$this->assertObjectHasAttribute('record_type', $query);

		$this->assertArrayHasKey('uniquid', $query->postfields);
		$this->assertArrayHasKey('depositor', $query->postfields);
		
	}

	public function test_create_upsert_project_query()
	{
		$query = new Tapascontent_UpsertQuery(
			$this->project->get_repo_data(),
			Tapascontent_aHydraConnector::TYPE_COMMUNITY);


		$this->common_query_checks($query);

		$this->assertEquals('/communities', $query->record_type);
		$this->assertEquals("base/communities", $query->build_url('base'));
		$this->assertEquals(162, $query->postfields['depositor']);
		$this->assertEquals(
			'9756885e-1131-4494-adee-cf914dddf701', 
			$query->postfields['uniquid']);
	}

}

class Tapascontent_UpsertProjectQuery_TestCase
extends Tapascontent_Query_TestCase
{
	private $query;
	public function setUp() {
		parent::setUp();
		$this->query = new Tapascontent_UpsertQuery(
			$this->project->get_repo_data(),
			Tapascontent_aHydraConnector::TYPE_COMMUNITY);
	}

	public function test_project_upsert_query_common_query_checks()
	{
		$this->common_query_checks($this->query);
	}

	public function test_project_upsert_query_record_type()
	{
		$this->assertEquals('/communities', $this->query->record_type);
	}

	public function test_project_upsert_query_url()
	{
		$this->assertEquals('base/communities', $this->query->build_url('base'));
	}

	public function test_project_upsert_query_depositor()
	{
		$this->assertEquals(162, $this->query->postfields['depositor']);
	}

	public function test_project_upsert_query_uuid()
	{
		$this->assertEquals(
			'9756885e-1131-4494-adee-cf914dddf701', 
			$this->query->postfields['uniquid']);
	}

	public function test_project_upsert_query_title()
	{
		$this->assertEquals('Digital Dinah Craik', $this->query->postfields['title']);
	}

	public function test_project_upsert_query_description()
	{
		$description = "This project aims to make a TEI-encoded edition of the letters
				and diaries of popular Victorian novelist Dinah Mulock Craik available 
				for the first time. Over 1,000 letters and 14 years of diaries exist in 
				archives across the US and the UK, including the University of 
				California at Los Angeles, Princeton University, the Harry Ransom 
				Center at the University of Texas at Austin, the British Library and 
				the National Library of Scotland. Craik's correspondence has never 
				been published before, and offers us insight into the material 
				conditions that could sustain a Victorian woman writer's career for 
				upwards of forty years.

				The TEI-transcriptions published here are currently works-in-progress. 
				We welcome feedback as we refine our work.";

		$actual = $this->query->postfields['description'];

		$this->assertEquals($description, $actual);
	}

	public function test_project_upsert_query_access()
	{
		$actual = $this->query->postfields['access'];
		$this->assertEquals('public', $actual);
	}
	/**
	 * Intentionlally not checked (because we'd ONLY be checking the mock):
	 *   - thumb file 
	 *	 - project members
	 */
}

