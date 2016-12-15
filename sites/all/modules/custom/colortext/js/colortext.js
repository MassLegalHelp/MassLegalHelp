(function ($) {
    Drupal.behaviors.colortext = {
    attach: function (context, settings) {
      if (Drupal.settings.colortext.on == 1) {
        $('select[name="colortext_colors"]').change(function () {
          var clr = $(this).val();
          $.cookie('colortext_color_pick', clr);
          bees_swarm(clr);
					
					// Add google universal analytics tracking 
					var trackColor = '';					
					// Track only if the two variables differ, i.e. the color actually changed, not via cookie.
					if (trackColor != clr) {
						var url = window.location.href;  
						var pageName = url.substr(url.lastIndexOf('/') + 1);			
						ga('send', 'event', 'beeline', pageName, clr, 1);  						
						trackColor = clr; //set tracked color to user selected color
					}
					
        });
        var clr_pick = $.cookie('colortext_color_pick');
        if (typeof clr_pick === "undefined" || clr_pick === "nocolor" || clr_pick === null) {}
        else {bees_swarm(clr_pick);}
      }
			function bees_swarm(clr) {
        var elem = Drupal.settings.colortext.element;
        var elements = document.querySelectorAll(elem);
        if (typeof clr == "undefined" || clr == "nocolor") {
          var color = {theme: 'nocolor'};
          for (var i = 0; i < elements.length; i++) {
            var beeline = new BeeLineReader(elements[i], color);
            beeline.uncolor();
          }
        }
        else {
          var color = {theme: clr};
          for (var i = 0; i < elements.length; i++) {
            // Apply selected theme to override the current page's text color
            var beeline = new BeeLineReader(elements[i], color);
            beeline.color();									
          }
        }
			}
    } //attach: function
  }; //Drupal.behaviors
}(jQuery));
