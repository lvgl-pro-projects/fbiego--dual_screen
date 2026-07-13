/**
 * @file screen_main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_main_gen.h"
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

lv_obj_t * screen_main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
        if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
            lv_style_init(&style_main);
            lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
            lv_style_set_bg_image_src(&style_main, background);
            lv_style_set_bg_image_tiled(&style_main, true);
            lv_style_set_bg_image_recolor(&style_main, lv_color_hex(0x000000));
            lv_style_set_bg_image_recolor_opa(&style_main, 150);
            lv_style_set_pad_ver(&style_main, 20);
            lv_style_set_pad_row(&style_main, 0);
            lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
            lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_COLUMN);
            lv_style_set_flex_main_place(&style_main, LV_FLEX_ALIGN_SPACE_BETWEEN);
            lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
            lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);
            lv_style_set_text_color(&style_main, lv_color_hex(0xFFFFFF));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_main_#");

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
        lv_image_set_src(lv_image_0, lvgl_logo);
        lv_obj_set_align(lv_image_0, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_image_0, 20);

        lv_obj_t * container_0 = container_create(lv_obj_0);
        lv_obj_set_width(container_0, 450);
        lv_obj_set_height(container_0, 300);
        lv_obj_set_align(container_0, LV_ALIGN_CENTER);
        lv_obj_set_style_layout(container_0, LV_LAYOUT_FLEX, 0);
        lv_obj_set_flex_flow(container_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_t * control_0 = control_create(container_0, "Show Time");
        lv_obj_t * switch_0 = switch_create(control_0);
        lv_obj_bind_checked(switch_0, &sb_time_view);

        lv_obj_t * control_1 = control_create(container_0, "Show Logo");
        lv_obj_t * switch_1 = switch_create(control_1);
        lv_obj_bind_checked(switch_1, &sb_logo_view);

        lv_obj_t * control_2 = control_create(container_0, "Show Value");
        lv_obj_t * switch_2 = switch_create(control_2);
        lv_obj_bind_checked(switch_2, &sb_value_view);

        lv_obj_t * control_3 = control_create(container_0, "");
        lv_obj_set_style_pad_hor(control_3, 40, 0);
        lv_obj_bind_flag_if_not_eq(control_3, &sb_value_view, LV_OBJ_FLAG_HIDDEN, 1);
        lv_obj_t * slider_0 = slider_create(control_3);
        lv_obj_set_width(slider_0, lv_pct(100));
        lv_slider_bind_value(slider_0, &sb_value);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_bind_text(lv_label_0, &sb_time, NULL);
        lv_obj_set_align(lv_label_0, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_y(lv_label_0, -20);
        lv_obj_set_style_text_font(lv_label_0, NS_Medium_32, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

