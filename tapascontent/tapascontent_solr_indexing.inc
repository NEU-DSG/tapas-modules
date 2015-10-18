<?php

function tapascontent_apachesolr_index_document_build_node(ApacheSolrDocument $document, $node, $env_id) { 
  _tapascontent_watchdog('solr index hook fired', WATCHDOG_NOTICE);

  if ($node->type === 'tapas_project') { 
    tapascontent_apachesolr_index_project($document, $node); 
  } elseif ($node->type === 'tapas_collection') { 
    tapascontent_apachesolr_index_collection($document, $node); 
  } elseif ($node->type === 'tapas_record') { 
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
