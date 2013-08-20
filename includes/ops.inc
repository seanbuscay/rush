<?php
/**
 * @file
 * Functions to get and parse operations for Drush Rush to execute.
 */

/**
 * @addtogroup helpers Helper Functions
 * @{
 */

/**
 * @addtogroup get_ops Operations Helpers
 * @brief Functions to get and parse operations for Drush Rush to execute.
 * @{
 */

/**
 * Parse rush operations files and return an array of operations.
 *
 * The following is the order of parsing:
 *   1. Get rush operations from the job rush ini file if it exists.
 *   2. Get rush operations from the job operations php file if it exists.
 *      - Operations in the job php file will run after all other operations
 *        to this point.
 *
 * @param array $params
 *   An associative array of rush parameters.
 *   The params are not directly used in the function, however passing them to
 *   the function makes them available to the include files.
 *
 * @return mixed
 *   An associative array of all rush operations.
 *   False via drush set error if now operations are found.
 * @backlog Fix to just return an empty array().
 */
function rush_get_operations($params) {

  $global_locations = rush_get_global_locations();
  $rush_type        = '';
  if (drush_get_option('rush', FALSE)) {
    $rush_type = drush_get_option('rush');
    $rush_type = $rush_type . '.';
  }
  $rush = array();
  // 1) Get rush operations from the top job rush ini file if it exists.
  $rush_ini_file = $global_locations['RUSH_JOB_TOP_DIRECTORY_PATH'] . $rush_type . 'rush.ini';
  if (file_exists($rush_ini_file)) {
    $msg = $msg = dt('[LOAD RUSH FILE]: !file.', array('!file' => $rush_ini_file));
    drush_log($msg, 'notice');
    $rush = rush_parse_operations_ini($rush_ini_file);
  }
  // 2) Get rush operations from the top job operations php file if it exists.
  // Operations in the top job php file will run after all other operations
  // to this point.
  $rush_php_file = $global_locations['RUSH_JOB_TOP_DIRECTORY_PATH'] . $rush_type . 'rush.php';
  if (file_exists($rush_php_file)) {
    $msg = $msg = dt('[LOAD RUSH FILE]: !file.', array('!file' => $rush_php_file));
    drush_log($msg, 'notice');

    include_once "$rush_php_file";
  }
  unset($rush_ini_file, $rush_php_file);
  $top_job_rush = $rush;
  unset($rush);
  $rush = array();
  // 3) Get rush operations from the job rush ini file if it exists.
  $rush_ini_file = $global_locations['RUSH_JOB_DIRECTORY_PATH'] . $rush_type . 'rush.ini';
  if (file_exists($rush_ini_file)) {
    $msg = $msg = dt('[LOAD RUSH FILE]: !file.', array('!file' => $rush_ini_file));
    drush_log($msg, 'notice');
    $rush = rush_parse_operations_ini($rush_ini_file);
  }
  // 4) Get rush operations from the job operations php file if it exists.
  // Operations in the job php file will run after all other operations to this
  // point.
  $rush_php_file = $global_locations['RUSH_JOB_DIRECTORY_PATH'] . $rush_type . 'rush.php';
  if (file_exists($rush_php_file)) {
    $msg = $msg = dt('[LOAD RUSH FILE]: !file.', array('!file' => $rush_php_file));
    drush_log($msg, 'notice');

    include_once "$rush_php_file";
  }

  // Check if job operations exist.
  // If so, then return the job operations.
  if (is_array($rush) && count($rush) > 0) {
    return $rush;
  }

  // Check if top job operations exist.
  // If so, then return the top job operations.
  // This allows for sub job folders with no rush file.
  if (is_array($top_job_rush) && count($top_job_rush) > 0) {
    return $top_job_rush;
  }

  return drush_set_error('RUSH_NO_OPERATIONS', dt('[ERROR]: *** No operations found.  Check that your job or parent job has a rush file. ***'));

}

/**
 * Parse a rush.ini file.
 *
 * Wrapper function for make_parse_info_file.
 *
 * @param string $ini_file
 *   Required. A string with the path of the ini file to parse.
 *
 * @return array
 *   An associative array of parameters on success.  FALSE on fail.
 */
function rush_parse_operations_ini($ini_file) {

  return make_parse_info_file($ini_file);
}

/** @}*/
/** @}*/
