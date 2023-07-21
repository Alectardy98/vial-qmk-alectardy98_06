#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0x6776
#define PRODUCT_ID      0x7476
#define DEVICE_VER      0x0001
#define MANUFACTURER    Alec
#define PRODUCT         Televideo 725

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 21

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {D7,E0,E1,C0,C1,C2}
#define MATRIX_COL_PINS {B6,B5,B4,B3,B2,B1,B0,E7,E6,B7,D0,D1,D2,D3,D4,D5,C3,C4,C5,C6,C7}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define QMK_ESC_OUTPUT B6 // usually COL
#define QMK_ESC_INPUT D7 // usually ROW

#define USB_POLLING_INTERVAL_MS 1
