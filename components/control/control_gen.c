/**
 * @file control_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_gen.h"
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

lv_obj_t * control_create(lv_obj_t * parent, const char * title)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited) {
        #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
        if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_width(&style_base, lv_pct(100));
            lv_style_set_height(&style_base, 70);
            lv_style_set_text_font(&style_base, NS_Medium_32);
            lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
            lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
            lv_style_set_flex_track_place(&style_base, LV_FLEX_ALIGN_CENTER);
            lv_style_set_pad_hor(&style_base, 40);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "control_#");

        lv_obj_remove_style_all(lv_obj_0);
        lv_obj_add_style(lv_obj_0, &style_base, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, title);
        lv_obj_set_flex_grow(lv_label_0, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

