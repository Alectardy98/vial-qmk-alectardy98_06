/* Copyright 2022 Alectardy98
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

// readability
#define XXX KC_NO

#define LAYOUT( \
	K00, K10,      K01, K11, K02, K12, K03, K13, K04, K14, K25, K05, K15, K06, K16, K07, K17, K08, K18, K19,  \
	K20, K30,      K21, K31, K22, K32, K23, K33, K24, K34, K35, K45,  K26, K36, K37, K27, K38, K28, K29, K09, \
    K50, K40,      K51, K41, K52, K42, K53, K43, K54, K44, K65, K55, K56, K46, K47,  K48, K58, K49, K39,  \
    K60, K70,      K61, K71, K62, K72, K63, K73, K64, K74, K84, K75, K85, K66, K67, K57, K78, K68, K69, K59,  \
    K90, K80,      K91, K81, K82, K92, K83, K76, K86, K77, K87, K88, K79, K89, K99  \
) { \
	{ K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
	{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
	{ K20, K21, K22, K23, K24, K25, K26, K27, K28, K29 }, \
	{ K30, K31, K32, K33, K34, K35, K36, K37, K38, K39 }, \
	{ K40, K41, K42, K43, K44, K45, K46, K47, K48, K49 }, \
	{ K50, K51, K52, K53, K54, K55, K56, K57, K58, K59 }, \
	{ K60, K61, K62, K63, K64, K65, K66, K67, K68, K69 }, \
	{ K70, K71, K72, K73, K74, K75, K76, K77, K78, K79 }, \
	{ K80, K81, K82, K83, K84, K85, K86, K87, K88, K89 }, \
	{ K90, K91, K92, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K99 }  \
}
