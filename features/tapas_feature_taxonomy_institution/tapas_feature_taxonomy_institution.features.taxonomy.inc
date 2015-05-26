<?php
/**
 * @file
 * tapas_feature_taxonomy_institution.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tapas_feature_taxonomy_institution_taxonomy_default_vocabularies() {
  return array(
    'institution' => array(
      'name' => 'Institution',
      'machine_name' => 'institution',
      'description' => 'A vocabulary of institutions that have contributed to TAPAS.',
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
