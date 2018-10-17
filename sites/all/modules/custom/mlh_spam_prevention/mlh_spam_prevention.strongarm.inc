<?php
/**
 * @file
 * mlh_spam_prevention.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mlh_spam_prevention_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_add_captcha_description';
  $strongarm->value = 1;
  $export['captcha_add_captcha_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_administration_mode';
  $strongarm->value = 0;
  $export['captcha_administration_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_allow_on_admin_pages';
  $strongarm->value = 0;
  $export['captcha_allow_on_admin_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_challenge';
  $strongarm->value = 'captcha/Math';
  $export['captcha_default_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_challenge_on_nonlisted_forms';
  $strongarm->value = 0;
  $export['captcha_default_challenge_on_nonlisted_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_validation';
  $strongarm->value = '1';
  $export['captcha_default_validation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_ab';
  $strongarm->value = 'This question is for testing whether or not you are a human visitor and to prevent automated spam submissions.';
  $export['captcha_description_ab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_en';
  $strongarm->value = 'Please help us cut down on spam. Type the letters you see into the box below.';
  $export['captcha_description_en'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_es';
  $strongarm->value = 'Ayúdenos a minimizar el spam. Tecleé las letras que ve en la casilla más abajo.';
  $export['captcha_description_es'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_ht';
  $strongarm->value = 'Silvouplè ede nou diminye papye initil. Tape lèt yo wou wè a nan Liy anba a.';
  $export['captcha_description_ht'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_pt';
  $strongarm->value = 'Por favor, ajude-nos a combater os spams. Digite as letras no campo abaixo.';
  $export['captcha_description_pt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_ru';
  $strongarm->value = 'Пожалуйста помогите нам бороться со спамом. Введите изображенные буквы в поле ниже.';
  $export['captcha_description_ru'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_vi';
  $strongarm->value = 'Hãy giúp chúng tôi cắt giảm những thư rác. Đưa những chữ cái bạn nhìn thấy vào ô dưới đây.';
  $export['captcha_description_vi'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_zh-hans';
  $strongarm->value = 'This question is for testing whether or not you are a human visitor and to prevent automated spam submissions.';
  $export['captcha_description_zh-hans'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description_zh-hant';
  $strongarm->value = '請幫助我們減少垃圾郵件。在下面的方框中輸入你看見的字母。';
  $export['captcha_description_zh-hant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_captcha_private_key';
  $strongarm->value = '6LdorAMTAAAAAPL_rIVQVka3yyeJRwYSkRoION7h';
  $export['google_captcha_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_captcha_site_key';
  $strongarm->value = '6LdorAMTAAAAACLh7PdA3bAwMa_XeJPmhHvsiBRY';
  $export['google_captcha_site_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_secret_key';
  $strongarm->value = '6LehXHUUAAAAAHPa9gII_S7PlLw_B_ZPIOztLtJ7';
  $export['recaptcha_secret_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_site_key';
  $strongarm->value = '6LehXHUUAAAAAAn1E2AfRyZm-6oIFtCc2ovyN_Nt';
  $export['recaptcha_site_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_size';
  $strongarm->value = '';
  $export['recaptcha_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_tabindex';
  $strongarm->value = '0';
  $export['recaptcha_tabindex'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_theme';
  $strongarm->value = 'light';
  $export['recaptcha_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'recaptcha_type';
  $strongarm->value = 'image';
  $export['recaptcha_type'] = $strongarm;

  return $export;
}
