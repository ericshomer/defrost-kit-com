<?php
/**
 * @file Rules integration for tropo_drupal.module
 */

/**
 * Implements hook_rules_condition_info().
 */
function tropo_drupal_rules_condition_info() {
  $conditions['user_notify'] = array(
    'label' => t('User is being notified'),
    'parameter' => array(
      'account' => array('type' => 'user', 'label' => t('User')),
    ),
    'base' => 'tropo_drupal_user_notified',
    'group' => t('User'),
  );

  return $conditions;
}

/**
 * Rules condition callback.
 * @param $account
 * @return bool
 */
function tropo_drupal_user_notified($account) {
  return (isset($account->notify) && $account->notify == TRUE);
}

/**
 * Implements hook_rules_action_info().
 */
function tropo_drupal_rules_action_info() {
  $actions['tropo_drupal_call'] = array(
    'parameter' => array(
      'number' => array(
        'type' => 'text',
        'label' => t('Phone number'),
        'save' => FALSE,
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Message to say'),
        'save' => FALSE,
      ),
    ),
    'label' => t('Make a phone call with Tropo'),
    'base' => 'tropo_drupal_call',
    'group' => t('Tropo'),
  );

  return $actions;
}

/**
 * Rules action callback.
 * @param $number
 * @param $message
 */
function tropo_drupal_call($number, $message) {
  $token = variable_get('tropo_drupal_token');
  $url = 'https://api.tropo.com/1.0/sessions';
  $query = array(
    'token' => $token,
    'message' => $message,
    'number' => $number,
    'action' => 'create',
  );
  $full_url = url($url, array('query' => $query));
  $response = drupal_http_request($full_url);
  $debug = variable_get('tropo_drupal_debug', FALSE);
  if ($debug) {
    watchdog('tropo_drupal', 'Outgoing Tropo request: <pre>@resp</pre>', array('@resp' => print_r($response, TRUE)), WATCHDOG_DEBUG);
  }
}