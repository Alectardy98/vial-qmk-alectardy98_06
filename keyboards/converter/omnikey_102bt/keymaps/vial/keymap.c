#include "stdint.h"
#include "ps2.h"
#include "led.h"
#include QMK_KEYBOARD_H


enum layer_names {                                             //Define Layers
    _BASE,
    _NUM,
    _FN
};

//Lock lights over bluetooth are hard to implament, as currently qmk dosent send the computer state back to the keyboard when in bluetooth, This code can be modified for the desired effect
void led_set(uint8_t usb_led) {
    uint8_t ps2_led = 0;
    if (usb_led &  (1<<USB_LED_SCROLL_LOCK))
        ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
    if (usb_led &  (1<<USB_LED_NUM_LOCK))
        ps2_led |= (1<<PS2_LED_NUM_LOCK);
    if (usb_led &  (1<<USB_LED_CAPS_LOCK))
        ps2_led |= (1<<PS2_LED_CAPS_LOCK);
    ps2_host_set_led(ps2_led);
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
         KC_F11,  KC_F12,                                                                                                                                         KC_PSCR, KC_SLCK, KC_PAUS,                                          \
          KC_F1,   KC_F2,       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,       KC_INS, KC_HOME, KC_PGUP,     TG(_NUM), KC_PSLS, KC_PAST, KC_PMNS, \
          KC_F3,   KC_F4,       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,       KC_DEL,  KC_END, KC_PGDN,        KC_P7,   KC_P8,   KC_P9, KC_PPLS, \
          KC_F5,   KC_F6,      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                                                          KC_P4,   KC_P5,   KC_P6, KC_PEQL, \
          KC_F7,   KC_F8,      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS,                          KC_UP,                 KC_P1,   KC_P2,   KC_P3, KC_PENT, \
          KC_F9,  KC_F10,      KC_LCTL,          KC_LALT,                             KC_SPC,                            KC_RALT,          KC_RCTL,               KC_LEFT, KC_DOWN, KC_RGHT,                 KC_P0,  KC_PDOT           \
    ),
    [_NUM] = LAYOUT(
        _______, _______,                                                                                                                                         _______, _______, _______,                                          \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                        _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                        _______,               _______, _______, _______, _______, \
        _______, _______,      _______,          _______,                            _______,                            _______,          _______,               _______, _______, _______,               _______, _______           \
    ),
    [_FN] = LAYOUT(
        _______, _______,                                                                                                                                         _______, _______, _______,                                          \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                                        _______, _______, _______, _______, \
        _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                        _______,               _______, _______, _______, _______, \
        _______, _______,      _______,          _______,                            _______,                            _______,          _______,               _______, _______, _______,               _______, _______           \
    )
};


