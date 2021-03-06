<?php

/**
 * Returns HTML for a breadcrumb trail.
 */
function qft_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  // Modify Breadcrumb
  qft_breadcrumb_alter($breadcrumb);
  if (!empty($breadcrumb)) {
    $output = '';

    // Override Drupal core breadcrumb item imploding (no arrow).
    //$output .= "<div class=\"breadcrumb-wrapper\">\n";
    $output .= "<ul class=\"breadcrumb\">\n";
    $list_items = array();
    $total = count($breadcrumb);
    foreach($breadcrumb as $i => $item) {
      if ( $i == ($total-1) ) {
        $class = 'class="last"';
      } else if ( $i == 0 ) {
        $class = 'class="first"';
      }
      $output .= "<li {$class}>{$item}</li>\n";
      if ( $i != ($total-1) ) {
        $output .= "<li class=\"separator\">/</li>\n";
      }
    }
    $output .= "</ul>\n";
    return $output;
  }
}

/**
 * Alters the Breadcrumb.
 */
function qft_breadcrumb_alter(&$breadcrumb) {
  // Node Page
  if ( arg(0) == 'node' && intval(arg(1)) > 0 && is_null(arg(2)) ) {
    qft_breadcrumb_alter_node($breadcrumb);
  }
  
  // Taxonomy Term Page
  if ( arg(0) == 'taxonomy' && arg(1) == 'term' && intval(arg(2)) > 0 && is_null(arg(3)) ) {
    qft_breadcrumb_alter_taxonomy_term($breadcrumb);
  }
  
  // Lugares
  if ( arg(0) == 'lugares' ) {
    $breadcrumb[] = "<span>Lugares</span>";
  }
}

/**
 * Alters the Breadcrumb for Node Pages.
 */
function qft_breadcrumb_alter_node(&$breadcrumb) {
  $node = node_load(arg(1));
  switch($node->type) {
    case 'event':
      qft_breadcrumb_alter_node_event($breadcrumb, $node);
      break;
  }
  $breadcrumb[] = "<span>{$node->title}</span>";
}

/**
 * Alters the Breadcrumb for Node Event Pages.
 */
function qft_breadcrumb_alter_node_event(&$breadcrumb, $node) {
  $tid = $node->field_lugar[$node->language][0]['tid'];
  $term = taxonomy_term_load($tid);
  $link = l($term->name, "taxonomy/term/{$tid}");
  $breadcrumb[] = $link;
  menu_tree_set_path('main-menu', 'eventos');
}

/**
 * Alters the Breadcrumb for Taxonomy Term Pages.
 */
function qft_breadcrumb_alter_taxonomy_term(&$breadcrumb) {
  $term = taxonomy_term_load(arg(2));
  $breadcrumb[] = "<span>{$term->name}</span>";
}