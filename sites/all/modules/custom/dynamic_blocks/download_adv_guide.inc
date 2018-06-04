<?php

function generate_content(&$list) {
	// 1. Get current page breadcrumb    
    $menuTrail = menu_get_active_trail("node/$node->nid"); 	 
	 
	 // 2. Construct file titles 
	 // 2.a Get text from the breadcrumb and use it as the file title for display
    $fileTitle = array();
	$fileTitle["guide"]=$menuTrail[4]["title"];		
	$fileTitle["chapter"]=$menuTrail[5]["title"];	
	
	// EA book goes a level deeper because it's in a different Subject area
	if ($fileTitle["guide"] = "Emergency Assistance Advocacy Guide") {		
		$fileTitle["guide"]=$menuTrail[5]["title"];		
		$fileTitle["chapter"]=$menuTrail[6]["title"];	 
	};
	
	$fileTitle["ePub"] = $fileTitle["guide"]." for Android or i-devices";
	$fileTitle["mobi"] = $fileTitle["guide"]." for Kindle";
	$fileTitle["azw3"] = $fileTitle["guide"]." for Kindle Fire and Kindle Flash";
	
	// 2.b Change blank space in the title above to "-", and convert the title to lower case. 
	// They will be used as download file titles.
	$guideName=array();
	$guideName["guide"] = strtolower(str_replace(' ', '-', $fileTitle["guide"]));
    $guideName["chapter"] = strtolower(str_replace(' ', '-', $fileTitle["chapter"]));

    // 3. Construct download file paths	using the path alias of each adv guide file field
    // On MLH there are only 3 online advocacy guides, which follows a pattern that make the yellow box useful.	
	// For the other two guides (UI and EAEDC) since no chapter files are available, yellow box is pointless, so ignore them in this module.
	switch ($guideName["guide"]) {
    case "food-stamp-advocacy-guide":
        $pathAlias = '/income-benefits/food-stamps-advocacy-guide'; 		
        break;
    case "tafdc-advocacy-guide":
        $pathAlias = '/income-benefits/tafdc-advocacy-guide'; 		
        break;
    case "emergency-assistance-advocacy-guide":
        $pathAlias = '/homelessness/emergency-assistance-advocacy-guide'; 		
        break;
	}	
	
	// Chapter file path.
	$pdfPath = array();
	$pdfPath["chapter"] = "/".$guideName["guide"]."/".$guideName["chapter"].".pdf";
	
	// Full book path.
	$pdfPath["guide"] = $pathAlias."/".$guideName["guide"].".pdf";
    $pdfPath["ePub"] = $pathAlias."/".$guideName["guide"].".epub";
	$pdfPath["mobi"] = $pathAlias."/".$guideName["guide"].".mobi"; 
	$pdfPath["azw3"] = $pathAlias."/".$guideName["guide"].".azw3"; 

    // 4. Generate links list
    $list = array();
	$PDFimg = '<p><img src="/sites/default/files/mlhfiles/file_images/pdf.gif" /> ';		
	
	$prefix = '<p>Download the entire book as an eBook - ';
	$title = 'Find out how';
	$href = 'https://www.masslegalhelp.org/how-do-i-download-an-ebook-';
	$list[] = addtolist($listItem, $title, $href, $prefix);		
	
	// 4a. For chapter and its children pages, display the chapter pdf download link    
	if ($pdfChapter = "Y") {	
		if ($guideName["chapter"] >= "a") {	  	  
			$title = $fileTitle["chapter"];		
			$href = $pdfPath["chapter"];
			$list[] = addtolist($listItem, $title, $href, $PDFimg);					
			};		// end of chapter pdf download
	}
	
	// 4b. For all pages, display the full guide pdf download link 				
	$title = $fileTitle["guide"];
	$href = $pdfPath["guide"];
	if ($title == 'Food Stamp (SNAP) Advocacy Guide' || $title == 'TAFDC Advocacy Guide' || $title == 'Emergency Assistance Advocacy Guide' || $title == 'Finding Housing' ) {
		$list[] = addtolist($listItem, $title, $href, $PDFimg);						
	} // end of full guide pdf download		
		
	// 4c. In addition, for all pages display the ebook download links 		
	$prefix = '<p><img src="/sites/default/files/mlhfiles/file_images/epub.png" /> ';
	$title = $fileTitle["ePub"];
	$href = $pdfPath["ePub"];
	$list[] = addtolist($listItem, $title, $href, $prefix);			

	$prefix = '<p><img src="/sites/default/files/mlhfiles/file_images/kindle.png" /> ';
	$title = $fileTitle["mobi"];
	$href = $pdfPath["mobi"];
	$list[] = addtolist($listItem, $title, $href, $prefix);			
	
	$prefix = '<p><img src="/sites/default/files/mlhfiles/file_images/KindleFire.png" /> ';
	$title = $fileTitle["azw3"];
	$href = $pdfPath["azw3"];
	$list[] = addtolist($listItem, $title, $href, $prefix);	
	
	// 4d. For all pages, display a link for buying a hard copy		
	$prefix = '<p>Buy a hard copy from ';
	$title = ' MCLE ($9.95)';
	
	switch ($guideName["guide"]) {
	case 'food-stamp-advocacy-guide':
		$href = variable_get('hard_copy_url_snap', '#url-snap');
		break;
	case 'tafdc-advocacy-guide':
		$href = variable_get('hard_copy_url_tafdc', '#url-tafdc');	
		break;
	case 'emergency-assistance-advocacy-guide':
		$href = variable_get('hard_copy_url_ea', '#url-ea');
		break;
	}
	
	$list[] = addtolist($listItem, $title, $href, $prefix);		
  // End of ebook download links
	
	return $list;		
}

function addtolist(&$listItem, $title, $href, $prefix) {
	$listItem = array(			
		'data' => array(				
			'#title' => $title,
			'#href' => $href,		
			'#type' => 'link',
			'#attributes' => array('target' => '_blank'),			
		),
		'#prefix' => $prefix,
		'#suffix' => '</p>',			
	);
	return $listItem;	
}
