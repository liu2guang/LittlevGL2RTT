# LittlevGL2RTT #

[![Build Status](https://travis-ci.org/liu2guang/LittlevGL2RTT.svg?branch=master)](https://travis-ci.org/liu2guang/LittlevGL2RTT)
[![release](https://img.shields.io/badge/Release-v0.0.1-orange.svg)](https://github.com/liu2guang/LittlevGL2RTT/releases)

LittlevGL2RTT 是在RTThread3.0版本以上做的LittlevGL中间框架层, 目的是无缝嵌入RTT的LCD框架, 无需开发者去移植. 如果您觉得该库看得顺眼舒服，请捐赠颗小星星. 小星星就是更新的动力!!! 

感谢LittlevGL作者的开源GUI库. 原库请移步到 [https://github.com/littlevgl/lvgl](https://github.com/littlevgl/lvgl "lvgl"). 

## 1. 效果图

![Rendering](https://i.imgur.com/hdq3RhV.gif)

## 2. 使用教程

目前littlevgl2rtt库没有添加到rtt官方pkgs包中, 需要通过手动添加到env中.

1. 下载PKG包文件: [https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT](https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT).
~~~
	下载文件如下: 
	- LittlevGL2RTT(文件夹)
	| - Kconfig(文件)
	| - package.json(文件)
~~~
2. 将pkg包文件存放到 `env_root/packages/packages/system/` 下. 
3. 在 `env_root/packages/packages/system/Kconfig` 文件中添加一行代码: `source "$PKGS_DIR/packages/system/LittlevGL2RTT/Kconfig"`
4. 在需要添加LittlevGL2RTT库的bsp中启动env输入menuconfig命令, 进入system packages选择LittlevGL2RTT库. 
5. menuconfig中修改LittlevGL2RTT对应配置参数.
6. 编译下载运行. 

## 3. 注意事项

因为LittlevGL使用了匿名结构体, 所以需要在MDK中需要添加编译参数: **--gnu -g -W**. 
