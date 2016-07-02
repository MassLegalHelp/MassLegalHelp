<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
if ((isset($output))) {
	global $language;
        $a = explode('^AP(',$output);
	$c = array();
	foreach($a as $b){
		$c[] = strstr($b,'^',true);
	}
        foreach($c as $d){
		if($d!=''){
			$nid = db_query("SELECT n.nid  FROM url_alias au INNER JOIN node n ON n.nid=SUBSTR(au.source,6) WHERE n.type =:type and au.alias =:alias and au.language=:language", array(":type" => "article", ":alias" => $d,":language" =>$language->language))->fetchField();
			if(!empty($nid)){
				$node = node_load($nid);
				if(is_object($node)){
					$embed_body = $node->body[$language->language][0]['value'];
					$output = str_replace("^AP(".$d."^", $embed_body, $output);
				}
			}
		}
	}
}
 print $output; ?>