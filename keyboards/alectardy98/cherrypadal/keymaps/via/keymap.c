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
  _FN1,
  _FN2,
  _FN3,
  _FN4
  };

void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (usb_led &  (1<<USB_LED_NUM_LOCK)) {              //LED 5 on when in host numlock
        writePinLow(GP27);                               //LED 5 is GP27
    } else {
        writePinHigh(GP27);
    }
    if (layer_state_is(_FN1)) {                          //LED 1 on when in layer FN1
        writePinLow(GP0);                               //LED 1 is GP0
    } else {
        writePinHigh(GP0);

    }
    if (layer_state_is(_FN2)) {                          //LED 2 on when in layer FN2
        writePinLow(GP1);                               //LED 2 is GP1
    } else {
        writePinHigh(GP1);

    }
    if (layer_state_is(_FN3)) {                          //LED 3 on when in layer FN3
        writePinLow(GP2);                               //LED 3 is GP2
    } else {
        writePinHigh(GP2);

    }
    if (layer_state_is(_FN4)) {                          //LED 4 on when in layer FN4
        writePinLow(GP3);                               //LED 4 is GP3
    } else {
        writePinHigh(GP3);

    }
}


    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    TG(_FN1), TG(_FN2), TG(_FN3), TG(_FN4), \
      KC_NUM,  KC_PSLS,  KC_PAST,  KC_PMNS, \
       KC_P7,    KC_P8,    KC_P9,  KC_PPLS, \
       KC_P4,    KC_P5,    KC_P6,  KC_PEQL, \
       KC_P1,    KC_P2,    KC_P3,  KC_PENT, \
       KC_P0,  KC_PCMM,  KC_PDOT, KC_BSPC), \
    
    [_FN1] = LAYOUT(
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______), \
    
    [_FN2] = LAYOUT(
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______), \
    
    [_FN3] = LAYOUT(
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______), \
    
    [_FN4] = LAYOUT(
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______), \
};


 
