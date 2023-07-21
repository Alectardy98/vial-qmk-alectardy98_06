
#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _CAPS,
    _NUM,
    _FN,
    _EMOJI
};


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
    BCAP,                   //Bluetooth Caps lock, hack job
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
    /*Scuffed Bluetooth Capslock Section
    QQ,                     // Shift Q
    WW,                     // Shift W
    EE,                     // Shift E
    RR,                     // Shift R
    TT,                     // Shift T
    YY,                     // Shift Y
    UU,                     // Shift U
    II,                     // Shift I
    OO,                     // Shift O
    PP,                     // Shift P
    AA,                     // Shift A
    SS,                     // Shift S
    DD,                     // Shift D
    FF,                     // Shift F
    GG,                     // Shift G
    HH,                     // Shift H
    JJ,                     // Shift J
    KK,                     // Shift K
    LL,                     // Shift L
    ZZ,                     // Shift Z
    XX,                     // Shift X
    CC,                     // Shift C
    VV,                     // Shift V
    BB,                     // Shift B
    NN,                     // Shift N
    MM                      // Shift M
    */
};
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool num_lock = host_keyboard_led_state().num_lock;       //Puts the keyboard into Num Lock state if host OS initializes in Num Lock state
        if (num_lock) {
            if(IS_LAYER_OFF(_NUM)) {
                layer_on(_NUM);
            }
        }
            if (record->event.pressed) {                              //Code for macros
                switch(keycode) {
            case TEST:
            if (record->event.pressed) {
                SEND_STRING("TEST");
                } else {}break;
            case VDRT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL) ));
                } else {}break;
            case VDLT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL) ));
                } else {}break;
            case VDUP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_TAB)"t"));
                } else {}break;
            case VDDN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("d"));
                } else {}break;
            case EXPL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("e"));
                } else {}break;
            case SNIP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                } else {}break;
            case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("ac"));
                } else {}break;
            case PAST:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("v"));
                } else {}break;

            //Discord Section
            case THIS:
            if (record->event.pressed) {
                    SEND_STRING(":this:" SS_TAP(X_ENTER) );
                    } else {}break;
            case OOF:
            if (record->event.pressed) {
                    SEND_STRING(":oof:" SS_TAP(X_ENTER));
                    } else {}break;
            case PIKA:
            if (record->event.pressed) {
                    SEND_STRING(":surprised:" SS_TAP(X_ENTER));
                    } else {}break;
            case SCAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_spanish:" SS_TAP(X_ENTER));
                    } else {}break;
            case FCAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_fancy:" SS_TAP(X_ENTER));
                    } else {}break;
            case HART:
            if (record->event.pressed) {
                    SEND_STRING(":heart:" SS_TAP(X_ENTER));
                    } else {}break;
            case DROL:
            if (record->event.pressed) {
                    SEND_STRING(":drooling_face:" SS_TAP(X_ENTER));
                    } else {}break;
            case MONY:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_takemoney:" SS_TAP(X_ENTER));
                    } else {}break;
            case FHAT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_tip_fedora:" SS_TAP(X_ENTER));
                    } else {}break;
            case SPIT:
            if (record->event.pressed) {
                    SEND_STRING(":smiley_spit_surprised:" SS_TAP(X_ENTER));
                    } else {}break;
            /*Bluetooth Capslock Section
            case QQ:
            if (record->event.pressed) {
                    SEND_STRING(SS_LSFT("q"));
                    } else {}break;
            case WW:
            if (record->event.pressed) {
                    SEND_STRING("W");
                    } else {}break;
            case EE:
            if (record->event.pressed) {
                    SEND_STRING("E");
                    } else {}break;
            case RR:
            if (record->event.pressed) {
                    SEND_STRING("R");
                    } else {}break;
            case TT:
            if (record->event.pressed) {
                    SEND_STRING("T");
                    } else {}break;
            case YY:
            if (record->event.pressed) {
                    SEND_STRING("Y");
                    } else {}break;
            case UU:
            if (record->event.pressed) {
                    SEND_STRING("U");
                    } else {}break;
            case II:
            if (record->event.pressed) {
                    SEND_STRING("I");
                    } else {}break;
            case OO:
            if (record->event.pressed) {
                    SEND_STRING("O");
                    } else {}break;
            case PP:
            if (record->event.pressed) {
                    SEND_STRING("P");
                    } else {}break;
            case AA:
            if (record->event.pressed) {
                    SEND_STRING("A");
                    } else {}break;
            case SS:
            if (record->event.pressed) {
                    SEND_STRING("S");
                    } else {}break;
            case DD:
            if (record->event.pressed) {
                    SEND_STRING("D");
                    } else {}break;
            case FF:
            if (record->event.pressed) {
                    SEND_STRING("F");
                    } else {}break;
            case GG:
            if (record->event.pressed) {
                    SEND_STRING("G");
                    } else {}break;
            case HH:
            if (record->event.pressed) {
                    SEND_STRING("H");
                    } else {}break;
            case JJ:
            if (record->event.pressed) {
                    SEND_STRING("J");
                    } else {}break;
            case KK:
            if (record->event.pressed) {
                    SEND_STRING("K");
                    } else {}break;
            case LL:
            if (record->event.pressed) {
                    SEND_STRING("L");
                    } else {}break;
            case ZZ:
            if (record->event.pressed) {
                    SEND_STRING("Z");
                    } else {}break;
            case XX:
            if (record->event.pressed) {
                    SEND_STRING("X");
                    } else {}break;
            case CC:
            if (record->event.pressed) {
                    SEND_STRING("C");
                    } else {}break;
            case VV:
            if (record->event.pressed) {
                    SEND_STRING("V");
                    } else {}break;
            case BB:
            if (record->event.pressed) {
                    SEND_STRING("B");
                    } else {}break;
            case NN:
            if (record->event.pressed) {
                    SEND_STRING("N");
                    } else {}break;
            case MM:
            if (record->event.pressed) {
                    SEND_STRING("M");
                    } else {}break;
                */
        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0

    /*
     *         ,-----------------------------------------------.
     *         |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
     * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|     |PrS|ScL|Pau|     |VDn|VUp|Mut|
     * `---'   `-----------------------------------------------'     `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
     * |-----------------------------------------------------------| `-----------' |---------------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| ^a|Entr|               |  4|  5|  6|KP,|
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
     * |-----------------------------------------------------------| ,-----------. |---------------|
     * |Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  #|  0|  .|KP=|
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
         
    [0] = LAYOUT(
                   KC_F13,KC_F14,KC_F15,KC_F16,KC_F17,KC_F18,KC_F19,KC_F20,KC_F21,KC_F22,KC_F23,KC_F24,                                                                             \
                   KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,KC_F10,KC_F11,KC_F12,         KC_PSCR,KC_SLCK,KC_PAUS,      KC_VOLD,KC_VOLU,KC_MUTE,              \
                   KC_ESC,                                                                                                                                                          \
                   KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_JYEN,KC_BSPC,     KC_INS,KC_HOME,KC_PGUP,       KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,      \
                   KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,            KC_DEL,KC_END,KC_PGDN,        KC_P7,KC_P8,KC_P9,KC_PPLS,            \
                   KC_CAPS,RESET,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,                                       KC_P4,KC_P5,KC_P6,KC_PCMM,            \
                   KC_LSFT,KC_NUBS,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RO,KC_RSFT,            KC_UP,                 KC_P1,KC_P2,KC_P3,KC_PENT,            \
                   KC_LCTL,KC_LGUI,KC_LALT,KC_MHEM,KC_SPC,KC_HENK,KC_KANA,KC_RALT,KC_RGUI,KC_NO,KC_RCTL,        KC_LEFT,KC_DOWN,KC_RGHT,      KC_NO,KC_P0,KC_PDOT,KC_PEQL           \
    ),


};
