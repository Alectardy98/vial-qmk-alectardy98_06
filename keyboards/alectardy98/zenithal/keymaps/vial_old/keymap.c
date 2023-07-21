
#include "zenithal.h"

enum layer_names {  //Define Layers
    _BASE,
    _BEEP,
    _FN
};

void matrix_init_user(void) {       //This code starts the keyboard in stock beeper mode, remove if you want to start the keyboard as normal
    layer_on(_BEEP);
}


enum custom_keycodes {
    TEST = 400
};
    

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {             //Code for macros
         if (layer_state_is(_BEEP)) {         //This code allows the stock bepper to funtion on key press
         if (record->event.pressed) {
             writePinHigh(B5); _delay_ms(2);
             writePinLow(B5);
            }
         }
        switch(keycode) {
            case TEST:
            if (record->event.pressed) {
                SEND_STRING("TEST");
                } else {}break;
        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};
        
        
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
          KC_F1,   KC_F2,     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_TILD, KC_NLCK,  KC_F13, KC_SLCK,
          KC_F3,   KC_F4,     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,   KC_P7,   KC_P8,   KC_P9, KC_PMNS,
          KC_F5,   KC_F6,    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_NUHS,            KC_P4,   KC_P5,   KC_P6, KC_PPLS,
          KC_F7,   KC_F8,    KC_LSFT, KC_NUBS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_PSCR,   KC_P1,   KC_P2,   KC_P3, KC_PENT,
          RESET,  KC_F10,    KC_LALT, KC_BSLS,  KC_F14,                    KC_F15,  KC_SPC,                             KC_F16, KC_CAPS,  KC_F17,   KC_P0,  KC_F18, KC_PDOT,  KC_F19,  KC_F20
        ),
    [_BEEP] = LAYOUT(  //DO NOT TOUCH THIS LAYER
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
    [_FN] = LAYOUT(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
};
