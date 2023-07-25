//The MIT License (MIT)
//
//Copyright (c) 2022 Carl Gessau
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#include "config_common.h"


//Below is full TMK CODE

#define MATRIX_ROWS 16  // keycode bit3-6
#define MATRIX_COLS 8   // keycode bit0-2


/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) || \
    keyboard_report->mods == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) \
)



/* Pin configuration */
#define IBM4704_CLOCK_PORT  PORTD
#define IBM4704_CLOCK_PIN   PIND
#define IBM4704_CLOCK_DDR   DDRD
#define IBM4704_CLOCK_BIT   1
#define IBM4704_DATA_PORT   PORTD
#define IBM4704_DATA_PIN    PIND
#define IBM4704_DATA_DDR    DDRD
#define IBM4704_DATA_BIT    0

/* Pin interrupt on rising edge of clock */
#define IBM4704_INT_INIT()  do { EICRA |= ((1<<ISC11)|(1<<ISC10)); } while (0)
#define IBM4704_INT_ON()    do { EIFR |= (1<<INTF1); EIMSK |= (1<<INT1); } while (0)
#define IBM4704_INT_OFF()   do { EIMSK &= ~(1<<INT1); } while (0)
#define IBM4704_INT_VECT    INT1_vect



