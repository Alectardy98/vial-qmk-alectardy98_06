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
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K74,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K28,      K4C,K65,K4E,  K5F,K60,K61,K57, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,K31,                        K5C,K5D,K5E,     \
    K79,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,K75,K7D,              K52,      K59,K5A,K5B,K58, \
    K78,K7A,K77,        K2C,            K76,K00,K7E,K7B,          K50,K51,K4F,  K62,K63          \
) { \
    {   K00, KC_NO, KC_NO, KC_NO,   K04,   K05,   K06,   K07,   /* 00-07 */ \
        K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F }, /* 08-0F */ \
    {   K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   /* 10-17 */ \
        K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F }, /* 18-1F */ \
    {   K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   /* 20-27 */ \
        K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F }, /* 28-2F */ \
    {   K30,   K31, KC_NO,   K33,   K34,   K35,   K36,   K37,   /* 30-37 */ \
        K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F }, /* 38-3F */ \
    {   K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   /* 40-47 */ \
        K48,   K49,   K4A,   K4B,   K4C, KC_NO,   K4E,   K4F }, /* 48-4F */ \
    {   K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   /* 50-57 */ \
        K58,   K59,   K5A,   K5B,   K5C,   K5D,   K5E,   K5F }, /* 58-5F */ \
    {   K60,   K61,   K62,   K63, KC_NO,   K65, KC_NO, KC_NO,   /* 60-67 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, /* 68-6F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO,   K74,   K75,   K76,   K77,   /* 70-77 */ \
        K78,   K79,   K7A,   K7B, KC_NO,   K7D,   K7E, KC_NO }  /* 78-7F */ \
}





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


