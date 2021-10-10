# 前言
该代码仓主要用于存放红旭无线ESP32C3开发板的硬件、软件、教程等相关的内容。

# 开发板简介
[HX-DK-商](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-22286946226.12.7f292c2cfSNrZb&id=654877303965)，是红旭无线第二代无线通讯开发板，采用乐鑫ESP32-C系列的第一代产品ESP32-C3，其是一款安全稳定、低功耗、低成本的物联网芯片，搭载 RISC-V 32 位单核处理器 **（高达 160 MHz）**，同时 **支持`2.4 GHz Wi-Fi`，`全功能Bluetooth 5.0 (LE)`，`Bluetooth Mesh`，`WiFi Mesh`** 等协议，更多关于ESP32-C3的详情请参阅[乐鑫官网](https://www.espressif.com/zh-hans/products/socs/esp32-c3)。

<img src="./Tutorials/Asserts/hx_dk_shang.png" width = "" height = "" alt="" align=center />

[HX-DK-商](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-22286946226.12.7f292c2cfSNrZb&id=654877303965)的概貌如上图所示，关于更多HX-DK-商的内容，请参阅红旭无线公众号的推文[【新品上市】HX-DK-商，支持WiFi+BLE5.0](https://mp.weixin.qq.com/s/7ETvlsvo3OYlM7oS1uCpLA)

# 资料
鉴于红旭无线上一代[HX-DK-夏](https://item.taobao.com/item.htm?spm=a230r.1.14.20.b5f04a28o0GC0A&id=608555326842&ns=1&abbucket=20#detail)的市场反馈，此次HX-DK-商开发板将采用全实战教程的方式，来阐述ESP32-C3的无线通讯的性能，并顺带讲解无线通讯过程中所使用到的ESP32-C3外设，如`UART`，`SPI`，`I2C`等等。同时，也鉴于目前市场上充斥着大量ESP32系列的WiFi教程，所以基于HX-DK-商的实战教程的优先级如下：
1. 低功耗蓝牙 <font color=#FF0000>**（高）**</font>
1. SIG MESH <font color=#CF000>**（中）**</font>
1. WiFi <font color=#AF000>**（低）**</font>

## 硬件
### 原理图
[HX-DK-商开发板原理图](./Hardware/Schematic/HX-DK-商_V1.1.pdf)
### PCB图
[HX-DK-商开发板PCB图](./Hardware/Schematic/HX-DK-商_Layout_V1.1.pdf)
### ESP32-C3关键资料
1. [ESP32-C3规格书](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)
1. [ESP32-C3技术参考手册](https://www.espressif.com/sites/default/files/documentation/esp32-c3_technical_reference_manual_en.pdf)
1. [ESP32-C3编程指南](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html#introduction)


## 教程
由上面的[资料](#资料)章节可知，[HX-DK-商](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-22286946226.12.7f292c2cfSNrZb&id=654877303965)的教程分成三大块即`BLE`，`SIG MESH`，`WiFi`，教程的编写优先级也是从高->中->低这样依次排列。
### 公共基础篇
1. [【新手必读】如何下载HX-DK-商开发板资料](https://github.com/xiaolongba/wireless-tech/tree/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E5%BC%80%E5%8F%91%E6%9D%BF%E5%AE%9E%E6%88%98%E6%95%99%E7%A8%8B/%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8%E6%8C%87%E5%8D%97)
    
    阐述下载HX-DK系列开发板资料的方法
1. [【新手必读】红旭相关源码的约定俗称](https://github.com/xiaolongba/wireless-tech/blob/master/%E8%BD%AF%E4%BB%B6/%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF%E7%9A%84%E6%BA%90%E7%A0%81%E7%9B%B8%E5%85%B3%E7%9A%84%E7%BA%A6%E5%AE%9A%E4%BF%97%E7%A7%B0/README.md)

    讲解红旭无线教程后续所涉及到的代码约定俗称
1. [【新手必读】基于VSCODE的ESP32-C3开发环境的搭建](./Tutorials/Basic_Chapter/基于VSCODE的ESP32C3开发环境的搭建.md)

    详述了如何利用`VSCODE` + `Espressif IDF`插件，一步一步地搭建ESP32-C3的开发环境
1. [【新手必读】基于JTAG对ESP32-C3的调试及下载](./Tutorials/Basic_Chapter/基于JTAG对ESP32-C3的调试及下载.md)

    讲述了基于`VSCODE` + `Espressif IDF`插件的基础上，如何利用JTAG接口对ESP32-C3进行调试或下载

1. [【新手必读】初识ESP32-C3](./Tutorials/Basic_Chapter/初识ESP32-C3.md)

    介绍ESP32-C3的软硬件特性，常用的文档以及获取技术支持的方式，让新手可以更快地了解并使用ESP32-C3，避免网上过多的资料让新人无从下手
1. [【新手选读】ESP32-C3启动流程详解](./Tutorials/Basic_Chapter/ESP32-C3启动流程详解.md)

    细述了ESP32-C3从上电到app_main()函数的整个过程
1. [【新手必读】第一课：Hello World](./Software/Examples_Project/hello_world/README.md)

    利用[HX-DK-商](https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-22286946226.12.7f292c2cfSNrZb&id=654877303965)开发板，搭建第一个Hello World工程
    
### BLE

#### 基础篇

1. [【新手必读】BLE基础知识](./Tutorials/Basic_Chapter/BLE基础知识.md)

    介绍一些日常高频使用到的BLE知识点

1. [【新手必读】BLE的地址类型](./Tutorials/Basic_Chapter/BLE的地址类型.md)

    讲解不同BLE地址之间的区别
#### 广播篇
#### 扫描篇
#### 连接篇
#### 混合篇
#### 安全篇


### SIG MESH
占位，待补充

### WiFi
占位，待补充
# 关于我们
1. 技术交流论坛
    
    [![](https://img.shields.io/badge/BBS-bbs.wireless--tech.cn-red)](http://bbs.wireless-tech.cn/)

    强烈建议在这个论坛上寻求帮助，我们可以免费为您解答相关的技术问题，**论坛里有大佬(24小时内回复!!!)**。


1. CSDN-博客

    [![](https://img.shields.io/badge/CSDN--%E5%8D%9A%E5%AE%A2-https%3A%2F%2Fwireless--tech.blog.csdn.net%2F-red)](https://wireless-tech.blog.csdn.net/)

    相关的文字教程将映射至CSDN博客上，方便大家快速查阅。

1. 淘宝店铺

    [![](https://img.shields.io/badge/%E6%B7%98%E5%AE%9D%E5%BA%97%E9%93%BA-%E7%BA%A2%E6%97%AD%E6%97%A0%E7%BA%BF-red)](https://shop166249478.taobao.com/index.htm?spm=2013.1.w5002-22232069179.2.8354125781JKC9)

    对我们的硬件感兴趣的朋友，可以到上述的淘宝地址购买。
1. QQ群

    ![](https://img.shields.io/badge/QQ%E7%BE%A4-808014164-red)

    QQ群主要用于自主的技术以及行业信息交流，无广告纯技术探讨 **（仅限技术开发者加入，非技术人员请勿加入免得发现被踢）**。
1. 微信公众号

    <img src="https://bbs.wireless-tech.cn/assets/files/wirelessImage/WeChat_QRcode.png?tdsourcetag=s_pctim_aiomsg">

    不定期发布相关的技术动态消息或文章，也方便大家手机查看。
