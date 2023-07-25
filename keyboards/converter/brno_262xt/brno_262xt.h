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


/* Universal 128-key keyboard layout(8x16)
        ,-----------------------------------------------.
        |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
|Esc|   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|     |PrS|ScL|Pau|     |VDn|VUp|Mut|
`---'   `-----------------------------------------------'     `-----------'     `-----------'
,-----------------------------------------------------------. ,-----------. ,---------------.
|  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
|-----------------------------------------------------------| |-----------| |---------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
|-----------------------------------------------------------| `-----------' |---------------|
|CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Entr|               |  4|  5|  6|KP,|
|-----------------------------------------------------------|     ,---.     |---------------|
|Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
|-----------------------------------------------------------| ,-----------. |---------------|
|Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|KP=|
`-----------------------------------------------------------' `-----------' `---------------'
App:         Windows Menu key
Gui:         Windows key, Mac ⌘ key or Meta key
VDn Vup Mut: Volume control
< #:         ISO keys(in UK legend)
KP=:         Keypad = for Mac
KP,:         Brazilian Keypad Comma
JPY:         Japanese Yen(￥)
RO:          Japanese ろ(Ro) or Brazilian /(Slash)
MHEN:        Japanese 無変換(Non Conversion) or Korean Hanja
HENK:        Japanese 変換(Conversion) or Korean Hangul/English
KANA:        Japanese かな(Hiragana/Katakana)
https://en.wikipedia.org/wiki/Keyboard_layout#Japanese
https://en.wikipedia.org/wiki/Keyboard_layout#Hangul_.28for_Korean.29
*/
#define LAYOUT( \
   K29, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K69, K6A, K55, K71, K72, K58, K00, \
   K35, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K2D, K2E, K2A, K53, K47, K5F, K60, K61, K56, \
   K6F, K2B, K14, K1A, K08, K15, K17, K1C, K18, K0C, K12, K13, K2F, K30, K70, K5C, K5D, K5E, K57, \
   K78, K39, K04, K16, K07, K09, K0A, K0B, K0D, K0E, K0F, K33, K34, K28, K59, K5A, K5B, \
   K7A, K79, K1D, K1B, K06, K19, K05, K11, K10, K36, K37, K38, K31, K7D, K62, K63, \
   K2C   \
) { \
/*0*/    { K00, XXX, XXX, XXX, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F },  \
/*1*/    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F },  \
/*2*/    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F },  \
/*3*/    { K30, K31, XXX, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F },  \
/*4*/    { K40, K41, K42, K43, XXX, XXX, XXX, K47, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX },  \
/*5*/    { XXX, XXX, XXX, K53, XXX, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E, K5F },  \
/*6*/    { K60, K61, K62, K63, XXX, XXX, XXX, XXX, XXX, K69, K6A, XXX, XXX, XXX, XXX, K6F },  \
/*7*/    { K70, K71, K72, XXX, XXX, XXX, XXX, XXX, K78, K79, K7A, XXX, XXX, K7D, XXX, XXX }   \
}/*         0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15*/


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


