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
  _NUM,
  _FN
  };


void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (layer_state_is(_FN)) {                           //Force Scroll Lock LED On when In layer FN
        writePinHigh(GP0);
    } else {
        writePinLow(GP0);
    }
    if (layer_state_is(_NUM)) {                          //Force Num Lock LED On when In layer NUM
        writePinHigh(GP1);
    } else {
        writePinLow(GP1);
    }
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {            //Put Caps LED on when keybaoard state is Caps
        writePinHigh(GP28);
    } else {
        writePinLow(GP28);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
     KC_F11,  KC_F12,     KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,  KC_F10,  KC_F11, KC_F12,       KC_F13,  KC_F14,  KC_F15,                                          \
      KC_F1,   KC_F2,     KC_GRV,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______,KC_BSPC,      KC_PSCR, KC_SLCK, KC_PAUS,   KC_NLCK, KC_PSLS ,KC_PAST, KC_PMNS,    \
      KC_F3,   KC_F4,     KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,               KC_INS, KC_HOME, KC_PGUP,     KC_P7,   KC_P8,   KC_P9, KC_PPLS,    \
      KC_F5,   KC_F6,    KC_CAPS,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,  KC_ENT,               KC_DEL,  KC_END, KC_PGDN,     KC_P4,   KC_P5,   KC_P6, _______,    \
      KC_F7,   KC_F8,    KC_LSFT, _______,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),              _______,   KC_UP, _______,     KC_P1,   KC_P2,   KC_P3, KC_PEQL,    \
      KC_F9,  KC_F10,    KC_LCTL, KC_LGUI,_______, KC_LALT, _______,                    KC_SPC,                   KC_RALT, KC_RGUI, _______, KC_RCTL,              KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0, _______, KC_PDOT, _______),   \
    
    [_NUM] = LAYOUT(
    _______, _______,   _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,     _______, _______, _______,                                          \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______),
    [_FN] = LAYOUT(
    _______, _______,   _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,     _______, _______, _______,                                          \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______,    \
    _______, _______,   _______, _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,              _______, _______, _______,   _______, _______, _______, _______)
    
};


