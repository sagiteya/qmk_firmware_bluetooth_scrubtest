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
  FN3,
  FN4,
  FN5,
  FN6
};

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
  GRABURL,
  REFRESH,
  BOOKMARK1,
  BOOKMARK2,
  BOOKMARK3,
  BOOKMARK4,
  BOOKMARK5,
  BOOKMARK6,
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
    case GRABURL:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_LCTL("x") SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6));
      } else {

      }
      break;
    case REFRESH:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_LCTL("V") SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK3:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK4:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK5:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK6:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

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
        case CTL_T(KC_Z):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_LEFT):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_UP):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case CTL_T(KC_DOWN):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case SFT_T(KC_LEFT):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case SFT_T(KC_RIGHT):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        //case SFT_T(KC_RIGHT):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
          //  return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

const uint16_t PROGMEM test_combo1[] = {SFT_T(KC_F), SFT_T(KC_J), COMBO_END}; // F + J = Single Quote
const uint16_t PROGMEM test_combo2[] = {KC_D, KC_C, COMBO_END}; // D + C = Enter
const uint16_t PROGMEM test_combo3[] = {SFT_T(KC_F), KC_V, COMBO_END};  // D + S = Delete
const uint16_t PROGMEM test_combo4[] = {KC_M, KC_COMM, COMBO_END};  // J + L = Double Quote
const uint16_t PROGMEM test_combo5[] = {KC_B, KC_H, COMBO_END};  // I + J = Underscore
const uint16_t PROGMEM test_combo6[] = {KC_O,SFT_T(KC_J), COMBO_END}; // O + J = Minus
const uint16_t PROGMEM test_combo7[] = {KC_Q, KC_W, COMBO_END}; // q + w = Backspace
const uint16_t PROGMEM test_combo8[] = {KC_LBRC, KC_BSLS, COMBO_END}; // Backslash + Del = PrintScreen
const uint16_t PROGMEM test_combo9[] = {KC_K, SFT_T(KC_J), COMBO_END}; // K + J = Pipe
const uint16_t PROGMEM test_combo10[] = {LT(FN5,KC_L), KC_K, COMBO_END}; // F + D = Left
const uint16_t PROGMEM test_combo11[] = {KC_X, KC_C, COMBO_END}; // X + C = Tab
const uint16_t PROGMEM test_combo12[] = {KC_X, KC_V, COMBO_END}; // X + V = Shift Tab
const uint16_t PROGMEM test_combo13[] = {KC_W, SFT_T(KC_F), COMBO_END}; // W + F = Grave (lang swap)
const uint16_t PROGMEM test_combo14[] = {KC_S, SFT_T(KC_F), COMBO_END}; // S + F = Ctrl M
const uint16_t PROGMEM test_combo15[] = {KC_3, KC_4, COMBO_END}; // 3 + 4 = alt left 
const uint16_t PROGMEM test_combo16[] = {KC_F3, KC_F4, COMBO_END}; // F3 + F4 = alt left DOES NOT WORK
const uint16_t PROGMEM test_combo17[] = {KC_4, KC_3, COMBO_END}; // 4 + 2 = alt right
const uint16_t PROGMEM test_combo18[] = {KC_F4, KC_F3, COMBO_END}; // F4 + F2 = alt right
const uint16_t PROGMEM test_combo19[] = {KC_9, KC_8, COMBO_END}; // 8 + 9 = left (
const uint16_t PROGMEM test_combo20[] = {KC_0, KC_9, COMBO_END}; // 9 + 0 = right )
const uint16_t PROGMEM test_combo21[] = {SFT_T(KC_J), KC_N, COMBO_END}; // Back + Lbracket(JP) = Delete
const uint16_t PROGMEM test_combo22[] = {KC_R, KC_Q, COMBO_END}; // R + Q = Home
const uint16_t PROGMEM test_combo23[] = {KC_T, KC_W, COMBO_END}; // Q + R = End
const uint16_t PROGMEM test_combo24[] = {KC_RBRC, KC_P, COMBO_END};  // D + F = Right
const uint16_t PROGMEM test_combo25[] = {KC_RBRC, KC_BSLS, COMBO_END};  // D + F = Right
const uint16_t PROGMEM test_combo26[] = {CTL_T(KC_SCLN), LT(FN5,KC_L), COMBO_END};  // D + F = Right
const uint16_t PROGMEM test_combo27[] = {CTL_T(KC_SCLN), KC_QUOT, COMBO_END};  // D + F = Right
const uint16_t PROGMEM test_combo28[] = {KC_COMM, KC_DOT, COMBO_END};  // D + F = Right
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, LSFT(KC_7)),
    COMBO(test_combo2, KC_ENTER), // keycodes with modifiers are possible too!
    COMBO(test_combo3, KC_ENTER),
    COMBO(test_combo4, S(KC_2)),
    COMBO(test_combo5, LSFT(KC_INT1)),
    COMBO(test_combo6, KC_MINUS),
    COMBO(test_combo7, KC_BACKSPACE),
    COMBO(test_combo8, KC_PRINT_SCREEN),
    COMBO(test_combo9, LSFT(KC_INT3)),
    COMBO(test_combo10, KC_BSPC),
    COMBO(test_combo11, KC_TAB),
    COMBO(test_combo12, LSFT(KC_TAB)),
    COMBO(test_combo13, KC_GRV),
    COMBO(test_combo14, LCTL(KC_M)),
    COMBO(test_combo15, LALT(KC_LEFT)),
    COMBO(test_combo16, LALT(KC_LEFT)),
    COMBO(test_combo17, LALT(KC_RIGHT)),
    COMBO(test_combo18, LALT(KC_RIGHT)),
    COMBO(test_combo19, LSFT(KC_8)),
    COMBO(test_combo20, LSFT(KC_9)),
    COMBO(test_combo21, KC_ENT),
    COMBO(test_combo22, KC_HOME),
    COMBO(test_combo23, KC_END),
    COMBO(test_combo24, KC_HOME),
    COMBO(test_combo25, KC_END),
    COMBO(test_combo26, KC_PGUP),
    COMBO(test_combo27, KC_PGDN),
    COMBO(test_combo28, S(KC_7))

};

//void pointing_device_init_user(void) {
//     set_auto_mouse_layer(WIN_BASE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
//     set_auto_mouse_enable(true);        // always required before the auto mouse feature will work
//}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_LBRC, KC_HOME,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,  KC_BSLS,  KC_BSPC, KC_DEL,
     CTL_T(KC_GRV),  LT(FN3,KC_A),     KC_S,     KC_D,     SFT_T(KC_F),     KC_G,     KC_H,     SFT_T(KC_J),     KC_K,     LT(FN5,KC_L),     CTL_T(KC_SCLN),  KC_QUOT,            LT(FN2,KC_ENT),  KC_END,
     MT(MOD_LSFT,KC_BSPC),  CTL_T(KC_Z),     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MT(MOD_RSFT,KC_INT1),  KC_UP,    KC_PGDN,
     TG(MAC_FN1),  KC_LGUI, KC_LALT,                               LT(WIN_BASE,KC_SPC),                       KC_RALT,MO(FN2),KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     GRABURL,  REFRESH,    KC_F2,    A(KC_LEFT),    A(KC_RIGHT),    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_PGUP,
     C(KC_TAB),  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN1,  KC_HOME,  KC_MS_WH_UP,  KC_NUM,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  LSFT(KC_8),  LSFT(KC_9),  C(KC_BSPC),  C(KC_DEL),
     CTL_T(C(S(KC_TAB))),  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_END,  KC_MS_WH_DOWN,  KC_BSPC,  KC_KP_4,  KC_KP_5,  KC_KP_6,  S(KC_7),  S(KC_2),            KC_TRNS,  KC_PGDN,
     MT(MOD_LSFT,KC_MS_BTN2), CTL_T(KC_LEFT),  KC_DOWN,  KC_UP,  KC_RIGHT,  KC_TRNS,  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN2,
     KC_TRNS,  KC_ENTER,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     GRABURL,   REFRESH,  BOOKMARK1,  BOOKMARK2,  BOOKMARK3,  BOOKMARK4,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     C(KC_TAB),  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN1,  A(KC_LEFT),  KC_F5,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     CTL_T(C(S(KC_TAB))),  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  A(KC_RGHT),  KC_MS_BTN1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     MT(MOD_LSFT,KC_MS_BTN2), CTL_T(KC_LEFT),  KC_DOWN,  KC_UP,  KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_MS_WH_UP,  KC_MS_WH_DOWN,                                KC_MS_BTN1,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[FN2] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_RIGHT,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
[FN3] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_HOME,  MT(MOD_LCTL,KC_UP),  KC_END,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  MT(MOD_LSFT,KC_LEFT),  MT(MOD_LCTL,KC_DOWN),  MT(MOD_LSFT,KC_RIGHT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  C(KC_X),  C(KC_C),  C(KC_V),  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
[FN4] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
[FN5] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     ALT_TAB,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TAB,  KC_TRNS,  LSFT(KC_7),  KC_UP,  KC_TRNS,  KC_HOME,  KC_END,  KC_TRNS,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  LCTL(KC_A),  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_RIGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,
     KC_TRNS,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),  BAT_LVL,  KC_TRNS,  KC_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
[FN6] = LAYOUT_ansi_68(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};
