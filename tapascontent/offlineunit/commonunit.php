<?php
/**
 * @file
 * commonunit.php
 *
 * This file contains the unit tests that don't require the installed Drupal environment.
 */

 include_once('tapascontent.module');
 include_once('tapascontent_common.inc');
 include_once('tapascontent_repo.inc');

 include_once('offlineunit/sample_nodes.inc');
 include_once('offlineunit/sample_forms.inc');

abstract class Tapascontent_UnitTestCase 
extends PHPUnit_Framework_TestCase 
{

	public function setUp() {
		parent::setUp();
	}

  /**
   * Fake enables a module for the purpose of a unit test
   *
   * @param $name
   *  The module's machine name (i.e. ctools not Chaos Tools)
	 *  (the DrupalUnitTestCase, does not have access to a database, 
	 *  so enabling a module the normal way is not available)
   */
  protected function enableModule($name) {
    $modules = module_list();
    $modules[$name] = $name;
    module_list(TRUE, FALSE, FALSE, $modules);
  }

	 /**
   * One can also add helper assert functions that might get used in tests
   *
   * This one test if the correct Exceptions is thrown (5.3 only)
   */
  protected function assertThrows(Closure $closure, $type, $error_message = NULL, $message) {
    try {
      $closure();
    }
    catch (Exception $e) {
      if (!($e instanceof $type)) {
        throw $e;
      }
      if (isset($error_message)) {
        if ($e->getMessage() != $error_message) {
          $this->fail($message, "SPS");
          return;
        }
      }
      $this->pass($message, "SPS");
      return;
    }
    $this->fail($message, "SPS");
  }
 
	protected function assertIsValidNode($name, $node) { // TODO
		$this->markTestIncomplete("Node validation function not yet implemented.");
	}

}

