<?php


/**
 * @file
 *
 * Holds the taxonomy terms that the build script will populate
 * the taxonomies with, allong with assorted other information.
 */

/**
 * Populates the Institution taxonomy
 */

function importtaxonomies_import_institution() {
	
	drupal_set_message("import taxonomies function called");

	$taxo_list = taxonomy_vocabulary_get_names();
	
	drupal_set_message(implode(',', $taxo_list), 'status');
/*	
	$vid = array_search('tapas_institution', $taxo_list);
	
	$base_array = array(
		'vid' => $vid,
		'format' => 'filtered_html',
		'vocabulary_machine_name' => 'tapas_institution',
	);

	drupal_set_message( implode(',', $base_array), 'status');

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "AIUCD",
	)));

*/



/*
	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "American Antiquarian Society",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Beck Center",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Berlin, Germany",
		"field_institution_address" => "Berlin, Germany",
		"field_institution_latitude" => "52.5192",
		"field_institution_longitude" => "13.4061",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Biblioteca Borgesiensis",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Bodleian Libraries",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Brandeis University",
		"description" => "Located in historic Providence, Rhode Island and founded in 1764, Brown University is the seventh-oldest college in the United States. Brown is an independent, coeducational Ivy League institution comprising undergraduate and graduate programs.",
		"field_institution_address" => "University\r\n101 Waterman St\r\n02912 Providence, RI\r\nUnited States",
		"field_institution_latitude" => "41.83",
		"field_institution_longitude" => "-71.4",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Brown University",
		"description" => "Located in historic Providence, Rhode Island and founded in 1764, Brown University is the seventh-oldest college in the United States. Brown is an independent, coeducational Ivy League institution comprising undergraduate and graduate programs.",
		"field_university_address" => "University\r\n101 Waterman St\r\n02912 Providence, RI\r\nUnited States",
		"field_institution_latitude" => "41.8273",
		"field_institution_longitude" => "-71.4002",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "California State University, Northridge",
		"field_institution_address" => "California State University, Northridge\r\n18111 Nordhoff Street\r\n91330 Northridge, CA\r\nUnited State",
		"field_institution_latitude" => "34.236",
		"field_institution_longitude" => "-118.528",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Center for Portuguese Literature at the University of Coimbra",
		"description" => "The Centre for Portuguese Literature (CLP) is a Unit of Research and Development funded by the Science and Technology Foundation (FCT) since 2003. The Centre is located at the School of Arts and Humanities at the University of Coimbra, and it includes researchers based both at the University of Coimbra and at other research institutions.",
		"field_institution_address" => "Faculdade de Letras da Universidade de Coimbra 3004-530 Coimbra\r\nPortugal",
		"field_institution_latitude" => "40.2084",
		"field_institution_longitude" => "-8.42529",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "College at Geneseo",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "CUNY",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Dickinson College",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Emory University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Friends Historical Library of Swarthmore College",
		"description" => "Friends Historical Library was established in 1871 to collect, preserve, and make available archival, manuscript, printed, and visual records concerning the Religious Society of Friends (Quakers) from their origins mid-seventeenth century to the present. The collection reflects the Quaker origins of Swarthmore College. With more than 45,000 books, pamphlets and serials, 60,000 photographs, 400 major manuscript collections, and 9,000 volumes of original meeting records, Friends Historical Library is one of the outstanding research facilities for the study of Quaker history. The Library also maintains the Swarthmore College Archives and the papers of the Swarthmore Historical Society.",
		"field_institution_address" => "Friends Historical Library\r\n500 College Avenue Swarthmore College\r\n19081 Swarthmore, PA\r\nUnited States",
		"field_institution_latitude" => "39.9065",
		"field_institution_longitude" => "-75.352",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Georgia Regents University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Hamilton College",
		"description" => "Hamilton is a liberal arts college situated on a hilltop overlooking the picturesque village of Clinton in central New York state. The mission of the college is to provide an educational experience that emphasizes academic excellence and the development of students as human beings.",
		"field_institution_address" => "Hamilton College\r\n198 College Hill Road\r\n13323 Clinton, NY\r\nUnited States",
		"field_institution_latitude" => "43.0531",
		"field_institution_longitude" => "-75.4089",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "IMF",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Indiana University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Indiana University Libraries",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Indiana University, Bloomington",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Jožef Stefan Institute",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "King's College London",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Kyoto University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Lou Burnard Consulting",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Loyola University Maryland",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Massachusetts",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Massachusetts Historical Society",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "New York Public Library",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Northeastern University",
		"field_institution_address" => "Northeastern University\r\n360 Huntington Ave.\r\n02115 Boston, MA\r\nUnited States",
		"field_institution_longitude" => "-71.0892",
		"field_institution_latitude" => "42.3398",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "NYU Libraries",
		"field_institution_address" => "NYU Libraries\r\n838 Broadway Suite 504\r\n10003 New York, NY\r\nUnited States",
		"field_institution_latitude" => "40.7144",
		"field_institution_longitude" => "-74.006",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Okanagan",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Penn State",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Pennsylvania State University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Pompeu Fabra University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Pompeu Fabra University, Department of Humanities",
		"field_institution_address" => "Universitat Pompeu Fabra\r\nRamon Trias Fargas, 25-27\r\n08005 Barcelona, BA\r\nSpain",
		"field_institution_latitude" => "41.3896",
		"field_institution_longitude" => "2.1914",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Portland State University",
		"field_institution_address" => "Portland, OR\r\nUnited States",
		"field_institution_latitude" => "45.5235",
		"field_institution_longitude" => "-122.676",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Princeton University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Providence College",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Quack College",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Ryerson University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Simmons College",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "State University of New York",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "TAPAS",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Texas A&M University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "The Graduate Center, CUNY",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "The Ohio State University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "UCLA Digital Library Program",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "Universidade de Santiago de Compostela",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of British Columbia",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Calgary",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of California - Berkeley",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Illinois at Urbana-Champaign",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Oregon",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Oxford",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Pennsylvania",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Pittsburgh at Greensburg",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Texas",
		"field_institution_address" => "Austin, TX\r\nUnited States",
		"field_institution_latitude" => "30.2672",
		"field_institution_longitude" => "-97.7431",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Toronto",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Tulsa",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
		"name" => "University of Virginia",
	"description" => "Thomas Jefferson founded the University of Virginia in 1819. He wished the publicly-supported school to have a national character and stature. Jefferson envisioned a new kind of university, one dedicated to educating leaders in practical affairs and public service rather than for professions in the classroom and pulpit exclusively. It was the first nonsectarian university in the United States and the first to use the elective course system.\r\n\r\nJefferson considered the founding of the University to be one of his greatest achievements. Undertaking the project toward the end of his life—after a long, illustrious career that included serving as a colonial revolutionary, political leader, writer, architect, inventor, and horticulturalist—he was closely involved in the University's design. He planned the curriculum, recruited the first faculty, and designed the Academical Village, a terraced green space surrounded by residential and academic buildings, gardens, and the majestic center-point—the Rotunda. The most recognizable symbol of the University, the Rotunda stands at the north end of the Lawn and is half the height and width of the Pantheon in Rome, which was the primary inspiration for the building. The Lawn and the Rotunda have served as models for similar designs of &quot;centralized green areas&quot; at universities across the United States.\r\n\r\nThe University opened for classes in 1825 with a faculty of eight and a student body numbering sixty-eight. Jefferson took great pains to recruit the most highly qualified faculty, five of whom were found in England and three in the United States. Instruction was offered in ancient languages, modern languages, mathematics, moral philosophy, natural philosophy, chemistry, law, and medicine. The students came from the American South and West; interestingly, though, most were not Virginians.\r\n\r\nJefferson opposed the granting of degrees on the grounds that they were &quot;artificial embellishments.&quot; In 1824, however, the Board of Visitors authorized granting the master of arts degree. The doctor of medicine, or M.D., was awarded to the first graduates of the School of Medicine in 1828, and the bachelor of laws degree, or LL.B., was first awarded for law school graduates in 1842. The bachelor's degree was awarded beginning in 1849, but became the standard undergraduate degree and a prerequisite for the master's degree in 1899, bringing the University into conformity with other institutions of higher learning. The Ph.D. has been awarded since 1883.",
	"field_institute_address" => "22904 Charlottesville, VA\r\nUnited States",
	"field_institute_latitude" => "38.034",
	"field_institute_longitude" => "-78.5103",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "University of Warsaw",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "University of Würzburg",
	"description" => "The &quot;Julius-Maximilians-Universität Würzburg&quot;, as the official name goes, is a university in Würzburg, Germany, founded in 1402. For more information, see https://en.wikipedia.org/wiki/University_of_W%C3%BCrzburg",
	"field_institute_address" => "Sanderring 2\r\n97070 Würzburg\r\nGermany",
	"field_institute_latitude" => "49.7882",
	"field_institute_longitude" => "9.93526",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "Vassar College",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "Washington and Lee University",
	"description" => "Washington and Lee is a small, private, liberal arts university nestled between the Blue Ridge and Allegheny Mountains in Lexington, Va. It is the ninth oldest institution of higher learning in the nation.",
	"field_institution_address" => "204 W. Washington\r\n24450 Lexington, VA\r\nUnited States",
	"field_institution_latitude" => "37.7914",
	"field_institution_longitude" => "-79.444",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "Wheaton College",
	"description" => "Wheaton was founded in 1834 as a female seminary and chartered as a four-year liberal arts college in 1912. The college became coeducational in 1988, and its Phi Beta Kappa chapter was established in 1932.\r\n\r\nLocated in Norton, Massachusetts, between Boston and Providence, R.I, Wheaton's residential campus is one of the most beautiful in New England. Prospective students and visitors often say our campus has a very relaxed feel. It's no wonder—we're a friendly community. With a 11:1 student-faculty ratio, students know their professors as teachers, advisors and often as friends. The campus is always buzzing with energy. Throughout the year, fun activities, celebrations and academic events keep people busy and connected.\r\n\r\nMission statement: Wheaton College provides a transformative liberal arts education for intellectually curious students in a collaborative, academically vibrant residential community that values a diverse world.",
	"field_institution_latitude" => "41.9673",
	"field_institution_longitude" => "-71.185",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "Willamette University",
	)));

	taxonomy_term_save((object)array_merge($base_array, array(
	"name" => "Yale",
	)));
*/		
}
