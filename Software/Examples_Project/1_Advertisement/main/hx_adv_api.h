/** 
* @file         hx_adv_api.h
* @brief        hx_adv_api.c的头文件
* @details      用于声明hx_adv_api.c对外开放的函数             
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

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_defs.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

/*
===========================
宏定义
=========================== 
*/

/* 当前的ESP IDF还不支持同时扫描和广播，所以需要通过宏来选择广播还是扫描 */
#define ADV_SENDER                0
#define ADV_RECEIVER              1
#define ADV_MODE CONFIG_ADV_MODE


/*
===========================
函数声明
=========================== 
*/
/**
* ESP32-C3 BLE协议栈及GAP事件回调处理函数初始化
*           
* @param[in]  NULL   
* @param[in]  NULL   
* @retval     NULL
*/
void ble_init(void);
