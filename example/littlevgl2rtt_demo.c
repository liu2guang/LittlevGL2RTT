#include "littlevgl2rtt.h" 
#include "lvgl.h" 

#include <rtthread.h> 
#include <rtdevice.h>  

extern const lv_img_t wallpaper1; 
extern const lv_img_t wallpaper2; 

static void lvgl_demo_run(void *p)
{
    uint8_t windex = 1; 
    uint16_t cnt = 0; 
    
    lv_obj_t *img = lv_img_create(lv_scr_act(), NULL); 
    lv_img_set_src(img, &wallpaper1);
    
    lv_obj_t *label =  lv_label_create(lv_scr_act(), NULL);
    lv_obj_align(label, img, LV_ALIGN_IN_TOP_RIGHT, 50, 272/2-16); 
    lv_label_set_recolor(label, true);
    lv_label_set_text(label, "Hello I am liuguang!\n#ff0000 LittlevGl2RTT#"); 

    while(1)
    {
        cnt++; 
        if(cnt == 100*5)
        {
            cnt = 0; 
            windex = 1-windex; 
            
            if(windex == 1)
            {
                lv_img_set_src(img, &wallpaper1);
            }
            else
            {
                lv_img_set_src(img, &wallpaper2);
            }
        }
        
        rt_thread_delay(RT_TICK_PER_SECOND/100);
        lv_task_handler(); 
    }
} 

int rt_lvgl_demo_init(void)
{
    rt_err_t ret = RT_EOK;
    rt_thread_t thread = RT_NULL; 

    /* init littlevGL */ 
    ret = littlevgl2rtt_init("lcd"); 
    if(ret != RT_EOK)
    {
        return ret; 
    }

    /* littleGL demo gui thread */ 
    thread = rt_thread_create("lv_demo", lvgl_demo_run, RT_NULL, 2048, 5, 10); 
    if(thread == RT_NULL)
    {
        return RT_ERROR;
    }
    rt_thread_startup(thread);

    return RT_EOK; 
}
INIT_APP_EXPORT(rt_lvgl_demo_init); 
