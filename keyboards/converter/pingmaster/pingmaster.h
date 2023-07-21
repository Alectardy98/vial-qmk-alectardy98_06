/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2023 Alec Tardy <tardyalec@gmail.com>

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

// readability
#define XXX KC_NO

#define LAYOUT( \
K00, K17, K01, K02, K03, K04, K05, K06, K07, K10, K11, K12, K13, K14, K15, K16,   K84, K85, K86,   K83, K81, K82, K92, \
K20, K21, K22, K23, K24, K25, K26, K27, K30, K31, K32, K33, K34, K35,      K36,   KA4, KA5, KA6,   KA0, KA1, KA2, KB2, \
K40, K41, K42, K43, K44, K45, K46, K47, K50, K51, K52, K53, K54, K55,      K56,   KC4, KC5, KC6,   KC0, KC1, KC2, KD3, \
K60, K62, K63, K64, K65, K66, K67, K70, K71, K72, K73, K74, K75,           K76,   KE4, KE5, KE6,   KE0, KE1, KE2, KF3, \
K61, K87, K77,                K80,                K97, K90,                K57,   KE7, KC7, KA7,   KE3, KC3, KA3, K96  \
) { \
{ K00, K01, K02, K03, K04, K05, K06, K07 }, \
{ K10, K11, K12, K13, K14, K15, K16, K17 }, \
{ K20, K21, K22, K23, K24, K25, K26, K27 }, \
{ K30, K31, K32, K33, K34, K35, K36, XXX }, \
{ K40, K41, K42, K43, K44, K45, K46, K47 }, \
{ K50, K51, K52, K53, K54, K55, K56, K57 }, \
{ K60, K61, K62, K63, K64, K65, K66, K67 }, \
{ K70, K71, K72, K73, K74, K75, K76, K77 }, \
{ K80, K81, K82, K83, K84, K85, K86, K87 }, \
{ K90, XXX, K92, XXX, XXX, XXX, K96, K97 }, \
{ KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7 }, \
{ XXX, XXX, KB2, XXX, XXX, XXX, XXX, XXX }, \
{ KC0, KC1, KC2, KC3, KC4, KC5, KC6, KC7 }, \
{ XXX, XXX, XXX, KD3, XXX, XXX, XXX, XXX }, \
{ KE0, KE1, KE2, KE3, KE4, KE5, KE6, KE7 }, \
{ XXX, XXX, XXX, KF3, XXX, XXX, XXX, XXX }  \
}

#define LAYOUT_pingmaster LAYOUT



