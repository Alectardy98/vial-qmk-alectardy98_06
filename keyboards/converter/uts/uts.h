
#pragma once

#include "quantum.h"

/*
 *
 * +-----+-----+ +-----+---+---+---+---+----+----+----+----+----+----+----+-----+ +---+---+---+---+
 * |74   |73   | |05   |61 |60 |65 |5D |02  |0A  |3A  |0B  |43  |44  |45  |4E   | |6B |6C |6D |71 |
 * +-----------+ +-+--------------------------------------------------------+---+ +---------------+
 * |6F   |6E   |   |4A |15 |14 |2E |39 |01 |2B |46 |27 |38 |3F |1E |11 |0F  |     |66 |67 |68 |70 |
 * +-----------+   +--------------------------------------------------------+---+ +---------------+
 * |6A   |69   |   |22   |21 |23 |24 |25 |29 |26 |28 |2F |32 |20 |4D |4C |5C |  | |62 |63 |64 |5E |
 * +-----------+ +-+---------------------------------------------------------|  | +-----------|   |
 * |1F         | |82* |81*|16 |17 |18 |1C |19 |1B |1A |1D |31 |13 |12 |56 |4B   | |5F     |75 |   |
 * +-----------+ +---------------------------------------------------------+----+ +-------+---+---+
 * |0D   |10   | |80*   |5A |06 |07 |08 |09 |50 |51 |52 |04 |0C |55 |80*   |
 * +-----------+ +---------+-----------------------------------+-----------+
 * |2C         |           |2A                                 |
 * +-----------+           +-----------------------------------+
 *
 * FCTN and SHIFT are handled specially and cannot generally be remapped.
 */

#define LAYOUT( \
    K74, K73,  K05, K61, K60, K65, K5D, K02, K0A, K3A, K0B, K43, K44, K45, K4E,            K6B, K6C, K6D, K71, \
    K6F, K6E,  K4A, K15, K14, K2E, K39, K01, K2B, K46, K27, K38, K3F, K1E, K11, K0F,       K66, K67, K68, K70, \
    K6A, K69,  K22, K21, K23, K24, K25, K29, K26, K28, K2F, K32, K20, K4D, K4C, K5C,       K62, K63, K64, K5E, \
    K1F,       K82, K81, K16, K17, K18, K1C, K19, K1B, K1A, K1D, K31, K13, K12, K56, K4B,  K5F, K75, \
    K0D, K10,  K80, K5A, K06, K07, K08, K09, K50, K51, K52, K04, K0C, K55, K80X, \
    K2C,       K2A) { \
    { KC_NO, K01, K02, KC_NO, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KC_NO, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, KC_NO, K2E, K2F }, \
    { KC_NO, K31, K32, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K38, K39, K3A, KC_NO, KC_NO, KC_NO, KC_NO, K3F }, \
    { KC_NO, KC_NO, KC_NO, K43, K44, K45, K46, KC_NO, KC_NO, KC_NO, K4A, K4B, K4C, K4D, K4E, KC_NO }, \
    { K50, K51, K52, KC_NO, KC_NO, K55, K56, KC_NO, KC_NO, KC_NO, K5A, KC_NO, K5C, K5D, K5E, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E, K6F }, \
    { K70, K71, KC_NO, K73, K74, K75, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K80, K81, K82 } \
}