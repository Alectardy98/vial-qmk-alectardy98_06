#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7281
#define PRODUCT_ID      0x0020
#define DEVICE_VER      0x0001
#define MANUFACTURER    Kuritakey
#define PRODUCT         M0110A

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { GP0, GP22, GP21, GP9, GP4, GP2, GP6, GP1 }
#define MATRIX_COL_PINS { GP27, GP11, GP12, GP13, GP14, GP28, GP16, GP17, GP18, GP19 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
