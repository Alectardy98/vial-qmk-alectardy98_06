
#pragma once

#define VENDOR_ID       0x7281
#define PRODUCT_ID      0x0035
#define DEVICE_VER      0x0001
#define MANUFACTURER    QMK
#define PRODUCT         Wyse WY-30

#define MATRIX_ROWS       18
#define MATRIX_COLS       8

/* key combination for command */
#define IS_COMMAND() ( \
    get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RCTL)) \
)
