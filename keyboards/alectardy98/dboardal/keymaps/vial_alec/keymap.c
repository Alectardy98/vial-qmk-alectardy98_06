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

#include "dboardal.h"

enum layer_names {
    _BASE,
    _MOUSE,
    _FN
};

enum custom_keycodes {      //In Mac OS Swap Command and Control for proper macro use
    TEST = SAFE_RANGE,
    VDRT,                   //Desktop Right "set to move right a space on mac"
    VDLT,                   //Desktop Left "set to move left a space on mac"
    VDUP,                   //V-Desktop Up "set to mission controll on mac"
    VDDN,                   //Min All "set to show desktop on mac"
    EXPL,                   //New Explorer On Windows "set to show launchpad on mac"
    SNIP,                   //Snip Tool Windows "set to save picture of selected area on mac"
    COPY,                   //Copy All
    CUTT,                   //Cut All
    PAST,                   //Paste Over
    TASK,                   //Task Manager
    QUIT,                   //Close App
    DZRO,                   //Double Zero
    ATAB,                   //Alt + Tab "brew install alt-tab on mac"
    LPRC,                   //The "(" Key
    RPRC,                   //The ")" Key
    //Control Section
    CTLA,                   //CTRL + A
    CTLS,                   //CTRL + S
    CTLD,                   //CTRL + D
    CTLF,                   //CTRL + F
    CTLZ,                   //CTRL + Z
    CTLX,                   //CTRL + X
    CTLC,                   //CTRL + C
    CTLV,                   //CTRL + V
    //Discord Section
    THIS,                   //Macro for ":this:" emoji on discord
    OOF,                    //Macro for ":oof:" emoji on discord
    PIKA,                   //Macro for ":surprised:" emoji on discord
    SCAT,                   //Macro for ":smiley_cat_spanish:" emoji on discord
    FCAT,                   //Macro for ":smiley_cat_fancy:" emoji on discord
    HART,                   //Macro for ":heart:" emoji on discord
    DROL,                   //Macro for ":drooling_face:" emoji on discord
    MONY,                   //Macro for ":smiley_takemoney:" emoji on discord
    FHAT,                   //Macro for "::smiley_tip_fedora:" emoji on discord
    SPIT,                   //Macro for ":smiley_spit_surprised:" emoji on discord
    KING,                   //Macro for ":pepe_king_royal:" emoji on discord

};
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {             //Code for macros
        switch(keycode) {
            case TEST:
            if (record->event.pressed) {
                SEND_STRING("TEST");
                }break;
            case VDRT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL) ));
                }break;
            case VDLT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL) ));
                }break;
            case VDUP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_TAB)"t"));
                }break;
            case VDDN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("d"));
                }break;
            case EXPL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("e"));
                }break;
            case SNIP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                }break;
            case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("ac"));
                }break;
            case CUTT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("ax"));
                }break;
            case PAST:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("v"));
                }break;
            case TASK:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_DOWN(X_RSHIFT)SS_TAP(X_ESCAPE)SS_UP(X_RSHIFT)));       // Windows
                SEND_STRING(SS_LCTRL(SS_DOWN(X_LALT)SS_TAP(X_ESCAPE)SS_UP(X_LALT)));           //Mac
                }break;
            case QUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F4)));                                          //Windows
                SEND_STRING(SS_LCTRL("w"));                                                   //Mac
                }break;
            case DZRO:
            if (record->event.pressed) {
                SEND_STRING("00");
                }break;
            case ATAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                }break;
            case LPRC:
            if (record->event.pressed) {
                SEND_STRING("(");
                }break;
            case RPRC:
            if (record->event.pressed) {
                SEND_STRING(")");
                }break;
                //Control Section
            case CTLA:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a"));
                }break;
            case CTLS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("s"));
                }break;
            case CTLD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("d"));
                }break;
            case CTLF:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("f"));
                }break;
            case CTLZ:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("z"));
                }break;
            case CTLX:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("x"));
                }break;
            case CTLC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("c"));
                }break;
            case CTLV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("v"));
                }break;
                //Discord Section
            case THIS:
            if (record->event.pressed) {
                    SEND_STRING(":this:" SS_TAP(X_ENTER) );
                    }break;
            case OOF:
            if (record->event.pressed) {
                    SEND_STRING(":oof:" SS_TAP(X_ENTER));
                    }break;
            case PIKA:
            if (record->event.pressed) {
                    SEND_STRING(":surprised:" SS_TAP(X_ENTER));
                    }break;
            case SCAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_spanish:" SS_TAP(X_ENTER));
                    }break;
            case FCAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_fancy:" SS_TAP(X_ENTER));
                    }break;
            case HART:
            if (record->event.pressed) {
                    SEND_STRING(":heart:" SS_TAP(X_ENTER));
                    }break;
            case DROL:
            if (record->event.pressed) {
                    SEND_STRING(":drooling_face:" SS_TAP(X_ENTER));
                    }break;
            case MONY:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_takemoney:" SS_TAP(X_ENTER));
                    }break;
            case FHAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_tip_fedora:" SS_TAP(X_ENTER));
                    }break;
            case SPIT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_spit_surprised:" SS_TAP(X_ENTER));
                    }break;
            case KING:
            if (record->event.pressed) {
                    SEND_STRING(":pepe_king_royal:" SS_TAP(X_ENTER));
                    }break;
        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};
        
        
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
           TASK,    QUIT,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                SNIP,    EXPL, \
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_BSPC,       COPY,    PAST, \
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_ENT,                 VDLT,    VDRT, \
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_NUHS,                        KC_UP,          \
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_NUBS, KC_RSFT,                      KC_LEFT, KC_RGHT, \
        KC_LALT, KC_LGUI, MO(_FN), KC_LCTL,        LT(_MOUSE, KC_SPC),  KC_SPC,          KC_BSPC,          KC_RALT, KC_CAPS,                      KC_DOWN,          \
                                                              KC_LSFT, KC_RSFT                                                                                      \
        ),
    [_MOUSE] = LAYOUT(
        _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,             _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      KC_MS_U,          \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_R, \
        _______, _______, _______, _______,          _______,          _______,          _______,          _______, _______,                      KC_MS_D,          \
                                                              KC_BTN1, KC_BTN2                                                                                      \
        ),
    [_FN] = LAYOUT(
        _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,             _______, _______, \
          RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,    _______, _______, \
        _______,    THIS,     OOF,    PIKA,    SCAT,    FCAT,    HART,    DROL,    MONY,    FHAT   , SPIT, _______, _______, _______,             _______, _______, \
        KC_CAPS,    CTLA,    CTLS,    CTLD,    CTLF, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______,                         VDUP,          \
        _______,    CTLZ,    CTLX,    CTLC,    CTLV, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,                         VDLT,    VDRT, \
        _______, _______, _______, KC_LGUI,          _______,          _______,          _______,          _______, _______,                         VDDN,          \
                                                              _______, _______                                                                                      \
        ),
};
