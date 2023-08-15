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

#define LAYOUT(k1A, k0A, k0J, k0K, k0L, k1L, k3A, k2A, k0B, k1B, k0C, k0D, k1D, k0E, k1E, k0F, k1F, k0G, k1G, k0H, k1H, k0I, k1I, k1J, k1K, k2L, k3L, k4A, k3B, k2B, k1C, k2C, k2D, k3D, k2E, k3F, k2F, k3G, k2G, k3H, k2H, k2I, k3I, k2J, k2K, k3K, k4L, k5A, k4B, k5B, k3C, k4C, k4D, k3E, k4E, k4F, k5F, k4G, k5G, k4H, k5H, k3J, k4K, k5K, k5L, k6A, k6B, k5C, k6C, k5D, k6D, k5E, k6E, k6F, k7F, k6G, k7G, k6H, k5I, k4J, k5J, k6K, k6L, k7A, k7B, k7C, k7D, k7E, k7H, k6I, k6J, k7J, k7K, k7L) {\
	 {k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, KC_NO, k4J, k4K, k4L}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, KC_NO, k7J, k7K, k7L} \
}
