var tag = document.createElement('script');
tag.src = "//www.youtube.com/iframe_api";
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

var videoArray = new Array();
var playerArray = new Array();

var videoTitle = new Array();
var showTitle = 3;
var reloadFrames = 0;
function trackYouTube()
{
	var i = 0;
	jQuery('iframe').each(function() {
           	if(jQuery(this).attr('src')){
			var video = jQuery(this);
			var vidSrc = video.attr('src');
			if(reloadFrames){
                            alert(reloadFrames);
				var regex1 = /(?:https?:)?\/\/www\.youtube\.com\/embed\/([\w-]{11})(\?)?/;
				var SourceCheckA = vidSrc.match(regex1);
				if(SourceCheckA[2]=="?"){
					var regex2 = /enablejsapi=1/;
					var SourceCheckB = vidSrc.match(regex2);
					if(SourceCheckB){
						//it has the gift
						//accept it and move on
					}else{
						vidSrc = vidSrc + "&enablejsapi=1";
					}
					var regex2 = /origin=.*/;
					var SourceCheckC = vidSrc.match(regex2);
					if(SourceCheckC){
						for (j=0; j<SourceCheckC.length; j++) {
							newOrigin = "origin=" + window.location.hostname;
							var vidSrc = vidSrc.replace(regex2,newOrigin);
						}
					}else{
						vidSrc = vidSrc + "&origin=" + window.location.hostname;
					}
				}else{
					vidSrc = vidSrc + "?enablejsapi=1&origin=" + window.location.hostname;
				}
				video.attr('src', vidSrc);
			}
			var regex = /(?:https?:)?\/\/www\.youtube\.com\/embed\/([\w-]{11})(?:\?.*)?/;
			var matches = vidSrc.match(regex);
			if(matches && matches.length > 1){
				videoArray[i] = matches[1];
				video.attr('id', matches[1]);	
				getRealTitles(i);
				i++;			
			}
		}
	});	
}
function getRealTitles(j) {
	if(showTitle==2){
		playerArray[j] = new YT.Player(videoArray[j], {
		    videoId: videoArray[j],
		    events: {
			    'onStateChange': onPlayerStateChange
			}
		});	
	}else{ 
	    var tempJSON = jQuery.getJSON('https://www.googleapis.com/youtube/v3/videos?id='+videoArray[j]+'&key=AIzaSyAfgKpSVPaM1uHll52gJ4narz3St1F3KUw&part=snippet',function(data,status,xhr){
               // alert(JSON.stringify(data, null, 4));
                //alert(data.items[0].snippet.title);
                    videoTitle[j] = data.items[0].snippet.title;
			playerArray[j] = new YT.Player(videoArray[j], {
			    videoId: videoArray[j],
			    events: {
				    'onStateChange': onPlayerStateChange
				}
			});
	    });
	}
}
jQuery(window).load(function() {
    trackYouTube();
});

function onPlayerReady(event) {
	//event.target.playVideo();
}
var pauseFlagArray = new Array();
function onPlayerStateChange(event) { 
   	var videoURL = event.target.getVideoUrl();
	var regex = /v=(.+)$/;
	var matches = videoURL.match(regex);
	videoID = matches[1];
	thisVideoTitle = "";
	for (j=0; j<videoArray.length; j++) {
	    if (videoArray[j]==videoID) {
	        thisVideoTitle = videoTitle[j]||"";
			console.log(thisVideoTitle);
			if(thisVideoTitle.length>0){
				if(showTitle==3){
					thisVideoTitle = thisVideoTitle + " | " + videoID;
				}else if(showTitle==2){
					thisVideoTitle = videoID;
				}
			}else{
				thisVideoTitle = videoID;
			}
	     //Should the video rear it's head
                if (event.data == YT.PlayerState.PLAYING) {
                    //alert(thisVideoTitle);
        	    ga('send', 'event', 'Videos', 'Play', thisVideoTitle);
        	} 
        	if (event.data == YT.PlayerState.ENDED){
        		ga('send', 'event', 'Videos', 'Watch to End', thisVideoTitle);
        	} 
			
	    }
	}
} 

if (typeof jQuery != 'undefined') {
    var filetypes = /\.(pdf|doc.*|docx|mobi|epub|xlsx.*|xls.*|rtf)$/i;
    var baseHref = '';
    if (jQuery('base').attr('href') != undefined) baseHref = jQuery('base').attr('href');
    var hrefRedirect = '';
 
    jQuery('body').on('click', 'a', function(event) {
        var el = jQuery(this);
        var track = true;
        var href = (typeof(el.attr('href')) != 'undefined' ) ? el.attr('href') : '';
        var isThisDomain = href.match(document.domain.split('.').reverse()[1] + '.' + document.domain.split('.').reverse()[0]);

        if (!href.match(/^javascript:/i)) {
            var elEv = []; elEv.value=1, elEv.non_i=false;
	    
	    if (href.match(/^https?\:/i) && !isThisDomain) {
                elEv.category = 'external';
                elEv.action = 'click - external';
                elEv.label = href.replace(/^https?\:\/\//i, '');
                elEv.non_i = true;
                elEv.loc = href;
            }
            
            else if (href.match(filetypes)) {
                var extension = (/[.]/.exec(href)) ? /[^.]+$/.exec(href) : undefined;
                elEv.category = 'download';
                elEv.action = 'click-' + extension[0];
                elEv.label = href.replace(/ /g,'-');
                elEv.loc = baseHref + href;		
            }            
            
            else track = false;
 
            if (track) {
                var ret = true;
 
                if((elEv.category == 'external' || elEv.category == 'download') && (el.attr('target') == undefined || el.attr('target').toLowerCase() != '_blank') ) {
                    hrefRedirect = elEv.loc;
 
                    ga('send','event', elEv.category.toLowerCase(),elEv.action.toLowerCase(),elEv.label.toLowerCase(),elEv.value,{
                        'nonInteraction': elEv.non_i ,
                        'hitCallback':gaHitCallbackHandler
                    });
 
                    ret = false;
                }
                else {
                    ga('send','event', elEv.category.toLowerCase(),elEv.action.toLowerCase(),elEv.label.toLowerCase(),elEv.value,{
                        'nonInteraction': elEv.non_i
                    });
                }
 
                return ret;
            }
        }
    });
 
    gaHitCallbackHandler = function() {
        window.location.href = hrefRedirect;
    }
}
ga('send', 'event', 'QnA', 'click-iframe', 'Bankruptcy'); 
