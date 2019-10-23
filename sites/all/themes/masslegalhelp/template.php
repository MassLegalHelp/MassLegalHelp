<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */
function masslegalhelp_preprocess_page(&$vars){

	if(isset($vars['page']['content']['system_main']['nodes'])){
		$key = key($vars['page']['content']['system_main']['nodes']);
	}
	
	if(isset($key)){
		if(isset($vars['page']['content']['system_main']['nodes'][$key]['field_question_group']['#bundle']) && $vars['page']['content']['system_main']['nodes'][$key]['field_question_group']['#bundle'] == 'quiz'){		
			drupal_add_js(drupal_get_path('module', 'quiz') . '/quiz.js'); 
		}
	}
  
	if (isset($vars['node']->type)) {
		// If the content type's machine name is "my_machine_name" the file
		// name will be "page--my-machine-name.tpl.php".
		$vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
	}
	
	if (isset($vars['node']->type)) {
		if($vars['node']->type=='page'){
			$menu_string = '';
                       $menu_detail = db_query("SELECT mlid,menu_name from menu_links WHERE link_path='node/".$vars['node']->nid."' AND (menu_name NOT LIKE '%header-menu' and menu_name NOT LIKE '%footer-menu')");
			foreach($menu_detail as $record){
				$menu_string = $record->menu_name.":".$record->mlid;
			}
			$vars['node_add_link'] = l(t('Add New'),"node/add/page",array('query' => array('parent' => $menu_string)));
			
		}
	}
  // 10/23/2019 remove "there is currently no content classified with this term" message from taxonomy term pages. This is needed for our Glossary terms.
	if(isset($vars['page']['content']['system_main']['no_content'])) {
		unset($vars['page']['content']['system_main']['no_content']);
	}
}

function masslegalhelp_print_url_list($vars) {
  global $_print_urls;
  global $base_url;
  
  $b = parse_url($base_url);
  
  // Display the collected links at the bottom of the page. Code once taken from Kjartan Mannes' project.module
  if (!empty($_print_urls)) {
    $urls = _print_friendly_urls();
    $max = count($urls);
    $url_list = '';
	$no = 1;
	foreach ($urls as $key => $url) {
	$a = parse_url($url);
	if($b['host']!=$a['host']){
      drupal_alter('print_url_list', $url); 
      $url_list .= '[' . ($no) . '] ' . check_plain($url) . "<br />\n";
	  $no++;
	  }
	  
    }
    if (!empty($url_list)) {
      return "<p><strong>" . t('Links') . "</strong><br />$url_list</p>";
    }
    else {
      return '';
    }
  }

}




/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  masslegalhelp_preprocess_html($variables, $hook);
  masslegalhelp_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */

/*function masslegalhelp_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // masslegalhelp_preprocess_node_page() or masslegalhelp_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}*/

function getStringBetweenn($str,$from,$to) {
		 $sub = substr($str, strpos($str,$from)+strlen($from),strlen($str));
		 return substr($sub,0,strpos($sub,$to));
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function masslegalhelp_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
* 9/23/2019 - Changes the core search form submit button text to "GO".
*/
function masslegalhelp_form_search_block_form_alter(&$form, &$form_state, $form_id) {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 30;  // define size of the textfield    
    $form['actions']['submit']['#value'] = t('GO'); // Change the text on the submit button

    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";
} 