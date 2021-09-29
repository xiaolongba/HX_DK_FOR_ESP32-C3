/** 
* @file         adv_demo_main.c
* @brief        BLE广播demo
* @details      本示例工程会阐述ESP32-C3所支持的所有类型的广播，但是需要用不同的宏切换不同类型的广播，
                用户可以通过menuconfig来选择不同的广播类型
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

#include "nvs_flash.h"
#include "hx_adv_api.h"

/*
===========================
主函数
=========================== 
*/

/**
* 整个示例工程的入口函数
* @param[in]  NULL
* @retval     NULL
*/
void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ble_init();

    /* set scan parameters */
#if (ADV_MODE == ADV_RECEIVER)
    esp_ble_gap_set_scan_params(&ble_scan_params);

#elif (ADV_MODE == ADV_SENDER)
    // esp_ble_ibeacon_t ibeacon_adv_data;
    // esp_err_t status = esp_ble_config_ibeacon_data (&vendor_config, &ibeacon_adv_data);
    // if (status == ESP_OK){
    //     esp_ble_gap_config_adv_data_raw((uint8_t*)&ibeacon_adv_data, sizeof(ibeacon_adv_data));
    // }
    // else {
    //     ESP_LOGE(DEMO_TAG, "Config iBeacon data failed: %s\n", esp_err_to_name(status));
    // }
#endif
}
