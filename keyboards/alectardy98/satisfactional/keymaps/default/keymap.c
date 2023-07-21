#include QMK_KEYBOARD_H
#include "oled/bongocat.h"

enum _layer {
  _BASE,
  _NUM,
  _FN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
   KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,          QK_BOOT, \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_BSPC, \
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,  KC_DEL, \
  KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,          KC_HOME, \
  KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,  KC_END, \
  KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                   KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______),
    
 [_FN] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
          // Mappings for 1st Encoder
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, // Mapping for Base layer
    [_NUM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, // Mapping for Layer 1
    [_FN] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, // Mapping for Layer 2
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
        oled_set_cursor(17, 3);
        oled_write_P(layer_state_is(_FN) ? PSTR("FN") : PSTR("    "), false);

        return true;
    }
#endif
