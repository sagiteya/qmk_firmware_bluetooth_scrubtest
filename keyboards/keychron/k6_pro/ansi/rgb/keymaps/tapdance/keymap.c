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

enum custom_keycodes {          // Make sure have the awesome keycode ready
  GRABURL = SAFE_RANGE,
  REFRESH,
  BOOKMARK1,
  BOOKMARK2,
  BOOKMARK3,
  BOOKMARK4
};


enum tap_dance_codes {
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
  CT_M_UNDER,
  CT_N_PIPE,
  CT_TAB_GRV,
  CT_A_ALL,
  CT_T_AMP,
  CT_Y_RED,
  CT_O_TILD,
  CT_P_MIN,
  CT_S_SLF,
  CT_D_SRG,
  CT_F1,
  CT_F2,
  CT_F3,
  CT_F4,
  CT_F5,
  CT_F6,
  CT_F7,
  CT_F8,
  CT_F9,
  CT_F10,
  CT_F11,
  CT_F12,
  CT_U_AST,
};



uint8_t mod_state;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //macros
  switch (keycode) { // This will do most of the grunt work with the keycodes.
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

    case LT(WIN_BASE,KC_SPC):
      // Detect the activation of only Left Alt
        if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
            if (record->event.pressed) {
                // No need to register KC_LALT because it's already active.
                // The Alt modifier will apply on this KC_TAB.
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
            }
            // Do not let QMK process the keycode further
            return false;
        }
        // Else, let QMK process the KC_ESC keycode as usual
        return true;

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
      }
 

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
    case TD(CT_M_UNDER):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_N_PIPE):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_TAB_GRV):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;          
    case TD(CT_A_ALL):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_T_AMP):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;          
    case TD(CT_U_AST):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_Y_RED):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_O_TILD):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_P_MIN):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_S_SLF):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_D_SRG):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F1):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F2):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F3):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F4):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F5):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F6):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F7):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F8):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;

    case TD(CT_F9):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F10):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F11):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_F12):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;

  };
  return true;
}


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
    [CT_B_UNDER] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, C(KC_Z)),
//    [CT_CTRL_CSTAB] = ACTION_TAP_DANCE_TAP_HOLD(S(C(KC_TAB)), KC_LCTL),
    [CT_X_CUT] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, C(KC_X)),
    [CT_C_COPY] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, C(KC_C)),
    [CT_V_PASTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, C(KC_V)),
    [CT_I_BACK] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, S(KC_2)),
    [CT_M_UNDER] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, S(KC_INT1)),
    [CT_N_PIPE] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, S(KC_INT3)),
    [CT_TAB_GRV] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, KC_GRV),
    [CT_A_ALL] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, C(KC_A)),
    [CT_T_AMP] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, S(KC_6)),
    [CT_U_AST] = ACTION_TAP_DANCE_TAP_HOLD(KC_U, S(KC_6)),
    [CT_Y_RED] = ACTION_TAP_DANCE_TAP_HOLD(KC_Y, C(KC_Y)),
    [CT_O_TILD] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, S(KC_EQL)),
    [CT_P_MIN] = ACTION_TAP_DANCE_TAP_HOLD(KC_P, S(KC_MINS)),
    [CT_S_SLF] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, S(KC_LEFT)),
    [CT_D_SRG] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, S(KC_RGHT)),
    [CT_F1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_F12),
    [CT_F2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_F2),
    [CT_F3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_F3),
    [CT_F4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_F4),
    [CT_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
    [CT_F6] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, KC_F6),
    [CT_F7] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, KC_F7),
    [CT_F8] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, KC_F8),
    [CT_F9] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_F9),
    [CT_F10] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_F10),
    [CT_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, S(KC_MINS)),
    [CT_F12] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, S(KC_EQL)),

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
const uint16_t PROGMEM test_combo2[] = {TD(CT_F7), TD(CT_F8), COMBO_END}; // D + C = Enter
const uint16_t PROGMEM test_combo3[] = {SFT_T(KC_F), TD(CT_V_PASTE), COMBO_END};  // D + S = Delete
const uint16_t PROGMEM test_combo4[] = {KC_M, KC_COMM, COMBO_END};  // J + L = Double Quote
const uint16_t PROGMEM test_combo5[] = {KC_B, KC_H, COMBO_END};  // I + J = Underscore
//const uint16_t PROGMEM test_combo6[] = {TD(CT_F11), TD(CT_F12), COMBO_END}; // O + J = Minus
const uint16_t PROGMEM test_combo7[] = {TD(CT_K_APOS), LT(FN5,KC_L), COMBO_END}; // q + w = Backspace
// const uint16_t PROGMEM test_combo8[] = {KC_LBRC, KC_BSLS, COMBO_END}; // Backslash + Del = PrintScreen
const uint16_t PROGMEM test_combo9[] = {TD(CT_F11), TD(CT_F12), COMBO_END}; // K + J = Pipe
//const uint16_t PROGMEM test_combo10[] = {LT(FN5,KC_L), KC_K, COMBO_END}; // F + D = Left
const uint16_t PROGMEM test_combo11[] = {TD(CT_I_BACK), TD(CT_O_TILD), TD(CT_P_MIN), COMBO_END}; // X + C = Tab
const uint16_t PROGMEM test_combo12[] = {KC_KP_8,  KC_KP_9,  KC_KP_MINUS, COMBO_END}; // X + V = Shift Tab
//const uint16_t PROGMEM test_combo13[] = {KC_W, SFT_T(KC_F), COMBO_END}; // W + F = Grave (lang swap)
//const uint16_t PROGMEM test_combo14[] = {KC_S, SFT_T(KC_F), COMBO_END}; // S + F = Ctrl M
//const uint16_t PROGMEM test_combo15[] = {KC_3, KC_4, COMBO_END}; // 3 + 4 = alt left 
//const uint16_t PROGMEM test_combo16[] = {KC_F3, KC_F4, COMBO_END}; // F3 + F4 = alt left DOES NOT WORK
//const uint16_t PROGMEM test_combo17[] = {KC_4, KC_3, COMBO_END}; // 4 + 2 = alt right
//const uint16_t PROGMEM test_combo18[] = {KC_F4, KC_F3, COMBO_END}; // F4 + F2 = alt right
const uint16_t PROGMEM test_combo19[] = {TD(CT_F8), TD(CT_F9), COMBO_END}; // 8 + 9 = left (
const uint16_t PROGMEM test_combo20[] = {TD(CT_F10), TD(CT_F9), COMBO_END}; // 9 + 0 = right )
const uint16_t PROGMEM test_combo21[] = {SFT_T(KC_J),  TD(CT_N_PIPE), COMBO_END}; // Back + Lbracket(JP) = Delete
//const uint16_t PROGMEM test_combo22[] = {KC_R, KC_Q, COMBO_END}; // R + Q = Home
//const uint16_t PROGMEM test_combo23[] = {KC_T, KC_W, COMBO_END}; // Q + R = End
//const uint16_t PROGMEM test_combo24[] = {KC_RBRC, KC_P, COMBO_END};  // D + F = Right
//const uint16_t PROGMEM test_combo25[] = {KC_RBRC, KC_BSLS, COMBO_END};  // D + F = Right
//const uint16_t PROGMEM test_combo26[] = {CTL_T(KC_SCLN), LT(FN5,KC_L), COMBO_END};  // D + F = Right
//const uint16_t PROGMEM test_combo27[] = {CTL_T(KC_SCLN), KC_QUOT, COMBO_END};  // D + F = Right
const uint16_t PROGMEM test_combo28[] = {TD(CT_F2), TD(CT_F3), COMBO_END};  // D + F = Right
const uint16_t PROGMEM esc_combo[] = {TD(CT_TAB_GRV),CTL_T(KC_BSPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, LSFT(KC_7)),
    COMBO(test_combo2, LSFT(KC_7)), // keycodes with modifiers are possible too!
    COMBO(test_combo3, KC_ENTER),
    COMBO(test_combo4, S(KC_2)),
    COMBO(test_combo5, LSFT(KC_INT1)),
//    COMBO(test_combo6, KC_MINUS),
    COMBO(test_combo7, KC_BACKSPACE),
//    COMBO(test_combo8, KC_PRINT_SCREEN),
    COMBO(test_combo9, LSFT(KC_INT3)),
//    COMBO(test_combo10, KC_BSPC),
    COMBO(test_combo11, TG(WIN_BASE)),
    COMBO(test_combo12, TG(WIN_BASE)),
//    COMBO(test_combo13, KC_GRV),
//    COMBO(test_combo14, LCTL(KC_M)),
//    COMBO(test_combo15, LALT(KC_LEFT)),
//    COMBO(test_combo16, LALT(KC_LEFT)),
//    COMBO(test_combo17, LALT(KC_RIGHT)),
//    COMBO(test_combo18, LALT(KC_RIGHT)),
    COMBO(test_combo19, LSFT(KC_8)),
    COMBO(test_combo20, LSFT(KC_9)),
    COMBO(test_combo21, KC_ENT),
    COMBO(esc_combo, KC_ESC),
//    COMBO(test_combo22, KC_HOME),
//    COMBO(test_combo23, KC_END),
//    COMBO(test_combo24, KC_HOME),
//    COMBO(test_combo25, KC_END),
//    COMBO(test_combo26, KC_PGUP),
//    COMBO(test_combo27, KC_PGDN),
    COMBO(test_combo28, KC_F2),

};

//void pointing_device_init_user(void) {
//     set_auto_mouse_layer(WIN_BASE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
//     set_auto_mouse_enable(true);        // always required before the auto mouse feature will work
//}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(CT_K_APOS):
//          return TAPPING_TERM + 1250;
            return TAPPING_TERM - 75;
        case TD(CT_S_SLF):
            //return 130;
            return TAPPING_TERM + 50;
        case TD(CT_D_SRG):
            //return 130;
            return TAPPING_TERM + 50;    
        default:
            return TAPPING_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   TD(CT_F1), TD(CT_F2), TD(CT_F3), TD(CT_F4), TD(CT_F5), TD(CT_F6), TD(CT_F7), TD(CT_F8), TD(CT_F9), TD(CT_F10), TD(CT_F11), TD(CT_F12),   KC_LBRC, KC_HOME,
     TD(CT_TAB_GRV),   TD(CT_Q_HOME),     TD(CT_W_END),     KC_E,     KC_R,     TD(CT_T_AMP),     TD(CT_Y_RED),     TD(CT_U_AST),TD(CT_I_BACK), TD(CT_O_TILD), TD(CT_P_MIN),   TD(CT_LBRC_HOME),  TD(CT_RBRC_END),  KC_BSPC, KC_DEL,
     CTL_T(KC_BSPC),  TD(CT_A_ALL),    TD(CT_S_SLF),     TD(CT_D_SRG),     SFT_T(KC_F),     KC_G,     KC_H,     SFT_T(KC_J),    TD(CT_K_APOS),     LT(FN5,KC_L),     CTL_T(KC_SCLN),  KC_QUOT,            LT(FN2,KC_ENT),  KC_END,
     MT(MOD_LSFT,KC_BSPC),  CTL_T(KC_Z),     TD(CT_X_CUT),     TD(CT_C_COPY),     TD(CT_V_PASTE),    TD(CT_B_UNDER),     TD(CT_N_PIPE),    TD(CT_M_UNDER),     KC_COMM,  KC_DOT,   SFT_T(KC_SLSH),  MT(MOD_RSFT,KC_INT1),  KC_UP,    KC_PRINT_SCREEN,
     TG(MAC_FN1),  KC_LGUI, KC_LALT,                               LT(WIN_BASE,KC_SPC),                       KC_RALT,MO(FN2),KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     GRABURL,  REFRESH,    KC_F2,    A(KC_LEFT),    A(KC_RIGHT),    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PRINT_SCREEN,  KC_PGUP,
     C(KC_TAB), S(C(KC_TAB)),  KC_MS_BTN2, KC_MS_UP,  KC_MS_BTN1,    KC_MS_WH_UP,  KC_NUM,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  LSFT(KC_8),  LSFT(KC_9),  C(KC_BSPC),  C(KC_DEL),
     KC_TRNS, C(KC_A), KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_MS_WH_DOWN,  KC_BSPC,  KC_KP_4,  KC_KP_5,  KC_KP_6,  S(KC_7),  S(KC_2),            KC_TRNS,  KC_PGDN,
     MT(MOD_LSFT,KC_MS_BTN2), CTL_T(KC_LEFT),  KC_DOWN,  KC_UP,  KC_RIGHT,  KC_TRNS,  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,  KC_MS_BTN1,  KC_MS_UP,  KC_MS_BTN2,
     QK_CAPS_WORD_TOGGLE,  KC_ENTER,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     GRABURL,   REFRESH,  BOOKMARK1,  BOOKMARK2,  BOOKMARK3,  BOOKMARK4,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     C(KC_TAB),  S(C(KC_TAB)),  KC_MS_UP,  KC_MS_BTN1,  A(KC_LEFT),  KC_F5,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_DYNAMIC_TAPPING_TERM_PRINT,  QK_DYNAMIC_TAPPING_TERM_UP,  QK_DYNAMIC_TAPPING_TERM_DOWN,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  A(KC_RGHT),  KC_MS_BTN1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
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
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TAB,  KC_TRNS,  LSFT(KC_7),  KC_UP,  KC_TRNS,  KC_HOME,  KC_END,  KC_TRNS,   KC_TRNS,  KC_TRNS,
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
