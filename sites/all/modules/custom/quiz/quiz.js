jQuery(document).ready(function(){
	var letters = new Array ('A.', 'B.', 'C.', 'D.', 'E.', 'F.', 'G.', 'H.', 'I.');
	
	jQuery("div.view-display-id-panel_pane_3").find("div.field-name-field-answer-type .field-label").css ("visibility", "hidden");	
	jQuery("div.view-display-id-panel_pane_3").find("div.field-name-field-answer-type .field-item").css('color','transparent');	

	jQuery("div.view-display-id-panel_pane_3").find("div.field-name-field-correct-message").hide();	
	jQuery("div.view-display-id-panel_pane_3").find("div.field-name-field-wrong-message").hide();


	
	
	jQuery("div.view-display-id-panel_pane_3").find("div.field-collection-item-field-question-group").each(function(){
		  var e=this;
		  var k = 0;
		  jQuery(e).find(".field-name-field-answer-type .field-item").each(function(){
			
			  jQuery(this).prepend('<input name="button" class="answerButton" type="button" style="width: 50px;" value="' + letters[k] + '">');
				k++;
		  
		  }); 
  
  
	});
	

	var i = 1;
    jQuery("div.view-display-id-panel_pane_3").find("input:button.answerButton").bind('click', function(){				
		var type = jQuery(this).parents().eq(3).find(".field-name-field-answer-type .field-item").text();
		var url = window.location.href;  
                var pageName = url.substr(url.lastIndexOf('/') + 1);
                var question = pageName + " - Q " + jQuery(this).parents().eq(7).find(".field-name-field-short-question").text(); //end
                
                //alert(question);
		if(type == "Correct"){
                    	jQuery(this).val(":-)");
			jQuery(this).parents().eq(7).find(".field-name-field-correct-message").slideDown ('slow');			  jQuery(this).parents().eq(7).find(".field-name-field-wrong-message").hide();
                        ga('send', 'event', 'quiz', question, 'correct answer', 1);  //end
		}else{
			jQuery(this).val(":-(");
			jQuery(this).parents().eq(7).find(".field-name-field-correct-message").hide();
			jQuery(this).parents().eq(7).find(".field-name-field-wrong-message").slideDown ('slow');
                        ga('send', 'event', 'quiz', question, 'wrong answer', 1);  //end
		}
	});
	
});