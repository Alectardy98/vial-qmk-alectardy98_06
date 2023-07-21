/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2023 Alec Tardy <tardyalec@gmail.com>

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

enum layer_names {
    _BASE,
    _FN
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,---------------------------------------------------------------.  ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|BS |BS |F21|  |PSC|SLK|PAU| |F1 |F2 |F3 |F4 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|F22|  |Ins|Hom|PgU| |F5 |F6 |F7 |F8 |
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Ret|Ret |F23|  |Del|End|PgD| |F9 |F10|F11|F12|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shf|Shift |F24|  |   |Up |   | |F13|F14|F15|F16|
     * |---------------------------------------------------------------|  |-----------| |---------------|
     * |Fn0  |Gui|Alt  |         Space             |Alt* |Gui|Fn0      |  |Lef|Dow|Rig| |F17|F18|F19|F20|
     * `---------------------------------------------------------------'  `-----------' `---------------'
     */

	[_BASE] = LAYOUT(
      RESET,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_BSPC, KC_BSPC,     KC_PSCR, KC_SLCK, KC_PAUS,     KC_NLCK, KC_PSLS, KC_PAST, KC_PEQL,  \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,            KC_F1,      KC_INS, KC_HOME, KC_PGUP,       KC_P7,   KC_P8,   KC_P9, KC_PMNS,  \
    KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_GRV,  KC_ENT,            KC_F2,      KC_DEL,  KC_END, KC_PGDN,       KC_P4,   KC_P5,   KC_P6, KC_PPLS,  \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_RSFT,                     KC_F3,       KC_F4,   KC_UP,   KC_F5,       KC_P1,   KC_P2,   KC_P3, KC_BSPC,  \
    KC_LCTL, KC_LGUI, KC_LALT,                                      KC_SPC,                                     KC_RALT, KC_RGUI, KC_RCTL,              KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_P0, KC_PDOT, KC_PENT   \
        ),
    
    [_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,     _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,     _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,     _______, _______, _______,     _______, _______, _______, _______,  \
    _______, _______, _______,                                     _______,                                     _______, _______, _______,              _______, _______, _______,     _______, _______, _______, _______   \
        )

};
