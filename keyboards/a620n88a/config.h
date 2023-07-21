/* Copyright 2020 Keymacs s.r.o. (https://keymacs.com/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER Keymacs
#define PRODUCT A620N-88 Rev. A
#define DESCRIPTION Custom-built QMK firmware

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 6

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
