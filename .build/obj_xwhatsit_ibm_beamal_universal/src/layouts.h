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

#define LAYOUT(k6L, k7L, k7C, k7B, k7A, k6A, k4L, k5L, k7K, k6K, k7J, k7I, k6I, k7H, k6H, k7G, k6G, k7F, k6F, k7E, k6E, k7D, k6D, k6C, k6B, k5A, k4A, k3L, k4K, k5K, k6J, k5J, k5I, k4I, k5H, k4G, k5G, k4F, k5F, k4E, k5E, k5D, k4D, k5C, k5B, k4B, k3A, k2L, k3K, k2K, k4J, k3J, k3I, k4H, k3H, k3G, k2G, k3F, k2F, k3E, k2E, k4C, k3B, k2B, k2A, k1L, k1K, k2J, k1J, k2I, k1I, k2H, k1H, k1G, k0G, k1F, k0F, k1E, k2D, k3C, k2C, k1B, k1A, k0L, k0K, k0J, k0I, k0H, k0E, k1D, k1C, k0C, k0B, k0A) {\
	 {k0A, k0B, k0C, KC_NO, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L}, \
	 {k3A, k3B, k3C, KC_NO, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, k7I, k7J, k7K, k7L} \
}
