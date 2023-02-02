/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 35
#define DRIVER_2_LED_TOTAL 34
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

/* Encoder Configuration */
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { A10 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 30


#    define MOUSEKEY_INERTIA
#    define MOUSEKEY_FRICTION 20
#    define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#    define COMBO_COUNT 7
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define AUTO_MOUSE_DEFAULT_LAYER WIN_BASE
#    define TAPPING_TOGGLE 2
#    define ONESHOT_TAP_TOGGLE 2