<?php
/**
 * @file
 * tapas_tiny_image.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function tapas_tiny_image_image_default_styles() {
  $styles = array();

  // Exported image style: tiny.
  $styles['tiny'] = array(
    'label' => 'Tiny',
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
