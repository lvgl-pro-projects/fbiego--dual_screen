/**
 * @file oled_view_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "oled_view_gen.h"
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

lv_obj_t * oled_view_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited) {
        #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
        if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_width(&style_base, 128);
            lv_style_set_height(&style_base, 64);
            lv_style_set_bg_color(&style_base, lv_color_hex(0x000000));
            lv_style_set_bg_opa(&style_base, 255);
            lv_style_set_text_color(&style_base, lv_color_hex(0xffffff));
            lv_style_set_text_font(&style_base, NS_Medium_24);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "oled_view_#");

        lv_obj_remove_style_all(lv_obj_0);
        lv_obj_add_style(lv_obj_0, &style_base, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_bind_text(lv_label_0, &sb_time, NULL);
        lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
        lv_obj_bind_flag_if_not_eq(lv_label_0, &sb_time_view, LV_OBJ_FLAG_HIDDEN, 1);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
        lv_label_bind_text(lv_label_1, &sb_value, "%d%%");
        lv_obj_set_x(lv_label_1, 5);
        lv_obj_set_align(lv_label_1, LV_ALIGN_BOTTOM_LEFT);
        lv_obj_bind_flag_if_not_eq(lv_label_1, &sb_value_view, LV_OBJ_FLAG_HIDDEN, 1);

        lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
        lv_image_set_src(lv_image_0, lvgl_logo);
        lv_image_set_scale_x(lv_image_0, 128);
        lv_image_set_scale_y(lv_image_0, 128);
        lv_obj_set_height(lv_image_0, 35);
        lv_obj_set_width(lv_image_0, 35);
        lv_obj_set_align(lv_image_0, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_bind_flag_if_not_eq(lv_image_0, &sb_logo_view, LV_OBJ_FLAG_HIDDEN, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

