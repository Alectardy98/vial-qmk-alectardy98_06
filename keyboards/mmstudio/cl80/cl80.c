/* Copyright 2019 Fate
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
#include "cl80.h"
//共负极
/*
void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(B0);
  setPinOutput(B3);
  setPinOutput(E6);
 // setPinOutput(D1);
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinHigh(B0);
    } else {
        writePinLow(B0);
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(B3);
    } else {
        writePinLow(B3);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinHigh(E6);
    } else {
        writePinLow(E6);
    }

}
*/
//共正极

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.       //Setting status LEDs pins to output and -5V (off)

  // Set our LED pins as output
  setPinOutput(B0);
  setPinOutput(B3);
  setPinOutput(E6);
}

bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) {
        writePin(B0, !led_state.num_lock);
        writePin(B3, !led_state.caps_lock);
        writePin(E6, !led_state.scroll_lock);
    }
    return true;
}
