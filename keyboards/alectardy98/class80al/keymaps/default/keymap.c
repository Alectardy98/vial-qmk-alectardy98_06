/* Copyright 2019 Fate
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
#ifdef AUDIO_ENABLE

float tone_startup[][2] = SONG(STARTUP_SOUND);
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_dvorak[][2] = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float tone_plover[][2] = SONG(PLOVER_SOUND);
float tone_plover_gb[][2] = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


enum layer_names {                                             //Define Layers
    _BASE,
    _NUM,
    _FN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
         KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,
		 KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,     KC_INS, KC_HOME, KC_PGUP,
		 KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL,  KC_END, KC_PGDN,
		KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,  KC_ENT,
		KC_LSFT, _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,                        KC_UP,
		KC_LCTL, MO(_FN), KC_LALT,                             KC_SPC,                   _______, KC_RALT,  KC_RGUI, KC_RCTL,             KC_LEFT, KC_DOWN, KC_RGHT
                   ),
    [_NUM] = LAYOUT(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,             _______, _______, _______
                   ),
    [_FN] = LAYOUT(
          RESET,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,             _______, _______, _______
                   )
    };
