<?php

function generate_content(&$list) {
	// 1. Get current page breadcrumb    	 	
    $menuTrail = menu_get_active_trail("node/$node->nid"); 	 
	 
	 // 2. Construct file titles 
	 // 2.a Get text from the breadcrumb and use it as the file display title 
    $fileTitle = array();
	$fileTitle["guide"]=$menuTrail[5]["title"];		
	$fileTitle["chapter"]=$menuTrail[6]["title"];	 
	
	$fileTitle["ePub"] = $fileTitle["guide"]." for Android or i-devices";
	$fileTitle["mobi"] = $fileTitle["guide"]." for Kindle";
	$fileTitle["azw3"] = $fileTitle["guide"]." for Kindle Fire and Kindle Flash";
	 
	// 2.b Change blank space to "_" and convert the guide file name to lower case 
	$guideName=array();
	$guideName["guide"] = strtolower(str_replace(' ', '_', $fileTitle["guide"]));
    $guideName["chapter"] = strtolower(str_replace(' ', '_', $fileTitle["chapter"]));

    // 3. Construct download paths
	$url = "/sites/default/files/mlhfiles/file_nonimages";
	
	$pdfPath = array();
    $pdfPath["chapter"] = $url."/".$guideName["chapter"].".pdf";
	$pdfPath["guide"] = $url."/".$guideName["guide"].".pdf";
    $pdfPath["ePub"] = $url."/".$guideName["guide"].".epub";
	$pdfPath["mobi"] = $url."/".$guideName["guide"].".mobi"; 
	$pdfPath["azw3"] = $url."/".$guideName["guide"].".azw3"; 

    // 4. Generate links list
    $list = array();
	$PDFprefix = '<p><img src="/sites/default/files/mlhfiles/file_images/pdf.gif" /> ';		
	
	$prefix = '<p>Download the entire book as an eBook - ';
	$title = 'Find out how';
	$href = 'http://www.masslegalhelp.org/how-do-i-download-an-ebook-';
	$list[] = addtolist($listItem, $title, $href, $prefix);		
	
	// 4a. For chapter and its children pages, display the chapter pdf download link    	
	if ($guideName["chapter"] >= "a") {	  	  
	  $title = $fileTitle["chapter"];		
	  $href = $pdfPath["chapter"];
	  $list[] = addtolist($listItem, $title, $href, $PDFprefix);					
	};		// end of chapter pdf download
	
	// 4b. For chapter and guide pages, display the full guide pdf download link 			
	if (strlen($menuTrail[7]["title"]) == 0) {	
		$title = $fileTitle["guide"];
		$href = $pdfPath["guide"];
		if ($title == 'Food Stamp (SNAP) Advocacy Guide' || $title == 'TAFDC Advocacy Guide' || $title == 'Emergency Assistance Advocacy Guide') {
			$list[] = addtolist($listItem, $title, $href, $PDFprefix);						
		}
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
	
	// 4d. For the guide level page, display a link for buying a hard copy		
	if (strlen($fileTitle["chapter"]) == 0) {
		if ($guideName["guide"] == "food_stamp_(snap)_advocacy_guide") {
			$prefix = '<p>Buy a hard copy from ';
			$title = ' MCLE ($9.95)';
			$href = 'https://www.mcle.org/product/catalog/code/2170245B21';
			$list[] = addtolist($listItem, $title, $href, $prefix);	
		}
		else if ($guideName["guide"] == "tafdc_advocacy_guide") {
			$prefix = '<p>Buy a hard copy from ';
			$title = ' MCLE ($9.95)';
			$href = 'https://www.mcle.org/product/catalog/code/2170244B21';
			$list[] = addtolist($listItem, $title, $href, $prefix);	
		}
		else if ($guideName["guide"] == "emergency_assistance_advocacy_guide") {
			$prefix = '<p>Buy a hard copy from ';
			$title = ' MCLE ($9.95)';
			$href = 'https://www.mcle.org/product/catalog/code/2170241B08';
			$list[] = addtolist($listItem, $title, $href, $prefix);	
		}
	
	}	  // End of ebook download links
	
	//dsm($list);
	return $list;		
}

function addtolist(&$listItem, $title, $href, $prefix) {
	$listItem = array(			
		'data' => array(				
			'#title' => $title,
			'#href' => $href,		
			'#type' => 'link',
			),
		'#prefix' => $prefix,
		'#suffix' => '</p>',			
	);
	return $listItem;	
}
