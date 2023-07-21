
#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}




/*
 *
 *
 *                 ,-----------------------------------------------.       ,-----------.
 *                 |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |PrS|ScL|Pau|
 *                 `-----------------------------------------------'       `-----------'
 * ,-------. ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |   |   | |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bsp  | |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-------| |-----------------------------------------------------------| |-----------| |---------------|
 * |   |   | |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-------| |-----------------------------------------------------------| |-----------| |---------------|
 * |   |   | |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Entr  | |Del|End|PgD| |  4|  5|  6|KP,|
 * |-------| |-----------------------------------------------------------| |-----------| |---------------|
 * |   |   | |Shft| Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift  |Extr | |Del|End|PgD| |  1|  2|  3|Ent|
 * |-------| |-----------------------------------------------------------| |-----------| |---------------|
 * |   |   | |Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  #|  0|  .|KP=|
 * `-------' `-----------------------------------------------------------' `-----------' `---------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(

                    KC_ESC,KC_T,    KC_F1,KC_F2,KC_F3,KC_F4,    KC_F5,KC_F6,KC_F7,KC_F8,    KC_F9,KC_F10,KC_F11,KC_F12,    KC_F13,KC_F14,KC_F15,                                          \
                    KC_T,KC_T,      KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,       KC_PSCR,KC_SLCK,KC_PAUS,   KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,    \
                    KC_T,KC_T,      KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,      KC_INS,KC_HOME,KC_PGUP,    KC_P7,KC_P8,KC_P9,KC_PPLS,          \
                    KC_T,KC_T,      KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,           KC_DEL,KC_END,KC_PGDN,     KC_P4,KC_P5,KC_P6,                  \
                    KC_T,KC_T,              KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,RESET,       KC_T,KC_UP,KC_T,           KC_P1,KC_P2,KC_P3,KC_PEQL,          \
                    KC_T,KC_T,      KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                  MO(1),                      KC_LEFT,KC_DOWN,KC_RGHT,   KC_P0,KC_PDOT                       \
    ),

    [1] = LAYOUT(

                    RESET,DEBUG,    KC_F1,KC_F2,KC_F3,KC_F4,    KC_F5,KC_F6,KC_F7,KC_F8,    KC_F9,KC_F10,KC_F11,KC_F12,    KC_F13,KC_F14,KC_F15,                                          \
                    KC_T,KC_T,      KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,       KC_PSCR,KC_SLCK,KC_PAUS,   KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,    \
                    KC_T,KC_T,      KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,      KC_INS,KC_HOME,KC_PGUP,    KC_P7,KC_P8,KC_P9,KC_PPLS,          \
                    KC_T,KC_T,      KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,           KC_DEL,KC_END,KC_PGDN,     KC_P4,KC_P5,KC_P6,                  \
                    KC_T,KC_T,              KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,RESET,       KC_T,KC_UP,KC_T,           KC_P1,KC_P2,KC_P3,KC_PEQL,          \
                    KC_T,KC_T,      KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                  KC_TRNS,                    KC_LEFT,KC_DOWN,KC_RGHT,   KC_P0,KC_PDOT                       \
    ),


};


/*

*/
