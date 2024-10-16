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

#ifndef LED_CAPS_LOCK_PIN
#   define LED_CAPS_LOCK_PIN GP28
#endif // LED_CAPS_LOCK_PIN

#ifndef LED_NUM_LOCK_PIN
#   define LED_NUM_LOCK_PIN GP13
#endif // LED_NUM_LOCK_PIN

#ifndef LED_SCROLL_LOCK_PIN
#   define LED_SCROLL_LOCK_PIN GP11
#endif // LED_SCROLL_LOCK_PIN

#ifndef LED_KANA_PIN
#   define LED_KANA_PIN GP17
#endif // LED_KANA_PIN

#ifndef LED_PIN_ON_STATE
#   define LED_PIN_ON_STATE 1
#endif // LED_PIN_ON_STATE

#ifndef MANUFACTURER
#   define MANUFACTURER Alectardy98
#endif // MANUFACTURER

#ifndef PRODUCT
#   define PRODUCT Zenithal
#endif // PRODUCT

#ifndef PRODUCT_ID
#   define PRODUCT_ID 0x0004
#endif // PRODUCT_ID

#ifndef VENDOR_ID
#   define VENDOR_ID 0x7281
#endif // VENDOR_ID

#ifndef MATRIX_COLS
#   define MATRIX_COLS 10
#endif // MATRIX_COLS

#ifndef MATRIX_ROWS
#   define MATRIX_ROWS 10
#endif // MATRIX_ROWS


#ifndef MATRIX_COL_PINS
#   define MATRIX_COL_PINS { GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP12, GP14 }
#endif // MATRIX_COL_PINS


#ifndef MATRIX_ROW_PINS
#   define MATRIX_ROW_PINS { GP2, GP1, GP0, GP18, GP19, GP20, GP21, GP22, GP26, GP27 }
#endif // MATRIX_ROW_PINS

#ifndef ENCODERS_PAD_A
#   define ENCODERS_PAD_A {  }
#endif // ENCODERS_PAD_A
#ifndef ENCODERS_PAD_B
#   define ENCODERS_PAD_B {  }
#endif // ENCODERS_PAD_B
#ifndef ENCODER_RESOLUTIONS
#   define ENCODER_RESOLUTIONS {  }
#endif // ENCODER_RESOLUTIONS
