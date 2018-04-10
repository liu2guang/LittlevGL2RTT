# LittlevGL2RTT #

[![build](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/liu2guang/LittlevGL2RTT)
[![release](https://img.shields.io/badge/Release-TestInProcess-orange.svg)](https://github.com/liu2guang/LittlevGL2RTT/releases)

LittlevGL2RTT is a LittlevGL intermediate framework layer above the RTThread3.0 version, with the aim of seamlessly embedding RTT's LCD framework without the need for a developer to migrate.

LittlevGL2RTT 是在RTThread3.0版本以上做的LittlevGL中间框架层, 目的是无缝嵌入RTT的LCD框架, 无需开发者去移植. 

# Rendering / 效果图

![LittlevGL2RTT效果图](https://i.imgur.com/NBtHZma.jpg) 

--- 

# Using the tutorial

Currently, littlevgl2rtt library is not added to the official PKGS package of RTT, which needs to be added to env manually. 
1. Download the PKG package file for [https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT](https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT).
~~~
	The download file is as follows: 
	- LittlevGL2RTT(folder)
	| - Kconfig(file)
	| - package.json(file)
~~~
2. Store the PKG package file to `env_root/packages/packages/system/` . 
3. `env_root/packages/packages/system/Kconfig` add a line of code: `source "$PKGS_DIR/packages/system/LittlevGL2RTT/Kconfig"` 
4. Start the env input menuconfig command in the BSP that needs to add LittlevGL2RTT library, enter the system packages and select LittlevGL2RTT library.
5. Modify the corresponding configuration parameters of LittlevGL2RTT in menuconfig.

# 1. Notice

Because LittlevGL uses an anonymous structure, you need to add the compilation parameter in MDK: **-gnu -g -W**.

# 2. Using the notes

## 2.1 Image format conversion

Image format conversion web: [https://littlevgl.com/image-to-c-array](https://littlevgl.com/image-to-c-array "Image format conversion web")

## 2.2 Image Loading

For C arrays: 
1. Copy the result C file into your LittlevGL project.
2. In a C file of your application declare the image as: extern const lv_img_t my_image_name; or LV_IMG_DECLARE(my_image_name);
3. Set the image for an lv_img object: lv_img_set_src(img1, &my_image_name);

For externally binary files (e.g. SD card): 
1. Set up a new driver. To learn more read the Tutorial.
2. Set the image for an lv_img object: lv_img_set_src(img1, "S:/path/to/image");

--- 

# 使用教程

目前littlevgl2rtt库没有添加到rtt官方pkgs包中, 需要通过手动添加到env中.

1. 下载PKG包文件: [https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT](https://github.com/liu2guang/mypackages/tree/master/LittlevGL2RTT).
~~~
	下载文件如下: 
	- LittlevGL2RTT(folder)
	| - Kconfig(file)
	| - package.json(file)
~~~
2. 将pkg包文件存放到 `env_root/packages/packages/system/` 下. 
3. 在 `env_root/packages/packages/system/Kconfig` 文件中添加一行代码: `source "$PKGS_DIR/packages/system/LittlevGL2RTT/Kconfig"`
4. 在需要添加LittlevGL2RTT库的bsp中启动env输入menuconfig命令, 进入system packages选择LittlevGL2RTT库. 
5. menuconfig中修改LittlevGL2RTT对应配置参数.

# 1. 注意

因为LittlevGL使用了匿名结构体, 所以需要在MDK中需要添加编译参数: **--gnu -g -W**. 

# 2. 使用笔记 

## 2.1 图像格式转换 

图像格式转换网站: [https://littlevgl.com/image-to-c-array](https://littlevgl.com/image-to-c-array "图像格式转换网站")

## 2.2 图像加载

针对C数组IMG: 
1. 拷贝C文件到你的 LittlevGL 工程. 
2. 在你的应用C文件中声明IMG: extern const lv_img_t my_image_name; 或者LV_IMG_DECLARE(my_image_name); 
3. 显示图片: lv_obj_t *img1 = lv_label_create(lv_scr_act(), NULL); lv_img_set_src(img1, &my_image_name);

针对外部BIN文件(例如 SD中的BIN文件): 
1. Set up a new driver. To learn more read the Tutorial. `待翻译!!!!` 
2. 显示图片: lv_obj_t *img1 = lv_label_create(lv_scr_act(), NULL); lv_img_set_src(img1, "S:/path/to/image"); 
