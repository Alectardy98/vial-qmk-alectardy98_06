/* Copyright 2021 djvs
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define ____ KC_NO

#define LAYOUT( \
K000, K001, KA01, K002, KA02, K003, KA03, K004, KA04, K005, KA05, K006, KA06, K007, KA07, K008, KA09, \
K100, KA00, K101, K901, K102, K902, K103, K803, K104, K904, K105, K905, K106, K906, K806, K107, K907, K108, KA08, K109, K909, \
K200, K900, K201, K801, K202, K802, K203, K703, K204, K804, K205, K805, K206, K306, K706, K207, K807, K208, K908, K209, K809, \
K300, K800, K301, K701, K302, K702, K303, K603, K304, K704, K305, K705, K406, K308, K808, K708, K309, \
K400, K700, K401, K601, K402, K602, K403, K503, K404, K604, K405, K605, K307, K707, K408, K608, K509, \
K500, K600, K501, K502, K504, K505, K506, K606, K407, K507, K607, K709, K508, K409 \
) \
{ \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, ____ }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309 }, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408, K409 }, \
    { K500, K501, K502, K503, K504, K505, K506, K507, K508, K509 }, \
    { K600, K601, K602, K603, K604, K605, K606, K607, K608, ____ }, \
    { K700, K701, K702, K703, K704, K705, K706, K707, K708, K709 }, \
    { K800, K801, K802, K803, K804, K805, K806, K807, K808, K809 }, \
    { K900, K901, K902, ____, K904, K905, K906, K907, K908, K909 }, \
    { KA00, KA01, KA02, KA03, KA04, KA05, KA06, KA07, KA08, KA09 }  \
}

