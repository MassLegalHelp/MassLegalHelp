<?php
/**
 * @file
 * mlh_spam_prevention.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function mlh_spam_prevention_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_article_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['comment_node_article_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_book_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['comment_node_book_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_page_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['comment_node_page_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_panel_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['comment_node_panel_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_quiz_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_quiz_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_webform_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['comment_node_webform_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'contact_personal_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['contact_personal_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'contact_site_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['contact_site_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'print_mail_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['print_mail_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['user_login'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login_block';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['user_login_block'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_pass';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['user_pass'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_register_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['user_register_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29382';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['webform_client_form_29382'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29384';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29384'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29385';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29385'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29386';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29386'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29390';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29390'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29392';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29392'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29396';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29396'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29400';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29400'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29401';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29401'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29402';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29402'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29403';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29403'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_29404';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_29404'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65629';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65629'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65666';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65666'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65672';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65672'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65676';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65676'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65678';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65678'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65679';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65679'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65680';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65680'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65681';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65681'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65740';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65740'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65748';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65748'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65749';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65749'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65750';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65750'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65751';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65751'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65752';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65752'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_65753';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_65753'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'webform_client_form_99';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['webform_client_form_99'] = $captcha;

  return $export;
}
