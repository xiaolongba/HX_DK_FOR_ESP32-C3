# 前言
ESP32-C3，是乐鑫于2020年11月27日向外公布的一款低成本高性能且注重安全的**WiFi4 & BLE 5.0** SoC；同时，其也是乐鑫ESP32家族C系列第一款采用RISC-V内核的芯片；然而，其在2021年4~5月份才开始真正推向市场。所以目前官方和第三方关于ESP32-C3的资料都非常的匮乏，这也很容易导致新人在入手这颗芯片时，由于多如牛毛的旧的ESP32资料的干扰，一方面打击了新手的自信性，另一方面会因资料与芯片不匹配而浪费大量的时间。因此，小编在本篇文章将带领新人如何快速认识并使用ESP32-C3。

# 开发环境搭建
阻碍新人玩转ESP32-C3的最大拦路虎就是开发环境的搭建，主要的问题点如下所示：

1. 问题最多的就是Windows环境，因为用于开发ESP32-C3的很多工具都是Linux系统天生自带的，同样的工具想要在Windows系统上运行，或多或少会存在兼容性和水土不服的情况；
1. 其次就是苹果的Mac系统，但是得益于Mac OS是基于Unix内核开发的界面操作系统，与Linux系统的兼容性会比Windows系统好很多，自然在Mac系统开发ESP32-C3就会顺畅很多，毕竟Linux和Unix之间有血缘关系；
1. 最后，开发ESP32-C3体验最好的就是Linux系统了；

综上所述，如果大家平时主力使用的系统就是Linux或者Mac，那么小编强烈推荐使用[Linux和Mac开发ESP32-C3](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html#step-1-install-prerequisites)。当然，如果是使用Windows系统开发ESP32-C3，相较于以前现在问题也不是很大，只是稍微有点曲折，这里小编推荐[基于VSCODE的ESP32-C3开发环境的搭建](./基于VSCODE的ESP32C3开发环境的搭建.md)和[基于JTAG对ESP32-C3的调试及下载](./Tutorials/Basic_Chapter/基于JTAG对ESP32-C3的调试及下载.md)，相较于官网的教程这两篇教程会更加符合新人，尤其是用习惯了IAR和KEIL的新人，其基本融合了IAR和KEIL大部分同样的功能；当然，如果你仍然觉得官网推出的教程更佳，则请单击[跳转](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html#step-1-install-prerequisites)。

# 开发工具
开发工具也是困扰新人的另一个绊脚石，有用`纯命令行`，`Eclipse＋插件`，`VScode＋插件`，`Microsoft VS＋插件`以及`第三方的一些工具`，可谓是五花八门；让新人迷失了方向，导致不知道选择哪个才是最稳定可靠、好用以及有乐鑫官方维护的。这里小编强烈推荐使用**VScode+插件**方式进行ESP32-C3的代码开发，因为VScode是一个跨平台的文本编辑器，配合各式各样的插件可以大大地提高工作效率，至于如何使用它们请参考上述[开发环境搭建](#开发环境搭建)中推荐的两篇文章，而其他方式请读者们自行查找。

# 软件开发
同样这也是一个让新人一脸懵逼地选择，目前有[ESP-IDF](https://github.com/espressif/esp-idf)，[ARDUINO-ESP32](https://github.com/espressif/arduino-esp32)，Micro-Python，Lua，Javascript等等这几种软件开发方式；对于这么多类型的软件开发，小编推荐的意见如下：

1. 【推荐★★★★★】，如果是想要使用ESP32-C3开发产品，则老老实实使用[ESP-IDF](https://github.com/espressif/esp-idf)，功能最全且更新最快；
1. 【推荐★★★】，如果是想要搞搞DIY，则使用[ARDUINO-ESP32](https://github.com/espressif/arduino-esp32)，但有可能你想要的功能没有对应的接口；
1. 【推荐★】，熟悉Python的又只是想搞DIY的，可以使用Micro-Python，但是是由第三方进行维护；
1. 【不推荐】，对于从互联网转过来的工程师，则可以选择Lua和Javascript，非主流的开发方式；

# 工具及软件下载
这也是很多新人吐槽最多的一个点，由于很多工具和软件的镜像并没有放在国内的服务器，导致用户下载的时候会很慢，以下的方法可以解决此问题：
1. [【推荐★★★★★】，乐鑫官方的Gitee仓库](https://gitee.com/EspressifSystems)

    镜像已经同步至国内的服务器，下载速度非常快，但是有些周折；

1. [【推荐★★★】，专用的梯子](https://efanccyun.net/aff.php?aff=527)

    如果有些仓库，乐鑫官方的Gitee没有同步过来，那就需要这个工程师必备的居家良药，也是小编使用这么多付费梯子中最稳的一把，但仅限于技术资料探讨及查询；


# 资料
对于日常的ESP32-C3开发，所使用到的必备资料如下：
1. [ESP32-C3规格书](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)
1. [ESP32-C3技术参考手册](https://www.espressif.com/sites/default/files/documentation/esp32-c3_technical_reference_manual_en.pdf)
1. [ESP32-C3编程指南](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html#introduction)
1. [红旭的ESP32-C3系列教程](../../README.md#教程)
1. [乐鑫官方的参考例程](https://github.com/espressif/esp-idf/tree/master/examples)

以上资料已经满足大部分的使用场景，无特殊情况无须额外的资料。

# 技术支持
如果在开发ESP32-C3遇到一些技术的难题，可以通过以下渠道获取得到技术支持：

1. [【推荐★★★★★】，乐鑫官方的Github的Issues](https://github.com/espressif/esp-idf/issues)

    有乐鑫官方专人解答，响应速度以及回复质量是最高的；

1. [【推荐★★★】，乐鑫官方的ESP32论坛](https://www.esp32.com/viewforum.php?f=23)

    有乐鑫官方专人解答，但是响应速度和回答率并没有Github的Issues高；

1. 【推荐★★★★】，乐鑫官方的技术支持邮件<sales@espressif.com>

    对于不擅长英文的工程师，可以采用这种方式，但是由于FAE的能力水平参差不齐，有时解决一个问题会花费很长一段时间，平均的响应速度不是太快，但略好于乐鑫官方的ESP32论坛；

1. [【推荐★★★★】，红旭技术论坛](https://bbs.wireless-tech.cn/)

    红旭无线有专人解答，但仅限于ESP32-C3无线相关的Issues；

1. 
    ![](https://img.shields.io/badge/QQ%E7%BE%A4-808014164-red)

    ESP32-C3相关问题可以在此ＱＱ群自由讨论；