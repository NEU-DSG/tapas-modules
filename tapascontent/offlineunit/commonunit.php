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


//=====================================================================
// Sample Objects.
//=====================================================================


$project_node = [
	'vid' => 443,
  'uid' => 162,
  'title' => 'Digital Dinah Craik',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '94a4b88d-3571-4d80-b6c7-7480445a5747',
  'nid' => 443,
  'type' => 'tapas_project',
  'language' => 'und',
  'created' => 1445262348,
  'changed' => 1458833925,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '9756885e-1131-4494-adee-cf914dddf701',
  'revision_timestamp' => 1458833925,
  'revision_uid' => 11,
  'field_tapas_description' => [
		'und' => [
				'0' => [
					'value' => "This project aims to make a TEI-encoded edition of the letters
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
							We welcome feedback as we refine our work.",

					'format' => 'filtered_html',
					'safe_value' => "This project aims to make a TEI-encoded edition of the 
							letters and diaries of popular Victorian novelist Dinah Mulock Craik 
							available for the first time. Over 1,000 letters and 14 years of diaries 
							exist in archives across the US and the UK, including the University of 
							California at Los Angeles, Princeton University, the Harry Ransom Center 
							at the University of Texas at Austin, the British Library and the 
							National Library of Scotland. Craik's correspondence has never been 
							published before, and offers us insight into the material conditions 
							that could sustain a Victorian woman writer's career for upwards of 
							forty years.

							The TEI-transcriptions published here are currently works-in-progress. 
							We welcome feedback as we refine our work."

					] // '0'
				] // 'und'
			], // 'field_tapas_description
			'field_tapas_thumbnail' => [
				'und' => [
					'0' => [
						'fid' => 153,
						'uid' => 162,
						'filename' => 'Digital Dinah Craik-logo (1)_0.png',
						'uri' => 'public://Digital Dinah Craik-logo (1)_0.png',
						'filemime' => 'image/png',
						'filesize' => 8175,
						'status' => 1,
						'timestamp' => 1445262348,
						'uuid' => '64c2b6aa-b070-413b-80bf-43868c363032',
						'rdf_mapping' => [],
						'width' => 220,
						'height' => 180,
					] // '0'
				] // 'und'
			], // 'field_tapas_thumbnail'
			'field_tapas_slug' => [
				'und' => [
          '0' => [
						'value' => 'digitaldinahcraik',
						'safe_value' => 'digitaldinahcraik'
					 ] // '0'
				] // 'und'
			], // 'field_tapas_slug'
    'field_tapas_links' => [
      'und' => [
        '0' => [
          'url' => "http://www.victorianweb.org/authors/craik/mitchell/1.html",
          'title' =>  "Sally Mitchell's Dinah Mulock Craik on the Victorian Web",
          'attributes' => []
				], // '0'
				'1' => [
					'url' => "http://www.example.com",
					'title' => "Dummy second url for testing",
					'attributes' => []
				]
			] // 'und'
		], // field_tapas_links
    'group_group' => ['und' => ['0' => ['value' => 1]]],
    'group_access' => ['und' => ['0' => ['value'=> 0]]],
    'field_tapas_institution' => ['und' => ['0' => ['tid' => 50]]],
    'rdf_mapping' => [
			'rdftype' => [
							'0' => 'sioc:Item',
							'1' => 'foaf:Document'
			],
			'title' => ['predicates' => ['0' => 'dc:title']],
			'created' => [
				'predicates' => [
					'0' => 'dc:date',
					'1' => 'dc:created',
					'datatype' => 'xsd:dateTime',
					'callback' => 'date_iso8601'
				]
			],
			'changed' => [
				'predicates' => ['0' => 'dc:modified'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
			'body' => ['predicates' => ['0' => 'content:encoded']],
			'uid' => [
				'predicates' => ['0' => 'sioc:has_creator'],
				'type' => 'rel'
			],
			'name' => ['predicates' => ['0' => 'foaf:name']],
			'comment_count' => [
				'predicates' => ['0' => 'sioc:num_replies'],
				'datatype' => 'xsd:integer'
			],
			'last_activity' => [
				'predicates' => ['0' => 'sioc:last_activity_date'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601',
			],
			'path' => ['pathauto' => 0],
			'cid' => 0,
			'last_comment_timestamp' => 1445262348,
			'last_comment_uid' => 162,
			'comment_count' => 0,
			'name' => 'karen.bourrier',
			'picture' => 0,
			'data' => 'a:1:{s:7:"contact";i:1;}'
		] // 'rdf_mapping'
];

$shared_node = [

    'vid' => 544,
    'uid' => 162,
    'title' => 'Parrish Collection of Victorian Novelists at Princeton University',
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => 'xd6c3e8d-f56a-4f8a-9b9b-a2fa7bc3158f',
    'nid' => 544,
    'type' => 'tapas_shared',
    'language' => 'und',
    'created' => 1445262415,
    'changed' => 1445262415,
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'xeb53f1c-bcac-41fb-84d4-f5cb97a1a46c',
    'revision_timestamp' => 1445262415,
    'revision_uid' => 162,
    'field_tapas_description' => [
			'und' => [
        '0' => [
          'value' => "The Morris L. Parrish Collection of Victorian Novelists,
						held at Princeton University, contains over 200 letters from Dinah
						Craik to friends, family, and publishers. Highlights of the 
						collection include letters from Craik to the Brownings, Oscar Wilde, 
						and John Ruskin. Most importantly, the collection sheds light on her 
						relationship with the Harper Brothers publishing firm in New York, 
						and on the serialization of her work in Good Words. Because the 
						letters were collected by a single man and then donated to the 
						archive after his death, the collection is miscellaneous, and does 
						not contain many consecutive letters. Thanks to Princeton University
						for permission to share these TEI-transcriptions.

						Craik, Dinah Maria Mulock; 1826-1887; M. L. Parrish Collection of 
						Victorian Novelists (C0171), Manuscripts Division, Department of Rare 
						Books and Special Collections, Princeton University Library.",

          'format' => 'filtered_html',
          'safe_value' => "The Morris L. Parrish Collection of Victorian Novelists, 
						held at Princeton University, contains over 200 letters from Dinah 
						Craik to friends, family, and publishers. Highlights of the 
						collection include letters from Craik to the Brownings, Oscar Wilde,
						and John Ruskin. Most importantly, the collection sheds light on her 
						relationship with the Harper Brothers publishing firm in New York, 
						and on the serialization of her work in Good Words. Because the 
						letters were collected by a single man and then donated to the 
						archive after his death, the collection is miscellaneous, and does 
						not contain many consecutive letters. Thanks to Princeton University 
						for permission to share these TEI-transcriptions.
							
						Craik, Dinah Maria Mulock; 1826-1887; M. L. Parrish Collection of 
						Victorian Novelists (C0171), Manuscripts Division, Department of Rare 
						Books and Special Collections, Princeton University Library.",
				] // '0'
			] // 'und'
		], // 'field_tapas_description
    'field_tapas_thumbnail' => [
      'und' => [
        '0' => [
					'fid' => 154,
					'uid' => 162,
					'filename' => 'Digital Dinah Craik-logo (1)_0.png',
					'uri' => 'public://Digital Dinah Craik-logo (1)_0_0.png',
					'filemime' => 'image/png',
					'filesize' => 8175,
					'status' => 1,
					'timestamp' => 1445262415,
					'uuid' => '0d3c0c24-3220-4016-bd5c-a88a402e3ab7',
					'rdf_mapping' => [],
					'width' => 220,
					'height' => 180
				] // '0'
			] // 'und'
		], // 'field_tapas_thumbnail
    'field_tapas_slug' => [
      'und' => [
        '0' => [
					'value' => 'parrishcollection',
					'safe_value' => 'parrishcollection'
				]
			]
		],
    'group_group' => ['und' => ['0' => ['value' => 1]]],
    'group_access' => ['und' => ['0' => ['value' => 0]]],
    'rdf_mapping' => [
			'rdftype' => [
				'0' => 'sioc:Item',
				'1' => 'foaf:Document'
			],
			'title' => ['predicates' => ['0' => 'dc:title']],
			'created' => [
				'predicates' => [
					'0' => 'dc:date',
					'1' => 'dc:created',
				],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
			'changed' => [
				'predicates' => ['0' => 'dc:modified'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
			'body' => ['predicates' => ['0' => 'content:encoded']],
			'uid' => [
				'predicates' => ['0' => 'sioc:has_creator'],
				'type' => 'rel'
			],
			'name' => ['predicates' => ['0' => 'foaf:name']],
			'comment_count' => [
				'predicates' => ['0' => 'sioc:num_replies'],
				'datatype' => 'xsd:integer'
			],
			'last_activity' => [
				'predicates' => ['0' => 'sioc:last_activity_date'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			]
		], // 'rdf_mapping'
    'cid' => 0,
    'last_comment_timestamp' => 1445262415,
    'last_comment_name' => '',
    'last_comment_uid' => 162,
    'comment_count' => 0,
    'name' => 'karen.bourrier',
    'picture' => 0,
    'data' => 'a:1:{s:7:"contact";i:1;}',
];

$collection_node = [

    'vid' => 444,
    'uid' => 162,
    'title' => 'Parrish Collection of Victorian Novelists at Princeton University',
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '4d6c3e8d-f56a-4f8a-9b9b-a2fa7bc3158f',
    'nid' => 444,
    'type' => 'tapas_collection',
    'language' => 'und',
    'created' => 1445262415,
    'changed' => 1445262415,
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'aeb53f1c-bcac-41fb-84d4-f5cb97a1a46c',
    'revision_timestamp' => 1445262415,
    'revision_uid' => 162,
    'field_tapas_description' => [
			'und' => [
        '0' => [
          'value' => "The Morris L. Parrish Collection of Victorian Novelists,
						held at Princeton University, contains over 200 letters from Dinah
						Craik to friends, family, and publishers. Highlights of the 
						collection include letters from Craik to the Brownings, Oscar Wilde, 
						and John Ruskin. Most importantly, the collection sheds light on her 
						relationship with the Harper Brothers publishing firm in New York, 
						and on the serialization of her work in Good Words. Because the 
						letters were collected by a single man and then donated to the 
						archive after his death, the collection is miscellaneous, and does 
						not contain many consecutive letters. Thanks to Princeton University
						for permission to share these TEI-transcriptions.

						Craik, Dinah Maria Mulock; 1826-1887; M. L. Parrish Collection of 
						Victorian Novelists (C0171), Manuscripts Division, Department of Rare 
						Books and Special Collections, Princeton University Library.",

          'format' => 'filtered_html',
          'safe_value' => "The Morris L. Parrish Collection of Victorian Novelists, 
						held at Princeton University, contains over 200 letters from Dinah 
						Craik to friends, family, and publishers. Highlights of the 
						collection include letters from Craik to the Brownings, Oscar Wilde,
						and John Ruskin. Most importantly, the collection sheds light on her 
						relationship with the Harper Brothers publishing firm in New York, 
						and on the serialization of her work in Good Words. Because the 
						letters were collected by a single man and then donated to the 
						archive after his death, the collection is miscellaneous, and does 
						not contain many consecutive letters. Thanks to Princeton University 
						for permission to share these TEI-transcriptions.
							
						Craik, Dinah Maria Mulock; 1826-1887; M. L. Parrish Collection of 
						Victorian Novelists (C0171), Manuscripts Division, Department of Rare 
						Books and Special Collections, Princeton University Library.",
				] // '0'
			] // 'und'
		], // 'field_tapas_description
    'field_tapas_thumbnail' => [
      'und' => [
        '0' => [
					'fid' => 154,
					'uid' => 162,
					'filename' => 'Digital Dinah Craik-logo (1)_0.png',
					'uri' => 'public://Digital Dinah Craik-logo (1)_0_0.png',
					'filemime' => 'image/png',
					'filesize' => 8175,
					'status' => 1,
					'timestamp' => 1445262415,
					'uuid' => '0d3c0c24-3220-4016-bd5c-a88a402e3ab7',
					'rdf_mapping' => [],
					'width' => 220,
					'height' => 180
				] // '0'
			] // 'und'
		], // 'field_tapas_thumbnail
    'field_tapas_slug' => [
      'und' => [
        '0' => [
					'value' => 'parrishcollectionofvictoriannovelistsatprincetonuniversity',
					'safe_value' => 'parrishcollectionofvictoriannovelistsatprincetonuniversity'
				]
			]
		],
    'group_group' => ['und' => ['0' => ['value' => 1]]],
    'group_access' => ['und' => ['0' => ['value' => 0]]],
    'og_tapas_c_to_p' => ['und' => ['0' => [ 'target_id' => 443]]],
    'field_tapas_parent_slug' => [],
    'rdf_mapping' => [
			'rdftype' => [
				'0' => 'sioc:Item',
				'1' => 'foaf:Document'
			],
			'title' => ['predicates' => ['0' => 'dc:title']],
			'created' => [
				'predicates' => [
					'0' => 'dc:date',
					'1' => 'dc:created',
				],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
			'changed' => [
				'predicates' => ['0' => 'dc:modified'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
			'body' => ['predicates' => ['0' => 'content:encoded']],
			'uid' => [
				'predicates' => ['0' => 'sioc:has_creator'],
				'type' => 'rel'
			],
			'name' => ['predicates' => ['0' => 'foaf:name']],
			'comment_count' => [
				'predicates' => ['0' => 'sioc:num_replies'],
				'datatype' => 'xsd:integer'
			],
			'last_activity' => [
				'predicates' => ['0' => 'sioc:last_activity_date'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			]
		], // 'rdf_mapping'
    'cid' => 0,
    'last_comment_timestamp' => 1445262415,
    'last_comment_name' => '',
    'last_comment_uid' => 162,
    'comment_count' => 0,
    'name' => 'karen.bourrier',
    'picture' => 0,
    'data' => 'a:1:{s:7:"contact";i:1;}',
];

$record_node = [

    'vid' => 602,
    'uid' => 162,
    'title' => 'Letter from Dinah Mulock Craik to Mrs. Valentine, post-1865.',
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'vuuid' => '850dc50c-573c-425d-aa73-7a8770051788',
    'nid' => 602,
    'type' => 'tapas_record',
    'language' => 'und',
    'created' => 1445538754,
    'changed' => 1445891004,
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '66db1ec1-e708-4f17-b55d-3706c39ab13e',
    'revision_timestamp' => 1445891004,
    'revision_uid' => 16,
    'field_tapas_tei_file' => [
      'und' => [
        '0' => [
					'fid' => 322,
					'uid' => 162,
					'filename' => 'PU55.xml',
					'uri' => 'public://1445538741/tei/PU55.xml',
					'filemime' => 'application/xml',
					'filesize' => 5975,
					'status' => 1,
					'timestamp' => 1445538754,
					'uuid' => '866fb930-df69-48b0-8f9c-608a07195e06',
					'rdf_mapping' => [],
					'display' => 1,
					'description' => '',
				]
			]
		], // field_tapas_tei_file
    'field_tapas_attachments' => [],
    'field_tapas_display_auth' => [
      'und' => [
        '0' => [
					'value' => 'Craik, Dinah Mulock',
					'safe_value' => 'Craik, Dinah Mulock'
				],
				'1' => [
					'value' => 'dummy_second_author_for_testing',
					'safe_value' => 'dummy_second_author_for_testing',
				]
			]
		],
    'field_tapas_display_contrib' => [
      'und' => [
        '0' => [
					'value' =>  'Karen Bourrier',
					'safe_value' =>  'Karen Bourrier',
				]
			]
		],
    'field_tapas_display_date' => [
      'und' => [
        '0' => [
					'value' => '2015-10-22T18:30:00',
					'timezone' => 'America/New_York',
					'timezone_db' => 'America/New_York',
					'date_type' => 'date'
				]
			]
		],
    'og_tapas_r_to_c' => ['und' => ['0' => ['target_id' => 444]]],
    'field_tapas_record_ography_type' => [],
    'field_tapas_parent_slug' => [
      'und' => [
        '0' => [
					'value' => 'digitaldinahcraik',
					'safe_value' => 'digitaldinahcraik',
				]
			]
		],
    'field_tapas_project' => ['und' => ['0' => ['target_id' => 443]]],
    'rdf_mapping' => [
      'rdftype' => [
        '0' => 'sioc:Item',
        '1' => 'foaf:Document'
			],
      'title' => [
        'predicates' => ['0' => 'dc:title']
			],
      'created' => [
        'predicates' => [
					'0' => 'dc:date',
					'1' => 'dc:created',
				],
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601'
			],
      'changed' => [
        'predicates' => ['0' => 'dc:modified'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
			],
      'body' => ['predicates' => ['0' => 'content:encoded']],
      'uid' => [
				'predicates' => ['0' => 'sioc:has_creator']],
				'type' => 'rel'
			],
      'name' => ['predicates' => ['0' => 'foaf:name']],
      'comment_count' => [
        'predicates' => ['0' => 'sioc:num_replies'],
        'datatype' => 'xsd:integer'
			],
      'last_activity' => [
        'predicates' => ['0' => 'sioc:last_activity_date'],
				'datatype' => 'xsd:dateTime',
				'callback' => 'date_iso8601'
		], // rdf_mapping
    'path' => ['pathauto' => 1],
    'cid' => 0,
    'last_comment_timestamp' => 1445538754,
    'last_comment_uid' => 162,
    'comment_count' => 0,
    'name' => 'karen.bourrier',
    'picture' => 0,
    'data' => 'a:1:{s:7:"contact";i:1;}',

];
