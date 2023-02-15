/* Copyright 2021 sagiteya (https://github.com/sagiteya/)
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

#    define MOUSEKEY_INERTIA
#    define MOUSEKEY_MAX_SPEED 32
#    define MOUSEKEY_TIME_TO_MAX 32
#    define MOUSEKEY_FRICTION 24


#    define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#    define TAPPING_TOGGLE 2
#    define ONESHOT_TAP_TOGGLE 2

#    define TAPPING_TERM 185
#    define TAPPING_TERM_PER_KEY

#    define COMBO_ONLY_FROM_LAYER 0
#    define COMBO_TERM 80

#    define COMBO_VARIABLE_LEN

#    ifdef DEBOUNCE
#    undef DEBOUNCE
#    endif

#    define DEBOUNCE 8

#    define LEADER_TIMEOUT 300
#    define LEADER_PER_KEY_TIMING

#    define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD


