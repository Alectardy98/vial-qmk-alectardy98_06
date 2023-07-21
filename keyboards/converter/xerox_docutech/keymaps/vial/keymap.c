/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
    _EMOJI
};

enum custom_keycodes {      //In Mac OS Swap Command and Control for proper macro use
    TEST = SAFE_RANGE,
    XCAP,                   //Desktop Right "set to move right a space on mac"
};
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {             //Code for macros
        switch(keycode) {
            case TEST:
            if (record->event.pressed) {
                SEND_STRING("TEST");
                }break;
            case XCAP:
            if (record->event.pressed) {
                SEND_STRING( SS_TAP(X_CAPS) SS_TAP(X_CAPS));
                }break;

        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %1u, time: %u, interrupt: %1u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*               ,--------------------.  ,--------------------.  ,-----------.
     *                |    |    |    |     |  |    |    |    |     |  |     |     |
     *                `--------------------'  `--------------------'  `-----------'
     *     ,--------. ,----------------------------------------------------------. ,---------------.
     *     |   |    | |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Back| |  +|  -|  *|  /|
     *     |--------| |----------------------------------------------------------| |---------------|
     *     |   |    | |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Rtn| |   |  7|  8|  9|
     *     |--------| |-------------------------------------------------------   | |---------------|
     *     |   |    | |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  `|   | |   |  4|  5|  6|
     *     |--------| |----------------------------------------------------------| |   |-----------|
     *     |   |    | |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|    Shift| |   |  1|  2|  3|
     *     |--------| |----------------------------------------------------------| |---------------|
     *     |   |    | |     |    |              Space                 |    |     | |      0|  .|  ,|
     *     `--------' `-----'    `------------------------------------'    `-----' `---------------'
     */

	[_BASE] = LAYOUT(
                           KC_F1,  KC_F2,  KC_F3,  KC_F4,                  KC_F5,  KC_F6,  KC_F7,  KC_F8,                  KC_F9, KC_F10,                                      \
        KC_T,   KC_T,     KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,    KC_PPLS,KC_PMNS,KC_PAST,KC_PSLS,  \
        KC_T,   KC_T,     KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC, KC_ENT,     KC_DEL,   KC_7,   KC_8,   KC_9,  \
        KC_T,   KC_T,    KC_CAPS,KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,KC_QUOT,    KC_PENT,   KC_4,   KC_5,   KC_6,  \
        KC_T,   KC_T,    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,                               KC_1,   KC_2,   KC_3,  \
        KC_T,   KC_T,    KC_LCTL,        KC_LALT,                 KC_SPC,                                        KC_RALT,        KC_RCTL,                KC_0, KC_DOT,KC_PCMM  \
        ),
    [_FN] = LAYOUT(
                         _______,_______,_______,_______,                _______,_______,_______,_______,                _______,_______,                                      \
     _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,  \
     _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,  \
     _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,  \
     _______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                            _______,_______,_______,  \
     _______,_______,    _______,        _______,                _______,                                        _______,        _______,            _______,_______,_______   \
        ),

};
