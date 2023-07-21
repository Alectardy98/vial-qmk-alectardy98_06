/* Copyright 2020 Keymacs s.r.o. (https://keymacs.com/)
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

#define KC_MAC_BRIU KC_BRK
#define KC_MAC_BRID KC_SLCK

enum keymacs_keycodes { 
    KMCS_BSLS = SAFE_RANGE,
    KMCS_VBAR,
    KMCS_LPAR,
    KMCS_RPAR,
    USER_SAFE_RANGE
};

#define KMCS_X(_ui) \
{ \
    if (record->event.pressed) { \
	send_unicode_hex_string(_ui); \
    } \
    break; \
}

#define KMCS_XP(_ui,_uj) \
{ \
    if (record->event.pressed) { \
	if (get_mods() & MOD_MASK_SHIFT) { \
	    send_unicode_hex_string(_uj); \
	} \
	else { \
	    send_unicode_hex_string(_ui); \
	} \
    } \
    break; \
}

// PCB: Keymacs A620N-88-REV-A

#define LAYOUT( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K20, K21, K22, K23, K24, K25, K26, K27, K29, \
  K30, K32, K33, K34, K35, K36, K37, K38, K40, K41, K42, K43, K44, K45, K46, K47, K49, \
  K50, K52, K53, K54, K55, K56, K57, K58, K60, K61, K62, K63, K64, K66, K67, K69, \
  K70, K71, K72, K73, K74, K75, K76, K77, K78, K80, K81, K82, K84, K85, K87, K88, K89, \
  K90, K91, K92, K93, K94, K95, K96, K97, K98, K99 \
) { \
    {K00, K01, K02, K03, K04, K05, K06, K07, K08, K09}, \
    {K10, K11, K12, K13, K14, K15, K16, K17, K18, KC_NO}, \
    {K20, K21, K22, K23, K24, K25, K26, K27, KC_NO, K29}, \
    {K30, KC_NO, K32, K33, K34, K35, K36, K37, K38, KC_NO}, \
    {K40, K41, K42, K43, K44, K45, K46, K47, KC_NO, K49}, \
    {K50, KC_NO, K52, K53, K54, K55, K56, K57, K58, KC_NO}, \
    {K60, K61, K62, K63, K64, KC_NO, K66, K67, KC_NO, K69}, \
    {K70, K71, K72, K73, K74, K75, K76, K77, K78, KC_NO}, \
    {K80, K81, K82, KC_NO, K84, K85, KC_NO, K87, K88, K89}, \
    {K90, K91, K92, K93, K94, K95, K96, K97, K98, K99} \
}
