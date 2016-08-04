<?php
/**
 * @file
 * tapascontent_common.inc
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 3.0
 */


include_once 'tapascontent_repo.inc';

// ====================================================================================
// Content Types.
// ====================================================================================

/** Machine name of the Collection content type. */
define ('TAPAS_COLLECTION', 'tapas_collection');

/** Machine name of the Project content type. */
define ('TAPAS_PROJECT', 'tapas_project');

/** Machine name of the Shared Repository content type. */
define ('TAPAS_SHARED', 'tapas_shared');

/** Machine name of the TEI Record content type. */
define ('TAPAS_RECORD', 'tapas_record');

//=======================================================================
// Iterators
//=======================================================================

abstract class Tapascontent_aIterator
implements Iterator
{
	private $index = 0;

	public function key() { return $this->index; }
	public function next() { $this->index++; }
	public function rewind() { $this->index = 0; }

	public abstract function as_array();

	protected function increment_index() { $this->index++; }
}

/**
 * @class
 * Tapascontent_FieldValueIterator
 *
 * Allows iterating through a list of values from a Drupal field.
 */

class Tapascontent_FieldValueIterator
extends Tapascontent_aIterator
{
	private $field;
	private $column;

	public function __construct($field, $column='value') { 
			$this->field = $field; 
			$this->column = $column?:'value';
	}

	public function valid() { 
		$return_value = array_key_exists($this->key(), $this->field['und']);
		return array_key_exists($this->key(), $this->field['und']); 
	}

	public function current($column=NULL)
	{
		return $this->valid() ?
			$this->field['und'][$this->key()][$column?:$this->column] :
			NULL;
	}

	public function as_array($column=NULL)
	{
		//TODO: add test asserting that this successfully restores the prior state.
		$original_key = $this->key();
		$this->rewind();
		$values=[];
		while($this->valid()) { 
			$values[] = $this->current($column?:$this->column);
			$this->next();
		}
		$this->rewind();
		while($this->key() < $original_key) { $this->next(); }
		return $values;
	}

	public function by_index($index, $column=NULL) {
		$values = $this->as_array($column);
		return array_key_exists($index, $values)?$values[$index]:NULL;
	}
}


class Tapascontent_NodeIterator
extends Tapascontent_aIterator
{
	private $nodes = [];

	public function __construct($array_of_nodes)
	{
		$this->nodes = $array_of_nodes;
	}

	public function current() 
	{
		return $this->nodes[$this->key()];
	}

	public function valid() 
	{
		return (sizeof($this->nodes) > $this->key()); 
	}

	public function as_array()
	{
		$nid_array = array();
		foreach($this->nodes as $node)
		{
			if ($node) {
				$nid_array[] = $node['nid'];
			}
		}
		return $nid_array;
	}

}

// ==============================================================
// Wrapper ancestor
// ==============================================================

interface Tapascontent_iWrapper
{
	function __construct($drupal_connector);
	function drupal();
}


abstract class Tapascontent_aWrapper 
{
	private $drupal;

	public function __construct($drupal_connector)
	{
		$this->drupal = $drupal_connector;
	}

	public function drupal() { return $this->drupal; }
}

// ==============================================================
// Factories
// ==============================================================

interface Tapascontent_iWrapperFactory
{
	function drupal();
	function repo();
	function wrap_user($uid);
	function wrap_form(&$form, &$form_state, $nid);
	function wrap_node($node);
	function wrap_node_ids($nids = []);
}

abstract class Tapascontent_aWrapperFactory
{
	private $drupal;
	private $repo;

	protected abstract function instantize_drupal_connector();
	protected abstract function instantize_repo_connector();

	public function __construct()
	{
		$this->drupal = $this->instantize_drupal_connector();
		$this->repo = $this->instantize_repo_connector();
	}

	public function drupal() { return $this->drupal; }
	public function repo() { return $this->repo; }

	public function wrap_user($uid)
	{
		return new Tapascontent_DrupalUser($this->drupal, $uid);
	}
	
	public function wrap_form(&$form, &$form_state, $nid)
	{
		return new Tapascontent_DrupalForm($this->drupal, $form, $form_state, $nid);
	}

	public function wrap_node($node)
	{
		switch ($node->type)
		{
			case TAPAS_PROJECT:
				$class = 'Tapascontent_ProjectNodeWrapper';
				break;
			case TAPAS_COLLECTION:
				$class = 'Tapascontent_CollectionNodeWrapper';
				break;
			case TAPAS_SHARED:
				$class = 'Tapascontent_SharedNodeWrapper';
				break;
			case TAPAS_RECORD:
				$class = 'Tapascontent_RecordNodeWrapper';
				break;
		}

		if (isset($class)) {
			return new $class($this->drupal, $this->repo, $node, $this);
		} else {
			return FALSE;
		}
	}

	public function wrap_node_ids($nids = [])
	{
		$node_array = [];
		foreach($nids as $nid) {
			$node_array[] = $this->drupal->node_load($nid);
		}

		return new Tapascontent_NodeIderator($node_array);
	}
}

class Tapascontent_WrapperFactory
extends Tapascontent_aWrapperFactory
{
	protected function instantize_drupal_connector()
	{
		return new Tapascontent_DrupalConnector($this);
	}

	protected function instantize_repo_connector()
	{
		return new Tapascontent_HydraConnector();
	}

}

class Tapascontent_MockWrapperFactory
extends Tapascontent_aWrapperFactory
{
	protected function instantize_drupal_connector()
	{
		return new Tapascontent_MockDrupalConnector($this);
	}

	protected function instantize_repo_connector()
	{
		return new Tapascontent_MockHydraConnector();
	}

}
