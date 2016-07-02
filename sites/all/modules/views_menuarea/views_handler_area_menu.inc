<?php
/**
 * @file
 * Views area handler class.
 */

class views_handler_area_menu extends views_handler_area {
  
  function option_definition() {
    $options = parent::option_definition();
    $options['menu'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    // Set dropdown of available menus
    $form['menu'] = array(
      '#type' => 'select',
      '#title' => t('Select menu'),
      '#description' => t('Choose the menu you want to list the links from.'),
      '#required' => TRUE,
      '#options' => menu_get_menus(),
      '#default_value' => $this->options['menu'],
    );
    
  }
  
  function render($empty = FALSE) {
    if (!empty($this->options['menu'])) {
      return render(menu_tree($this->options['menu']));
    }
    return '';
  }

}
