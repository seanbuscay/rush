<?php
/**
 * @file
 * Functions to assist with text output.
 */

/**
 * @addtogroup helpers Helper Functions
 * @{
 */

/**
 * @addtogroup output Output Helpers
 * @brief Functions to assist with text output.
 * @{
 */
 
/**
 * Helper function to output a consistent error message for empty parameters.
 *
 * @param string $value
 *   Required. A string containing the name of the parameter missing a value.
 * @param string $function
 *   Required.  A string containing the name of the calling function.
 *
 * @return bool
 *   Always returns FALSE via drush_set_error()
 */
function rush_empty_error($value, $function) {

  return drush_set_error('RUSH_EMPTY_VALUE', dt('[ERROR]: *** !value should be set when calling !function. ***', array(
    '!value'    => $value,
    '!function' => $function,
  )));
}

/**
 * Style messages for output to the console.
 *
 * @param string $message
 *   A string containing the message text to style.
 * @param int $style
 *   An integer indicating which style to use for the message.
 *
 * @return string
 *   The styled message string.
 */
function rush_message_wrapper($message = '', $style = 0) {

  $msg = '';
  switch ($style) {
    case 0:
      $msg .= "\n**********$message********************************************\n";
      break;
  }

  $msg = substr($msg, 0, 80);

  return ($msg);
} 

/**
 * Get an array of doc block comments from an array of function names.
 *
 * Uses PHP ReflectionFunction Class for doc comment reflection. 
 * The function names passed to this function must be functions which are
 * defined in the current runtime. 
 *
 * @param array $functions
 *   An array of function names.
 *
 * @return array
 *   An array of function names as the key and docblocks as the value.
 */
function rush_get_docblocks ($functions) {

  $docblocks = array();
  foreach ($functions as $func) {
    $f = new ReflectionFunction($func);
    $f_name = $f->getName();
    $f_doc_block = $f->getDocComment();        
    $docblocks[$f_name] = $f_doc_block;
  }
  
  return $docblocks;

}

/**
 * Get an array of formatted block comments from the $docblocks array.
 *
 * This is a helper function to format doc block comments for output.
 *
 * @param array $docblocks
 *   An array of function names as the key and docblocks as the value.
 *
 * @return array
 *   An array of function names as the key and formated 
 *   docblocks as the value.
 */
function _rush_format_docblocks($docblocks) {

  $functions = array();
  foreach($docblocks as $f_name => $f_doc_block) {
    $strip = array("*", "/");
    $f_doc_block = str_replace($strip, "", $f_doc_block);
    $f_doc_block = str_replace('@param', "Parameter:", $f_doc_block);
    $f_doc_block = str_replace('@return', "Returns:", $f_doc_block);
    $functions[$f_name] = $f_doc_block;
  }
  
  return $functions;
}

function _rush_get_function_names ($file) {

  $content = file_get_contents($file);
  $functions_names = array();
  preg_match_all("/(function )(\S*\(\S*\))/", $content, $matches);
  foreach($matches[2] as $match) {
    // @todo Get the right regex.
    $match = trim($match);
    $match = str_replace('($params)', '', $match);
    $functions_names[] = $match;
  }
  natcasesort($functions_names);

  return $functions_names;
}

function rush_print_function_blocks ($file) {
 
  $function_names = _rush_get_function_names ($file);
  $docblocks = rush_get_docblocks ($function_names); 
  $docblocks = _rush_format_docblocks ($docblocks);
  foreach ($docblocks as $f_name => $doc) {
   
   $msg = '*** ' . $f_name . ' ***';
   drush_print ($msg);
   drush_print ($doc);
    
  }
  
}

function _rush_print_ops_table ($file) {
  $docs_dir = rush_self_path() . 'operations/';
  $function_names = _rush_get_function_names ($docs_dir.$file);
  $docblocks = rush_get_docblocks ($function_names); 
  $docblocks = _rush_format_docblocks ($docblocks);
  $rows = array();
  foreach ($docblocks as $f_name => $doc) {
    $f_name = str_replace('rush_op_', '', $f_name);
    $doc = strtok($doc, "\n");
    $rows[$f_name] = $doc;
  }
  $rows = drush_key_value_to_array_table($rows);
  drush_print_table($rows);
}