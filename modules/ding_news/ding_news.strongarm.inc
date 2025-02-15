<?php
/**
 * @file
 * ding_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ding_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'autosave_ding_news';
  $strongarm->value = 1;
  $export['autosave_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ding_news';
  $strongarm->value = 0;
  $export['comment_anonymous_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ding_news';
  $strongarm->value = 0;
  $export['comment_default_mode_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ding_news';
  $strongarm->value = '10';
  $export['comment_default_per_page_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ding_news';
  $strongarm->value = '1';
  $export['comment_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ding_news';
  $strongarm->value = 1;
  $export['comment_form_location_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ding_news';
  $strongarm->value = '0';
  $export['comment_preview_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ding_news';
  $strongarm->value = 0;
  $export['comment_subject_field_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__ding_news';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_highlight' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'workflow_tab' => array(
        'custom_settings' => FALSE,
      ),
      'block_feature' => array(
        'custom_settings' => TRUE,
      ),
      'alternative_layout_full' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(
        'webform' => array(
          'teaser' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'teaser_highlight' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'block_feature' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'alternative_layout_full' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser_no_overlay' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'ding_serendipity_info' => array(
          'alternative_layout_full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser_no_overlay' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'flag_mobile_app_default_ding_news';
  $strongarm->value = 1;
  $export['flag_mobile_app_default_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'flag_push_to_mongo_default_ding_news';
  $strongarm->value = 1;
  $export['flag_push_to_mongo_default_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ding_news';
  $strongarm->value = '1';
  $export['language_content_type_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ding_news';
  $strongarm->value = array();
  $export['menu_options_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ding_news';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ding_news';
  $strongarm->value = '1';
  $export['node_preview_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ding_news';
  $strongarm->value = 1;
  $export['node_submitted_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_ding_news_pattern';
  $strongarm->value = 'nyheder/[node:field_ding_news_category]/[node:title]';
  $export['pathauto_node_ding_news_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_news_category_pattern';
  $strongarm->value = 'nyheder/[term:name]';
  $export['pathauto_taxonomy_term_news_category_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_ding_news';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_ding_news';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_ding_news';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_ding_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_ding_news';
  $strongarm->value = 1;
  $export['webform_node_ding_news'] = $strongarm;

  return $export;
}
