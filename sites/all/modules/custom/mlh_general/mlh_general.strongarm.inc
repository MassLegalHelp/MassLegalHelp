<?php
/**
 * @file
 * mlh_general.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mlh_general_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_advanced_project_settings';
  $strongarm->value = array(
    'admin_menu' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'admin_views' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'backup_migrate' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'bigmenu' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'drupal' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'block_class' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'blockcache_alter' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'browserclass' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'ctools' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'cacheexclude' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'captcha' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'ckeditor' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'node_clone' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'cloudflare' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'cloudflare_cc' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'crumbs' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'css_injector' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'date' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'ds' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'entity' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'entity_translation' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'entityreference' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'expire' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'fast_404' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'features' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'field_collection' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'field_group' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'file_aliases' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'filefield_paths' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'find_content' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'google_captcha' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'google_cse' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'google_analytics' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'honeypot' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'i18n' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'imce' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'insert_block' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'jquery_update' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'libraries' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'mailsystem' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'menu_attributes' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'menu_block' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'menu_select' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'metatag' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'mimemail' => array(
      'check' => '7.x-1.1',
      'notes' => 'Patched 7.x-1.0-beta4 for SA-CONTRIB-2018-068',
    ),
    'module_filter' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'multiblock' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'multifield' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'nice_menus' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'node_embed' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'nodeaccess' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'open_readspeaker' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'panelizer' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'panels' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'path_breadcrumbs' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'path_redirect_import' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'print' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'Custom' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'recaptcha' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'redirect' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'responsive_menus' => array(
      'check' => '7.x-1.7',
      'notes' => 'Patched 7.x-1.5 for SA-CONTRIB-2018-079',
    ),
    'rules' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'scanner' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'smtp' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'strongarm' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'title' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'tmgmt' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'token' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'token_filter' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'update_advanced' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'variable' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'views' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'views_bulk_operations' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'views_content_cache' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'views_menuarea' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'views_php' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'webform' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'webform_component_roles' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'webform_localization' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'webform_submissions_multiple_delete' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'webspeech' => array(
      'check' => 'always',
      'notes' => '',
    ),
    'zen' => array(
      'check' => 'always',
      'notes' => '',
    ),
  );
  $export['update_advanced_project_settings'] = $strongarm;

  return $export;
}
