/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "timer.h"
#include "matrix.h"
#include "avr/timer_avr.h"
#include <avr/wdt.h>
#include "suspend.h"
#include "news.h"
#include "lufa.h"

//static uint8_t matrix[MATRIX_ROWS];
//
//inline uint8_t matrix_rows(void)
//{return MATRIX_ROWS;}
//
//inline uint8_t matrix_cols(void)
//{return MATRIX_COLS;}

//void matrix_init(void)
void matrix_init_custom(void)
{
	//#ifdef DEBUG
	debug_enable = true;
	debug_keyboard = true;
	//#endif
    serial_init();

	//for(uint8_t x = 0; x < MATRIX_ROWS; x++)
	//{current_matrix[x] = 0;}
	
	//matrix_init_quantum();
}

//__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
//
//__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
//
//__attribute__((weak)) void matrix_init_user(void) {}
//
//__attribute__((weak)) void matrix_scan_user(void) {}

//uint8_t matrix_scan_custom(void)
bool matrix_scan_custom(matrix_row_t current_matrix[])
{
	uint8_t keycode = 0;
	uint8_t matrix_changed = 0;
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t col_pos = 0;

	keycode = serial_recv();
	row = (keycode & 0x78) >> 3;
	col = keycode & 0x7;
	col_pos = 1 << col;

	if(!(keycode & 0x7F))
	{return matrix_changed;}

	if(!(keycode & 0x80))
	{
		// exclusive or: if the same > false; if not the same > true
		matrix_changed = (current_matrix[row] ^ col_pos) >> col;
		current_matrix[row] |= col_pos;
	}
	else
	{
		matrix_changed = ((current_matrix[row] & col_pos) ^ 0) >> col;
		current_matrix[row] &= ~col_pos;
	}

	//matrix_scan_quantum();

	//return matrix_changed;
	return 1;
}

//inline bool matrix_is_on(uint8_t row, uint8_t col)
//{return 1;}
//
//inline matrix_row_t matrix_get_row(uint8_t row)
//{return matrix[row];}
//
//void matrix_print(void)
//{
//	print("\nr/c 01234567\n");
//	for (uint8_t row = 0; row < matrix_rows(); row++) {
//		xprintf("%02X: %08b\n", row, bitrev(matrix_get_row(row)));
//	}
//}
