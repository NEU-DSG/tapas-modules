<?php
/**
 * @file
 * tapas_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tapas_project_taxonomy_default_vocabularies() {
  return array(
    'institution_names' => array(
      'name' => 'Institution Names',
      'machine_name' => 'institution_names',
      'description' => 'Having this as a vocabulary in addition to the content type so that users can easily add an affiliation that doesn\'t have an Ins',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
