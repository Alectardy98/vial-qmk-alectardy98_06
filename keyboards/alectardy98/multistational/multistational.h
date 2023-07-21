/* Copyright 2023 Alectardy98
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
    k00, k01, k02, k12, k03, k04, k14, k05, k06, k16, k07, k08, \
    k10, k11, k22, k13, k23, k24, k15, k25, k26, k36, k17, k18, \
    k20, k30, k21, k31, k32, k42, k33, k43, k34, k44, k35, k45, k46, k56, k27, k37, k28, k38, k09, k19, k29, k39, k0A, k1A, \
    k40, k50, k41, k51, k52, k62, k53, k63, k54, k64, k55, k65, k66, k76, k47, k57, k48, k58, k49, k59, k69, k2A, k3A, \
    k60, k70, k61, k71, k72, k82, k73, k83, k74, k84, k75, k85, k86, k96, k67, k77, k68, k78, k79, k89, k99, k4A, k5A, \
    k80, k90, k81, k91, k92, kA2, k93, kA3, k94, kA4, k95, kA5, kA6, kB6, k87, k97, k88, k98, kA9, k7A, k6A, k8A, \
    kA0, kB0, kA1, kB1, kB2, kB3, kB4, kB5, kA7, kB7, kA8, kB8, kB9, k9A, kAA, kBA \
) { \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A}, \
    {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A}, \
    {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5A}, \
    {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6A}, \
    {k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7A}, \
    {k80, k81, k82, k83, k84, k85, k86, k87, k88, k89, k8A}, \
    {k90, k91, k92, k93, k94, k95, k96, k97, k98, k99, k9A}, \
    {kA0, kA1, kA2, kA3, kA4, kA5, kA6, kA7, kA8, kA9, kAA}, \
    {kB0, kB1, kB2, kB3, kB4, kB5, kB6, kB7, kB8, kB9, kBA}, \
}

