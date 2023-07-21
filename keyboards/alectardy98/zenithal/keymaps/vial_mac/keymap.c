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

#include "zenithal.h"

enum layer_names {  //Define Layers
    _BASE,
    _BEEP,
    _NUM,
    _FN
};

void matrix_init_user(void) {       //This code starts the keyboard in stock beeper mode, remove if you want to start the keyboard as normal
    layer_on(_BEEP);
}



void led_set(uint8_t usb_led) {                          //Lock Light LED Overide
    if (layer_state_is(_FN)) {                           //Force Scroll Lock LED On when In layer FN
        writePinHigh(C6);
    } else {
        writePinLow(C6);
    }
    if (layer_state_is(_NUM)) {                          //Force Num Lock LED On when In layer NUM
        writePinHigh(C7);
    } else {
        writePinLow(C7);
    }
    if (usb_led &  (1<<USB_LED_CAPS_LOCK)) {            //Put Caps LED on when keybaoard state is Caps
        writePinHigh(F0);
    } else {
        writePinLow(F0);
    }
}

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
    GOGL,                   //Opens Google Chrome, Set in automator on mac to Controll + Alt + G
    CMD,                    //Opens Comand Prompt, Set In automator on mac to Controll + Alt + T
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
    SCAT,                   //Macro for ":smiley_cat2:" emoji on discord
    FCAT,                   //Macro for ":smiley_cat1:" emoji on discord
    HART,                   //Macro for ":heart:" emoji on discord
    DROL,                   //Macro for ":drooling_face:" emoji on discord
    MONY,                   //Macro for ":smiley_take:" emoji on discord
    FHAT,                   //Macro for ":smiley_fedora:" emoji on discord
    SPIT,                   //Macro for ":smiley_spit:" emoji on discord
    KING,                   //Macro for ":pepe_king:" emoji on discord
    FLEX,                   //Macro for ":muscle:" emoji on discord
    HAHA,                   //Macro for ":smiley_kekw:" emoji on discord
    LCRY,                   //Macro for ":joy:" emoji on discord
    NICE,                   //Macro for ":nice~2:" emoji on discord
    PPOG,                   //Macro for ":pepe_pog:" emoji on discord
    PRAY,                   //Macro for ":pray_tone2:" emoji on discord
};
    

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool num_lock = host_keyboard_led_state().num_lock;       //Puts the keyboard into Num Lock state if host OS initializes in Num Lock state
        if (num_lock) {
            if(IS_LAYER_OFF(_NUM)) {
                layer_on(_NUM);
            }
        }
     if (record->event.pressed) {             //Code for macros
         if (layer_state_is(_BEEP)) {         //This code allows the stock bepper to funtion on key press
         if (record->event.pressed) {
             writePinHigh(B5); _delay_ms(2);
             writePinLow(B5);
            }
         }
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
             case GOGL:
             if (record->event.pressed) {
                 SEND_STRING(SS_LCTRL(SS_LALT("g")));
                 }break;
             case CMD:
             if (record->event.pressed) {
                 SEND_STRING(SS_LCTRL(SS_LALT("t")));
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
                     SEND_STRING(":smiley_cat2:" SS_TAP(X_ENTER));
                     }break;
             case FCAT:
             if (record->event.pressed) {
                     SEND_STRING(":smiley_cat1:" SS_TAP(X_ENTER));
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
                     SEND_STRING(":smiley_take:" SS_TAP(X_ENTER));
                     }break;
             case FHAT:
             if (record->event.pressed) {
                     SEND_STRING(":smiley_fedora:" SS_TAP(X_ENTER));
                     }break;
             case SPIT:
             if (record->event.pressed) {
                     SEND_STRING(":smiley_spit:" SS_TAP(X_ENTER));
                     }break;
             case KING:
             if (record->event.pressed) {
                     SEND_STRING(":pepe_king:" SS_TAP(X_ENTER));
                     }break;
             case FLEX:
             if (record->event.pressed) {
                     SEND_STRING(":muscle:" SS_TAP(X_ENTER));
                     }break;
             case HAHA:
             if (record->event.pressed) {
                     SEND_STRING(":smiley_kekw:" SS_TAP(X_ENTER));
                     }break;
             case LCRY:
             if (record->event.pressed) {
                     SEND_STRING(":joy:" SS_TAP(X_ENTER));
                     }break;
             case NICE:
             if (record->event.pressed) {
                     SEND_STRING(":nice~2:" SS_TAP(X_ENTER));
                     }break;
             case PPOG:
             if (record->event.pressed) {
                     SEND_STRING(":pepe_pog:" SS_TAP(X_ENTER));
                     }break;
             case PRAY:
             if (record->event.pressed) {
                     SEND_STRING(":pray_tone2:" SS_TAP(X_ENTER));
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
           QUIT,    TASK,    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_GRV,TG(_NUM), _______, CK_TOGG,
        DM_PLY1, DM_PLY2,    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,    KC_7,    KC_8,    KC_9, KC_PMNS,
           COPY,    PAST,    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,             KC_4,    KC_5,    KC_6, KC_PPLS,
           SNIP,    EXPL,    KC_LSFT, _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS,    KC_1,    KC_2,    KC_3, KC_PENT,
           VDLT,    VDRT,    KC_LALT, MO(_FN), _______,                   _______,  KC_SPC,                            _______, KC_CAPS, _______,   KC_P0, _______, KC_PDOT, _______, _______
        ),
    [_BEEP] = LAYOUT(  //DO NOT TOUCH THIS LAYER
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
    [_NUM] = LAYOUT(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP, KC_PGUP, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_LEFT, _______, KC_RGHT, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_END, KC_DOWN, KC_PGDN, _______,
        _______, _______,    _______, _______, _______,                   _______, _______,                            _______, _______, _______,  KC_INS, _______,  KC_DEL, _______, _______
        ),
    [_FN] = LAYOUT(
          RESET, TG(_BEEP),      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______, _______, _______, _______,
        DM_REC1, DM_REC2,    _______,    THIS,     OOF,    PIKA,    SCAT,    FCAT,    HART,    DROL,    MONY,    FHAT,    SPIT, _______, _______, _______, _______,    VDUP, _______, _______,
        _______, _______,    _______,    CTLA,    CTLS,    CTLD,    CTLF, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,          _______,    VDLT,    QUIT,    VDRT, _______,
        _______, _______,    _______,    CTLZ,    CTLX,    CTLC,    CTLV, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______,    VDDN, _______, _______,
        _______, _______,    KC_LGUI, _______, _______,                   _______, _______,                            _______, _______, _______, _______, _______, _______, _______, _______
        ),
};



