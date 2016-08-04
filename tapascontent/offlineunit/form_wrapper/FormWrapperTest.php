<?php

/**
 * @file
 * FormWrapperTest.php
 *
 * Offline unit tests for the FormWrapper classes.
 */

include_once('offlineunit/commonunit.php');

abstract class Tapascontent_FormWrapper_TestCase
extends Tapascontent_UnitTestCase
{
	protected $factory;

	public function setUp()
	{
		$this->factory = new Tapascontent_MockWrapperFactory();
	}

	public function test_form_validation_good()
	{
		$this->markTestIncomplete();
	}

	public function test_form_validation_bad()
	{

	}
}

abstract class Tapascontent_CreateNodeFormWrapper_TestCase
extends Tapascontent_FormWrapper_TestCase
{
	public function setUp()
	{
		parent::setUp();
	}

}

class Tapascontent_CreateRecordFormWrapper_TestCase
extends Tapascontent_CreateNodeFormWrapper_TestCase
{
	private $form;

	public function setUp()
	{
		parent::setUp();
	}

}

class Tapascontent_CreateCollectionFormWrapper_TestCase
extends Tapascontent_CreateNodeFormWrapper_TestCase
{
	public function setUp()
	{
		parent::setUp();
	}
}

class Tapascontent_CreateSharedFormWrapper_TestCase
extends Tapascontent_CreateNodeFormWrapper_TestCase
{
	
	public function setUp()
	{
		parent::setUp();
	}
}


class Tapascontent_CreateProjectFormWrapper_TestCase
extends Tapascontent_CreateNodeFormWrapper_TestCase
{
	public function setUp()
	{
		parent::setUp();
	}
}

// ==============================================================
//  Mock Forms
// ==============================================================

$create_record_form = array();

$create_shared_form = array();

$create_collection_form = array();

$create_project_form = array();

$create_record_invalid = array();

$create_shared_invalid = array();

$create_collection_invalid = array();

$create_project_invalid = array();
