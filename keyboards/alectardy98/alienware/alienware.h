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
    k1f, k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k60, k61, k62, k63, k1c, k2f, k0c, \
    k3f, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k70, k71, k72, k64, k65, k66, k6c, k7c, k0d, k1d, \
    k4f, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k67, k68, k73, k74, k75, k4d, k5d, k6d, k2d, \
    k5f, k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k69, k6a, k7d, k0e, k1e, \
    k6f, k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k6b, k76, k78, k2e, k3e, k4e, k3d, \
    k7f, k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k77, k79, k7a, k7b, k5e, k6e \
) \
{ \
    {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, XXX}, \
    {k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d, k2e, k2f}, \
    {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d, k3e, k3f}, \
    {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, XXX, k4d, k4e, k4f},  \
    {k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, XXX, XXX, XXX, k5d, k5e, k5f},  \
    {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c, k6d, k6e, k6f},  \
    {k70, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, k7c, k7d, XXX, k7f},  \
}
