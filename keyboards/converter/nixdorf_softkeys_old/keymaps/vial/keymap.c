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
  _FN
  };

void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {             //LED 3 on when in host capslock
        writePinHigh(GP16);                               //LED 3 is GP22
    } else {
        writePinLow(GP16);
    }
    if (layer_state_is(_FN)) {                           //Force Scroll Lock LED On when In layer FN
        writePinHigh(GP29);                               //LED 5 is GP26
    } else {
        writePinLow(GP29);
    }
}

    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed)
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    TG(_FN),    KC_2,    KC_3,    KC_4,    KC_5,    KC_6, \
      KC_F1,   KC_F2,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,                                                   KC_F10,  KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, KC_LBRC, KC_RBRC, \
      KC_F3,   KC_F4,      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,      KC_INS, KC_HOME, KC_PGUP,     KC_PEQL, KC_PSLS, KC_PAST,     KC_PMNS, \
      KC_F5,   KC_F6,      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,      KC_DEL,  KC_END, KC_PGDN,       KC_P7,   KC_P8,   KC_P9,     KC_PPLS, \
      KC_F7,   KC_F8,     KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_BSLS,              KC_MPRV, KC_MPLY, KC_MNXT,       KC_P4,   KC_P5,   KC_P6,     KC_BSPC, \
      KC_F9,  KC_F10,     KC_LSFT, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),     KC_VOLD,   KC_UP, KC_VOLU,       KC_P1,   KC_P2,   KC_P3,     KC_PENT, \
     KC_F11,  KC_F12,     KC_LCTL, KC_LALT,                                      KC_SPC,                                              KC_RALT, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_P0, KC_PDOT),             \
    
    [_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, 
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                 _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,     _______, _______, _______,      _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,     _______, _______, _______,      _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,     _______, _______, _______,      _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,     _______, _______, _______,      _______, \
    _______, _______,     _______, _______,                                     _______,                                              _______, _______,    _______, _______, _______,     _______, _______, _______),              
};
