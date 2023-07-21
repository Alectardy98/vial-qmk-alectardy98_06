//The MIT License (MIT)
//
//Copyright (c) 2022 Carl Gessau
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 16
#define MATRIX_COLS 8

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32U2__)
#   define NEWS_KBD_RX_VECT        USART1_RX_vect
#   define NEWS_KBD_RX_DATA        UDR1
#   define NEWS_KBD_RX_BAUD        9600
#   define NEWS_KBD_RX_UBBR        ((F_CPU/(16UL*NEWS_KBD_RX_BAUD))-1)
#   define NEWS_KBD_RX_INIT()      do { \
        UBRR1L = (uint8_t) NEWS_KBD_RX_UBBR; \
        UBRR1H = (uint8_t) (NEWS_KBD_RX_UBBR>>8); \
        UCSR1B |= (1<<RXCIE1) | (1<<RXEN1); \
    } while(0)
#else
#   error "USART configuration is needed."
#endif
