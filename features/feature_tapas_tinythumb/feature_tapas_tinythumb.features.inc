<?php
/**
 * @file
 * feature_tapas_tinythumb.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function feature_tapas_tinythumb_image_default_styles() {
  $styles = array();

  // Exported image style: tapas_tiny.
  $styles['tapas_tiny'] = array(
    'label' => 'Tiny (50x50)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
