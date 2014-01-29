<?php
/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <div class="content">
    <div class="image">
      <img src="<?php print $field_picture_evento_teaser[0]['url'];?>" />
    </div>
    <div class="right-column">
      <h2><a href="<?php print $node_url;?>"><?php print $title;?></a></h2>
      <div class="body">
        <?php print $body[0]['safe_value'];?>
      </div>
    </div>
  </div>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>