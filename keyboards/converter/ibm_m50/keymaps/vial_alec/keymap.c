
#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user    
enum blender_keycode {
    TEST = USER00,
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
    SWET,                   //Macro for ":sweat_smile:" emoji on discord
    COLD,                   //Macro for ":cold_face:" emoji on discord
    THUM,                   //Macro for ":thumbsup:" emoji on discord
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
            return true;
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
            case SWET:
            if (record->event.pressed) {
                    SEND_STRING(":sweat_smile:" SS_TAP(X_ENTER));
                    }break;
            case COLD:
            if (record->event.pressed) {
                    SEND_STRING(":cold_face:" SS_TAP(X_ENTER));
                    }break;
            case THUM:
            if (record->event.pressed) {
                    SEND_STRING(":thumbsup:" SS_TAP(X_ENTER));
                    }break;
        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
    * ,-----------. ,-----------. ,---------------.
    * | 1C| 1D| 24| | 2D| D5| 3C| | 43| 44| 4C| 71|
    * |-----------| |-----------| |---------------|
    * | 1A| 22| 21| | 2A| 5A| 3A| | 41| 4B| 49| 4A|
    * |-----------| |-----------| |---------------|
    * | 16| 1E| 26| | 25| 09| 3D| | 3E| 46| 45| 52|
    * |-----------| |-----------| |---------------|
    * | 12| 05| 06| | 2E| 01| 36| | 55| 0A| 54| 4E|
    * |-----------| |-----------| |---------------|
    * | 14| 11| 04| | 2C| 66| 35| | 5B| 0B| 83| 33|
    * `-----------' `-----------' `---------------'
    */
         
    [_BASE] = LAYOUT(
                   RESET,     CMD,    TASK,    KC_INS, KC_HOME, KC_PGUP,      THIS,    NICE,     OOF,    HAHA, \
                 _______,  OUT_BT, OUT_USB,    KC_DEL,  KC_END, KC_PGDN,      SCAT,    FCAT,    FHAT,    MONY, \
                 _______,    SNIP,    EXPL,   KC_MPRV, KC_MPLY, KC_MNXT,      KING,    PPOG,    SPIT,    PIKA, \
                 _______,    COPY,    PAST,   KC_VOLD,   KC_UP, KC_VOLU,      SWET,    LCRY,    DROL,    COLD, \
                 _______,    VDLT,    VDRT,   KC_LEFT, KC_DOWN, KC_RGHT,      FLEX,    THUM,    PRAY,    HART  \
    ),
    [_FN] = LAYOUT(
                 _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, \
                 _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, \
                 _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, \
                 _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, \
                 _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______  \
    ),

};
