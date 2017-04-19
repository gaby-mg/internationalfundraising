<?php
/**
 * @file
 * international_fundraising.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function international_fundraising_default_rules_configuration() {
  $items = array();
  $items['rules_wv_intfund_upsert'] = entity_import('rules_config', '{ "rules_wv_intfund_upsert" : {
      "LABEL" : "Update International Fundraising Contact",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "World Vision" ],
      "REQUIRES" : [ "wsclient", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "wsclient_wv_international_fundraising_wv_intfund_upsert" : {
            "USING" : {
              "param_numero_formulario" : [ "commerce-order:order-id" ],
              "param_fundraiser_codigo" : "PRUEBA"
            },
            "PROVIDE" : { "result" : { "result" : "International Fundraising Contact Update Response" } }
          }
        }
      ]
    }
  }');
  return $items;
}
