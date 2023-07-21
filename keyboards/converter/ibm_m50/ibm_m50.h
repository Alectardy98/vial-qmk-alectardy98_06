#pragma once

#include "quantum.h"




/*

  * ,-----------. ,-----------. ,---------------.
  * | 1C| 1D| 24| | 2D| 5D| 3C| | 43| 44| 4C| 71|
  * |-----------| |-----------| |---------------|
  * | 1A| 22| 21| | 2A| 5A| 3A| | 41| 4B| 49| 4A|
  * |-----------| |-----------| |---------------|
  * | 16| 1E| 26| | 25| 09| 3D| | 3E| 46| 45| 52|
  * |-----------| |-----------| |---------------|
  * | 12| 05| 06| | 2E| 01| 36| | 55| 0A| 54| 4E|
  * |-----------| |-----------| |---------------|
  * | 14| 11| 04| | 2C| 66| 35| | 5B| 0B| 83| 33|
  * `-----------' `-----------' `---------------'
  */


#define LAYOUT( \
K1C,K1D,K24,   K2D,K5D,K3C,   K43,K44,K4C,K71, \
K1A,K22,K21,   K2A,K5A,K3A,   K41,K4B,K49,K4A, \
K16,K1E,K26,   K25,K09,K3D,   K3E,K46,K45,K52, \
K12,K05,K06,   K2E,K01,K36,   K55,K0A,K54,K4E, \
K14,K11,K04,   K2C,K66,K35,   K5B,K0B,K83,K33  \
) { \
{ KC_NO,   K01, KC_NO, KC_NO,   K04,   K05, K06, KC_NO, KC_NO,   K09,   K0A,   K0B, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   K11,   K12, KC_NO,   K14, KC_NO,   K16, KC_NO, KC_NO, KC_NO,   K1A, KC_NO,   K1C,   K1D,   K1E, KC_NO }, \
{ KC_NO,   K21,   K22, KC_NO,   K24,   K25, K26, KC_NO, KC_NO, KC_NO,   K2A, KC_NO,   K2C,   K2D,   K2E, KC_NO, KC_NO, KC_NO, KC_NO,   K33, KC_NO,   K35,   K36, KC_NO, KC_NO, KC_NO,   K3A, KC_NO,   K3C,   K3D,   K3E, KC_NO }, \
{ KC_NO,   K41, KC_NO,   K43,   K44,   K45, K46, KC_NO, KC_NO,   K49,   K4A,   K4B,   K4C, KC_NO,   K4E, KC_NO, KC_NO, KC_NO,   K52, KC_NO,   K54,   K55, KC_NO, KC_NO, KC_NO, KC_NO,   K5A,   K5B, KC_NO,   K5D, KC_NO, KC_NO }, \
{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K66, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   K71, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
{ KC_NO, KC_NO, KC_NO, K83,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
} //0      1      2      3      4      5     6     7      8      9      10     11     12     13     14     15     16      17   18      19     20     21     22     23     24     25     26     27     28     29     30     31



