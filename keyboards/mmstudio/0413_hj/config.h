/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* Mechanical locking support. Use KC_LCAP  KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define SOLENOID_PIN B3
#define HAPTIC_ENABLE_PIN A15
#define SOLENOID_DEFAULT_DWELL 4
#define SOLENOID_MIN_DWELL 4
#define SOLENOID_MAX_DWELL  45
#define HAPTIC_OFF_IN_LOW_POWER 1

#define AUDIO_CLICKY
//#define AUDIO_INIT_DELAY
#define AUDIO_PIN A6
#define AUDIO_PWM_DRIVER PWMD3
#define AUDIO_PWM_CHANNEL 1

#define AUDIO_STATE_TIMER  GPTD4
#define AUDIO_PIN_ALT_AS_NEGATIVE
#define AUDIO_PIN_ALT A13
#define NO_MUSIC_MODE 


#define AUDIO_DAC_SAMPLE_MAX 4095U

#ifdef AUDIO_ENABLE
    //#define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(CAPS_LOCK_ON_SOUND),  \
                                  SONG(CAPS_LOCK_OFF_SOUND), \
                                  SONG(NUM_LOCK_ON_SOUND),   \
                                  SONG(NUM_LOCK_OFF_SOUND) \
                                                            }
#endif