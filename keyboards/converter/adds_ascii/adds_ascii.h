
#pragma once

#include "quantum.h"

/*
 *
 * +---+ +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+ +---+---+---+---+
 * |1D | |23 |24 |25 |26 |28 |29 |2A |2B |3A |3C |3E |3F |40 |5E |5F |61 | |01 |62 |63 |0C |
 * +---+ +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+ +---+---+---+---+
 * +---+    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+  +---+---+---+---+
 * |1E |    |1B |31 |32 |33 |34 |35 |36 |37 |38 |39 |30 |2D |3D |60 |08 |  |0A |15 |06 |1A |
 * +---+  +-+-----------------------------------------------------------+  +---------------+
 * |1F |  |09     |51 |57 |45 |52 |54 |59 |55 |49 |4F |50 |5B |5D |   |    |07 |0B |0E |0F |
 * +---+ ++-------------------------------------------------------|   |    +---------------+
 * |21 | |02 |03   |41 |53 |44 |46 |47 |48 |4A |4B |4C |3B |27 |0D    |    |10 |11 |12 |13 |
 * +---+ +------------------------------------------------------------+--+ +---------------+
 * |22 | |04 |05     |5A |58 |43 |56 |42 |4E |4D |2C |2E |2F |05     |5C | |14 |16 |17 |1C |
 * +---+ +---+-------+-+-----------------------------------+-+-------+---+ +-----------|   |
 *                     |20                                 |               |18     |19 |   |
 *                     +-----------------------------------+               +-------+---+---+
 *
 * Break codes:
 * +---+ +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+ +---+---+---+---+
 * |   | |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   | |   |   |   |   |
 * +---+ +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+ +---+---+---+---+
 * +---+    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+  +---+---+---+---+
 * |   |    |64 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |  |   |   |   |   |
 * +---+  +-+-----------------------------------------------------------+  +---------------+
 * |   |  |       |   |   |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |
 * +---+ ++-------------------------------------------------------|   |    +---------------+
 * |   | |65 |     |   |   |   |   |   |   |   |   |   |   |   |      |    |   |   |   |   |
 * +---+ +------------------------------------------------------------+--+ +---------------+
 * |   | |66 |67     |   |   |   |   |   |   |   |   |   |   |67     |   | |   |   |   |   |
 * +---+ +---+-------+-+-----------------------------------+-+-------+---+ +-----------|   |
 *                     |                                   |               |       |   |   |
 *                     +-----------------------------------+               +-------+---+---+
 */

#define LAYOUT( \
    K1D, K23, K24, K25, K26, K28, K29, K2A, K2B, K3A, K3C, K3E, K3F, K40, K5E, K5F, K61, K01, K62, K63, K0C, \
    K1E, K1B, K31, K32, K33, K34, K35, K36, K37, K38, K39, K30, K2D, K3D, K60, K08,      K0A, K15, K06, K1A, \
    K1F, K09, K51, K57, K45, K52, K54, K59, K55, K49, K4F, K50, K5B, K5D,                K07, K0B, K0E, K0F, \
    K21, K02, K03, K41, K53, K44, K46, K47, K48, K4A, K4B, K4C, K3B, K27, K0D,           K10, K11, K12, K13, \
    K22, K04, K05, K5A, K58, K43, K56, K42, K4E, K4D, K2C, K2E, K2F, K05X, K5C,          K14, K16, K17, K1C, \
                                  K20,                                                   K18,      K19) { \
    { KC_NO, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, \
    { K60, K61, K62, K63, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}