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
  MAC_FN1,
  WIN_FN1,
  FN2,
  FN3
};

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

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
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

const uint16_t PROGMEM test_combo1[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {SFT_T(KC_F), KC_D, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {SFT_T(KC_J), KC_L, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM test_combo8[] = {KC_BSLS, KC_DELETE, COMBO_END};
const uint16_t PROGMEM test_combo9[] = {SFT_T(KC_J), KC_K, COMBO_END};
const uint16_t PROGMEM test_combo10[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM test_combo11[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM test_combo12[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM test_combo13[] = {KC_W, SFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM test_combo14[] = {KC_S, SFT_T(KC_F), COMBO_END};
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
    COMBO(test_combo14, LCTL(KC_M))
};

//void pointing_device_init_user(void) {
//     set_auto_mouse_layer(WIN_BASE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
//     set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
//}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS, RGB_MOD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC, KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     SFT_T(KC_F),     KC_G,     KC_H,     SFT_T(KC_J),     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_END,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MT(MOD_RSFT,KC_INT1),  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI, KC_LALT,                               LT(WIN_BASE,KC_SPC),                       KC_RALT,MO(FN2),KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     KC_TRNS,  MACRO00,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     C(S(KC_TAB)),  C(KC_TAB),  KC_MS_BTN2,  KC_MS_UP,  KC_MS_BTN1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  C(KC_BSPC),  KC_PGUP,
     KC_TRNS,  KC_TRNS,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_PGDN,
     KC_TRNS,  C(KC_Z),  C(KC_X),  KC_MS_WH_DOWN,  KC_MS_WH_UP,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[MAC_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LNPD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[FN2] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
[FN3] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

