# 前言
在BLE领域中，地址是每个BLE设备不可或缺的重要组成部分，其就类似于我们日常的住宅地址；那么，BLE的地址有哪几种？

# 公共地址（Public Address）
BLE的公共地址，就类似于我们日常的身份证号码，是全球唯一的且不可改变的，不同的是：
1. 为了保证BLE公共地址的全球唯一性，需要向[IEEE](https://standards.ieee.org/products-services/regauth/index.html)购买，然后IEEE组织就会对应地分配公共地址；
1. 如果想要查询某BLE设备的公共地址是哪个厂商的，则可以点此[链接](https://regauth.standards.ieee.org/standards-ra-web/pub/view.html#registries)查询；
1. 其是全球唯一的且不变的，存在于BLE设备的整个生命周期；
1. 总长度为6个字节，组成结构如下图所示：



# 随机地址（Random Address）
## 静态地址（Static Address）
## 私有地址（Private Address）
### 不可解析私有地址（Non-resolvable private address)
### 可解析私有地址（Resolvable private address）
