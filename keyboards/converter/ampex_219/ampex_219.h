
#pragma once

#include "quantum.h"

/*
 *   +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+   +---+---+---+---+
 *   |13 |0B |09 |03 |1B |43 |4B |53 |5B |17 |0F |07 |1F |47 |4F |57 |   |67 |6F |27 |2F |
 *   +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+   +---+---+---+---+
 *   +----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+  +---+---+---+---+
 *   |12  |0A |08 |02 |1A |42 |4A |52 |5A |16 |0E |06 |1E |46 |4E |56 |  |66 |6E |26 |2E |
 *   +----------------------------------------------------------------+  +---------------+
 *   |11    |01 |19 |41 |49 |51 |59 |15 |0D |05 |1D |45 |4D |   |55  |   |65 |6D |25 |2D |
 *   +------------------------------------------------------|   |----+   +---------------+
 *   |200|10 |00 |18 |40 |48 |50 |58 |14 |0C |04 |1C |44 |4C    |54  |   |64 |6C |24 |2C |
 *   +---------------------------------------------------------------+   +---------------+
 *   |29 |100  |23 |22 |69 |6A |6B |68 |60 |61 |62 |32 |100  |3A |3B |   |3D |34 |35 |36 |
 *   +---------------------------------------------------------------+   +-----------|   |
 *   |2A |21 |400|63                                 |31 |33 |39 |38 |   |3E     |37 |   |
 *   +---+---+---+-----------------------------------+---+---+---+---+   +-------+-------+
 *
 */

#define LAYOUT( \
    K13, K0B, K09, K03, K1B, K43, K4B, K53, K5B, K17, K0F, K07, K1F, K47, K4F, K57, K67, K6F, K27, K2F, \
    K12, K0A, K08, K02, K1A, K42, K4A, K52, K5A, K16, K0E, K06, K1E, K46, K4E, K56, K66, K6E, K26, K2E, \
    K11, K01, K19, K41, K49, K51, K59, K15, K0D, K05, K1D, K45, K4D, K55, K65, K6D, K25, K2D, \
    K200, K10, K00, K18, K40, K48, K50, K58, K14, K0C, K04, K1C, K44, K4C, K54, K64, K6C, K24, K2C, \
    K29, K100, K23, K22, K69, K6A, K6B, K68, K60, K61, K62, K32, K100X, K3A, K3B, K3D, K34, K35, K36, \
    K2A, K21, K400, K63, K31, K33, K39, K38, K3E, K37) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { KC_NO, K21, K22, K23, K24, K25, K26, K27, KC_NO, K29, K2A, KC_NO, K2C, K2D, K2E, K2F }, \
    { KC_NO, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, KC_NO, K3D, K3E, KC_NO }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E, K6F }, \
    { K100, K200, K400, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}