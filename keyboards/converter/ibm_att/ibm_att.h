/*
Copyright 2019 Markus Fritsche <fritsche.markus@gmail.com>

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

#pragma once

#include "quantum.h"
#include "unimap.h"
#define XXX KC_NO


#define LAYOUT( \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K65,K4E,  K5F,K60,K61,K57, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,        K28,                K5C,K5D,K5E,     \
    K79,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,            K7D,      K52,      K59,K5A,K5B,K58, \
    K78,K7A,                K2C,                        K7E,K7B,  K50,K51,K4F,      K62,K63      \
) { \
    { XXX, XXX, XXX, XXX, K04, K05, K06, K07,   /* 00-07 */ \
      K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, /* 08-0F */ \
    { K10, K11, K12, K13, K14, K15, K16, K17,   /* 10-17 */ \
      K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, /* 18-1F */ \
    { K20, K21, K22, K23, K24, K25, K26, K27,   /* 20-27 */ \
      K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, /* 28-2F */ \
    { K30, K31, XXX, K33, K34, K35, K36, K37,   /* 30-37 */ \
      K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, /* 38-3F */ \
    { K40, K41, K42, K43, K44, K45, K46, K47,   /* 40-47 */ \
      K48, K49, K4A, K4B, K4C, XXX, K4E, K4F }, /* 48-4F */ \
    { K50, K51, K52, K53, K54, K55, K56, K57,   /* 50-57 */ \
      K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, /* 58-5F */ \
    { K60, K61, K62, K63, XXX, K65, XXX, XXX,   /* 60-67 */ \
      XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX }, /* 68-6F */ \
    { XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX,   /* 70-77 */ \
      K78, K79, K7A, K7B, XXX, K7D, K7E, XXX }  /* 78-7F */ \
}


/* Matrix poision for Universal 128-key keyboard
        ,-----------------------------------------------.
        | 68| 69| 6A| 6B| 6C| 6D| 6E| 6F| 70| 71| 72| 73|
,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
| 29|   | 3A| 3B| 3C| 3D| 3E| 3F| 40| 41| 42| 43| 44| 45|     | 46| 47| 48|     | 01| 02| 03|
`---'   `-----------------------------------------------'     `-----------'     `-----------'
,-----------------------------------------------------------. ,-----------. ,---------------.
| 35| 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 2D| 2E| 74| 2A| | 49| 4A| 4B| | 53| 54| 55| 56|
|-----------------------------------------------------------| |-----------| |---------------|
|   2B| 14| 1A| 08| 15| 17| 1C| 18| 0C| 12| 13| 2F| 30|   31| | 4C| 4D| 4E| | 5F| 60| 61| 57|
|-----------------------------------------------------------| `-----------' |---------------|
|    39| 04| 16| 07| 09| 0A| 0B| 0D| 0E| 0F| 33| 34| 32|  28|               | 5C| 5D| 5E| 66|
|-----------------------------------------------------------|     ,---.     |---------------|
|  79| 64| 1D| 1B| 06| 19| 05| 11| 10| 36| 37| 38| 75|    7D|     | 52|     | 59| 5A| 5B| 58|
|-----------------------------------------------------------| ,-----------. |---------------|
| 78| 7B| 7A|  77|              2C|  76|  00| 7E| 7F| 65| 7C| | 50| 51| 4F| |     62| 63| 67|
`-----------------------------------------------------------' `-----------' `---------------'
*/


typedef enum { NONE, PC_XT, PC_AT, PC_TERMINAL, PC_MOUSE } keyboard_kind_t;
#define KEYBOARD_KIND_STR(kind) \
    (kind == PC_XT ? "XT" :   \
     kind == PC_AT ? "AT" :   \
     kind == PC_TERMINAL ? "TERMINAL" :   \
     kind == PC_MOUSE ? "MOUSE" :   \
     "NONE")

extern const uint8_t PROGMEM unimap_cs1[MATRIX_ROWS][MATRIX_COLS];
extern const uint8_t PROGMEM unimap_cs2[MATRIX_ROWS][MATRIX_COLS];
extern const uint8_t PROGMEM unimap_cs3[MATRIX_ROWS][MATRIX_COLS];


