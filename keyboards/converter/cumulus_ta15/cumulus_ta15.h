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
    k00, k01, k04, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, k0G, k77, k78, k79, k7A, k7B,             \
    k10, k11, k14, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k67, k68, k87, k88, k89, k8A, k8B,   \
    k20, k21, k24, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k6B, k6A, k7G, k7F, k7E, k7C, k7D,   \
    k30, k52, k31, k34, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F, k3G, k69, k8G, k8F, k8E, k8C, k8D,   \
    k40, k53, k41, k44, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k43, k4E, k4F, k4G, k80, k86, k84, k74,        \
    k60, k64, k55, k66, k45, k6C, k6E, k6F, k6G, k70, k76                                                      \
) { \
    {k00, k01, XXX, XXX, k04, XXX, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, k0G}, \
    {k10, k11, XXX, XXX, k14, XXX, k16, k17, k18, k19, k1A, k1B, k1C, k1D, XXX, k1F, k1G}, \
    {k20, k21, XXX, XXX, k24, XXX, k26, k27, k28, k29, k2A, k2B, k2C, k2D, XXX, k2F, k2G}, \
    {k30, k31, XXX, XXX, k34, XXX, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F, k3G}, \
    {k40, k41, XXX, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C, k4D, k4E, k4F, k4G}, \
    {XXX, XXX, k52, k53, XXX, k55, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX}, \
    {k60, XXX, XXX, XXX, k64, XXX, k66, k67, k68, k69, k6A, k6B, k6C, XXX, k6E, k6F, k6G}, \
    {k70, XXX, XXX, XXX, k74, XXX, k76, k77, k78, k79, k7A, k7B, k7C, k7D, k7E, k7F, k7G}, \
    {k80, XXX, XXX, XXX, k84, XXX, k86, k87, k88, k89, k8A, k8B, k8C, k8D, k8E, k8F, k8G}, \
}

