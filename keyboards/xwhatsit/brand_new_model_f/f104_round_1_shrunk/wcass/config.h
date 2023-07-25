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

#define CONTROLLER_IS_WCASS_MODEL_F

// Here we set up solenoid support, but only for custom wiring
// To make the solenoid driver work with this configuration, you must take the trigger signal
// from pin B7, which is normally the enable pin, and you can take the enable signal from pin B3,
// or you can hardwire it to Vcc.
// Comment out HAPTIC_ENABLE_PIN if you don't have an enable pin:
#define HAPTIC_ENABLE_PIN B3

// ^ Note: The B3 pin on normal classical xwhatsit/wcass controllers is a corner-pin of the atmega,
// which is not used, so it's easy to solder to for custom modifications.
// In the 33-pin version of the wcass board, this pin may be bought out to a header.

// Change this if you are using a different pin for the solenoid:
#define SOLENOID_PIN B7
// If you are not using a solenoid then comment out the above, and also in rules.mk, remove "HAPTIC_ENABLE += SOLENOID"
// You can also tune the following for your solenoid:
// We disable haptic feedbeck during USB low power conditions:
#define HAPTIC_OFF_IN_LOW_POWER 1
// You can also tune the following for your solenoid:
#define SOLENOID_DEFAULT_DWELL 20
#define SOLENOID_MIN_DWELL 4
//#define SOLENOID_MAX_DWELL 100
#define NO_HAPTIC_MOD

// If the lock lights are not used, then please don't define the below pins,
// or leave them set as unused pins:

// The following definitions match how the locklights have been soldered on the "shrunk" f104 round1 keyboards:
#define LED_NUM_LOCK_PIN B5
#define LED_CAPS_LOCK_PIN B4
#define LED_SCROLL_LOCK_PIN B6

// Uncomment below if the leds are on when the pin is driving zero:
//#define LED_NUM_LOCK_ACTIVE_LOW
//#define LED_CAPS_LOCK_ACTIVE_LOW
//#define LED_SCROLL_LOCK_ACTIVE_LOW
