#include QMK_KEYBOARD_H
#include "oled/bongocat.h"

enum layer_names {                                             //Define Layers
    _BASE,
    _NUM,
    _FN
};



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
    bool num_lock = host_keyboard_led_state().num_lock;       //Puts the keyboard into Num Lock state if host OS initializes in Num Lock state
        if (num_lock) {
            if(IS_LAYER_OFF(_NUM)) {
                layer_on(_NUM);
            }
        }
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

[_BASE] = LAYOUT(
   KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,           KC_MPLY, \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______,  KC_BSPC, \
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS, TG(_NUM), \
  KC_LCAP,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,            KC_DEL, \
  KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,  KC_LGUI, \
  KC_LCTL, MO(_FN), KC_LALT,                             KC_SPC,                   KC_RALT, _______, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_8,    KC_9, _______, KC_PMNS, KC_PPLS, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6, _______, KC_PAST, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, KC_PEQL, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______,    KC_0, _______, KC_PDOT, KC_PSLS, _______, _______, _______, \
  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______),
    
 [_FN] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL, \
  _______,    THIS,     OOF,    PIKA,    SCAT,    FCAT,    HART,    DROL,    MONY,    FHAT,    SPIT, _______, _______, _______, _______, \
  _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F), _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______,           KC_INS, \
  _______,          C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,    VDUP, _______, \
  KC_LGUI, _______, _______,                            _______,                   _______, _______, _______,    VDLT,    VDDN,    VDRT)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
          // Mappings for 1st Encoder
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
    [_NUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Layer 1
    [_FN] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  }, // Mapping for Layer 2
    // You can add more layers here if you need them, or you can also delete lines for layers you are not using
};
#endif


#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        led_t led_usb_state = host_keyboard_led_state();

        render_bongocat();
        oled_set_cursor(14, 0);                                // sets cursor to (column, row) using charactar spacing (4 rows on 128x32 screen, anything more will overflow back to the top)
        oled_write_P(PSTR("WPM:"), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false); // writes wpm on top right corner of string
        oled_set_cursor(17, 2);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
        oled_set_cursor(17, 4);
        oled_write_P(layer_state_is(_FN) ? PSTR("FN") : PSTR("    "), false);
        oled_set_cursor(17, 3);
        oled_write_P(layer_state_is(_NUM) ? PSTR("NUM") : PSTR("    "), false);
        return true;
    }
#endif
