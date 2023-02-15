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

#include QMK_KEYBOARD_H
#include "sagiteya.h"

// clang-format off

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _GBF:
                rgb_matrix_set_color(i, 10, 10, 10);
                break;
            case _NUM:
                rgb_matrix_set_color(i, 20, 1, 1);
                break;
            case _NAV:
                rgb_matrix_set_color(i, 1, 20, 20);
                break;  
            case _MISC:
                rgb_matrix_set_color(i, 2, 20, 2);
                break;    
            case _BL:
                rgb_matrix_set_color(i, RGB_OFF);
                break;    
            case _FN:
                rgb_matrix_set_color(i, RGB_PURPLE);
                break;
            default:
                break;
        }
    }
    return false;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      [_BL] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row__0_______________,
_______________Ansi65__Row__1_______________,
_______________Ansi65__Row__2_______________,
_______________Ansi65__Row__3_______________,
_______________Ansi65__Row__4_______________

),
     [_NUM] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row__NUM0____________,
_______________Ansi65__Row__NUM1____________,
_______________Ansi65__Row__NUM2____________,
_______________Ansi65__Row__NUM3____________,
_______________Ansi65__Row__NUM4____________

),

     [_NAV] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row__NAV0____________,
_______________Ansi65__Row__NAV1____________,
_______________Ansi65__Row__NAV2____________,
_______________Ansi65__Row__NAV3____________,
_______________Ansi65__Row__NAV4____________

),
     [_GBF] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row__GBF0____________,
_______________Ansi65__Row__GBF1____________,
_______________Ansi65__Row__GBF2____________,
_______________Ansi65__Row__GBF3____________,
_______________Ansi65__Row__GBF4____________

),
     [_MISC] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row__MSC0____________,
_______________Ansi65__Row__MSC1____________,
_______________Ansi65__Row__MSC2____________,
_______________Ansi65__Row__MSC3____________,
_______________Ansi65__Row__MSC4____________


),
     [_FN] = LAYOUT_ansi_68_wrapper(
_______________Ansi65__Row___FN0____________,
_______________Ansi65__Row___FN1____________,
_______________Ansi65__Row___FN2____________,
_______________Ansi65__Row___FN3____________,
_______________Ansi65__Row___FN4____________


),

     };