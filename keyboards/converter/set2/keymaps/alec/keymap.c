#include "stdint.h"
#include "ps2.h"
#include "led.h"
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
};
/*
void led_set(uint8_t usb_led) {
    uint8_t ps2_led = 0;
    if (layer_state_is(_FN))
        ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
    if (layer_state_is(_NUM))
        ps2_led |= (1<<PS2_LED_NUM_LOCK);
    if (host_keyboard_leds() &  (1<<USB_LED_CAPS_LOCK))
        ps2_led |= (1<<PS2_LED_CAPS_LOCK);

}
*/
void led_set(uint8_t usb_led) {
    uint8_t ps2_led = 0;
    if (layer_state_is(_FN))
        ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
    if (usb_led &  (1<<USB_LED_NUM_LOCK))
        ps2_led |= (1<<PS2_LED_NUM_LOCK);
    if (usb_led &  (1<<USB_LED_CAPS_LOCK))
        ps2_led |= (1<<PS2_LED_CAPS_LOCK);
    ps2_host_set_led(ps2_led);
}


enum custom_keycodes {
    TEST= SAFE_RANGE,
    VDRT,                   //Desktop Right "set to move right a space on mac"
    VDLT,                   //Desktop Left "set to move left a space on mac"
    VDUP,                   //V-Desktop Up "set to mission controll on mac"
    VDDN,                   //Min All "set to show desktop on mac"
    EXPL,                   //New Explorer On Windows "set to show finder search window on mac"
    SNIP,                   //Snip Tool Windows "set to save picture of selected area on mac"
    COPY,                   //Copy All
    PAST,                   //Paste Over
    TASK,                   //Task Manager
    DZRO,                   //Double Zero
    ATAB,                   //Alt + Tab "brew install alt-tab on mac"
    THIS,                   //Macro for "THIS" emoji on discord
    OOF,                    //Macro for "OOF" emoji on discord
    PIKA,                   //Macro for "PIKA" emoji on discord
    SCAT,                   //Macro for "SCAT" emoji on discord
    FCAT,                   //Macro for "FCAT" emoji on discord
    HART                   //Macro for "HART" emoji on discord
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TEST:
        if (record->event.pressed) {
            SEND_STRING("I LOVE YOU");
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
        case TASK:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_DOWN(X_RSHIFT)SS_TAP(X_ESCAPE)SS_UP(X_RSHIFT)));
            SEND_STRING(SS_LGUI(SS_DOWN(X_LALT)SS_TAP(X_ESCAPE)SS_UP(X_LALT)));
            } else {}break;
        case DZRO:
        if (record->event.pressed) {
            SEND_STRING("00");
            } else {}break;
        case ATAB:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
            } else {}break;
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
            SEND_STRING(":cat_spanish:" SS_TAP(X_ENTER));
            } else {}break;
        case FCAT:
        if (record->event.pressed) {
            SEND_STRING(":cat_fancy:" SS_TAP(X_ENTER));
            } else {}break;
        case HART:
        if (record->event.pressed) {
            SEND_STRING(":heart:" SS_TAP(X_ENTER));
            } else {}break;
    }
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
         
                [_BASE] = LAYOUT(
                   KC_F13,KC_F14,KC_F15,KC_F16,KC_F17,KC_F18,KC_F19,KC_F20,KC_F21,KC_F22,KC_F23,KC_F24,                                                                             \
                   KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,KC_F10,KC_F11,KC_F12,         KC_PSCR,KC_SLCK,RESET,      KC_VOLD,KC_VOLU,KC_MUTE,              \
                   KC_ESC,                                                                                                                                                          \
                   KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_JYEN,KC_BSPC,     KC_INS,KC_HOME,KC_PGUP,       KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,      \
                   KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,            KC_DEL,KC_END,KC_PGDN,        KC_P7,KC_P8,KC_P9,KC_PPLS,            \
                   KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,                                       KC_P4,KC_P5,KC_P6,KC_PCMM,            \
                   KC_LSFT,KC_NUBS,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RO,KC_RSFT,            KC_UP,                 KC_P1,KC_P2,KC_P3,KC_PENT,            \
                   KC_LCTL,KC_LGUI,KC_LALT,KC_MHEM,KC_SPC,KC_HENK,KC_KANA,KC_RALT,MO(_FN),KC_LGUI,KC_RCTL,             KC_LEFT,KC_DOWN,KC_RGHT,      KC_NO,KC_P0,KC_PDOT,KC_PEQL           \
                 ),

                 [_FN] = LAYOUT(
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                                                                                  \
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                             KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS,KC_TRNS,KC_TRNS,              \
                   RESET,                                                                                                                                                                                            \
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,      \
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,KC_TRNS,KC_TRNS,       THIS,   KC_VOLU,KC_P9,  OOF,          \
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                            KC_MPRV,KC_MPLY,KC_MNXT,KC_TRNS,      \
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                     VDUP,                  PIKA,   KC_VOLD,SCAT,   KC_TRNS,      \
                   KC_TRNS,KC_TRNS,KC_LGUI,KC_TRNS,TEST,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                        VDLT,VDDN,VDRT,             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS       \
                 ),
};


