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
    k48, k88, kc8, k58, kd8, k98, \
    k00, k01, k07, k17, k27, k47, k57, k77, k97, ka7, kb1, kc7, kc1, kd7, kd1, ke7, ke1, kf7, kf1, \
    k02, k03, k10, k13, k23, k21, k31, k41, k51, k61, k71, k81, k91, k93, ka1, ka3, kb3, kb0, kc3, kd3, ke3, kf3, kf0, \
    k04, k14, k12, k20, k32, k30, k33, k43, k53, k63, k73, k83, k80, k90, k92, ka0, ka2, kb2, kc0, kd0, ke0, kf2, kf4, \
    k05, k15, k22, k34, k44, k42, k40, k50, k60, k70, k72, k74, k82, k84, k94, ka4, kb4, kc2, kd2, ke2, ke4, kf5, \
    k06, k16, k24, k35, k45, k56, k55, k54, k52, k62, k64, k65, k75, k76, k85, k95, ka5, kb5, kc4, kd4, kd5, ke5, kf6, \
    k26, k25, k36, k46, k66, k86, k96, ka6, kb6, kc5, kc6, kd6, ke6 \
) { \
    {k00, k01, k02, k03, k04, k05, k06, k07, XXX}, \
    {k10, XXX, k12, k13, k14, k15, k16, k17, XXX}, \
    {k20, k21, k22, k23, k24, k25, k26, k27, XXX}, \
    {k30, k31, k32, k33, k34, k35, k36, XXX, XXX}, \
    {k40, k41, k42, k43, k44, k45, k46, k47, k48}, \
    {k50, k51, k52, k53, k54, k55, k56, k57, k58}, \
    {k60, k61, k62, k63, k64, k65, k66, XXX, XXX}, \
    {k70, k71, k72, k73, k74, k75, k76, k77, XXX}, \
    {k80, k81, k82, k83, k84, k85, k86, XXX, k88}, \
    {k90, k91, k92, k93, k94, k95, k96, k97, k98}, \
    {ka0, ka1, ka2, ka3, ka4, ka5, ka6, ka7, XXX}, \
    {kb0, kb1, kb2, kb3, kb4, kb5, kb6, XXX, XXX}, \
    {kc0, kc1, kc2, kc3, kc4, kc5, kc6, kc7, kc8}, \
    {kd0, kd1, kd2, kd3, kd4, kd5, kd6, kd7, kd8}, \
    {ke0, ke1, ke2, ke3, ke4, ke5, ke6, ke7, XXX}, \
    {kf0, kf1, kf2, kf3, kf4, kf5, kf6, kf7, XXX}, \
}


