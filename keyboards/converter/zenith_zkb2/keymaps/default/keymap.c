/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H
#include "ibmpc.h"

enum layer_names {                                             //Define Layers
    _BASE,
    _NUM,
    _FN
};

void led_set(uint8_t usb_led)                                  //Custom Locklight override
{
    uint8_t ibmpc_led = 0;
    if (usb_led &  (1<<USB_LED_SCROLL_LOCK)) {
        ibmpc_led |= (1<<IBMPC_LED_SCROLL_LOCK);
    }
    if (usb_led &  (1<<USB_LED_NUM_LOCK)) {
        ibmpc_led |= (1<<IBMPC_LED_NUM_LOCK);
    }
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {
        ibmpc_led |= (1<<IBMPC_LED_CAPS_LOCK);
    }
    ibmpc_host_set_led(ibmpc_led);
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SLCK, KC_PAUS,                                         \
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,    KC_INS, KC_HOME, KC_PGUP,    TG(_NUM), KC_PSLS, KC_PAST, KC_PMNS, \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,    KC_DEL,  KC_END, KC_PGDN,     KC_HOME,   KC_UP, KC_PGUP, KC_PPLS, \
    KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                                                    KC_LEFT, _______, KC_RGHT,          \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS,                       KC_UP,               KC_END, KC_DOWN, KC_PGDN, KC_PENT, \
    MO(_FN), KC_LALT,                             KC_SPC,                                     KC_RCTL, KC_RALT,                     KC_LEFT, KC_DOWN, KC_RGHT,               KC_INS,  KC_DEL           \
    ),
    [_NUM] = LAYOUT(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,                                        \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,       KC_7,    KC_8,    KC_9, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                       KC_4,    KC_5,    KC_6,          \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,                KC_1,    KC_2,    KC_3, _______, \
    _______, _______,                            _______,                                     _______, _______,                      _______, _______, _______,                KC_0,  KC_DOT           \
    ),
    [_FN] = LAYOUT(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,                                        \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                    _______, _______, _______,          \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,             _______, _______, _______, _______, \
    _______, _______,                            _______,                                     _______, _______,                      _______, _______, _______,             _______, _______           \
    ),
};

  

