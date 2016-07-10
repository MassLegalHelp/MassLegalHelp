(function ($) {

  Drupal.behaviors.beeline = {
    attach: function (context, settings) {

      // Example of how to use the beeline reader library.
      var elements = document.querySelectorAll(".views-field-body p");
      for (var i = 0; i < elements.length; i++) {
        // Possible themes: bright, dark, blues, gray, night_gray, night_blues.
        var beeline = new BeeLineReader(elements[i], { theme: "bright" });
        beeline.color();
      }

    }
  };

}(jQuery));
