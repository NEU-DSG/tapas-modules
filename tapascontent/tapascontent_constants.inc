<?php
/**
 * @file
 * TAPAS constants and utility functions.
 *
 * Functions useful to more than one tapas module and that are not
 * module specific go here, as do project-wide constnts.
 *
 * @author Linda Moss (github LindaJeanne) <l.moss@neu.edu>
 * @since 2.0
 * @version 2.0
 */

// ====================================================================================
// Prefixes for fields and field instances.
// ====================================================================================

/** Prefix used on all tapasfield base names. */
define ('TAPAS_FIELD_PREFIX', 'field_tapas_');
/** Prefix used by all Collection field instances. */
define ('TAPAS_C_INSTANCE_PRE', 'fi_tapas_c_');
/** Prefix used by all project field instances. */
define ('TAPAS_P_INSTANCE_PRE', 'fi_tapas_p_');
/** Prefic before sll tapasrecord field instances. */
define ('TAPAS_R_INSTANCE_PRE', 'fi_tapas_r_');

// ====================================================================================
// Content Types.
// ====================================================================================

/** Machine name of the Collection content type. */
define ('TAPAS_COLLECTION', 'tapas_collection');

/** Machine name of the Project content type. */
define ('TAPAS_PROJECT', 'tapas_project');

/** Machine name of the TEI Record content type. */
define ('TAPAS_RECORD', 'tapas_record');


// ====================================================================================
// Organc Groups.
// ====================================================================================

/** Field name for collection-to-project OG audience link*/
define ('TAPAS_C_TO_P', 'og_tapas_c_to_p');
/** FIeld name for record-to-collection OG audience link */
define ('TAPAS_R_TO_C', 'og_tapas_r_to_c');


// ====================================================================================
// Images.
// ====================================================================================
define ('TAPAS_C_DEFAULT_IMAGE', 0);
define ('TAPAS_P_DEFAULT_IMAGE', 0);

define ('TAPAS_C_IMAGE_DIR', '');
define ('TAPAS_P_IMAGE_DIR', '');

define ('TAPAS_THUMB_MAX_FILESIZE', '');
define ('TAPAS_THUMB_MAX_RES', '');
define ('TAPAS_THUMB_MIN_RES', '');

define ('TAPAS_THUMB_PREVIEW_STYLE', 'thumbnail');
define ('TAPAS_THUMB_PROGRESS_IND', 'throbber');

// ====================================================================================
// Other Files.
// ====================================================================================

define ('TAPAS_FILE_MAXSIZE', 128);

// ====================================================================================
// Field Instance Descriptions.
// ====================================================================================
define ('TAPAS_INSTANCE_DESC_TAGS', '');
define ('TAPAS_INSTANCE_DESC_MIGRATIONTITLE', '');
define ('TAPAS_INSTANCE_DESC_MIGRATIONIMAGE', '');
define ('TAPAS_INSTANCE_DESC_MIGRATIONINST', '');

define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', '');
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', '');
define ('TAPAS_INSTANCE_DESC_PROJSLUG', '');
define ('TAPAS_INSTANCE_DESC_INSTITUTIONS', '');
define ('TAPAS_INSTANCE_DESC_PROJLINKS', '');

define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', '');
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', '');
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', '');
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', '');

define ('TAPAS_INSTANCE_DESC_PERSISTID', '');
define ('TAPAS_INSTANCE_DESC_TEIFILE', '');
define ('TAPAS_INSTANCE_DESC_ATTATCH', '');
define ('TAPAS_INSTANCE_DESC_AUTHORS', '');
define ('TAPAS_INSTANCE_DESC_CONTRIBUTORS', '');
define ('TAPAS_INSTANCE_DESC_DISPLAYDATE', '');

// ====================================================================================
// Content Type Descriptions
// ====================================================================================

define ('TAPAS_CONTENT_PROJ_DESC', '');
define ('TAPAS_CONTENT_COLL_DESC', '');
define ('TAPAS_CONTENT_REC_DESC', '');

define ('TAPAS_CONTENT_PROJ_HELP', '');
define ('TAPAS_CONTENT_COLL_HELP', '');
define ('TAPAS_CONTENT_REC_HELP', '');

// ====================================================================================
//  Hydra API.
// ====================================================================================

// include_once('/var/www/hydratoken.php');
// define ('TAPAS_AUTH_TOKEN', HYDRA_API_KEY);
define ('TAPASHYDRA_AUTH_TOKEN', 'tapas12345');


define('TAPAS_BASE_API_URL', 'http://rails_api.localhost:8080');

define('TAPAS_POST_PROJECT_URL', TAPAS_BASE_API_URL . "/communities");
define('TAPAS_POST_COLLECTION_URL', TAPAS_BASE_API_URL . "/collections");
define('TAPAS_POST_TEI_URL', TAPAS_BASE_API_URL . "/files");

define('TAPAS_GET_RAW', 'tei');
define('TAPAS_GET_BP', 'teibp');
define('TAPAS_GET_GENERIC', 'tapas_generic');

define("TAPAS_INCLUDE_CURL_DEBUG", TRUE);
