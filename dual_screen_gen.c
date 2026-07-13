/**
 * @file dual_screen_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "dual_screen_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t dual_screen_target = DUAL_SCREEN_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * NS_Medium_24;
extern lv_font_t NS_Medium_24_data;
lv_font_t * NS_Medium_32;
extern lv_font_t NS_Medium_32_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * background = NULL;
extern const void * background_data;
const void * lvgl_logo = NULL;
extern const void * lvgl_logo_data;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t sb_time;
lv_subject_t sb_value;
lv_subject_t sb_time_view;
lv_subject_t sb_value_view;
lv_subject_t sb_logo_view;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void dual_screen_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        if (!NS_Medium_24) {
            /* NS_Medium_24 */
            /* get font 'NS_Medium_24' from a C array */
            NS_Medium_24 = &NS_Medium_24_data;

        }
        if (!NS_Medium_32) {
            /* NS_Medium_32 */
            /* get font 'NS_Medium_32' from a C array */
            NS_Medium_32 = &NS_Medium_32_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if DUAL_SCREEN_CHECK_COMPILE_TARGET(DUAL_SCREEN_TARGET_ALL)
    if (dual_screen_check_target(DUAL_SCREEN_TARGET_ALL)) {
        /* background */
        if (!background) {
            background = &background_data;
        }
        /* lvgl_logo */
        if (!lvgl_logo) {
            lvgl_logo = &lvgl_logo_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    static char sb_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char sb_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&sb_time,
                           sb_time_buf,
                           sb_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "12:45:34"
                          );
    lv_subject_init_int(&sb_value, 50);
    lv_subject_init_int(&sb_time_view, 1);
    lv_subject_init_int(&sb_value_view, 1);
    lv_subject_init_int(&sb_logo_view, 1);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&NS_Medium_24, "NS_Medium_24");
    check_font(&NS_Medium_32, "NS_Medium_32");

    /* Register fonts */
    lv_xml_register_font(NULL, "NS_Medium_24", NS_Medium_24);
    lv_xml_register_font(NULL, "NS_Medium_32", NS_Medium_32);

    /* Register subjects */
    lv_xml_register_subject(NULL, "sb_time", &sb_time);
    lv_xml_register_subject(NULL, "sb_value", &sb_value);
    lv_xml_register_subject(NULL, "sb_time_view", &sb_time_view);
    lv_xml_register_subject(NULL, "sb_value_view", &sb_value_view);
    lv_xml_register_subject(NULL, "sb_logo_view", &sb_logo_view);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "background", background);
    lv_xml_register_image(NULL, "lvgl_logo", lvgl_logo);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void dual_screen_set_target(uint32_t target)
{
    dual_screen_target = target;
}

uint32_t dual_screen_get_target(void)
{
    return dual_screen_target;
}

bool dual_screen_check_target(uint32_t target)
{
    return (dual_screen_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}