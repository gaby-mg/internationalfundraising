<?php
/**
 * @file
 * international_fundraising.features.inc
 */

/**
 * Implements hook_default_wsclient_service().
 */
function international_fundraising_default_wsclient_service() {
  $items = array();
  $items['wv_international_fundraising'] = entity_import('wsclient_service', '{
    "settings" : {
      "authentication" : {
        "type" : "basic",
        "basic" : { "username" : "WorldVision", "password" : "Jv4rdXa19je2cmV" },
        "wss" : { "username" : "", "password" : "" },
        "oauth2" : {
          "auth_flow" : "client-credentials",
          "token_endpoint" : "",
          "client_id" : "",
          "client_secret" : "",
          "scope" : "",
          "query_auth" : "0",
          "redirect_uri" : "",
          "authorization_endpoint" : "",
          "username" : "",
          "password" : ""
        }
      },
      "send_formatter" : {
        "class" : "WsclientRestJSONFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      },
      "receive_formatter" : {
        "class" : "WsclientRestJSONFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      }
    },
    "operations" : { "wv_intfund_upsert" : {
        "type" : "POST",
        "url" : "\\/worldvision.php",
        "label" : "Update Contact",
        "parameter" : {
          "numero_formulario" : { "type" : "text", "allow null" : 0 },
          "fundraiser_codigo" : { "type" : "text", "allow null" : 0 }
        },
        "result" : {
          "type" : "text",
          "label" : "International Fundraising Contact Update Response"
        }
      }
    },
    "datatypes" : [],
    "global_parameters" : [],
    "global_header_parameters" : [],
    "name" : "wv_international_fundraising",
    "label" : "International Fundraising",
    "url" : "https:\\/\\/www.grupofundraising.es",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
