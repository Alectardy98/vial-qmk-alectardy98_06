// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

#ifndef DEBOUNCE
#   define DEBOUNCE 6
#endif // DEBOUNCE

#ifndef DEVICE_VER
#   define DEVICE_VER 0x0001
#endif // DEVICE_VER

#ifndef DIODE_DIRECTION
#   define DIODE_DIRECTION COL2ROW
#endif // DIODE_DIRECTION

#ifndef LED_NUM_LOCK_PIN
#   define LED_NUM_LOCK_PIN GP27
#endif // LED_NUM_LOCK_PIN

#ifndef LED_PIN_ON_STATE
#   define LED_PIN_ON_STATE 0
#endif // LED_PIN_ON_STATE

#ifndef MANUFACTURER
#   define MANUFACTURER Alectardy98
#endif // MANUFACTURER

#ifndef PRODUCT
#   define PRODUCT Cherrypadal
#endif // PRODUCT

#ifndef PRODUCT_ID
#   define PRODUCT_ID 0x0740
#endif // PRODUCT_ID

#ifndef VENDOR_ID
#   define VENDOR_ID 0x7281
#endif // VENDOR_ID

#ifndef MATRIX_COLS
#   define MATRIX_COLS 4
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#   define MATRIX_ROWS 6
#endif // MATRIX_ROWS


#ifndef MATRIX_COL_PINS
#   define MATRIX_COL_PINS { GP26, GP24, GP23, GP21 }
#endif // MATRIX_COL_PINS


#ifndef MATRIX_ROW_PINS
#   define MATRIX_ROW_PINS { GP11, GP25, GP20, GP19, GP18, GP17 }
#endif // MATRIX_ROW_PINS

