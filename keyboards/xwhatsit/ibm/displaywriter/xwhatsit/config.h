/*
Copyright 2020-2023 Purdea Andrei

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define DEF_SERIAL_NUMBER "purdea.ro:qmk_xwhatsit"

#ifndef SERIAL_NUMBER
#define SERIAL_NUMBER DEF_SERIAL_NUMBER
#endif

#define CONTROLLER_IS_XWHATSIT_DISPLAYWRITER

// By default we set up for support of xwhatsit's solenoid driver board.
// Comment out HAPTIC_ENABLE_PIN if you don't have an enable pin:
#define HAPTIC_ENABLE_PIN B7
// Change this if you are using a different pin for the solenoid:
#define SOLENOID_PIN B6
// If you are not using a solenoid then comment out the above, and also in rules.mk, remove HAPTIC_ENABLE
// We disable haptic feedbeck during USB low power conditions:
#define HAPTIC_OFF_IN_LOW_POWER 1
// You can also tune the following for your solenoid:
#define SOLENOID_DEFAULT_DWELL 20
#define SOLENOID_MIN_DWELL 4
//#define SOLENOID_MAX_DWELL 100
#define NO_HAPTIC_MOD

// If the lock lights are not used, then please don't define the below pins,
// or leave them set as unused pins:

// The following definitions match the lock lights as used by the original
// xwhatsit firmware, but enabling all three of these is not compatible with
// standard solenoid support, because B6 and B7 pins are already in use:
//#define LED_NUM_LOCK_PIN B5
//#define LED_CAPS_LOCK_PIN B6
//#define LED_SCROLL_LOCK_PIN B4
// Since solenoid support is enabled by default, the above lock light pin
// assignments are disabled by default.
// Instead the more common Num Lock and Caps Lock are assigned the following
// way by default, and this can be used in combination with the solenoid:
#define LED_NUM_LOCK_PIN B4
#define LED_CAPS_LOCK_PIN B5

#define LED_SCROLL_LOCK_PIN B3
// ^ Note: The B3 pin on normal classical xwhatsit/wcass controllers is a corner-pin of the atmega,
// which is not used, so it's easy to solder to for custom modifications.
// In the 33-pin version of the wcass board, pins B3, B4, B5 are all brought as extra pins to the
// row of pins connecting the sense matrix, making it easy to connect up the locklight leds.

// Uncomment below if the leds are on when the pin is driving zero:
//#define LED_NUM_LOCK_ACTIVE_LOW
//#define LED_CAPS_LOCK_ACTIVE_LOW
//#define LED_SCROLL_LOCK_ACTIVE_LOW
