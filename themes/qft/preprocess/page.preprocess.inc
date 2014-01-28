<?php

/**
 * Implements hook_preprocess_page().
 */
function qft_preprocess_page(&$vars) {
  if ( arg(0) == 'node' && intval(arg(1)) > 0 && is_null(arg(2)) ) {
    if ( ($node = node_load(arg(1))) && $node->type == 'event' ) {
      $vars['theme_hook_suggestions'][] = 'page__node__event';
      $date = format_date($node->created, 'event');
      $vars['date'] = "<div class=\"node-date\">{$date}</div>";
      $vars['social_buttons'] = qft_social_buttons();
    }
  }
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
}

/**
 * Returns a block of Social Buttons.
 */
function qft_social_buttons() {
  $node_url = url('node/' . arg(1), array('absolute'=>TRUE));
  $output = "<div id=\"social-buttons\">
              <div class=\"fb-like\" data-href=\"http://www.google.com\" data-layout=\"button\" data-action=\"like\" data-show-faces=\"false\" data-share=\"false\"></div>
            </div>";
  return $output;
}