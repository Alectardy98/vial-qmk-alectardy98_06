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

#include "config_common.h"

#define LED_PIN_ON_STATE 1
#define LED_NUM_LOCK_PIN GP13
#define LED_CAPS_LOCK_PIN GP28
#define LED_SCROLL_LOCK_PIN GP11
#define LED_KANA_PIN GP17  //Required for zenith beeper code to work

#define AUDIO_PIN GP16
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_MIN         65.0f       // Default 65
#define AUDIO_CLICKY_FREQ_DEFAULT     280.0f      // Default 440
#define AUDIO_CLICKY_FREQ_MAX         1500.0f     // Default 1500
#define AUDIO_CLICKY_FREQ_FACTOR    0.0000000000000001f      // Default 1.18921
#define AUDIO_CLICKY_FREQ_RANDOMNESS    0.0f      // Default 0.05
#define AUDIO_CLICKY_DELAY_DURATION     0         // Default 1

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
