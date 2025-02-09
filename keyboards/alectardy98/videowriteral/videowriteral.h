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
    k18,   \
    k00, k01, k11, k02, k03, k13, k04, k05, k15, k06, k07, k08, \
    k17, \
    k10, k20, k21, k31, k12, k22, k23, k14, k24, k25, k35, k16, k26, k27, k28, \
    k30, k40, k41, k32, k42, k33, k43, k34, k44, k45, k55, k36, k37, k47, k48, \
    k50, k60, k51, k52, k62, k53, k63, k54, k65, k75, k46, k56, k68, \
    k70, k80, k61, k72, k82, k73, k83, k64, k74, k85, k66, k76, k67, k77, k78, \
    k71, k81, k84, k86, k87 \
) { \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, XXX}, \
    {k40, k41, k42, k43, k44, k45, k46, k47, k48}, \
    {k50, k51, k52, k53, k54, k55, k56, XXX, XXX}, \
    {k60, k61, k62, k63, k64, k65, k66, k67, k68}, \
    {k70, k71, k72, k73, k74, k75, k76, XXX, k78}, \
    {k80, k81, k82, k83, k84, k85, k86, k87, XXX}, \
}

