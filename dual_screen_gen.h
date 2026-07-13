/**
 * @file dual_screen_gen.h
 */

#ifndef DUAL_SCREEN_GEN_H
#define DUAL_SCREEN_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void dual_screen_set_target(uint32_t target);
uint32_t dual_screen_get_target(void);
bool dual_screen_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define DUAL_SCREEN_TARGET_UNDEFINED  (0 << 1)
#define DUAL_SCREEN_TARGET_TARGET1    (1 << 1)
#define DUAL_SCREEN_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef DUAL_SCREEN_COMPILE_TARGET
#define DUAL_SCREEN_COMPILE_TARGET DUAL_SCREEN_TARGET_ALL
#endif

#define DUAL_SCREEN_CHECK_COMPILE_TARGET(target) (DUAL_SCREEN_COMPILE_TARGET & (target) ? 1 : 0)

#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * NS_Medium_24;
extern lv_font_t * NS_Medium_32;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * background;
extern const void * lvgl_logo;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t sb_time;
extern lv_subject_t sb_value;
extern lv_subject_t sb_time_view;
extern lv_subject_t sb_value_view;
extern lv_subject_t sb_logo_view;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void dual_screen_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/container/container_gen.h"
#include "components/control/control_gen.h"
#include "components/oled_view/oled_view_gen.h"
#include "components/slider/slider_gen.h"
#include "components/switch/switch_gen.h"
#include "screens/screen_main/screen_main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*DUAL_SCREEN_GEN_H*/