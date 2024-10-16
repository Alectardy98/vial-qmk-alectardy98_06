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

#include "zenithal.h"

enum layer_names {  //Define Layers
    _BASE,
    _BEEP,
    _NUM,
    _FN
};

void matrix_init_user(void) {       //This code starts the keyboard in stock beeper mode, remove if you want to start the keyboard as normal
    layer_on(_BEEP);
}



void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (usb_led &  (1<<USB_LED_SCROLL_LOCK)) {           //Put Caps LED on when keybaoard state is Scroll Lock
        writePinLow(C6);
    } else {
        writePinHigh(C6);
    }
    if (usb_led &  (1<<USB_LED_NUM_LOCK)) {             //Put Caps LED on when keybaoard state is Num Lock
        writePinLow(C7);
    } else {
        writePinHigh(C7);
    }
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {            //Put Caps LED on when keybaoard state is Caps
        writePinLow(F0);
    } else {
        writePinHigh(F0);
    }
}


    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {             //Code for macros
         if (layer_state_is(_BEEP)) {         //This code allows the stock bepper to funtion on key press
         if (record->event.pressed) {
             writePinHigh(B5);
             _delay_ms(2);
             writePinLow(B5);
            }
         }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
          KC_F1,    KC_F2,    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_GRV,TG(_NUM), _______, TG(_BEEP),
          KC_F3,    KC_F4,    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT, KC_HOME,   KC_UP, KC_PGUP, KC_PMNS,
          KC_F5,    KC_F6,    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,          KC_LEFT, _______, KC_RGHT, KC_PPLS,
          KC_F7,    KC_F8,    KC_LSFT, _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS,  KC_END, KC_DOWN, KC_PGDN, KC_PENT,
          KC_F9,   KC_F10,    KC_LALT, MO(_FN), _______,                   _______,  KC_SPC,                            _______, KC_CAPS, _______,  KC_INS, _______,  KC_DEL, _______, _______
        ),
    [_BEEP] = LAYOUT(  //DO NOT TOUCH THIS LAYER
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
    [_NUM] = LAYOUT(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_8,    KC_9, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,    KC_4,    KC_5,    KC_6, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______,    KC_0, _______, KC_PDOT, _______, _______
        ),
    [_FN] = LAYOUT(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
};



