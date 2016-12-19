<?php

/**
 * @file
 * RoleWrapperTest.php
 *
 * Offline unit tests for role-wrapper.
 */

include_once('offlineunit/comminunit.php');

class Tapascontent_RoleWrapper_TestCase
extends Tapascontent_UnitTestCase
{
	private $role;

	public function setUp()
	{
		$this->role = new MockRoleWrpper(128, TRUE);
	}

}


