<?php
/**
 * @file
 * mlh_backups.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mlh_backups_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_endpoint_urls';
  $strongarm->value = array(
    0 => 'api.nodesquirrel.com/services/xmlrpc',
  );
  $export['nodesquirrel_endpoint_urls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_schedule';
  $strongarm->value = '604800';
  $export['nodesquirrel_schedule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_schedule_enabled';
  $strongarm->value = 1;
  $export['nodesquirrel_schedule_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_schedule_keep';
  $strongarm->value = '3';
  $export['nodesquirrel_schedule_keep'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_schedule_source_id';
  $strongarm->value = 'archive';
  $export['nodesquirrel_schedule_source_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodesquirrel_secret_key';
  $strongarm->value = '6d1b5619ab26b40245c689077035c5ed:f182351f453ff6c46a12e6d6e255eeb0';
  $export['nodesquirrel_secret_key'] = $strongarm;

  return $export;
}
