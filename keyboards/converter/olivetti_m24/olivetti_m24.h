
#pragma once

#include "quantum.h"

/*
 * Keyboard 1
 *
 * +---+---+ +---+---+---+---+---+---+---+---+---+---+---+---+---+------+-------+-------+
 * |3B |3C | |01 |02 |03 |04 |05 |06 |07 |08 |09 |0A |0B |0C |0D |0E    |45     |46     |
 * +-------+ +--------------------------------------------------------------------------+
 * |3D |3E | |0F   |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |1A |1B  |1C |47 |48 |49 |4A |
 * +-------+ +------------------------------------------------------|   |---------------+
 * |3F |40 | |1D    |1E |1F |20 |21 |22 |23 |24 |25 |26 |27 |28 |29 |   |4B |4C |4D |4E |
 * +-------+ +----------------------------------------------------------------------|   |
 * |41 |42 | |2A  |2B |2C |2D |2E |2F |30 |31 |32 |33 |34 |35 |36   |37 |4F |50 |51 |   |
 * +-------+ +----------------------------------------------------------------------|   |
 * |43 |44 | |38     |39                                   |3A      |52     |53     |   |
 * +---+---+ +-------+-------------------------------------+--------+-------+-------+---+
 * 
 */

#define LAYOUT_xt( \
    K3B, K3C, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K45, K46, \
    K3D, K3E, K0F, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K47, K48, K49, K4A, \
    K3F, K40, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K4B, K4C, K4D, K4E, \
    K41, K42, K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K4F, K50, K51, \
    K43, K44, K38, K39, K3A, K52, K53) { \
    { KC_NO, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}

/*
 * Keyboard 2
 *
 *     +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 *     |3B |3C |3D |3E |3F |40 |41 |42 |43 |44 |60 |61 |62 |63 |64 |65 |66 |67 |
 *     +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+-------+---+---+---+---+---+---+---+
 * |01 |02 |03 |04 |05 |06 |07 |08 |09 |0A |0B |0C |0D |0E     |5C |5D |46 |5F |37 |4A |4E |
 * +---------------------------------------------------------------+---+---+---------------+
 * |38   |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |1A |1B |0F   |   |45 |   |47 |48 |49 |55 |
 * +-----------------------------------------------------------|   +---+   +---------------+
 *    |1D |1E |1F |20 |21 |22 |23 |24 |25 |26 |27 |28 |29 |1C  |           |4B |4C |4D |56 |
 * +--+---------------------------------------------------|    |   +---+   +---------------+
 * |2A  |2B |2C |2D |2E |2F |30 |31 |32 |33 |34 |35 |36  |     |   |5B |   |4F |50 |51 |57 |
 * +----+-+-------------------------------------+---+----+-----+---+---+---+-----------|   |
 *        |3A   |39                             |              |58 |59 |5A |52 |54 |53 |   |
 *        +-----+-------------------------------+              +---+---+---+---+---+---+---+
 *
 */

#define LAYOUT_m24_2( \
    K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K44, K60, K61, K62, K63, K64, K65, K66, K67, \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K5C, K5D, K46, K5F, K37, K4A, K4E, \
    K38, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K0F, K45, K47, K48, K49, K55, \
    K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K1C, K4B, K4C, K4D, K56, \
    K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K5B, K4F, K50, K51, K57, \
    K3A, K39, K58, K59, K5A, K52, K54, K53) { \
    { KC_NO, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, KC_NO, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}