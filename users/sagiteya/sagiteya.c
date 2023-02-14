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
#include "my_tapdances.h"
#include "process_keycode/process_tap_dance.h"
#include "keymap_combo.h"
#include "my_leads.h"
#include "my_overrides.h"

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
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}



bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_INT1:
        case SG_Q:
        case SG_W:
        case SG_S:
        case SG_D:
        case SG_F:
        case SG_G:
        case SG_H:
        case SG_J:
        case SG_K:
        case SG_L:
        case SG_X:
        case SG_C:
        case SG_V:
        case SG_B:
        case SG_M:
        case Q_A:
        case Q_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



//Per key tapping terms for simple tap/hold tap dances to prevent accidental activations on alphas/get hold values faster etc
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
        case TD(QD_A):
            return TAPPING_TERM + 20;
        case TD(QD_SPC):
            return TAPPING_TERM + 10;    
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
        case MT(MOD_LCTL,KC_L):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case MT(MOD_LCTL,KC_S):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        case ALT_T(KC_SEMICOLON):
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //
  //Macro keys
  //
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case GRABURL: //copies url of current web page 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_LCTL("x") SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6));
      } else {

      }
      break;
    case REFRESH: //moves to address bar and pastes clipboard+hits enter
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_LCTL("V") SS_TAP(X_ENTER));
      } else {

      }
      break;
    case BOOKMARK1: //"clicks" the first(second/third/etc) item on the bookmark bar
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
    case BM01:
      if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM02:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM03:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM04:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM05:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER)); SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM06:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM07:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM08:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM09:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM10:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM11:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM12:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM13:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM14:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM15:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM16:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM17:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_F6) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_LSFT) SS_TAP(X_ENTER));
      } else {

      }
      break;  
    case BM_BAHA: //goes to summon select screen for pbaha
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/301061/1/0/59"SS_TAP(X_ENTER));
      } else {

      }
      break;  
        
     case BM_PROHARD: //island pro
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305261/28"SS_TAP(X_ENTER));
      } else {   

      }
      break;

     case BM_PROMAG: //magna pro
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305441/28/1"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_BROD: //alex hl
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/303171/1/0/524"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_RA: //ra hl
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305351/1/0/44"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_EWIYAR: //ewiyar raid 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305221/1/0/44"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_COLOHL: //colo hl
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/300491/1/0/47"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_LIND: //lindwurm raid
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#quest/supporter/305171/1/0/535"SS_TAP(X_ENTER));
      } else {   

      }
      break;   
     case BM_JDROPS: //journey drops page
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F6)"game.granbluefantasy.jp/#shop/exchange/trajectory"SS_TAP(X_ENTER));
      } else {   

      }
      break;   

  return true;


//
// Defining simple tap/hold tap dances
//

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
    case TD(CT_TAB):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;
    case TD(CT_H):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;    

    case TD(CT_G):  // list all tap dance keycodes with tap-hold configurations
          action = &tap_dance_actions[TD_INDEX(keycode)];
          if (!record->event.pressed && action->state.count && !action->state.finished) {
              tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
              tap_code16(tap_hold->tap);
          }
          break;


  };
  return true;
}

//**********************
//**********************
//**********************

