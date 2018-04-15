#include "littlevgl2rtt.h" 
#include "lvgl.h" 

static rt_device_t device; 
static struct rt_device_graphic_info info; 
static struct rt_messagequeue *input_mq; 

/* Todo: add gpu */
static void lcd_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color)
{
    /*Return if the area is out the screen*/
    if(x2 < 0) return;
    if(y2 < 0) return;
    if(x1 > info.width  - 1) return;
    if(y1 > info.height - 1) return;

    /*Truncate the area to the screen*/
    int32_t act_x1 = x1 < 0 ? 0 : x1;
    int32_t act_y1 = y1 < 0 ? 0 : y1;
    int32_t act_x2 = x2 > info.width  - 1 ? info.width  - 1 : x2;
    int32_t act_y2 = y2 > info.height - 1 ? info.height - 1 : y2;

    uint32_t x; 
    uint32_t y; 
    long int location = 0;

    /* 8 bit per pixel */
    if(info.bits_per_pixel == 8)
    {
        uint8_t *fbp8 = (uint8_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp8[location] = color.full;
            }
        }
    }
    
    /* 16 bit per pixel */ 
    else if(info.bits_per_pixel == 16)
    {
        uint16_t *fbp16 = (uint16_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp16[location] = color.full;
            }
        }
    }
        
    /* 24 or 32 bit per pixel */
    else if(info.bits_per_pixel == 24 || info.bits_per_pixel == 32)
    {
        uint32_t *fbp32 = (uint32_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp32[location] = color.full;
            }
        }
    }

    struct rt_device_rect_info rect_info; 

    rect_info.x = x1;
    rect_info.y = y1;
    rect_info.width = x2 - x1;
    rect_info.height = y2 - y1;
    rt_device_control(device, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info); 
}

static void lcd_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    /*Return if the area is out the screen*/
    if(x2 < 0) return;
    if(y2 < 0) return;
    if(x1 > info.width  - 1) return;
    if(y1 > info.height - 1) return;

    /*Truncate the area to the screen*/
    int32_t act_x1 = x1 < 0 ? 0 : x1;
    int32_t act_y1 = y1 < 0 ? 0 : y1;
    int32_t act_x2 = x2 > info.width  - 1 ? info.width  - 1 : x2;
    int32_t act_y2 = y2 > info.height - 1 ? info.height - 1 : y2;

    uint32_t x; 
    uint32_t y; 
    long int location = 0;

    /* 8 bit per pixel */
    if(info.bits_per_pixel == 8)
    {
        uint8_t *fbp8 = (uint8_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp8[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
    
    /* 16 bit per pixel */ 
    else if(info.bits_per_pixel == 16)
    {
        uint16_t *fbp16 = (uint16_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp16[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
        
    /* 24 or 32 bit per pixel */
    else if(info.bits_per_pixel == 24 || info.bits_per_pixel == 32)
    {
        uint32_t *fbp32 = (uint32_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp32[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }

    struct rt_device_rect_info rect_info; 

    rect_info.x = x1;
    rect_info.y = y1;
    rect_info.width = x2 - x1;
    rect_info.height = y2 - y1;
    rt_device_control(device, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info); 
}

static void lcd_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    /*Return if the area is out the screen*/
    if(x2 < 0) return;
    if(y2 < 0) return;
    if(x1 > info.width  - 1) return;
    if(y1 > info.height - 1) return;

    /*Truncate the area to the screen*/
    int32_t act_x1 = x1 < 0 ? 0 : x1;
    int32_t act_y1 = y1 < 0 ? 0 : y1;
    int32_t act_x2 = x2 > info.width  - 1 ? info.width  - 1 : x2;
    int32_t act_y2 = y2 > info.height - 1 ? info.height - 1 : y2;

    uint32_t x; 
    uint32_t y; 
    long int location = 0;

    /* 8 bit per pixel */
    if(info.bits_per_pixel == 8)
    {
        uint8_t *fbp8 = (uint8_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp8[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
    
    /* 16 bit per pixel */ 
    else if(info.bits_per_pixel == 16)
    {
        uint16_t *fbp16 = (uint16_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp16[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
        
    /* 24 or 32 bit per pixel */
    else if(info.bits_per_pixel == 24 || info.bits_per_pixel == 32)
    {
        uint32_t *fbp32 = (uint32_t*)info.framebuffer;
        
        for(y = act_y1; y <= act_y2; y++) 
        {
            for(x = act_x1; x <= act_x2; x++) 
            {
                location = (x) + (y) * info.width;
                fbp32[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
    
    struct rt_device_rect_info rect_info; 

    rect_info.x = x1;
    rect_info.y = y1;
    rect_info.width = x2 - x1;
    rect_info.height = y2 - y1;
    rt_device_control(device, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info); 
    
    lv_flush_ready();
}

static bool input_read(lv_indev_data_t *data) 
{
    lv_indev_data_t input_date = {0}; 
    
    if(rt_mq_recv(input_mq, &input_date, sizeof(lv_indev_data_t), 1) == RT_EOK)
    {
        rt_memcpy(data, &input_date, sizeof(lv_indev_data_t)); 
        data->state   = LV_INDEV_STATE_PR;
        
        //rt_kprintf("input recv x: %.4d, y: %.4d\n", data->point.x, data->point.y); 
    }
    else
    {
        data->state   = LV_INDEV_STATE_REL;
        data->point.x = 0; 
        data->point.y = 0; 
    }
    
    return false; /* No buffering so no more data read */
}

static void lvgl_tick_run(void *p)
{
    while(1)
    {
        lv_tick_inc(1); 
        rt_thread_delay(1);
    }
} 

rt_err_t littlevgl2rtt_post_input_data(rt_int16_t x, rt_int16_t y) 
{
    lv_indev_data_t input_data; 
    
    input_data.point.x = x; 
    input_data.point.y = y; 
    
    return rt_mq_send(input_mq, (rt_uint32_t)&input_data, sizeof(lv_indev_data_t));
}

rt_err_t littlevgl2rtt_init(const char *name) 
{
    RT_ASSERT(name != RT_NULL); 
    
    /* LCD Device Init */
    device = rt_device_find(name); 
    rt_device_open(device, RT_DEVICE_OFLAG_RDWR); 
    rt_device_control(device, RTGRAPHIC_CTRL_GET_INFO, &info); 
    
    RT_ASSERT(info.bits_per_pixel ==  8 || info.bits_per_pixel == 16 || 
              info.bits_per_pixel == 24 || info.bits_per_pixel == 32); 

    if(info.bits_per_pixel != LV_COLOR_DEPTH)
    {
        rt_kprintf("Error: framebuffer color depth mismatch! (Should be %d to match with LV_COLOR_DEPTH)", 
            info.bits_per_pixel); 
        return RT_ERROR; 
    }

    /* littlevgl Init */ 
    lv_init(); 
    
    /* littlevGL Display device interface */
    lv_disp_drv_t disp_drv; 
    lv_disp_drv_init(&disp_drv); 
    
    disp_drv.disp_fill  = lcd_fill;
    disp_drv.disp_map   = lcd_map;
    disp_drv.disp_flush = lcd_flush;

    lv_disp_drv_register(&disp_drv); 
    
    /* littlevGL Input device interface */ 
    input_mq = rt_mq_create("lv_input", sizeof(lv_indev_data_t), 256, RT_IPC_FLAG_FIFO);
    
    lv_indev_drv_t indev_drv; 
    lv_indev_drv_init(&indev_drv); 
    
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = input_read;
    
    lv_indev_drv_register(&indev_drv); 
    
    /* littlevGL Tick thread */ 
    rt_thread_t thread = RT_NULL; 
    
    thread = rt_thread_create("lv_tick", lvgl_tick_run, RT_NULL, 512, 6, 10); 
    if(thread == RT_NULL)
    {
        return RT_ERROR; 
    }
    rt_thread_startup(thread); 

    /* Info Print */
    rt_kprintf("[littlevgl2rtt] Welcome to the littlevgl2rtt.\n"); 
    rt_kprintf("[littlevgl2rtt] You can find latest ver from https://github.com/liu2guang/LittlevGL2RTT.\n"); 
    
    return RT_EOK; 
}
