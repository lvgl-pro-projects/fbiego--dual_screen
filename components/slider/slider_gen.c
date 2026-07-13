/**
 * @file slider_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "slider_gen.h"
#include "../../dual_screen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * slider_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
        if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_height(&style_base, 50);

            lv_style_init(&style_knob);
            lv_style_set_bg_color(&style_knob, lv_color_hex(0x0a57ee));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        lv_obj_t * lv_slider_0 = lv_slider_create(parent);
        lv_obj_set_name_static(lv_slider_0, "slider_#");

        lv_obj_add_style(lv_slider_0, &style_base, 0);
        lv_obj_add_style(lv_slider_0, &style_knob, LV_PART_KNOB);

        the_root = lv_slider_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

