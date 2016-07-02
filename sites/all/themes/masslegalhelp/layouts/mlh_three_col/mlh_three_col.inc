<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('MLH Three column'),
  'category' => t('MLH'),
  'icon' => 'mlh_three_col.png',
  'theme' => 'mlh_three_col',
  'theme arguments' => array('id', 'content'),
  'css' => 'mlh_three_col.css',
  'regions' => array(
	'title' => t('Title'),
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side')
  ),
);


