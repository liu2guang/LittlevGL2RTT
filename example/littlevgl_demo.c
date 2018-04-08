#include "littlevgl2rtt.h" 

#include <rtthread.h> 
#include <rtdevice.h> 

static void lvgl_demo_run(void *p)
{
    lv_obj_t *tab; 
    lv_obj_t *tab1; 
    lv_obj_t *tab2; 
    lv_obj_t *tab3; 
    
    // lv_theme_t* theme = lv_theme_zen_init(22, NULL); 
    lv_theme_t* theme = lv_theme_material_init(16, NULL); 
    lv_theme_set_current(theme); 
    
    lv_obj_t* win = lv_win_create(lv_scr_act(), NULL); 
    lv_win_set_title(win, "LittlevGl 5.1"); 
    
    lv_win_add_btn(win, SYMBOL_CLOSE, NULL); 
    lv_win_add_btn(win, SYMBOL_UPLOAD, NULL); 
    lv_win_add_btn(win, SYMBOL_BLUETOOTH, NULL); 
    
    tab = lv_tabview_create(win, NULL); 
    tab1 = lv_tabview_add_tab(tab, "tabview1"); 
    tab2 = lv_tabview_add_tab(tab, "tabview2"); 
    tab3 = lv_tabview_add_tab(tab, "tabview3"); 
    lv_tabview_set_anim_time(tab, 1000); 
    
    lv_obj_t* btn1 = lv_btn_create(tab1, NULL); 
    lv_obj_set_size(btn1, 160, 60); 
    lv_obj_align(btn1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0); 
    
    lv_obj_t* label = lv_label_create(btn1, NULL); 
    lv_label_set_text(label, "Hello!\n#ffff00 LittlevGl2RTT#"); 
    lv_label_set_anim_speed(label, 30); 
    lv_label_set_long_mode(label, LV_LABEL_LONG_DOT); 
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER); 
    lv_label_set_recolor(label, true); 
    
    lv_obj_t* label2 = lv_label_create(tab1, NULL);
    lv_obj_set_pos(label2, 20, 100);
    lv_label_set_text(label2, "bluetooth "SYMBOL_BLUETOOTH);
    
    /* LINE */
    lv_obj_t* page = lv_page_create(tab1, NULL); 
    lv_obj_set_width(page, 160); 
    
    while(1)
    {
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
