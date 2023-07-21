
/* Copyright 2020 Keymacs s.r.o. (https://keymacs.com/)
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

// Keymap: Keymacs Default

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MYCODE = USER_SAFE_RANGE
};

enum layer_names {
    _LYR0,
    _LYR8
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Default
    [_LYR0] = LAYOUT(
        KC_F4, KC_ESC, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
        KC_F3, KC_COLN, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KMCS_BSLS, KMCS_VBAR, KC_BRK, \
        KC_F2, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KMCS_LPAR, KMCS_RPAR, KC_DEL, LSFT(KC_TAB), KC_PSCR, \
        KC_F1, KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_HOME, KC_END, \
        KC_CLCK, MO(_LYR8), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_LYR8), KC_LOCK, KC_PGUP, \
        KC_MENU, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, KC_RCTL, KC_RALT, KC_RGUI, KC_APP, KC_PGDN
    ),
    // Layer 8: Navigation _ Other Keys
    [_LYR8] = LAYOUT(
        KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, \
        KC_F13, KC_NUHS, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, KC_PEQL, KC_BSLS, KC_NUBS, KC_F24, \
        KC_SLCT, KC_FIND, KC_PGUP, KC_UP, KC_PGDN, KC_HAEN, KC_HANJ, KC_LANG3, KC_LANG4, KC_LANG5, KC_LANG6, KC_PGUP, KC_LBRC, KC_RBRC, KC_INS, KC_PSTE, KC_COPY, \
        KC_HELP, KC_EXEC, KC_LEFT, KC_DOWN, KC_RGHT, KC_RO, KC_INT2, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, KC_PAST, KC_PENT, KC_UNDO, KC_CUT, \
        KC_SLCK, KC_TRNS, KC_TRNS, KC_HOME, KC_CLR, KC_END, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_PCMM, KC_PDOT, KC_PSLS, KC_TRNS, KC_TRNS, KC_CALC, KC_MSEL, \
        KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_MYCM
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MYCODE: break;
    }
    return true;
}

void keyboard_post_init_user(void) {

}
