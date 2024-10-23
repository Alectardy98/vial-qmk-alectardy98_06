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

#include QMK_KEYBOARD_H

enum _layer {
  _BASE,
  _BEEP,
  _FN
  };

void matrix_init_user(void) {       //This code starts the keyboard in stock beeper mode, remove if you want to start the keyboard as normal
    layer_on(_BEEP);
}

void simpleDelayMs(int milliseconds) {
    for (int i = 0; i < milliseconds; i++) {
        // A simple loop that spins for 1 ms
        for (volatile int j = 0; j < 1000; j++) {
            // Empty loop for delay; adjust 1000 for your clock speed
        }
    }
}

void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (layer_state_is(_BASE)) {                         //LED 1 on when in base layer
        writePinLow(GP20);                               //LED 1 is GP20
    } else {
        writePinHigh(GP20);
    }
    if (usb_led &  (1<<USB_LED_NUM_LOCK)) {              //LED 2 on when in host numlock
        writePinLow(GP21);                               //LED 2 is GP21
    } else {
        writePinHigh(GP21);
    }
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {             //LED 3 on when in host capslock
        writePinLow(GP22);                               //LED 3 is GP22
    } else {
        writePinHigh(GP22);
    }
    if (usb_led &  (1<<USB_LED_SCROLL_LOCK)) {            //LED 4 on when in host scrolllock
        writePinLow(GP25);                                //LED 4 is GP25
    } else {
        writePinHigh(GP25);
    }
    if (layer_state_is(_FN)) {                           //LED 5, LED 6, LED 7 on when In layer FN
        writePinLow(GP26);                               //LED 5 is GP26
        writePinLow(GP27);                               //LED 6 is GP27
        writePinLow(GP28);                               //LED 7 is GP28
    } else {
        writePinHigh(GP26);
        writePinHigh(GP27);
        writePinHigh(GP28);
    }
    
}


    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {             //Code for macros
         if (layer_state_is(_BEEP)) {         //This code allows the stock bepper to funtion on key press
         if (record->event.pressed) {         //GP16 is Free Pin
             writePinLow(GP16);
             simpleDelayMs(25);
             writePinHigh(GP16);
            }
         }
    }
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_NUM,                                                                                             KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_HOME,        KC_F1,   KC_F2,   KC_F3,   KC_F4, \
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_GRV, KC_BSPC,  KC_INS,        KC_P7,   KC_P8,   KC_P9, KC_PMNS, \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,  KC_DEL,                 KC_P4,   KC_P5,   KC_P6, KC_PCMM, \
    KC_LCTL, KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_BSLS,                          KC_P1,   KC_P2,   KC_P3, KC_PENT, \
    KC_SCRL, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, MO(_FN),                          KC_P0, KC_PDOT,          \
                                                                   KC_SPC),                                                                                                                  \
    
    [_BEEP] = LAYOUT(
    _______,                                                                                           _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______, _______,          \
                                                                   _______),                                                                                                                \
    
    [_FN] = LAYOUT(
    _______,                                                                                           _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______, _______,          \
                                                                   _______),
};


