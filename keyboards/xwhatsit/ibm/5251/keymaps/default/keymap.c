/* Copyright 2020 Purdea Andrei
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _FN2
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_F1, KC_F2,  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,            LSFT(KC_TAB),             KC_NUM ,
        KC_F3, KC_F4,  KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,         KC_P7,   KC_P8,   KC_P9,  KC_PMNS,
        KC_F5, KC_F6,  KC_CAPS,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NONUS_HASH,     KC_P4,   KC_P5,   KC_P6,  KC_PPLS,
        KC_F7, KC_F8,  KC_LSFT,KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),   KC_P1,   KC_P2,   KC_P3,
        KC_F9, KC_F10, KC_LCTL,                                  KC_SPC,                                                   KC_RALT, KC_P0,               KC_PDOT
    ),
    [_FN] = LAYOUT(
        _______, _______, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,             _______,                        _______,
        _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,   _______,   _______,  _______,
        _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                _______,   _______,   _______,  _______,
        _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,   _______,   _______,
        _______, _______, _______,                          MO(_FN2),                                                  _______,                           _______,                       _______
    ),
    [_FN2] = LAYOUT(
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,                        _______,
        _______, _______, _______,    _______, _______, EE_CLR,  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,   _______,   _______,  _______,
        _______, _______, _______,      _______, _______, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______,                _______,   _______,   _______,  _______,
        _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,   _______,   _______,
        _______, _______, _______,                           _______,                                                  _______,                           _______,                       _______
    )
};

