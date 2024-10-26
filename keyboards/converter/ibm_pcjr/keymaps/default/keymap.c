
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+-----+------+
 * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |Backs|  Fn  |
 * +---------------------------------------------------------+------+
 * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |   |
 * +-----------------------------------------------------|   |------+
 * | Ctrl | A | S | D | F | G | H | J | K | L | ; | ' |Enter |  Up  |
 * +----------------------------------------------------------------+
 * |  Shift | Z | X | C | V | B | N | M | , | . | / | Shift |Lft|Rgt|
 * +--------+---+---------------------------------------------------+
 *              |Alt|                           |Cap|Ins|Del| Down  |
 *              +---+---------------------------+---+---+---+-------+
 */

  [0] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BSPACE, MO(1), \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_RBRACKET, \
    KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_ENTER, KC_UP, \
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, KC_LEFT, KC_RIGHT, \
    MO(2), KC_SPACE, KC_CAPS, KC_INS, KC_DEL, KC_DOWN
  ),

/*
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+-----+------+
 * |   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|   |   |     |      |
 * +---------------------------------------------------------+------+
 * |     |Pau|   |Ech|   |   |   |   |   |   |Prt|   |   |   |
 * +-----------------------------------------------------|   |------+
 * |      |   |Scl|   |   |   |   |   |   |   |   |   |      | Home |
 * +----------------------------------------------------------------+
 * |        |   |   |   |   |Brk|   |   |   |   |   |       |PgU|PgD|
 * +--------+---+---------------------------------------------------+
 *              |Alt|                           |   |   |   | End   |
 *              +---+---------------------------+---+---+---+-------+
 */

  [1] = LAYOUT(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, _______, _______, \
    _______, KC_PAUSE, _______, KC_NO, _______, _______, _______, _______, _______, _______, KC_PSCREEN, _______, _______, \
    _______, _______, KC_SCROLLLOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, \
    _______, _______, _______, _______, _______, KC_SYSREQ, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDOWN, \
    MO(3), _______, _______, _______, _______, KC_END
  ),

/*
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+-----+------+
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |     |  Fn  |
 * +---------------------------------------------------------+------+
 * |     |   |   |   |   |   |   |   |   |   |   | | | ~ |   |
 * +-----------------------------------------------------|   |------+
 * |      |   |   |   |   |   |   |   |   |   |   | ` |      |      |
 * +----------------------------------------------------------------+
 * |        |   |   |   |   |   |   |   |   |   | \ |       |   |   |
 * +--------+---+---------------------------------------------------+
 *              |   |                           |   |   |   |       |
 *              +---+---------------------------+---+---+---+-------+
 */

  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(3), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_TILDE, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLASH, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______
  ),

/*
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+-----+------+
 * |   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |   |   |     |      |
 * +---------------------------------------------------------+------+
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |   |
 * +-----------------------------------------------------|   |------+
 * |      |   |   |   |   |   |   |   |   |   |   |   |      |      |
 * +----------------------------------------------------------------+
 * |        |   |   |   |   |   |   |   |   |   |   |       |   |   |
 * +--------+---+---------------------------------------------------+
 *              |   |                           |   |   |   |       |
 *              +---+---------------------------+---+---+---+-------+
 */

  [3] = LAYOUT(
    _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8,KC_KP_9, KC_KP_0, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______
  ),

} ;
