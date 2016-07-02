<?php
/**
 * @file
 * Views integration implementation.
 */

/**
 * Implements hook_views_data()
 */
function views_menuarea_views_data() {
  $data = array();
  $data['views']['menu'] = array(
    'title' => t('Menu area'),
    'help' => t('Provides an link item list from specified menu.'),
    'area' => array(
      'handler' => 'views_handler_area_menu',
    ),
  );

  return $data;
}
