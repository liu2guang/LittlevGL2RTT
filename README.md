# LittlevGL2RTT Lib #

[![build](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/liu2guang/LittlevGL2RTT)
[![release](https://img.shields.io/badge/Release-TestInProcess-orange.svg)](https://github.com/liu2guang/LittlevGL2RTT/releases)

LittlevGL2RTT is a LittlevGL intermediate framework layer above the RTThread3.0 version, with the aim of seamlessly embedding RTT's LCD framework without the need for a developer to migrate.

LittlevGL2RTT 是在RTThread3.0版本以上做的LittlevGL中间框架层, 目的是无缝嵌入RTT的LCD框架, 无需开发者去移植. 

![LittlevGL2RTT效果图](https://i.imgur.com/NBtHZma.jpg) 

# 1. notice/注意

Because LittlevGL uses an anonymous structure, you need to add the compilation parameter in MDK: **-gnu -g -W**.

因为LittlevGL使用了匿名结构体, 所以需要在MDK中需要添加编译参数: **--gnu -g -W**. 

# 2. Using the notes/使用笔记 

## 2.1 Image format conversion/图像格式转换 

Image format conversion web/图像格式转换网站: [https://littlevgl.com/image-to-c-array](https://littlevgl.com/image-to-c-array "Image format conversion web/图像格式转换网站")

## 2.2 Image Loading/图像加载

For C arrays: 
1. Copy the result C file into your LittlevGL project.
2. In a C file of your application declare the image as: extern const lv_img_t my_image_name; or LV_IMG_DECLARE(my_image_name);
3. Set the image for an lv_img object: lv_img_set_src(img1, &my_image_name);

For externally binary files (e.g. SD card): 
1. Set up a new driver. To learn more read the Tutorial.
2. Set the image for an lv_img object: lv_img_set_src(img1, "S:/path/to/image");

针对C数组IMG: 
1. 拷贝C文件到你的 LittlevGL 工程. 
2. 在你的应用C文件中声明IMG: extern const lv_img_t my_image_name; 或者LV_IMG_DECLARE(my_image_name); 
3. 显示图片: lv_obj_t *img1 = lv_label_create(lv_scr_act(), NULL); lv_img_set_src(img1, &my_image_name);

针对外部BIN文件(例如 SD中的BIN文件): 
1. Set up a new driver. To learn more read the Tutorial. `待翻译!!!!` 
2. 显示图片: lv_obj_t *img1 = lv_label_create(lv_scr_act(), NULL); lv_img_set_src(img1, "S:/path/to/image"); 
