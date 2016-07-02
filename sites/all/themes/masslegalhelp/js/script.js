/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
    Drupal.behaviors.my_custom_behavior = {
        attach: function (context, settings) {
            var eles = jQuery('.section-basic-legal-information');

            // Place your code here.
            if (eles.length > 0) {
                var element_menue_wrapper = jQuery('.menu-block-wrapper');
                var element_menue_main = element_menue_wrapper.children('ul');
                var element_menue_li = element_menue_main.children('li');
                var len = element_menue_li.length;
                var element_menue_child, element_menue_child_li, child_lenth, k;
                for (var i = 0; i < len; i++) {
                    if (typeof element_menue_li[i].children[1] !== 'undefined') {
                        child_lenth = element_menue_li[i].children[1].children.length;
                        k = 0;
                        for (; k < child_lenth; k++) {
                            if (k >= 5) {
                                element_menue_li[i].children[1].children[k].style.display = 'none';
                            }
                        }
                    }
                }

            }

        }
    };


})(jQuery, Drupal, this, this.document);