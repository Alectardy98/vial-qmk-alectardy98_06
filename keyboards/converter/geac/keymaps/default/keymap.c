
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *   +-----+-----+-----+-----+       +-----+-----+-----+-----+
 *   | f1  | f2  | f3  | f4  |       | f5  | f6  | f7  | f8  |
 *   +-----+-----+-----+-----+       +-----+-----+-----+-----+   +-----+
 *                                                               |UP   |
 *   +---+---+---+---+---+---+---+---+---+---+---+---+---+---+   +-----+
 *   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | : | - |BS |LF |   |DOWN |
 * +-+------------------------------------------------------++   +-----+
 * |   | Q | W | E | R | T | Y | U | I | O | P | [ | ] |RETN|    |RIGHT|
 * ++----------------------------------------------------   |    +-----+
 *  |   | A | S | D | F | G | H | J | K | L | ; | @ |UPL|   |    |LEFT |
 *  +-------------------------------------------------------+    +-----|
 *  |SHIFT| Z | X | C | V | B | N | M | , | . | / |SHIFT|CAP|    |SEND |
 *  +-----+---+-------------------------------+---+-----+---+    +-----+
 *            |            SPACE              |
 *            +-------------------------------+
 *
 * Note: both shift keys send the same code.
 */

  [0] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4,                     KC_F5, KC_F6, KC_F7, KC_F8, \
                                                                                                   KC_UP, \
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,  KC_DOWN, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,  KC_RIGHT, \
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_HOME,      KC_LEFT, \
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCAP, KC_ESC, \
              KC_SPC \
  )
} ;