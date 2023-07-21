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
	K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K66, K60, K75, \
    K10, K11, K21, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K6A, K76, K71, K61, K64, \
    K20, K31, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K77, K72, K69, K62, K65, \
    K30, K41, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K78, K73, K68, \
    K40, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K79, K74, K67, K63, K70, \
    K50, K51, K52, K53, K54, K57, K58, K59, K5A, K7A, \
    K55, K56 \
) { \
	{K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A}, \
	{K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A}, \
	{K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A}, \
	{K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A}, \
	{K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A}, \
	{K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A}, \
	{K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A}, \
	{K70, K71, K72, K73, K74, K75, K76, K77, K78, K79, K7A}  \
}
