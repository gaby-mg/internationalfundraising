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
      "REQUIRES" : [ "rules", "wsclient", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "commerce-order:owner" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        },
        { "data_is" : {
            "data" : [ "commerce-order:owner:profile-fundraiser:field-fundraiser-company" ],
            "value" : "international_fundraising"
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "commerce_customer_billing" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-billing" ],
            "field" : "commerce_customer_address"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-order" ],
            "field" : "commerce_customer_wv_adtnl_info"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-billing" ],
            "field" : "field_sponsorer_nif"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-order:commerce-customer-wv-adtnl-info" ],
            "field" : "field_phonenumber"
          }
        }
      ],
      "DO" : [
        { "wsclient_wv_international_fundraising_wv_intfund_upsert" : {
            "USING" : {
              "param_numero_formulario" : [ "commerce-order:order-id" ],
              "param_fundraiser_codigo" : [ "commerce-order:owner:profile-fundraiser:field-fundraiser-id" ],
              "param_fundraiser_nombre" : [ "commerce-order:owner:field-first-name" ],
              "param_metodo" : [ "commerce-order:owner:profile-fundraiser:field-fundraising-method" ],
              "param_provincia_captacion" : [ "commerce-order:owner:profile-fundraiser:field-fundraiser-state" ],
              "param_nombre" : [
                "commerce-order:commerce-customer-billing:commerce-customer-address:name-line"
              ],
              "param_direccion_calle" : [
                "commerce-order:commerce-customer-billing:commerce-customer-address:thoroughfare"
              ],
              "param_codigo_postal" : [
                "commerce-order:commerce-customer-billing:commerce-customer-address:postal-code"
              ],
              "param_poblacion" : [
                "commerce-order:commerce-customer-billing:commerce-customer-address:locality"
              ],
              "param_provincia" : [
                "commerce-order:commerce-customer-billing:commerce-customer-address:administrative-area"
              ],
              "param_nif" : [ "commerce-order:commerce-customer-billing:field-sponsorer-nif" ],
              "param_email" : [ "commerce-order:mail" ],
              "param_telefono" : [ "commerce-order:commerce-customer-wv-adtnl-info:field-phonenumber" ],
              "param_aportacion" : [ "commerce-order:commerce-order-total:amount-decimal" ],
              "param_periodicidad" : "PRUEBA",
              "param_debito" : "0",
              "param_proyecto" : "PRUEBA",
              "param_fecha_alta" : "now",
              "param_lopd" : "1"
            },
            "PROVIDE" : { "result" : { "result" : "International Fundraising Contact Update Response" } }
          }
        }
      ]
    }
  }');
  return $items;
}
