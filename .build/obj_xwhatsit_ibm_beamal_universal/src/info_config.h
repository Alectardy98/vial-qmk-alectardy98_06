// Copyright 2023 QMK
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

#ifndef DEVICE_VER
#   define DEVICE_VER 0x0001
#endif // DEVICE_VER

#ifndef LED_CAPS_LOCK_PIN
#   define LED_CAPS_LOCK_PIN E6
#endif // LED_CAPS_LOCK_PIN

#ifndef LED_NUM_LOCK_PIN
#   define LED_NUM_LOCK_PIN D7
#endif // LED_NUM_LOCK_PIN

#ifndef LED_SCROLL_LOCK_PIN
#   define LED_SCROLL_LOCK_PIN B6
#endif // LED_SCROLL_LOCK_PIN

#ifndef MANUFACTURER
#   define MANUFACTURER Alectardy98/Tom Wong-Cornall/listofoptions/kmnov2017/Purdea Andrei
#endif // MANUFACTURER

#ifndef PRODUCT
#   define PRODUCT BEAMal
#endif // PRODUCT

#ifndef PRODUCT_ID
#   define PRODUCT_ID 0x27DB
#endif // PRODUCT_ID

#ifndef VENDOR_ID
#   define VENDOR_ID 0x16C0
#endif // VENDOR_ID
