<?php

// Prefixes for fields and field instances

/** Prefix used on all tapascollection field base names. */
define ('TAPAS_FIELD_PREFIX', 'field_tapas_');
/** Prefix used by all Collection field instances. */
define ('TAPAS_C_INSTANCE_PRE', 'fi_tapas_c_');
/** Prefix used by all project field instances. */
define ('TAPAS_P_INSTANCE_PRE', 'fi_tapas_p_');

// The content types.

/** Machine name of the Collection content type. */
define ('TAPAS_COLLECTION', 'tapascollection_collection');

/** Machine name of the Project content type. */
define ('TAPAS_PROJECT', 'tapascollection_project');


// Other constants

/** Field name for collection-to-project OG audience link*/
define ('TAPAS_C_TO_P', 'og_tapas_c_to_p');

define ('TAPAS_C_DEFAULT_IMAGE', 0);
define ('TAPAS_P_DEFAULT_IMAGE', 0);

define ('TAPAS_C_IMAGE_DIR', '');
define ('TAPAS_P_IMAGE_DIR', '');

define ('TAPAS_THUMB_MAX_FILESIZE', '');
define ('TAPAS_THUMB_MAX_RES', '');
define ('TAPAS_THUMB_MIN_RES', '');

define ('TAPAS_THUMB_PREVIEW_STYLE', 'thumbnail');
define ('TAPAS_THUMB_PROGRESS_IND', 'throbber');

// Field Instance decriptions.

define ('TAPAS_INSTANCE_DESC_HIDDENIMAGENAME', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_COLLECTIONSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_INSTITUTIONS', t(''));
define ('TAPAS_INSTANCE_DESC_PROJDESCRIPTION', t(''));
define ('TAPAS_INSTANCE_DESC_PROJTHUMB', t(''));
define ('TAPAS_INSTANCE_DESC_HIDDENINST', t(''));
define ('TAPAS_INSTANCE_DESC_TAGS', t(''));
define ('TAPAS_INSTANCE_DESC_PARENTSLUG', t(''));
define ('TAPAS_INSTANCE_DESC_LINKS', t(''));
define ('TAPAS_INSTANCE_DESC_HIDDENTITLESTRING', t(''));



