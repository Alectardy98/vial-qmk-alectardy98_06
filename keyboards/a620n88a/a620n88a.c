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

#include "a620n88a.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
    case KC_COLN:
    	{
    	    const uint8_t mods = get_mods();
    	    if (record->event.pressed) {
		if (mods & MOD_MASK_SHIFT) {
		    add_key(KC_SCLN);
		    send_keyboard_report();
		    del_key(KC_SCLN);
		}
		else {
		    add_mods(MOD_BIT(KC_LSFT));
		    add_key(KC_SCLN);
		    send_keyboard_report();
		    set_mods(mods);
		    del_key(KC_SCLN);
		}
	    }
	    send_keyboard_report();
	    return false;
    	}
    case KMCS_BSLS:
    	{
    	    const uint8_t mods = get_mods();
    	    if (record->event.pressed) {
		if (mods & MOD_MASK_SHIFT) {
		    add_key(KC_LBRC);
		    send_keyboard_report();
		    del_key(KC_LBRC);
		}
		else {
		    add_key(KC_BSLS);
		    send_keyboard_report();
		    del_key(KC_BSLS);
		}
	    }
	    send_keyboard_report();
	    return false;
    	}
    case KMCS_VBAR:
	{
	    const uint8_t mods = get_mods();
	    if (record->event.pressed) {
		if (mods & MOD_MASK_SHIFT) {
		    add_key(KC_RBRC);
		    send_keyboard_report();
		    del_key(KC_RBRC);
		}
		else {
		    add_mods(MOD_BIT(KC_LSFT));
		    add_key(KC_BSLS);
		    send_keyboard_report();
		    set_mods(mods);
		    del_key(KC_BSLS);
		}
	    }
	    send_keyboard_report();
	    return false;
	}
    case KMCS_LPAR:
	{
	    const uint8_t mods = get_mods();
	    if (record->event.pressed) {
		if (mods & MOD_MASK_SHIFT) {
		    del_mods(MOD_MASK_SHIFT);
		    send_keyboard_report();
		    add_key(KC_LBRC);
		    send_keyboard_report();
		    set_mods(mods);
		    del_key(KC_LBRC);
		} else {
		    add_key(KC_9);
		    add_mods(MOD_BIT(KC_LSFT));
		    send_keyboard_report();
		    del_key(KC_9);
		    set_mods(mods);
		}
	    }
	    send_keyboard_report();
	    return false;
	}
    case KMCS_RPAR:
	{
	    const uint8_t mods = get_mods();
	    if (record->event.pressed) {
		if (mods & MOD_MASK_SHIFT) {
		    del_mods(MOD_MASK_SHIFT);
		    send_keyboard_report();
		    add_key(KC_RBRC);
		    send_keyboard_report();
		    set_mods(mods);
		    del_key(KC_RBRC);
		} else {
		    add_key(KC_0);
		    add_mods(MOD_BIT(KC_LSFT));
		    send_keyboard_report();
		    del_key(KC_0);
		    set_mods(mods);
		}
	    }
	    send_keyboard_report();
	    return false;
	}
    }
    return true;
}
