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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
     KC_ESC,  KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_LGUI,       KC_RGUI,   KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_PGUP, KC_PGDN,       KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F13,   \
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_DEL,  KC_INS,     KC_PAST, KC_PSLS, KC_PPLS, KC_PMNS, S(KC_5),   \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS, KC_LBRC, KC_RBRC, KC_VOLU, KC_VOLD,       KC_P7,   KC_P8,   KC_P9, KC_PCMM,  KC_DEL,   \
    KC_CAPS, KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT, KC_MNXT, KC_MPRV,       KC_P4,   KC_P5,   KC_P6, KC_PENT, KC_PEQL,   \
    KC_LALT, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_COPY,   KC_UP, KC_PSTE,       KC_P1,   KC_P2,   KC_P3,  KC_TAB,            \
    KC_LCTL, KC_LGUI, MO(_FN),                             KC_SPC,                                     KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT,                KC_P0, KC_PDOT),                    \
    
    
    [_FN] = LAYOUT(
    _______, _______,      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,         _______, _______,     _______, _______, _______, _______, _______,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______,            \
    _______, _______, _______,                            _______,                                     _______, _______, _______, _______, _______,              _______, _______)                     \
};
