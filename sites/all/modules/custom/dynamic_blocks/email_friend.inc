<?php

function generate_link(&$items) {
		$url='';
		$current_url='';
		$extra='';
		$lang = '';
		global $base_url;	
		$url = $base_url.request_uri(); 	
		
		// On the webform node, it expects the caller node's url and title
		// Note: request_uri() has the article page's language prefix, so it handles the translation automatically.
		$current_url = substr(request_uri(), 1);	//remove leading "/".
		
		$nid = arg(1);
		$dataNode = node_load($nid);
		$nodeTitle = $dataNode->title;
		$nodeTitle = rawurlencode($nodeTitle); //replace space with %20		

	  $extra='?url='.$current_url.'&title='.$nodeTitle; 
		
		// Construct the link: form's url plus the extra
		// Need language prefix for the form node in order to see the translated labels. 
		$stopat = stripos($current_url, '/'); //find position of the first "/"
		$lang = substr($current_url, 0, $stopat); 
		$formUrl=$base_url.'/'.$lang.'/email-this';		
		
		// No language prefix if English
		$menuTrail = menu_get_active_trail("node/$node->nid"); 	 
		if ($menuTrail[1]["title"] == "English") {		
			$formUrl=$base_url.'/email-this';		
		}
		
		$href = $formUrl.$extra;		
    $alt = t('Send this page to a friend');    	  
				
		// Create a link to the webform node along w/ the param values
		$items = array(                
				'#type' => 'markup',				
				'#markup' => '<a href='.$href.' class="greytxt"  title="'.$alt.'">'.t('Email').'</a>',
		);
	return $items;
}