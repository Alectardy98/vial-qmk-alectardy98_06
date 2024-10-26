
#pragma once

#include "quantum.h"

/*
 *
 * Original keyboard; then called K1 for B2x series.
 *
 * +---+---+                                                             +-----+---+-----+
 * |0C |11 |                                                             |02   |01 |03   |
 * +---+---+  +----+----+----+  +----+----+----+----+  +----+----+----+  +-----+---+-----+
 * |05 |13 |  |15  |16  |17  |  |18  |19  |1A  |1C  |  |1D  |1E  |1F  |  |0E   |0B |0F   |
 * +---+---+  +----+----+----+  +----+----+----+----+  +----+----+----+  +-----+---+-----+
 * +---+---+  +-------------------------------------------------------+  +---------------+
 * |07 |12 |  |5E |31 |32 |33 |34 |35 |36 |37 |38 |39 |30 |2D |2B |08 |  |5C |7C |21 |1B |
 * +-------+  +-------------------------------------------------------+  +---------------+
 * |00 |7F |  |09 |71 |77 |65 |72 |74 |79 |75 |69 |6F |70 |06 |5B |5D |  |7B |7D |41 |42 |
 * +-------+  +-------------------------------------------------------+  +---------------+
 * |43 |44 |  |45   |61 |73 |64 |66 |67 |68 |6A |6B |6C |3B |27 |0A   |  |60 |46 |47 |0D |
 * +-------+  +-------------------------------------------------------+  +-----------+   |
 * |04 |14 |  |48     |7A |78 |63 |76 |62 |6E |6D |2C |2E |2F |49     |  |4A     |4B |   |
 * +-------+  +-------+---------------------------------------+-------+  +-------+---+---+
 *                       |4C  |20                     |4D  |
 *                       +----+-----------------------+----+
 *
 */
#define LAYOUT_k1( \
    K0C, K11, K02, K01, K03, \
    K05, K13, K15, K16, K17, K18, K19, K1A, K1C, K1D, K1E, K1F, K0E, K0B, K0F, \
    K07, K12, K5E, K31, K32, K33, K34, K35, K36, K37, K38, K39, K30, K2D, K2B, K08, K5C, K7C, K21, K1B, \
    K00, K7F, K09, K71, K77, K65, K72, K74, K79, K75, K69, K6F, K70, K06, K5B, K5D, K7B, K7D, K41, K42, \
    K43, K44, K45, K61, K73, K64, K66, K67, K68, K6A, K6B, K6C, K3B, K27, K0A, K60, K46, K47, K0D, \
    K04, K14, K48, K7A, K78, K63, K76, K62, K6E, K6D, K2C, K2E, K2F, K49, K4A, K4B, \
    K4C, K20, K4D) { \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { KC_NO, K11, K12, K13, K14, K15, K16, K17 }, \
    { K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K27 }, \
    { KC_NO, KC_NO, KC_NO, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K38, K39, KC_NO, K3B, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, K41, K42, K43, K44, K45, K46, K47 }, \
    { K48, K49, K4A, K4B, K4C, K4D, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, K5B, K5C, K5D, K5E, KC_NO }, \
    { K60, K61, K62, K63, K64, K65, K66, K67 }, \
    { K68, K69, K6A, K6B, K6C, K6D, K6E, K6F }, \
    { K70, K71, K72, K73, K74, K75, K76, K77 }, \
    { K78, K79, K7A, K7B, K7C, K7D, KC_NO, K7F } \
}
