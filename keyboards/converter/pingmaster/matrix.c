/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2023 Alec Tardy <tardyalec@gmail.com>

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

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "action.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "ibm4704.h"
#include "matrix.h"
#include "pingmaster.h"







static void matrix_make(uint8_t code);
static void matrix_break(uint8_t code);
void matrix_print(void) {return;}



/*
 * Matrix Array usage:
 * IBM 4704 scan codes are assigned into 128(16x8)-cell matrix.
 *
 *    8bit wide
 *   +---------+
 *  0|         |
 *  :|   XX    | 00-7F
 *  f|         |
 *   +---------+
 *
 * Exceptions:
 */
static uint8_t matrix[MATRIX_ROWS];

// scan code bits  7654 3210
// R:row/C:column  -RRR RCCC
#define ROW(code)      ((code>>3)&0x0f)
#define COL(code)      (code&0x07)

//ibm code
__attribute__ ((weak))
void matrix_init_user(void) {
}

void matrix_clear(void)
{
    for (uint8_t i=0; i < MATRIX_ROWS; i++) matrix[i] = 0x00;
}






static void enable_break(void)
{
    print("Enable break: ");
    while (ibm4704_send(0xFC)) { _delay_ms(10); }
    // valid scancode: 00-79h
    for (uint8_t code = 0; code < 0x7F; code++) {
        while (ibm4704_send(0x80|code)) _delay_ms(10);
        _delay_ms(5);   // wait for response
        // No response(FF) when ok, FD when out of bound
        xprintf("s%02X:r%02X ", code, ibm4704_recv());
    }
    while (ibm4704_send(0xFF)) { _delay_ms(10); } // End
    print("End\n");
}


void matrix_setup(void)
{
    ibm4704_init();
}

void matrix_init(void)
{
    debug_enable = true;

    print("IBM 4704 converter\n");
    matrix_clear();
    _delay_ms(2000);    // wait for keyboard starting up
    uint8_t keyboard_id = ibm4704_recv();
    xprintf("Keyboard ID: %02X\n", keyboard_id);
    enable_break();
}

/*
 * IBM 4704 Scan Code
 */
uint8_t matrix_scan(void)
{
    uint8_t code = ibm4704_recv();
    if (code==0xFF) {
        // Not receivd
        return 0;
    } else if ((code&0x7F) >= 0x7C) {
        // 0xFF-FC and 0x7F-7C is not scancode
        xprintf("Error: %02X\n", code);
        matrix_clear();
        return 0;
    } else if (code&0x80) {
        dprintf("%02X\n", code);
        matrix_make(code);
    } else {
        dprintf("%02X\n", code);
        matrix_break(code);
    }
    return 1;
}

inline
uint8_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

inline
static void matrix_make(uint8_t code)
{
    matrix[ROW(code)] |= 1<<COL(code);
}

inline
static void matrix_break(uint8_t code)
{
    matrix[ROW(code)] &= ~(1<<COL(code));
}

