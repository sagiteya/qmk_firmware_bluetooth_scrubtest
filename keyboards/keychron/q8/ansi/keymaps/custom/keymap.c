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

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3,
    _6,
    _7,
    _8
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_F):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case SFT_T(KC_J):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_SEMICOLON):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_Z):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_LEFT):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}


const uint16_t PROGMEM test_combo1[] = {KC_K, KC_L, COMBO_END}; // K + L = Single Quote
const uint16_t PROGMEM test_combo2[] = {KC_D, KC_V, COMBO_END}; // D + V = Enter
const uint16_t PROGMEM test_combo3[] = {SFT_T(KC_F), KC_D, COMBO_END};  // F + D = Delete
const uint16_t PROGMEM test_combo4[] = {SFT_T(KC_J), KC_L, COMBO_END};  // J + L = Double Quote
const uint16_t PROGMEM test_combo5[] = {KC_U, KC_I, COMBO_END};  // U + I = Underscore
const uint16_t PROGMEM test_combo6[] = {KC_I, KC_O, COMBO_END}; // I + O = Minus
const uint16_t PROGMEM test_combo7[] = {KC_S, KC_D, COMBO_END}; // S + D = Backspace
const uint16_t PROGMEM test_combo8[] = {KC_BSLS, KC_DELETE, COMBO_END}; // Backslash + Del = PrintScreen
const uint16_t PROGMEM test_combo9[] = {SFT_T(KC_J), KC_K, COMBO_END}; // K + J = Pipe
const uint16_t PROGMEM test_combo10[] = {CTL_T(KC_Z), KC_X, COMBO_END}; // K + L = ctrl a
const uint16_t PROGMEM test_combo11[] = {KC_X, KC_C, COMBO_END}; // K + L = ctrl x
const uint16_t PROGMEM test_combo12[] = {KC_C, KC_V, COMBO_END}; // K + L = ctrl v
const uint16_t PROGMEM test_combo13[] = {KC_W, SFT_T(KC_F), COMBO_END}; // W + F = Grave (lang swap) DOES NOT WORK
const uint16_t PROGMEM test_combo14[] = {KC_S, SFT_T(KC_F), COMBO_END}; // K + L = Ctrl M
const uint16_t PROGMEM test_combo15[] = {KC_3, KC_4, COMBO_END}; // K + L = alt left 
const uint16_t PROGMEM test_combo16[] = {KC_F3, KC_F4, COMBO_END}; // K + L = alt left DOES NOT WORK
const uint16_t PROGMEM test_combo17[] = {KC_4, KC_2, COMBO_END}; // K + L = alt right
const uint16_t PROGMEM test_combo18[] = {KC_F4, KC_F2, COMBO_END}; // K + L = alt right
const uint16_t PROGMEM test_combo19[] = {KC_8, KC_9, COMBO_END}; // K + L = left (
const uint16_t PROGMEM test_combo20[] = {KC_9, KC_0, COMBO_END}; // K + L = right )
const uint16_t PROGMEM test_combo21[] = {KC_BSPC, KC_RBRC, COMBO_END}; // K + L = Delete
const uint16_t PROGMEM test_combo22[] = {KC_W, KC_Q, COMBO_END}; // K + L = Home
const uint16_t PROGMEM test_combo23[] = {KC_Q, KC_S, COMBO_END}; // K + L = End
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, LSFT(KC_7)),
    COMBO(test_combo2, KC_ENTER), // keycodes with modifiers are possible too!
    COMBO(test_combo3, KC_DELETE),
    COMBO(test_combo4, LSFT(KC_2)),
    COMBO(test_combo5, LSFT(KC_INT1)),
    COMBO(test_combo6, KC_MINUS),
    COMBO(test_combo7, KC_BACKSPACE),
    COMBO(test_combo8, KC_PRINT_SCREEN),
    COMBO(test_combo9, LSFT(KC_INT3)),
    COMBO(test_combo10, LCTL(KC_A)),
    COMBO(test_combo11, LCTL(KC_X)),
    COMBO(test_combo12, LCTL(KC_V)),
    COMBO(test_combo13, KC_GRV),
    COMBO(test_combo14, LCTL(KC_M)),
    COMBO(test_combo15, LALT(KC_LEFT)),
    COMBO(test_combo16, LALT(KC_LEFT)),
    COMBO(test_combo17, LALT(KC_RIGHT)),
    COMBO(test_combo18, LALT(KC_RIGHT)),
    COMBO(test_combo19, LSFT(KC_8)),
    COMBO(test_combo20, LSFT(KC_9)),
    COMBO(test_combo21, KC_DELETE),
    COMBO(test_combo22, KC_HOME),
    COMBO(test_combo23, KC_END)
};



#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        LCTL_T(KC_GRV), LT(_6,KC_A),     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    LT(_7,KC_L),     KC_SCLN,  KC_QUOT,  LT(_8,KC_ENT),           KC_HOME,
        KC_LSFT,           LCTL_T(KC_Z),     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,           LT(_6,KC_SPC),           LT(_6,KC_SPC), LT(_FN4,KC_ENT),         KC_BSPC,            KC_RCMD,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(_FN2), MO(_FN3),         KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN2] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN3] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_6] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_7] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_8] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};
