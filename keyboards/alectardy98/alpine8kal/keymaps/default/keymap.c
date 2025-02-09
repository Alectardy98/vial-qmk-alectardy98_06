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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    KC_ESC, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F13,            KC_PSCR, KC_SCRL, KC_PAUS, \
    KC_GRV, _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_BSPC,    KC_INS, KC_HOME, KC_PGUP, \
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_DEL,  KC_END, KC_PGDN, \
   KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,  KC_ENT,                     _______, _______, _______, \
   KC_LSFT, _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______, KC_RSFT,                     _______,   KC_UP, _______, _______, \
   KC_LCTL, KC_LGUI, KC_LALT, _______, _______,           KC_SPC,          _______, _______, KC_RALT, KC_RGUI, KC_RCTL,                     KC_LEFT, _______, KC_DOWN, _______, KC_RGHT, _______),

    

    

[_FN] = LAYOUT(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, \
   _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______),
};




#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
          // Mappings for 1st Encoder
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, // Mapping for Base layer
    [_FN] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) }, // Mapping for Layer 3


    // You can add more layers here if you need them, or you can also delete lines for layers you are not using
};
#endif
