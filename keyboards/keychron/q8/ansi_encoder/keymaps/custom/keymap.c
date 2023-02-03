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
    _8,
    _9
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


//const uint16_t PROGMEM apostrophe_combo[] = {KC_DOT,KC_COMM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_P,KC_LBRC, COMBO_END};
const uint16_t PROGMEM righbracket_combo[] = {KC_LBRC,KC_RBRC, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_RBRC,KC_BSPC, COMBO_END};
const uint16_t PROGMEM enterleft_combo[] = {MT(MOD_LSFT,KC_F),KC_V, COMBO_END};
const uint16_t PROGMEM enterright_combo[] = {KC_N,MT(MOD_LSFT,KC_J), COMBO_END};
const uint16_t PROGMEM backspaceleft_combo[] = {KC_Q,KC_W, COMBO_END};
const uint16_t PROGMEM pageup_combo[] = {KC_LBRC,CTL_T(KC_SEMICOLON), COMBO_END};
const uint16_t PROGMEM pagedown_combo[] = {KC_RBRC,KC_QUOT, COMBO_END};
const uint16_t PROGMEM home_combo[] = {KC_DOT,CTL_T(KC_SEMICOLON), COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_QUOT,LSFT_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM backspaceright_combo[] = {KC_DOT,KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
//    COMBO(apostrophe_combo, LSFT(KC_7)),
    COMBO(pipe_combo, LSFT(KC_INT3)),
    COMBO(righbracket_combo, KC_BSLS),
    COMBO(delete_combo, KC_DEL),
    COMBO(enterleft_combo, KC_ENT),
    COMBO(enterright_combo, KC_ENT),
    COMBO(backspaceleft_combo, KC_BACKSPACE),
    COMBO(pageup_combo, KC_PGUP),
    COMBO(pagedown_combo, KC_PGDN),
    COMBO(home_combo, KC_HOME),
    COMBO(end_combo, KC_END),
    COMBO(backspaceright_combo, KC_BACKSPACE)
}; 

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BACKSPACE,          KC_HOME,
        LCTL_T(KC_GRV), LT(_FN3,KC_A),       KC_S,     LT(_9,KC_D),    MT(MOD_LSFT,KC_F),    KC_G,              KC_H,    MT(MOD_LSFT,KC_J),    LT(_9,KC_K),    LT(_FN3,KC_L),     CTL_T(KC_SEMICOLON),  KC_QUOT,  KC_ENT,         LALT_T(KC_END),
        MT(MOD_LSFT,KC_BSPC),           LCTL_T(KC_Z),     KC_X,    KC_C,    KC_V,    KC_B,     S(KC_INT1),    KC_N,    KC_M,    KC_COMM,  KC_DOT,   LSFT_T(KC_SLSH),  MT(MOD_RSFT,KC_INT1), KC_UP,
        TG(_7), KC_LGUI,  KC_LALT,           LT(_6,KC_SPC),           LT(_7,KC_SPC), LT(_7,KC_ENT),         LT(_6,KC_BSPC),            KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(_FN2), MO(_FN3),         KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN2] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN3] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, _______,  KC_HOME,  KC_UP, KC_END, _______, _______,  _______, KC_UP, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, KC_LEFT,  KC_DOWN, KC_RGHT, _______,           _______, KC_LEFT, KC_RGHT, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, KC_DOWN, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

     [_6] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        C(S(KC_TAB)), C(KC_TAB),    KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_NUM_LOCK,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  KC_PGUP,  _______,  _______,          _______,
        _______,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_PLUS, _______,  KC_PGDN,          _______,
        _______,           C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), KC_F12,   _______, KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,  _______, _______,
        _______, KC_LALT,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_7] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  KC_MS_WH_UP, KC_MS_BTN2,  KC_MS_UP, KC_MS_BTN1,   KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,_______, _______,  _______,  _______,  _______,          _______,
        _______, _______,KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,           KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,   _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, KC_MS_WH_UP, KC_MS_WH_DOWN,  _______, KC_MS_WH_UP, KC_MS_WH_DOWN,   _______,  _______,  _______, _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_8] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),
    
    [_9] = LAYOUT_ansi_69(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        
        KC_ESC,  S(KC_1),     S(KC_2),     S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),     S(KC_7),    S(KC_8),    S(KC_9),  KC_MINUS,    S(KC_MINS),  S(KC_EQL),   KC_BSPC,         _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  KC_EQL,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = {ENCODER_CCW_CW(_______, _______)},
    [_6]   = {ENCODER_CCW_CW(_______, _______)},
    [_7]   = {ENCODER_CCW_CW(_______, _______)},
    [_8]   = {ENCODER_CCW_CW(_______, _______)},
    [_9]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
