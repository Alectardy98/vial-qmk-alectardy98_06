#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6776
#define PRODUCT_ID      0x5341
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gvalchca
#define PRODUCT         SatisfyerAlbz

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {B1,B0,E6,D4,D3,D2}
#define MATRIX_COL_PINS {F0,F1,F4,F5,F6,F7,C7,C6,B6,B5,B4,D7,D6,D5,B2}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A {B3}
#define ENCODERS_PAD_B {B7}

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define QMK_ESC_OUTPUT F0 // usually COL
#define QMK_ESC_INPUT B1 // usually ROW
