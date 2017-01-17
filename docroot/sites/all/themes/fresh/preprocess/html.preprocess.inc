<?php

/**
 * Implements hook_preprocess_html()
 * - We're hooking into the function to add stylesheets
 *
 * @see hook_preprocess_html()
 * @param $vars
 * @return [type] [description]
 */
function omega_zsl_preprocess_html(&$variables) {
  // Add Fonts CSS
  drupal_add_css(
    'https://fonts.googleapis.com/css?family=Lato:400,400italic,700,700italic,300italic,300',
    array('type' => 'external')
  );

  // Add Owl Carousel CSS and JS
  drupal_add_css(
    libraries_get_path('owl.carousel') . '/owl.carousel.css',
    array('group' => CSS_DEFAULT, 'every_page' => TRUE)
  );

  drupal_add_js(
    libraries_get_path('owl.carousel') . '/owl.carousel.js',
    array('group' => JS_DEFAULT, 'every_page' => TRUE)
  );

  drupal_add_js(
    libraries_get_path('zoom') . '/jquery.zoom.js',
    array('group' => JS_DEFAULT, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.carousel.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  // Theme CSS
  drupal_add_css(
    path_to_theme() . '/css/omega-zsl.styles.css',
    array('group' => CSS_DEFAULT, 'every_page' => TRUE)
  );

  // Theme JS
  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.utils.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.header.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.footer.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.forms.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.form-number.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.carousel.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(path_to_theme() . '/js/omega-zsl.pca.js');

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.responsive-table.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.product-filter.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  drupal_add_js(
    path_to_theme() . '/js/omega-zsl.adoptions.js',
    array('group' => JS_THEME, 'every_page' => TRUE)
  );

  // Apple touch icons
  $apple_icon_sizes = array(57,60,72,76,114,120,144,152,180);
  foreach($apple_icon_sizes as $size){
    $apple = array(
      '#tag' => 'link',
      '#attributes' => array(
        'href' => '/'.path_to_theme().'/images/favicons/apple-touch-icon-'.$size.'x'.$size.'.png',
        'rel' => 'apple-touch-icon-precomposed',
        'sizes' => $size . 'x' . $size,
      ),
    );
    drupal_add_html_head($apple, 'apple-touch-icon-'.$size);
  }

  // Android icons
  $andriod_icon_sizes = array(36,48,72,96,144,192);
  foreach($andriod_icon_sizes as $size){
    $android = array(
      '#tag' => 'link',
      '#attributes' => array(
        'href' => '/'.path_to_theme().'/images/favicons/android-chrome-'.$size.'x'.$size.'.png',
        'rel' => 'icon',
        'sizes' => $size . 'x' . $size,
      ),
    );
    drupal_add_html_head($android, 'android-chrome-'.$size);
  }
  if (drupal_is_front_page()) {
    $site_name = variable_get('site_name', 'ZSL Shop');
    $variables['head_title'] = $site_name . ' | Home';
  }


}
