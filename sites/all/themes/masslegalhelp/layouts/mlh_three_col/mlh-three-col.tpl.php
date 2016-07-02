<?php
/**
 * @file
 * Template for the 1 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 */
 
 $left = $content['left'];
 $title = $content['title'];
 $right = $content['right'];
?>
<div class="mlh_three_col <?php if(!$left) echo 'nosidebar' ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="mlh_main"> <div class="mlh_main_inner">
  <?php if($title): ?>
	  <div class="mlh_title">
		<?php print $title; ?>
	  </div>
	   <?php endif; ?>
	  <div class="mlh_center <?php if(!$right) echo 'no-right-col' ?>">
		<?php print $content['middle']; ?>
	  </div>
	  <?php if($right): ?>
	  <div class="mlh-right">
		<?php print $right; ?>
	  </div>
	  <?php endif; ?>
  </div> </div>
  
  <?php if($left): ?>
	  <div class="mlh_left">
	   <?php print $left; ?>
	  </div>
  <?php endif; ?>
  
</div>
