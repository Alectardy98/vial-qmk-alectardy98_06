
#pragma once

#include "quantum.h"

/*
 *   +-----+-----+-----+-----+       +-----+-----+-----+-----+
 *   |10   |11   |12   |13   |       |14   |15   |16   |17   |
 *   +-----+-----+-----+-----+       +-----+-----+-----+-----+   +-----+
 *                                                               |7E   |
 *   +---+---+---+---+---+---+---+---+---+---+---+---+---+---+   +-----+
 *   |21 |22 |23 |24 |25 |26 |27 |28 |29 |60 |72 |61 |66 |30 |   |6E   |
 * +-+------------------------------------------------------++   +-----+
 * |20 |31 |32 |33 |34 |35 |36 |37 |38 |39 |65 |73 |79 |78  |    |7D   |
 * ++----------------------------------------------------   |    +-----+
 *  |05 |41 |42 |43 |44 |45 |46 |47 |48 |49 |70 |74 |67 |   |    |6D   |
 *  +-------------------------------------------------------+    +-----|
 *  |04   |50 |51 |52 |53 |54 |55 |56 |57 |6F |59 |04   |02 |    |6A   |
 *  +-----+---+-------------------------------+---+-----+---+    +-----+
 *            |77                             |
 *            +-------------------------------+
 *
 * Note: both shift keys send the same code.
 */

#define LAYOUT( \
    K10, K11, K12, K13,                     K14, K15, K16, K17, \
                                                                                K7E, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K60, K72, K61, K66, K30,       K6E, \
    K20, K31, K32, K33, K34, K35, K36, K37, K38, K39, K65, K73, K79, K78,       K7D, \
    K05, K41, K42, K43, K44, K45, K46, K47, K48, K49, K70, K74, K67,            K6D, \
    K04, K50, K51, K52, K53, K54, K55, K56, K57, K6F, K59, K04X, K02,           K6A, \
              K77 \
) { \
    { KC_NO, KC_NO, K02, KC_NO, K04, K05, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, K41, K42, K43, K44, K45, K46, K47, K48, K49, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, KC_NO, K59, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K60, K61, KC_NO, KC_NO, KC_NO, K65, K66, K67, KC_NO, KC_NO, K6A, KC_NO, KC_NO, K6D, K6E, K6F }, \
    { K70, KC_NO, K72, K73, K74, KC_NO, KC_NO, K77, K78, K79, KC_NO, KC_NO, KC_NO, K7D, K7E, KC_NO }, \
}
