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
    _NUM,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    TEST = 400,
    VDRT,                   //Desktop Right "set to move right a space on mac"
    VDLT,                   //Desktop Left "set to move left a space on mac"
    VDUP,                   //V-Desktop Up "set to mission controll on mac"
    VDDN,                   //Min All "set to show desktop on mac"
    EXPL,                   //New Explorer On Windows "set to show launchpad on mac"
    SNIP,                   //Snip Tool Windows "set to save picture of selected area on mac"
    COPY,                   //Copy All
    PAST,                   //Paste Over
    TASK,                   //Task Manager
    DZRO,                   //Double Zero
    ATAB,                   //Alt + Tab "brew install alt-tab on mac"
};

//Code for macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {
        switch(keycode) {
            case TEST:
                SEND_STRING("TEST");
                return false;
            case VDRT:
                SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_RGHT))));
                return false;
            case VDLT:
                SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_LEFT))));
                return false;
            case VDUP:
                SEND_STRING(SS_LGUI(SS_TAP(X_TAB)"t"));
                return false;
            case VDDN:
                SEND_STRING(SS_LGUI("d"));
                return false;
            case EXPL:
                SEND_STRING(SS_LGUI("e"));
                return false;
            case SNIP:
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                return false;
            case COPY:
                SEND_STRING(SS_TAP(X_F2)SS_LCTL("ac"));
                return false;
            case PAST:
                SEND_STRING(SS_TAP(X_F2)SS_LCTL("v"));
                return false;
            case TASK:
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESC)))SS_LGUI(SS_LALT(SS_TAP(X_ESC))));
                return false;
            case DZRO:
                SEND_STRING("00");
                return false;
            case ATAB:
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_all(
        KC_ESC,  TASK,    KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,        KC_BSLS,  TG(_NUM), KC_PSLS, KC_PAST, KC_PMNS,
        DM_PLY1,  DM_PLY2,    KC_TAB,    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,    KC_BSPC,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        EXPL,  SNIP,    KC_LCTRL,      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT, KC_NO, KC_ENT,   KC_P4,   KC_P5,   KC_P6,   KC_PEQL,
        COPY,  PAST,    KC_LSFT, KC_NO,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  MO(_FN), KC_P1,   KC_P2,   KC_P3,   KC_BSPC,
        VDLT,  VDRT,   KC_LCTRL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,       KC_BSPC,             KC_RALT,  KC_RGUI,   KC_RCTRL, KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    ),
    [_NUM] = LAYOUT_all(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
        _______, _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_INS,  KC_HOME, KC_PGUP, _______,
        _______, _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DEL,  KC_END,  KC_PGDN, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, KC_UP,   _______, _______,
        _______, _______,    _______,  _______,  _______,  _______,  _______,               _______,          _______,          _______,  _______,  _______,     KC_LEFT, KC_DOWN, KC_RGHT, _______
    ),
    [_FN] = LAYOUT_all(
        RESET,   HPT_TOG,      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLD,
        DM_REC1, DM_REC2,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_VOLU,
        KC_NO,   KC_NO,      KC_CAPS,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_MPLY, VDUP,    KC_MPLY,   KC_NO,
        KC_NO,   KC_NO,      KC_NO,    KC_NO,    KC_NO,    _______,  KC_NO,                 KC_NO,            KC_NO,            KC_NO,    KC_NO,    KC_NO,       KC_MPRV, VDDN,    KC_MNXT,   KC_NO
    )
};

