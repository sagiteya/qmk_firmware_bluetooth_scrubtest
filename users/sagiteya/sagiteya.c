/*
  Copyright 2018 Eric Gebhart <e.a.gebhart@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "sagiteya.h"
#include "g/keymap_combo.h"


//Shft+BSPC=DEL
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t rparen_key_override = ko_make_basic(MOD_MASK_SHIFT, SG_0, S(KC_9));
const key_override_t lparen_key_override = ko_make_basic(MOD_MASK_SHIFT, SG_9, S(KC_8));
const key_override_t eitqut_key_override = ko_make_basic(MOD_MASK_SHIFT, SG_8, S(KC_7));
const key_override_t svnamp_key_override = ko_make_basic(MOD_MASK_SHIFT, SG_7, S(KC_6));
const key_override_t ctlspc_key_override = ko_make_basic(MOD_MASK_CTRL, SG_SPC1, C(KC_BSPC));
const key_override_t ctlsp2_key_override = ko_make_basic(MOD_MASK_CTRL, SG_SPC2, C(KC_BSPC));
//const key_override_t sftspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, S(KC_6));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &rparen_key_override,
    &lparen_key_override,
    &eitqut_key_override,
    &svnamp_key_override,
    &ctlspc_key_override,
    &ctlsp2_key_override,
    NULL // Null terminate the array of overrides!
};



// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}


void matrix_scan_user(void) {
 LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_PRINTSCREEN);
      unregister_code(KC_PRINTSCREEN);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_SEMICOLON) {
      // Anything you can do in a macro.
     register_code(KC_LALT);
      register_code(KC_PRINTSCREEN);
      unregister_code(KC_PRINTSCREEN);
      unregister_code(KC_LALT);
    }
    SEQ_TWO_KEYS(KC_B, KC_A) {
      register_code(BM_BAHA);
      unregister_code(BM_BAHA);
    }
    SEQ_THREE_KEYS(KC_A, KC_R, KC_D) {
      register_code(BM_PROHARD);
      unregister_code(BM_PROHARD);
    //  SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_R, KC_O) {
      register_code(BM_BROD);
      unregister_code(BM_BROD);
      
    }
  }

}

//Per key tapping terms for tap dance to prevent accidental activations on alphas etc
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(CT_K_APOS):
            return TAPPING_TERM - 25;
        case TD(CT_S_SLF):
            //return 130;
            return TAPPING_TERM + 50;
        case TD(CT_D_SRG):
            return TAPPING_TERM + 50;  
        case TD(CT_A_ALL):
            return TAPPING_TERM + 100;    
        default:
            return TAPPING_TERM;
    }
}


// List of keys for "home row mod" functionality to prevent "first→Irst"
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



//**********************
// process_record
//**********************
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


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
    case BOOKMARK7:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT)  SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BOOKMARK8:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BOOKMARK9:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT)  SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BOOKMARK10:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM_PBAHA:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/301061/1/0/59"SS_TAP(X_ENTER));
      } else {

      }
      break;  
        
     case BM_PROHARD:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305261/28"SS_TAP(X_ENTER));
      } else {   

      }
      break;

     case BM_PROMAG:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305441/28/1"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_BROD:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/303171/1/0/524"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_RA:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305351/1/0/44"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_EWIYAR:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305221/1/0/44"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_COLOHL:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/300491/1/0/47"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_LIND:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305171/1/0/535"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_JDROPS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#shop/exchange/trajectory"SS_TAP(X_ENTER));
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
    case TD(CT_AT):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_PGUP):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_PGDN):  // list all tap dance keycodes with tap-hold configurations
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
    [CT_U_AST] = ACTION_TAP_DANCE_TAP_HOLD(KC_U, S(KC_7)),
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
    [CT_AT] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, S(KC_INT3)),
    [CT_PGUP] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGUP, KC_HOME),
    [CT_PGDN] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGDN, KC_END),

};