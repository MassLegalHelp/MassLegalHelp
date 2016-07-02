DESCRIPTION
===========
Provides an "handler area" for Views 3 to list menu tree of specified menu.

Sometimes you might want to attach list of links in footer, header or empty
text when just single link isn't enough or you want to maintain links more
friendly.

Requires Views 3.


INSTRUCTIONS
============
1. Enable the module
2. Edit your preferred view
3. Click "Add" link in header/footer section
4. Check "Global: Menu area" and click "Add and configure footer" button
5. Enter label and select the menu you wish to list links from
6. Click "Apply" button and save the view


SIMILAR MODULE
==============
You can also use Views Block Area[1] instead, since each menu has an block
and therefore you can just render the block instead a clean menu.

[1] https://drupal.org/project/views_block_area


DRUPAL 8
========
In Drupal 8, you don't need this module since Views is in core and you can
render block entities.

How?
----
1. Create block instance from block layout page
2. In views display configuration, attach an rendered block entity
