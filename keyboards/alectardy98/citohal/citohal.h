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
    k00, k06, k16, k07, k17, k08, k18, k09, k19, k0a, \
    k10, k20, k01, k11, k02, k03, k13, k04, k14, k05, k15, k26, k36, k27, k37, k28, k38, k29, k1a, k2a, \
    k30, k21, k31, k22, k32, k23, k33, k24, k34, k25, k35, k46, k47, k57, k48, k39, k49, k3a, k4a, \
    k40, k50, k41, k51, k42, k52, k43, k53, k44, k45, k55, k56, k66, k58, k59, k69, k5a, k6a, \
    k60, k70, k61, k71, k62, k63, k73, k54, k64, k65, k75, k76, k67, k77, k68, k79, k7a, \
    k74 \
) { \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a}, \
    {k10, k11, XXX, k13, k14, k15, k16, k17, k18, k19, k1a}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a}, \
    {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a}, \
    {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a}, \
    {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a}, \
    {k70, k71, XXX, k73, k74, k75, k76, k77, XXX, k79, k7a}, \
}

