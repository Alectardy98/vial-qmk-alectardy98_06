
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *
 * +-----+-----+ +-----+---+---+---+---+----+----+----+----+----+----+----+-----+ +---+---+---+---+
 * |ERASE|EODL | |LINE |DUP|LF |FF |CHG|FLOC|FCLR|FENA|FGEN|CERS|PAGE|WAIT|XMIT | | 7 | 8 | 9 | - |
 * +-----------+ +-+--------------------------------------------------------+---+ +---------------+
 * |DELET|INSRT|   | | | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | / | ^ | BS |     | 4 | 5 | 6 | + |
 * +-----------+   +--------------------------------------------------------+---+ +---------------+
 * |HOME |TAB S|   | TAB | Q | W | E | R | T | Y | U | I | O | P | @ | [ |BTB|  | | 1 | 2 | 3 |TAB|
 * +-----------+ +-+---------------------------------------------------------|  | +-----------|   |
 * |    UP     | |FCTN|LCK| A | S | D | F | G | H | J | K | L | ; | : | ] |ENTER| |   0   | . |   |
 * +-----------+ +---------------------------------------------------------+----+ +-------+---+---+
 * |LEFT |RIGHT| |SHIFT |< >| Z | X | C | V | B | N | M | , | . | - |SHIFT |
 * +-----------+ +---------+-----------------------------------+-----------+
 * |   DOWN    |           |               SPACE               |
 * +-----------+           +-----------------------------------+
 *
 */

  [0] = LAYOUT(
    KC_PGUP, KC_PGDN,  KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_SLCK, KC_PAUS,           KC_P7, KC_P8, KC_P9, KC_PMNS, \
    KC_DEL, KC_INS,    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,               KC_P4, KC_P5, KC_P6, KC_PPLS, \
    KC_HOME, KC_END,   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LBRC, KC_DEL,               KC_P1, KC_P2, KC_P3, KC_PENT, \
    KC_UP,             KC_LCTL, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_RBRC, KC_ENT,  KC_P0, KC_PDOT, \
    KC_LEFT, KC_RGHT,  KC_LSFT, KC_NUHS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
    KC_DOWN,           KC_SPACE
  )
} ;
