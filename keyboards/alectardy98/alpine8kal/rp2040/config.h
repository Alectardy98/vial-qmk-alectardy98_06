/* Copyright 2022 Alectardy98
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config_common.h"

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define LED_PIN_ON_STATE 0
#define LED_NUM_LOCK_PIN GP2


#define RGB_DI_PIN GP3
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 12
#    define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_RAINBOW_SWIRL)

#    define RGBLIGHT_DEFAULT_HUE 64
//#    define RGBLIGHT_DEFAULT_SAT 255
#    define RGBLIGHT_DEFAULT_VAL 255
//#    define RGBLIGHT_HUE_STEP 8
//#    define RGBLIGHT_SAT_STEP 8
//#    define RGBLIGHT_VAL_STEP 8
//#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
//
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

#define AUDIO_PIN GP0
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_MIN         65.0f       // Default 65
#define AUDIO_CLICKY_FREQ_DEFAULT     280.0f      // Default 440
#define AUDIO_CLICKY_FREQ_MAX         1500.0f     // Default 1500
#define AUDIO_CLICKY_FREQ_FACTOR    0.0000000000000001f      // Default 1.18921
#define AUDIO_CLICKY_FREQ_RANDOMNESS    0.0f      // Default 0.05
#define AUDIO_CLICKY_DELAY_DURATION     0         // Default 1
