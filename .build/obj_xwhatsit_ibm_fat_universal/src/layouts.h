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

#define LAYOUT_all(k3A, k2A, k2B, k2C, k2D, k2E, k3E, k2F, k2G, k3H, k2H, k2I, k3I, k2J, k2K, k2L, k1M, k1O, k0O, k1P, k0P, k4A, k4B, k3B, k3C, k3D, k4E, k3F, k4F, k3G, k4H, k5I, k4I, k3J, k3K, k4L, k3L, k3N, k2O, k2P, k3P, k5A, k5B, k4C, k4D, k5D, k5E, k5F, k4G, k5G, k5H, k6I, k5J, k4J, k5K, k4K, k5L, k4N, k4O, k3O, k4P, k6A, k6B, k6C, k5C, k6D, k6E, k7E, k6F, k6G, k7G, k6H, k7I, k7J, k6J, k6K, k6L, k6N, k5O, k5P, k6P, k7A, k7B, k7C, k7D, k7F, k7H, k7L, k7N, k7O, k6O, k7P) {\
	 {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k0O, k0P}, \
	 {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k1M, KC_NO, k1O, k1P}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, KC_NO, KC_NO, k2O, k2P}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, KC_NO, k3N, k3O, k3P}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, KC_NO, k4N, k4O, k4P}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L, KC_NO, KC_NO, k5O, k5P}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, k6K, k6L, KC_NO, k6N, k6O, k6P}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F, k7G, k7H, k7I, k7J, KC_NO, k7L, KC_NO, k7N, k7O, k7P} \
}

#define LAYOUT_default(k3A, k2A, k2B, k2C, k2D, k2E, k3E, k2F, k2G, k3H, k2H, k2I, k3I, k2J, k2K, k2L, k1M, k1O, k0O, k1P, k0P, k4A, k4B, k3B, k3C, k3D, k4E, k3F, k4F, k3G, k4H, k5I, k4I, k3J, k3K, k4L, k5L, k3N, k2O, k2P, k3P, k5A, k5B, k4C, k4D, k5D, k5E, k5F, k4G, k5G, k5H, k6I, k5J, k4J, k5K, k4N, k4O, k3O, k4P, k6A, k6B, k6C, k6D, k6E, k7E, k6F, k6G, k7G, k6H, k7I, k7J, k6J, k6L, k6N, k5O, k5P, k6P, k7A, k7B, k7C, k7F, k7L, k7O, k6O) {\
	 {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k0O, k0P}, \
	 {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k1M, KC_NO, k1O, k1P}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, KC_NO, KC_NO, k2O, k2P}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, KC_NO, KC_NO, k3N, k3O, k3P}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, KC_NO, k4L, KC_NO, k4N, k4O, k4P}, \
	 {k5A, k5B, KC_NO, k5D, k5E, k5F, k5G, k5H, k5I, k5J, k5K, k5L, KC_NO, KC_NO, k5O, k5P}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F, k6G, k6H, k6I, k6J, KC_NO, k6L, KC_NO, k6N, k6O, k6P}, \
	 {k7A, k7B, k7C, KC_NO, k7E, k7F, k7G, KC_NO, k7I, k7J, KC_NO, k7L, KC_NO, KC_NO, k7O, KC_NO} \
}
