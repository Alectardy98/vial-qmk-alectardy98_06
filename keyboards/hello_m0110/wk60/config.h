#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6060
#define PRODUCT_ID      0x0060
#define DEVICE_VER      0x0001
#define MANUFACTURER    wanke studio
#define PRODUCT         wk60

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { D0, D1, B0, F1, F4 }
#define MATRIX_COL_PINS { B1, F5, F6, F7, C7, C6, B6, B5, B4, D7, D6, D4, D5, D3, D2 }

#define DIODE_DIRECTION COL2ROW

#define LED_CAPS_LOCK_PIN B2
#define LED_PIN_ON_STATE 0

#define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
#define BACKLIGHT_LEVELS 3

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
    #define RGBLED_NUM 12
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 200 /* The maximum brightness level */
    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
    #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//     #define RGBLIGHT_EFFECT_BREATHING
//     #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//     #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//     #define RGBLIGHT_EFFECT_SNAKE
//     #define RGBLIGHT_EFFECT_KNIGHT
//     #define RGBLIGHT_EFFECT_CHRISTMAS
//     #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//     #define RGBLIGHT_EFFECT_RGB_TEST
//     #define RGBLIGHT_EFFECT_ALTERNATING
#endif


