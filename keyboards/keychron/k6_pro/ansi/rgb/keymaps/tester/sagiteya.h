#pragma once

enum sagi_layers {
	_KI, //base
	_NN, //nav, num
	_GB, //f
	_XX, //
}

enum sagi_keycodes {



}

enum sagi_tapdance_codes {
	T_TAB,
	T_Q,
	T_W,
	T_E,
	T_R,
	T_T,
	T_Y,
	T_U,
	T_I,
	T_O,
	T_P,
	T_RB,
	T_LB,
	T_BSP,
	T_CAP,
	T_A,
	T_S,
	T_D,
	T_F,
	T_G,
	T_H,
	T_J,
	T_K,
	T_L,
	T_SEMI,
	T_COLN,
	T_ENT,
	T_LSHIF,
	T_Z,
	T_X,
	T_C,
	T_V,
	T_B,
	T_N,
	T_M,
	T_COM,
	T_DOT,
	T_SLSH,
	T_RSHIF,
	T_LCTL,
	T_LGUI,
	T_LALT,
	T_SPC,
	T_RALT,
	T_RFN,
	T_RCTL,
	T_1,
	T_2,
	T_3,
	T_4,
	T_5,
	T_6,
	T_7,
	T_8,
	T_9,
	T_0,
	T_MIN,
	T_TILD,
	T_AT,
}

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);


__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}


#define Qt 
