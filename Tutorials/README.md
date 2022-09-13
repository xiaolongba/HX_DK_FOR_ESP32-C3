# HX-DK-商教程大纲
## 第1章 基础篇----基础不牢，地动山摇
### [1.1 初识ESP32-C3](第1章%20基础篇----基础不牢，地动山摇/1.1%20初识ESP32-C3.md)
  - 1.1.1 ESP32-C3 背景介绍
  - 1.1.2 开发环境搭建
    - 1.1.2.1 开发方式
    - 1.1.2.2 软件开发套件
    - 1.1.2.3 工具及软件开发套件下载
  - 1.1.3 资料
  - 1.1.4 技术支持
### [1.2 基于VSCode的ESP32-C3开发环境的搭建](第1章%20基础篇----基础不牢，地动山摇/1.2%20基于VSCode的ESP32-C3开发环境的搭建.md)
- 1.2.1 准备工作
- 1.2.2 开发环境搭建
  - 1.2.2.1 SDK
  - 1.2.2.2 工具包
  - 1.2.2.3 Espressif IDF插件
  - 1.2.2.4 更新
- 1.2.3 实验
  - 1.2.3.1 新建一个工程
  - 1.2.3.2 编译\&下载\&监控一个工程
  - 1.2.3.3 代码补全及函数跳转

### [1.3 基于JTAG对ESP32-C3的调试及下载](第1章%20基础篇----基础不牢，地动山摇/1.3%20基于JTAG对ESP32-C3的调试及下载.md)
- 1.3.1 JTAG接口
  - 1.3.1.1 内置的USB-SERIAL-JTAG
  - 1.3.1.2 实验一
    - 1.3.1.2.1 下载
      - 1.3.1.2.1.1 UART下载
      - 1.3.1.2.1.2 JTAG下载
    - 1.3.1.2.2 调试仿真
  - 1.3.1.3 外置的ESP-Prog
  - 1.3.1.4 实验二
    - 1.3.1.4.1 下载
      - 1.3.1.4.1.1 UART下载
      - 1.3.1.4.1.2 JTAG下载
    - 1.3.1.4.2 调试仿真

## 外设篇
### SPI
### I2C
### I2S
### UART
### GPIO
### RTC_GPIO
### TWAI
### RMT
### eFuse Controller
### RTC Super Watchdog Timer
### GDMA
### DIG ADC Controller
### RTC Watchdog Timer
### LED PWM
### USB Serial/JTAG
### System Timer
### Temperature Sensor
### General-purpose Timers
### Main System Watchdog Timers

## 安全篇
### SHA
### RSA
### AES
### RNG
### HMAC
### Digital Signature
### Secure Boot
### Flash Encryption

## Bluetooth LE 从机篇
### 广播
- [4.1.1 Bluetooth LE地址](#411-bluetooth-le地址)
  - [4.1.2 公有地址（Public Address）](#412-公有地址public-address)
  - [4.1.3 随机地址（Random Address）](#413-随机地址random-address)
    - [4.1.3.1 静态地址（Static Address）](#4131-静态地址static-address)
    - [4.1.3.2 私有地址（Private Address）](#4132-私有地址private-address)
      - [4.1.3.2.1 可解析私有地址（Resolvable Private Address）](#41321-可解析私有地址resolvable-private-address)
      - [4.1.3.2.2 不可解析私有地址（Non-Resolvable Private Address)](#41322-不可解析私有地址non-resolvable-private-address)
- [4.1.2 不同地址的区别](#412-不同地址的区别)
  - [4.1.2.1 公共地址（Public Address）](#4121-公共地址public-address)
  - [4.1.2.2 静态地址（Static Address）](#4122-静态地址static-address)
  - [4.1.2.3 可解析私有地址（Resolvable Private Address）](#4123-可解析私有地址resolvable-private-address)
  - [4.1.2.4 不可解析私有地址（Non-Resolvable Private Address)](#4124-不可解析私有地址non-resolvable-private-address)
- [4.1.3 结语](#413-结语)
### 串口透传
#### 服务
#### 特征值
#### 属性与权限
#### 描述符
### 发射功率
### 连接间隔更新
### MTU交换
### 数据长度扩展
### PHY切换
#### 2M PHY
#### CODED PHY
### 配对与绑定
### 一从多主
### 空中升级

## Bluetooth LE 主机篇
### 扫描
### 连接Bluetooth LE外设
#### 传统广播
#### 扩展广播
### 串口透传
#### 服务
#### 特征值
#### 属性与权限
#### 描述符
### 发射功率
### 连接间隔更新
### MTU交换
### 数据长度扩展
### PHY切换
#### 2M PHY
#### CODED PHY
### 配对与绑定
### 一主多从

## Bluetooth LE 综合篇
### 主从一体
### 多主多从
### 基于Bluetooth LE的按键应用
### 基于Bluetooth LE的Flash存储
### 基于Bluetooth LE的温湿度传感器应用
### 基于Bluetooth LE的OLED屏应用
### Bluetooth LE 吞吐量
#### 一主一从
#### 一主多从
#### LL 传输
### Bluetooth LE iBeacon
### Bluetooth LE ANCS
### 基于功耗分析仪的Bluetooth LE功耗分析
### 利用捉包器分析Bluetooth LE数据

## Bluetooth LE MESH篇
### 搭建Bluetooth LE MESH开发环境
### 不同认证方式的Bluetooth LE MESH入网过程
### 单播和组播的实现
### 基于按键的单播和组播
### Friend节点与Low Power节点
### 创建Bluetooth LE MESH网络
### Bluetooth LE MESH多角色的实现
### Vendor Model
### 基于Bluetooth LE MESH网络的大数据透传
### 接入天猫精灵
### 基于HeartBeat包实现节点的掉线监控
### Bluetooth LE MESH网络节点的增删减查
### 利用捉包器分析Bluetooth LE MESH数据