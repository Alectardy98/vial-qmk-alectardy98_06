/*
 Note: This config allows for the use of num lock states in both Mac OS and Windows will relativly seamless functionality. In order to make this happen a couple of consessions had to be made. The function matrix_scan_user(void) is always running on a constant loop and will result in preformance loss that can be midigated by disableing the code. I personaly have not noticed anything wrong but your results may varry. Also it is important to note that if using 2 keyboards on the same windows computer, by pushing num lock key on a second keyboard from the on state to the off state, this keyboard will become out of sinc with the host OS and will be stuck in the num lock state untill num lock is pressed again. Other then this rare occurance I do not belive any other issues occure.
 */

#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUM,
    _FN,
};

void matrix_scan_user(void) {                       //note that this will run on a constant loop
    if (layer_state_is(_FN)){                       // When in layer _FN, this will activate the scroll lock light
        led_set(host_keyboard_leds() | (1<<USB_LED_SCROLL_LOCK));
    } else if (layer_state_is(_NUM)){           //When in layer _NUM, this will activate Num lock light
        led_set(host_keyboard_leds() | (1<<USB_LED_NUM_LOCK));
    } else {                                         // When in base layer turn everything off
        led_set(host_keyboard_leds() & ~(1<<USB_LED_NUM_LOCK));
        led_set(host_keyboard_leds() & ~(1<<USB_LED_SCROLL_LOCK));
    };
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
    GOGL,                   //Opens Google Chrome, Set in automator on mac to Controll + Alt + G
    CMD,                    //Opens Comand Prompt, Set In automator on mac to Controll + Alt + T
    QUIT,                   //Close App
    DZRO,                   //Double Zero
    ATAB,                   //Alt + Tab "brew install alt-tab on mac"
    LPRC,                   //The "(" Key
    RPRC,                   //The ")" Key
    NUM,                    //Num Lock for both mac and windows
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
            case NUM:
            if (record->event.pressed) {
                SEND_STRING( SS_TAP(X_NLCK) );                  //Toggles layer change and presses the num lock button, to allow for Num lock toggle to occure for both Mac OS and Windows
                layer_invert(_NUM);
            return false;
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
    [_BASE] = LAYOUT_all(
         KC_ESC,    TASK,    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______, KC_BSPC,             NUM, KC_PSLS, KC_PAST, KC_PMNS,
        DM_PLY1, DM_PLY2,    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,          KC_INS, KC_HOME, KC_PGUP, KC_PSLS,
           SNIP,    EXPL,   KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, _______,           KC_ENT,          KC_DEL,  KC_END, KC_PGDN, KC_PEQL,
           COPY,    PAST,   KC_LSFT, MO(_FN),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,          KC_RSFT,         _______,   KC_UP, _______, KC_BSPC,
           VDLT,    VDRT,   KC_LCTL,          KC_LALT,                             KC_SPC,                                              KC_BSPC,          KC_LGUI,         KC_LEFT, KC_DOWN, KC_RGHT, KC_PENT
    ),
    [_NUM] = LAYOUT_all(
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,            KC_7,    KC_8,    KC_9, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,            KC_4,    KC_5,    KC_6, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,            KC_1,    KC_2,    KC_3, _______,
        _______, _______,   _______,          _______,                            _______,                                              _______,          _______,            KC_0,    DZRO, KC_PDOT, _______
    ),
    [_FN] = LAYOUT_all(
          RESET,   DEBUG,   HPT_TOG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,        _______, _______, _______, _______,
        DM_REC1, DM_REC2,   _______,    THIS,     OOF,    PIKA,    SCAT,    FCAT,    HART,    DROL,    MONY,    FHAT,    SPIT, _______, _______,          _______,        _______, _______, _______, _______,
        _______, _______,   KC_LCTL,    CTLA,    CTLS,    CTLD,    CTLF, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______,          _______,        _______, _______, _______, _______,
        _______, _______,   _______, _______,    CTLZ,    CTLX,    CTLC,    CTLV, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,          _______,        KC_MPRV,    VDUP, KC_MNXT, _______,
        _______, _______,   KC_LGUI,          _______,                            _______,                                              _______,          _______,           VDLT,    VDDN,    VDRT, _______
    ),
    
};

