
#pragma once

#include "quantum.h"

// readability
#define XXX KC_NO

#define LAYOUT( \
    K07, K17, K27, K47, K67, K77, K87, K97, KA7, K36, K34, K33, K32, K31, K30, K02, K12, K22, K92, \
    K65, K75, K85, K95, KA5, K53, K54, K52, K51, K50, K05, K15, K25, K35, KA0, KA2, K90, K80, K01, \
    K44, K62, K24, K04, K74, K94, K84, K63, KA4, K61, K60, K37, K14, K57, K11, K21, KA1, K81, \
    K06, K66, K26, K56, K16, K76, K96, K86, KA6, K45, K43, K42, K41, K40, K00, K10, K20, K70, \
    K03, K13, K23, K83, K93, KA3, K72, K71)  {  \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K40, K41, K42, K43, K44, K45, XXX, K47 }, \
    { K50, K51, K52, K53, K54, XXX, K56, K57 }, \
    { K60, K61, K62, K63, XXX, K65, K66, K67 }, \
    { K70, K71, K72, XXX, K74, K75, K76, K77 }, \
    { K80, K81, XXX, K83, K84, K85, K86, K87 }, \
    { K90, XXX, K92, K93, K94, K95, K96, K97 }, \
    { KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

