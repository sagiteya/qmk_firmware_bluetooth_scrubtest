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


enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
  GRABURL,
  REFRESH,
  BOOKMARK1,
  BOOKMARK2,
  BOOKMARK3,
  BOOKMARK4
};





// Tap Dance keycodes
enum td_keycodes {
    G_LAYER, // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
    H_LAYER, 
    CT_RBRC_END,
    CT_LBRC_HOME,
    CT_Q_HOME,
    CT_W_END,
    CT_K_APOS,
    CT_X_CUT,
    CT_C_COPY,
    CT_V_PASTE,
    CT_B_UNDER,
    CT_I_BACK,
    PLUS_LAYER,
};




bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.





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


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //macros
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
  
  return true;

  qk_tap_dance_action_t *action;

    case TD(CT_RBRC_END):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;  
    case TD(CT_LBRC_HOME):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
         }
         break;  
    case TD(CT_Q_HOME):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;  
    case TD(CT_W_END):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;      
    case TD(CT_B_UNDER):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;      
    case TD(CT_K_APOS):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;      
    case TD(CT_X_CUT):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;
    case TD(CT_C_COPY):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;           
    case TD(CT_V_PASTE):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;
    case TD(CT_I_BACK):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;
    case TD(G_LAYER):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;
    case TD(H_LAYER):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }       
        break;
     
  };
  return true;
}



//const uint16_t PROGMEM apostrophe_combo[] = {KC_DOT,KC_COMM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_P,KC_LBRC, COMBO_END}; //1
const uint16_t PROGMEM righbracket_combo[] = {KC_LBRC,KC_RBRC, COMBO_END}; //2
const uint16_t PROGMEM delete_combo[] = {KC_RBRC,KC_BSPC, COMBO_END}; //3
const uint16_t PROGMEM enterleft_combo[] = {MT(MOD_LSFT,KC_F),KC_V, COMBO_END}; //4
const uint16_t PROGMEM enterright_combo[] = {KC_N,MT(MOD_LSFT,KC_J), COMBO_END}; //5
const uint16_t PROGMEM backspaceleft_combo[] = {KC_Q,KC_W, COMBO_END}; //6
const uint16_t PROGMEM pageup_combo[] = {KC_LBRC,CTL_T(KC_SEMICOLON), COMBO_END}; //7
const uint16_t PROGMEM pagedown_combo[] = {KC_RBRC,KC_QUOT, COMBO_END}; //8
const uint16_t PROGMEM home_combo[] = {KC_DOT,CTL_T(KC_SEMICOLON), COMBO_END}; //9
const uint16_t PROGMEM end_combo[] = {KC_QUOT,LSFT_T(KC_SLSH), COMBO_END}; //10
const uint16_t PROGMEM backspaceright_combo[] = {KC_DOT,KC_COMM, COMBO_END}; //11
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

#define X_CAT TD(CT_X_CUT)
#define C_COP TD(CT_C_COPY)
#define V_PAS TD(CT_V_PASTE)
#define LB_END TD(CT_RBRC_END)
#define AT_HOM TD(CT_LBRC_HOME)
#define Q_HOM TD(CT_Q_HOME)
#define W_END TD(CT_W_END)
#define G_FN TD(G_LAYER)
#define H_FN TD(H_LAYER)
#define PLUS_FN TD(PLUS_LAYER)




void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_RBRC_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSLS, KC_END),
    [CT_LBRC_HOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_RBRC, KC_HOME),
    [CT_Q_HOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, KC_HOME),
    [CT_W_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, KC_END),
    [CT_K_APOS] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, S(KC_7)),
    [CT_B_UNDER] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, S(KC_INT1)),
//    [CT_CTRL_CSTAB] = ACTION_TAP_DANCE_TAP_HOLD(S(C(KC_TAB)), KC_LCTL),
    [CT_X_CUT] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, C(KC_X)),
    [CT_C_COPY] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, C(KC_C)),
    [CT_V_PASTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, C(KC_V)),
    [CT_I_BACK] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, S(KC_2)),
    [G_LAYER] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, TG(_8)),
    [H_LAYER] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, TG(_8)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  Q_HOM,     W_END,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     AT_HOM,  LB_END,  KC_BACKSPACE,          KC_HOME,
        LCTL_T(KC_GRV), LT(_FN3,KC_A),       KC_S,     LT(_9,KC_D),    MT(MOD_LSFT,KC_F),    KC_G,              KC_H,    MT(MOD_LSFT,KC_J),    LT(_9,KC_K),    LT(_FN3,KC_L),     CTL_T(KC_SEMICOLON),  KC_QUOT,  KC_ENT,         LALT_T(KC_END),
        MT(MOD_LSFT,KC_BSPC),           LCTL_T(KC_Z),     X_CAT,    C_COP,   V_PAS,    KC_B,     S(KC_INT1),    KC_N,    KC_M,    KC_COMM,  KC_DOT,   LSFT_T(KC_SLSH),  MT(MOD_RSFT,KC_INT1), KC_UP,
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
        _______, _______, KC_LEFT,  KC_DOWN, KC_RGHT, TG(_8),           _______, KC_LEFT, KC_RGHT, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, KC_DOWN, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

     [_6] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        C(S(KC_TAB)), C(KC_TAB),    KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_NUM_LOCK,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  KC_PGUP,  _______,  KC_DEL,          _______,
        _______,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_PLUS, _______,  KC_PGDN,          _______,
        _______,           C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), KC_F12,   _______, KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,  _______, _______,
        _______, KC_LALT,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_7] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  KC_MS_WH_UP, KC_MS_BTN2,  KC_MS_UP, KC_MS_BTN1,   KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,_______, _______,  _______,  _______,  KC_DEL,          _______,
        _______, _______,KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,           KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,   _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, KC_MS_WH_UP, KC_MS_WH_DOWN,  _______, KC_MS_WH_UP, KC_MS_WH_DOWN,   _______,  _______,  _______, _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_8] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, KC_KP_EQUAL, KC_KP_7,  KC_KP_8,  KC_KP_9, KC_NUM_LOCK, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_KP_MINUS, KC_KP_4,  KC_KP_5,  KC_KP_6, TG(_8),           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           KC_KP_DOT, KC_KP_1,  KC_KP_2,  KC_KP_3, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           KC_KP_0,          _______,  _______,          _______,           _______,            _______, _______, _______),
    
    [_9] = LAYOUT_ansi_69(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        
        KC_ESC,  S(KC_1),     S(KC_2),     S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),     S(KC_7),    S(KC_8),    S(KC_9),  KC_MINUS,    S(KC_MINS),  S(KC_EQL),   KC_BSPC,         _______,
        _______, _______, _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  KC_EQL,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = {ENCODER_CCW_CW(_______, _______)},
    [_6]   = {ENCODER_CCW_CW(_______, _______)},
    [_7]   = {ENCODER_CCW_CW(_______, _______)},
    [_8]   = {ENCODER_CCW_CW(_______, _______)},
    [_9]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
