
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN
    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
             KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_INS,       KC_F1,   KC_F2,   KC_F3,   KC_F4, \
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_GRV,  KC_DEL,        KC_7,    KC_8,    KC_9, KC_PMNS, \
            KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,  KC_END,                 KC_4,    KC_5,    KC_6, KC_PCMM, \
            MO(_FN), KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,            KC_UP, KC_HOME,        KC_1,    KC_2,    KC_3, KC_PENT, \
            KC_CAPS,                                                RESET,                                     KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,                 KC_0,  KC_DOT           \
            ),
    [_FN] = LAYOUT(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,     _______, _______, _______, _______, \
            _______,                                              _______,                                     _______, _______, _______, _______,              _______, _______           \
            ),
} ;
