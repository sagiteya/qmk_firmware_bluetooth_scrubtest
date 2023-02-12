
#include "process_keycode/process_tap_dance.h"

//from .h



typedef struct {
     bool is_press_action;
    int state;
} xtap;


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;



#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


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




int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted) {
      //     if (!state->pressed) return SINGLE_TAP;
      //need "permissive hold" here.
      //     else return SINsGLE_HOLD;
      //If the interrupting key is released before the tap-dance key, then it is a single HOLD
      //However, if the tap-dance key is released first, then it is a single TAP
      //But how to get access to the state of the interrupting key????
      return SINGLE_TAP;
    }
    else {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if ((state->count == 3) && ((state->interrupted) || (!state->pressed))) return TRIPLE_TAP;
  else if (state->count == 3) return TRIPLE_HOLD;
  else if ((state->count == 4) && ((state->interrupted) || (!state->pressed))) return QUADRUPLE_TAP;
  else if (state->count == 4) return QUADRUPLE_HOLD;
  else if ((state->count == 5) && ((state->interrupted) || (!state->pressed))) return QUINTUPLE_TAP;
  else if (state->count == 5) return QUINTUPLE_HOLD;
  else if ((state->count == 6) && ((state->interrupted) || (!state->pressed))) return SEXTUPLE_TAP;
  else if (state->count == 6) return SEXTUPLE_HOLD;
  else if ((state->count == 7) && ((state->interrupted) || (!state->pressed))) return SEPTUPLE_TAP;
  else if (state->count == 7) return SEPTUPLE_HOLD;
  else if ((state->count == 8) && ((state->interrupted) || (!state->pressed))) return OCTUPLE_TAP;
  else if (state->count == 8) return OCTUPLE_HOLD;
  else return 99; //magic number. At some point this method will expand to work for more presses
}

//This works well if you want this key to work as a "fast modifier". It favors being held over being tapped.
int hold_cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
    else {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (!state->pressed) return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else if (state->count == 4) {
    if (!state->pressed) return QUADRUPLE_TAP;
    else return QUADRUPLE_HOLD;
  }
  else if (state->count == 5) {
    if (!state->pressed) return QUINTUPLE_TAP;
    else return QUINTUPLE_HOLD;
  }
  else if (state->count == 6) {
    if (!state->pressed) return SEXTUPLE_TAP;
    else return SEXTUPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}


/////////////
////A alt, sel-all key
////////////

static xtap atap_state = {
  .is_press_action = true,
  .state = 0
};


void a_finished (qk_tap_dance_state_t *state, void *user_data) {
  atap_state.state = cur_dance(state);
  switch (atap_state.state) {
    case SINGLE_TAP: register_code(KC_A); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_A);unregister_code(KC_A);register_code(KC_A); break;
    case DOUBLE_HOLD: register_code(KC_LCTL);register_code(KC_A);unregister_code(KC_A); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_A);unregister_code(KC_A);register_code(KC_A); break;
  }    
}


void a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (atap_state.state) {
    case SINGLE_TAP: unregister_code(KC_A); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_A);break;
    case DOUBLE_HOLD: unregister_code(KC_LCTL);break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_A);
  }
  atap_state.state = 0;
}

/////////////
////Z ctrl, undo key
////////////


static xtap ztap_state = {
  .is_press_action = true,
  .state = 0
};


void z_finished (qk_tap_dance_state_t *state, void *user_data) {
  ztap_state.state = cur_dance(state);
  switch (ztap_state.state) {
    case SINGLE_TAP: register_code(KC_Z); break;
    case SINGLE_HOLD: register_code(KC_LCTL); break;
    case DOUBLE_TAP: register_code(KC_Z);unregister_code(KC_Z);register_code(KC_Z); break;
    case DOUBLE_HOLD: register_code(KC_LCTL);register_code(KC_Z);unregister_code(KC_Z); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_Z);unregister_code(KC_Z);register_code(KC_Z); break;
  }
}

void z_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ztap_state.state) {
    case SINGLE_TAP: unregister_code(KC_Z); break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code(KC_Z);break;
    case DOUBLE_HOLD: unregister_code(KC_LCTL);break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_Z);
  }
  ztap_state.state = 0;
}

/////////////
////Spacebar layer key
////////////


static xtap spctap_state = {
  .is_press_action = true,
  .state = 0
};


void spc_finished (qk_tap_dance_state_t *state, void *user_data) {
  spctap_state.state = cur_dance(state);
  switch (spctap_state.state) {
    case SINGLE_TAP: register_code(KC_SPC); break;
    case SINGLE_HOLD: layer_on(_NUM); break;
    case DOUBLE_TAP: register_code(KC_SPC);unregister_code(KC_SPC);register_code(KC_SPC); break;
    case DOUBLE_HOLD: layer_on(_NAV); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SPC);unregister_code(KC_SPC);register_code(KC_SPC); break;
  }
}

void spc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (spctap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SPC); break;
    case SINGLE_HOLD: layer_off(_NUM); break;
    case DOUBLE_TAP: unregister_code(KC_SPC);break;
    case DOUBLE_HOLD: layer_off(_NAV);break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SPC);
  }
  spctap_state.state = 0;
}


/////////////
////Spacebar layer key
////////////

static xtap srbctap_state = {
  .is_press_action = true,
  .state = 0
};


void sbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  srbctap_state.state = cur_dance(state);
  switch (srbctap_state.state) {
   case SINGLE_TAP: register_code(KC_RBRC);unregister_code(KC_RBRC);register_code(KC_BSLS);unregister_code(KC_BSLS);register_code(KC_LEFT); break;
    case SINGLE_HOLD: register_code(KC_HOME); break;
    case DOUBLE_TAP: register_code(KC_LCTL);register_code(KC_LSFT);register_code(KC_HOME);unregister_code(KC_HOME);unregister_code(KC_LCTL); break;
    case DOUBLE_HOLD: register_code(KC_LCTL);register_code(KC_LSFT);register_code(KC_END);unregister_code(KC_END);unregister_code(KC_LCTL); break;

  }
}

void sbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (srbctap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LEFT); break;
    case SINGLE_HOLD: unregister_code(KC_HOME); break;
   case DOUBLE_TAP: unregister_code(KC_LSFT);break;
    case DOUBLE_HOLD: unregister_code(KC_LSFT);break;

  }
  srbctap_state.state = 0;
}



/////////////
////right ctrl layer toggle
////////////

static xtap rctltap_state = {
.is_press_action = true,
.state = 0
};


void rctl_finished (qk_tap_dance_state_t *state, void *user_data) {
rctltap_state.state = cur_dance(state);
switch (rctltap_state.state) {
case SINGLE_TAP: layer_invert(_GBF); break;
case SINGLE_HOLD: register_code(KC_RCTL); break;
//case DOUBLE_TAP: register_code(KC_Z);unregister_code(KC_Z);register_code(KC_Z); break;
//case DOUBLE_HOLD: register_code(KC_LCTL);register_code(KC_Z);unregister_code(KC_Z); break;
//case DOUBLE_SINGLE_TAP: register_code(KC_Z);unregister_code(KC_Z);register_code(KC_Z); break;
  }
}

void rctl_reset (qk_tap_dance_state_t *state, void *user_data) {
switch (rctltap_state.state) {
case SINGLE_TAP: break;
case SINGLE_HOLD: unregister_code(KC_RCTL); break;
//case DOUBLE_TAP: unregister_code(KC_Z);break;
//case DOUBLE_HOLD: unregister_code(KC_LCTL);break;
//case DOUBLE_SINGLE_TAP: unregister_code(TG(_GBF));
  }
rctltap_state.state = 0;
}


/*
static xtap spctap_state = {
  .is_press_action = true,
  .state = 0
};

void h_finished (qk_tap_dance_state_t *state, void *user_data) {
  htap_state.state = cur_dance(state);
  switch (htap_state.state) {
    case SINGLE_TAP: register_code(KC_H); break;
    case SINGLE_HOLD: layer_on(8); register_code(KC_LALT); break;
    case DOUBLE_TAP: layer_invert(8); register_code(KC_LALT); break;
    case DOUBLE_HOLD: register_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: register_code(KC_H);unregister_code(KC_H);register_code(KC_H);
  }
}

void h_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (htap_state.state) {
    case SINGLE_TAP: unregister_code(KC_H); break;
    case SINGLE_HOLD: layer_off(8); unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LALT);break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_H);
  }
  htap_state.state = 0;
}

*/



qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_RBRC_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_DEL, KC_END),
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
    [CT_PGUP] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, KC_PGUP),
    [CT_PGDN] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, KC_PGDN),
    [QD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    [QD_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_finished, spc_reset),
    [QD_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset),
    [QD_SBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sbrc_finished, sbrc_reset),
    [CT_TAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, MO(_NAV)),
    [CT_G] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, C(KC_BACKSPACE)),
    [CT_H] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, C(KC_BACKSPACE)),
    [QD_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rctl_finished, rctl_reset),
};