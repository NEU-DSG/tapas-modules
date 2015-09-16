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
/** Default thumbnail image for collections. */
define ('TAPAS_C_DEFAULT_IMAGE', 0);
/** Default thumbnail image for projects. */
define ('TAPAS_P_DEFAULT_IMAGE', 0);

/** Where (under files:/public) collection thumnails will be stored. */
define ('TAPAS_C_IMAGE_DIR', '');
/** Where (under files:/public) project thumnails will be stored. */
define ('TAPAS_P_IMAGE_DIR', '');

/** Maximum filesize allowed for uploaded project/collection thumbnails. */
define ('TAPAS_THUMB_MAX_FILESIZE', '');
/** Maximum resolution allowed for uploaded project/collection thumbnails. */
define ('TAPAS_THUMB_MAX_RES', '');
/** Minimum resolution required for project/collection thumbnails. */
define ('TAPAS_THUMB_MIN_RES', '');

/** Which style setting to use for thumbnails */
define ('TAPAS_THUMB_PREVIEW_STYLE', 'thumbnail');
/** Which cursor to use while uploading. */
define ('TAPAS_THUMB_PROGRESS_IND', 'throbber');

// ====================================================================================
// Other Files.
// ====================================================================================

/** Maximum filesize allowed for any uploaded file. */
define ('TAPAS_FILE_MAXSIZE', '');

// ====================================================================================
// Field Instance Descriptions.
// ====================================================================================

/*
 * The following constants are for the user-facing field descriptions for various
 * custom fields.
 */

define ('TAPAS_INSTANCE_DESC_TAGS', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONTITLE', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONIMAGE', t(''));
define ('TAPAS_INSTANCE_DESC_MIGRATIONINST', t(''));

define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_PROJSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_INSTITUTIONS', t(''));
define ('TAPAS_INSTANCE_DESC_PROJLINKS', t(''));

define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', t(''));

define ('TAPAS_INSTANCE_DESC_PERSISTID', t(''));
define ('TAPAS_INSTANCE_DESC_TEIFILE', t(''));
define ('TAPAS_INSTANCE_DESC_ATTATCH', t(''));
define ('TAPAS_INSTANCE_DESC_AUTHORS', t(''));
define ('TAPAS_INSTANCE_DESC_CONTRIBUTORS', t(''));
define ('TAPAS_INSTANCE_DESC_DISPLAYDATE', t(''));

// ====================================================================================
// Content Type Descriptions
// ====================================================================================

/* User-facing descriptions for content types. */
define ('TAPAS_CONTENT_PROJ_DESC', '');
define ('TAPAS_CONTENT_COLL_DESC', '');
define ('TAPAS_CONTENT_REC_DESC', '');

/* User-facing help text for content types. */
define ('TAPAS_CONTENT_PROJ_HELP', '');
define ('TAPAS_CONTENT_COLL_HELP', '');
define ('TAPAS_CONTENT_REC_HELP', '');

// ====================================================================================
//  Hydra API.
// ====================================================================================

// include_once('/var/www/hydratoken.php');
// define ('TAPAS_AUTH_TOKEN', HYDRA_API_KEY);
define ('TAPASHYDRA_AUTH_TOKEN', 'tapas12345');

/** Base URL to build the API calls off of. */
define('TAPAS_BASE_API_URL', 'http://rails_api.localhost:8080');

/** Send Project POST calls to this url. */
define('TAPAS_POST_PROJECT_URL', TAPAS_BASE_API_URL . "/communities");
/** Send Collection POST calls to this url. */
define('TAPAS_POST_COLLECTION_URL', TAPAS_BASE_API_URL . "/collections");
/** Send TEI Record POST calls to this url. */
define('TAPAS_POST_TEI_URL', TAPAS_BASE_API_URL . "/files");

/* The following three constants tell which view of a tei record is being
 * Fetched by a GET command. 
 */
define('TAPAS_GET_RAW', 'tei');
define('TAPAS_GET_BP', 'teibp');
define('TAPAS_GET_GENERIC', 'tapas_generic');

/** Whether to include debug output. Not intended for production! */
define("TAPAS_INCLUDE_CURL_DEBUG", TRUE);
