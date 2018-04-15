#ifndef __LITTLEVGL2RTT_H__
#define __LITTLEVGL2RTT_H__

#include <rtthread.h> 
#include <rtdevice.h> 

rt_err_t littlevgl2rtt_init(const char *name); 
rt_err_t littlevgl2rtt_post_input_data(rt_int16_t x, rt_int16_t y); 

#endif
