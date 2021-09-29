/** 
* @file         hx_adv_api.c
* @brief        红旭无线对外开放的BLE广播相关API
* @details      红旭无线基于乐鑫官方的API再次封装一层BLE相关的广播API函数，使得这些API更符合本广播示例工程的功能用途，
                更多的细节请参考本示例工程对应的文字教程               
* @author       红旭无线一哥，Wireless-tech
* @par Copyright (c):  
*               红旭无线开发团队
* @par Website:  
*               官网        ：www.wireless-tech.cn
                技术支持论坛 ：bbs.wireless-tech.cn
* @par History:          
*               Ver0.0.1:
                  Wireless-tech：2021/07/08, 初始化版本\n 
*/

/*
===========================
头文件包括
=========================== 
*/

#include "hx_adv_api.h"

/*
===========================
全局变量定义
=========================== 
*/
static const char *DEMO_TAG = "ADV_DEMO";

#if (ADV_MODE == ADV_RECEIVER)
static esp_ble_scan_params_t ble_scan_params = {
    .scan_type = BLE_SCAN_TYPE_ACTIVE,
    .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
    .scan_filter_policy = BLE_SCAN_FILTER_ALLOW_ALL,
    .scan_interval = 0x50,
    .scan_window = 0x30,
    .scan_duplicate = BLE_SCAN_DUPLICATE_DISABLE};

#elif (ADV_MODE == ADV_SENDER)
static esp_ble_adv_params_t ble_adv_params = {
    .adv_int_min = 0x20,
    .adv_int_max = 0x40,
    .adv_type = ADV_TYPE_NONCONN_IND,
    .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
    .channel_map = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};
#endif

/*
===========================
私有函数定义
=========================== 
*/

/**
* BLE GAP层的事件回调处理函数
*           
* @param[in]  event   GAP层的事件
* @param[in]  param   事件所携带的参数
* @retval      NULL
*/
static void esp_gap_cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{
  esp_err_t err;

  switch (event)
  {
  case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT:
  {
#if (ADV_MODE == ADV_SENDER)
    if(esp_ble_gap_start_advertising(&ble_adv_params) == ESP_OK)
    {
      ESP_LOGI(DEMO_TAG, "start adverstising successfully");
    }
    else
    {
      ESP_LOGE(DEMO_TAG, "start adverstising failed");
    }
#endif
    break;
  }
  case ESP_GAP_BLE_SCAN_PARAM_SET_COMPLETE_EVT:
  {
#if (IBEACON_MODE == IBEACON_RECEIVER)
    //the unit of the duration is second, 0 means scan permanently
    uint32_t duration = 0;
    esp_ble_gap_start_scanning(duration);
#endif
    break;
  }
  case ESP_GAP_BLE_SCAN_START_COMPLETE_EVT:
    //scan start complete event to indicate scan start successfully or failed
    if ((err = param->scan_start_cmpl.status) != ESP_BT_STATUS_SUCCESS)
    {
      ESP_LOGE(DEMO_TAG, "Scan start failed: %s", esp_err_to_name(err));
    }
    break;
  case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
    //adv start complete event to indicate adv start successfully or failed
    if ((err = param->adv_start_cmpl.status) != ESP_BT_STATUS_SUCCESS)
    {
      ESP_LOGE(DEMO_TAG, "Adv start failed: %s", esp_err_to_name(err));
    }
    break;
  case ESP_GAP_BLE_SCAN_RESULT_EVT:
  {
    esp_ble_gap_cb_param_t *scan_result = (esp_ble_gap_cb_param_t *)param;
    switch (scan_result->scan_rst.search_evt)
    {
    case ESP_GAP_SEARCH_INQ_RES_EVT:
      /* Search for BLE iBeacon Packet */
      // if (esp_ble_is_ibeacon_packet(scan_result->scan_rst.ble_adv, scan_result->scan_rst.adv_data_len))
      // {
      //   esp_ble_ibeacon_t *ibeacon_data = (esp_ble_ibeacon_t *)(scan_result->scan_rst.ble_adv);
      //   ESP_LOGI(DEMO_TAG, "----------iBeacon Found----------");
      //   esp_log_buffer_hex("IBEACON_DEMO: Device address:", scan_result->scan_rst.bda, ESP_BD_ADDR_LEN);
      //   esp_log_buffer_hex("IBEACON_DEMO: Proximity UUID:", ibeacon_data->ibeacon_vendor.proximity_uuid, ESP_UUID_LEN_128);

      //   uint16_t major = ENDIAN_CHANGE_U16(ibeacon_data->ibeacon_vendor.major);
      //   uint16_t minor = ENDIAN_CHANGE_U16(ibeacon_data->ibeacon_vendor.minor);
      //   ESP_LOGI(DEMO_TAG, "Major: 0x%04x (%d)", major, major);
      //   ESP_LOGI(DEMO_TAG, "Minor: 0x%04x (%d)", minor, minor);
      //   ESP_LOGI(DEMO_TAG, "Measured power (RSSI at a 1m distance):%d dbm", ibeacon_data->ibeacon_vendor.measured_power);
      //   ESP_LOGI(DEMO_TAG, "RSSI of packet:%d dbm", scan_result->scan_rst.rssi);
      // }
      break;
    default:
      break;
    }
    break;
  }

  case ESP_GAP_BLE_SCAN_STOP_COMPLETE_EVT:
    if ((err = param->scan_stop_cmpl.status) != ESP_BT_STATUS_SUCCESS)
    {
      ESP_LOGE(DEMO_TAG, "Scan stop failed: %s", esp_err_to_name(err));
    }
    else
    {
      ESP_LOGI(DEMO_TAG, "Stop scan successfully");
    }
    break;

  case ESP_GAP_BLE_ADV_STOP_COMPLETE_EVT:
    if ((err = param->adv_stop_cmpl.status) != ESP_BT_STATUS_SUCCESS)
    {
      ESP_LOGE(DEMO_TAG, "Adv stop failed: %s", esp_err_to_name(err));
    }
    else
    {
      ESP_LOGI(DEMO_TAG, "Stop adv successfully");
    }
    break;

  default:
    break;
  }
}

/**
* 注册BLE GAP层的事件回调处理函数
*           
* @param[in]  NULL   
* @param[in]  NULL   
* @retval     NULL
*/
static void ble_adv_appRegister(void)
{
  esp_err_t status;

  ESP_LOGI(DEMO_TAG, "register callback");

  //register the scan callback function to the gap module
  if ((status = esp_ble_gap_register_callback(esp_gap_cb)) != ESP_OK)
  {
    ESP_LOGE(DEMO_TAG, "gap register error: %s", esp_err_to_name(status));
    return;
  }
}

/**
* 配置ESP32-C3 BLE的广播数据参数
*           
* @param[in]  NULL   
* @param[in]  NULL   
* @retval     NULL
*/
static void ble_adv_init(void)
{
  esp_err_t status;
  char device_name[]={0xE7,0xBA,0xA2,0xE6,0x97,0xAD,0xE6,0x97,0xA0,0xE7,0xBA,0xBF};

  esp_ble_adv_data_t ble_adv_data = {
      .include_name = 1,
      .include_txpower = 1,
      .flag = ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT,
  };

  if (esp_ble_gap_set_device_name("test1234567890123456789") == ESP_OK)
  {
    ESP_LOGI(DEMO_TAG, "set device name successfully");
  }
  else
  {
    ESP_LOGE(DEMO_TAG, "set device name failed");
  }

  status = esp_ble_gap_config_adv_data(&ble_adv_data);
  if (status == ESP_OK)
  {
    ESP_LOGI(DEMO_TAG, "configure adv data successfully");
  }
  else
  {
    ESP_LOGE(DEMO_TAG, "configure adv data failed");
  }
}

/*
===========================
公有函数定义
=========================== 
*/

/**
* ESP32-C3 BLE协议栈及GAP事件回调处理函数初始化
*           
* @param[in]  NULL   
* @param[in]  NULL   
* @retval     NULL
*/
void ble_init(void)
{
  ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_BLE));
  esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
  esp_bt_controller_init(&bt_cfg);
  esp_bt_controller_enable(ESP_BT_MODE_BLE);

  esp_bluedroid_init();
  esp_bluedroid_enable();
  ble_adv_appRegister();
  ble_adv_init();
}
