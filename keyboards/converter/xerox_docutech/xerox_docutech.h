#pragma once

#include "quantum.h"

#define LAYOUT( \
            K63,K64,K65,K66,        K67,K68,K69,K6A,        K6B,K6C,                  \
K54,K55,    K04,K05,K06,K07,K08,K09,K0A,K0B,K0C,K0D,K0E,K0F,K10,K11,    K40,K41,K42,K43,  \
K56,K57,    K12,K13,K14,K15,K16,K17,K18,K19,K1A,K1B,K1C,K1D,K1E,K1F,    K44,K45,K46,K47,  \
K58,K59,    K6E,K6D,K21,K22,K23,K24,K25,K26,K27,K28,K29,K2A,K2B,K2C,        K48,K49,K4A,K4B,  \
K5B,K5C,    K2D,    K2F,K30,K31,K32,K33,K34,K35,K36,K37,K38,    K39,        K4D,K4E,K4F,  \
K5D,K5E,    K3A,    K3B,            K3D,            K3E,        K3F,    K50,    K52,K53   \
) { \
/*0*/ { KC_NO, KC_NO, KC_NO, KC_NO, K04,   K05,   K06,   K07 }, \
/*1*/ { K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F }, \
/*2*/ { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17 }, \
/*3*/ { K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F }, \
/*4*/ { KC_NO, K21,   K22,   K23,   K24,   K25,   K26,   K27 }, \
/*5*/ { K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, K2F }, \
/*6*/ { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37 }, \
/*7*/ { K38,   K39,   K3A,   K3B,   KC_NO, K3D,   K3E,   K3F }, \
/*8*/ { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47 }, \
/*9*/ { K48,   K49,   K4A,   K4B,   KC_NO, K4D,   K4E,   K4F }, \
/*10*/ { K50,   KC_NO, K52,   K53,   K54,   K55,   K56,   K57 }, \
/*11*/ { K58,   K59,   KC_NO, K5B,   K5C,   K5D,   K5E,   KC_NO }, \
/*12*/ { KC_NO, KC_NO, KC_NO, K63,   K64,   K65,   K66,   K67 }, \
/*13*/ { K68,   K69,   K6A,   K6B,   K6C,   K6D,   K6E, KC_NO }, \
/*14*/ { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
/*16*/ { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}/*       0      1      2      3      4      5      6      7   */

#define LAYOUT_xerox_docutech LAYOUT
