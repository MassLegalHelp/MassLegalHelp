<?php
/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function masslegalhelp_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL)  {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  // Create the form using Forms API: http://api.drupal.org/api/7

  
  $form['sub_logo_file_new'] = array(
    '#type'     => 'managed_file',
    '#title'    => t('Sub Logo'),
    '#required' => FALSE,
    '#upload_location' => file_default_scheme() . '://themes/masslegalhelp/images/',
    '#default_value' => theme_get_setting('sub_logo_file_new'), 
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
  );
  
  // */

  // Remove some of the base theme's settings.
  /* -- Delete this line if you want to turn off this setting.
  unset($form['themedev']['zen_wireframes']); // We don't need to toggle wireframes on this site.
  // */

  // We are editing the $form in place, so we don't need to return anything.
}
