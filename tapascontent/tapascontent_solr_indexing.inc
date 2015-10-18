<?php


// Implements the apachesolr hook that lets you modify the solr doc
// representation of your entity before its sent off for processing.
function tapascontent_apachesolr_index_document_build_node(ApacheSolrDocument $document, $node, $env_id) { 

  if ($node->type === TAPAS_PROJECT) { 
    tapascontent_apachesolr_index_project($document, $node); 
  } elseif ($node->type === TAPAS_COLLECTION) { 
    tapascontent_apachesolr_index_collection($document, $node); 
  } elseif ($node->type === TAPAS_RECORD) { 
    tapascontent_apachesolr_index_record($document, $node); 
  }
}

function tapascontent_apachesolr_index_project(&$document, $project) {
  _set_teaser_and_description($document, $project);
}

function tapascontent_apachesolr_index_collection(&$document, $collection) { 
  _set_teaser_and_description($document, $collection);
}

function tapascontent_apachesolr_index_record(&$document, $record) { 

}

// Implements the apachesolr hook for changing the query sent to Solr.
// Necessary for searching multiple fields, weighting, sorting, etc.
function tapascontent_apachesolr_query_alter($query) { 
  $query->addParam('qf', ['label']);
}

#------------------------------------------------------------------------------
# Helper functions
#------------------------------------------------------------------------------

function _set_teaser_and_description(&$document, $node) {
  $fname = TAPAS_FIELD_PREFIX . 'description';
  $desc = tapas_simple_fieldval($node, $fname, '');

  if (str_word_count($desc) > 200) { 
    $document->content = $desc; 
    $document->teaser = $desc;
  } else { 
    $document->content = $desc; 
    $document->teaser = $desc;
  }
}

// Doesn't work in boris, works fine in the project
// Immediately indexes the given node.
function _tapascontent_index_content($node) { 
  $env  = apachesolr_default_environment(); 
  _tapascontent_watchdog('indexing', WATCHDOG_NOTICE);
  $docs = apachesolr_convert_entity_to_documents($node, 'node', $env);
  apachesolr_index_send_to_solr($env, $docs); 
}
