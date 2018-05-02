/**
 * @file lv_test_theme.h
 *
 */

#ifndef LV_TEST_THEME_H
#define LV_TEST_THEME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
//#include "../../../lvgl/lv_conf_templ.h"   
#include "../../../lvgl/lvgl.h"
#include "../../lv_conf.h"
//#if USE_LV_TESTS


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a test screen with a lot objects and apply the given theme on them
 * @param th pointer to a theme
 */
void lv_test_theme_1(lv_theme_t *th);

/**********************
 *      MACROS
 **********************/

#endif /*USE_LV_TESTS*/

#ifdef __cplusplus
} /* extern "C" */
#endif

//#endif /*LV_TEST_THEME_H*/
