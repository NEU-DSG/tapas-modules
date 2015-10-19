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

function tapascontent_apachesolr_index_record(&$document, $record){
  _add_tei_to_document($document, $record);
}

// Implements the apachesolr hook for changing the query sent to Solr.
// Necessary for searching multiple fields, weighting, sorting, etc.
function tapascontent_apachesolr_query_alter($query) { 
  $query->addParam('qf', ['label']);
  $query->addParam('qf', ['sm_field_tapas_display_auth']);
  $query->addParam('qf', ['sm_field_tapas_display_contrib']);
  $query->addParam('qf', ['dm_field_tapas_display_date']);
}

#------------------------------------------------------------------------------
# Helper functions
#------------------------------------------------------------------------------

function _add_tei_to_document(&$document, $record) {
  $file = $record->field_tapas_tei_file['und'][0]['uri'];

  if($file) {
    $string = strip_tags(file_get_contents($file));
    // Removes extra spaces, which cause indentation that 
    // doesn't look right once all of the xml tags are gone
    $one_space = preg_replace("/\040\040+/", " ", $string);
    // Removes extra newlines, allowing for one newline
    // between every two lines with some content
    $one_newline = preg_replace("/\n(\s*\n){2,}/", "\n\n", $one_space);

    $document->content = $one_newline; 
    $document->teaser  = _truncate_str($one_newline, 400);
  }
}

function _set_teaser_and_description(&$document, $node) {
  $fname = TAPAS_FIELD_PREFIX . 'description';
  $desc = tapas_simple_fieldval($node, $fname, '');
  $document->content = $desc;
  $document->teaser = _truncate_str($desc, 400);
}

// Truncates the string to the word nearest the specified character count:w
function _truncate_str($str, $char_count) { 
  if (strlen($str) > $char_count) { 
    $newstr = substr($str, 0, strrpos(substr($str, 0, $char_count), ' '));
    return("$newstr...");
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
