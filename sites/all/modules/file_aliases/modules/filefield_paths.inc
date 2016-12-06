<?php

/**
 * @file
 * FileField Paths module integration.
 */

/**
 * Implements hook_filefield_paths_field_settings().
 *
 * @param $field
 * @param $instance
 *
 * @return array
 */
function file_aliases_filefield_paths_field_settings($field, $instance) {
  return array(
    'file_alias' => array(
      'title' => 'File alias',
      'form'  => array(
        'value' => array(
          '#type'          => 'textfield',
          '#title'         => t('File alias'),
          '#default_value' => drupal_substr(parse_url(file_create_url($field['settings']['uri_scheme'] . '://'), PHP_URL_PATH) . '[file:ffp-name-only-original].[file:ffp-extension-original]', 1),
          '#maxlength'     => 512,
          '#size'          => 128,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_filefield_paths_process_file().
 *
 * @param $type
 * @param $entity
 * @param $field
 * @param $instance
 * @param $langcode
 * @param $items
 */
function file_aliases_filefield_paths_process_file($type, $entity, $field, $instance, $langcode, &$items) {
  if (isset($instance['settings']['filefield_paths'])) {
    $settings = $instance['settings']['filefield_paths'];

    if (isset($settings['file_alias'])) {
      foreach ($items as &$file) {
        // Process file if this is a new entity, 'Active updating' is set or
        // file wasn't previously attached to the entity.
        if (isset($entity->original) && empty($settings['active_updating']) && !empty($entity->original->{$field['field_name']}[$langcode])) {
          foreach ($entity->original->{$field['field_name']}[$langcode] as $original_file) {
            if ($original_file['fid'] == $file['fid']) {
              continue(2);
            }
          }
        }

        $token_data = array(
          'file' => (object) $file,
          $type  => $entity
        );

        // Process file alias.
        // This is a bit hacky, the context should be 'file_alias', but to
        // ensure the file name doesn't have it's '.' removed we need to
        // identify as the file name.
        $settings['file_alias']['options']['context'] = 'file_name';
        $file['alias'] = filefield_paths_process_string($settings['file_alias']['value'], $token_data, $settings['file_alias']['options']);

        // Convert the file alias into an absolute URL and ensure that it begins
        // with the current base URL and path.
        $url = url($file['alias'], array('absolute' => TRUE));
        $base = $GLOBALS['base_url'] . base_path();
        if (variable_get('clean_url', 0) == FALSE) {
          $base .= '?q=';
        }
        if (substr($url, 0, strlen($base)) !== $base) {
          watchdog('file_aliases', 'The file alias %alias could not be created for %destination as it is invalid.', array(
            '%alias'       => $file['alias'],
            '%destination' => $file['uri'],
          ));
          continue;
        }

        // Remove the current base URL and path to normalise the file alias.
        $file['alias'] = substr($url, strlen($base));

        $source = "file_aliases/{$file['fid']}";
        $alias = drupal_get_path_alias($source);
        if ($alias !== $source) {
          path_delete(array('source' => $source));
        }
        $path = array(
          'source' => $source,
          'alias'  => $file['alias']
        );
        path_save($path);
      }
    }
  }
}
