#pragma once

#include "quantum.h"


// Define layer names and order
enum userspace_layers {
  _BL = 0,
  _NAV,
  _NUM,
  _FN,
  _MISC,
  _GBF,
};




//List of macro keys
enum userspace_custom_keycodes {
  GRABURL = SAFE_RANGE,
  REFRESH,
  BOOKMARK1,
  BOOKMARK2,
  BOOKMARK3,
  BOOKMARK4,
  BOOKMARK5,
  BOOKMARK6,
  BOOKMARK7,
  BOOKMARK8,
  BOOKMARK9,
  BOOKMARK10,
  BM01,
  BM02,
  BM03,
  BM04,
  BM05,
  BM06,
  BM07,
  BM08,
  BM09,
  BM10,
  BM11,
  BM12,
  BM13,
  BM14,
  BM15,
  BM16,
  BM17,
  BM_BAHA,
  BM_PROHARD,
  BM_PROMAG,
  BM_BROD,
  BM_RA,
  BM_EWIYAR,
  BM_COLOHL,
  BM_LIND,
  BM_JDROPS,
  SG_RBRC,  //from here down is tap dance codes, pulled from the excel based on tap dance list 
  SG_LBRC,
  SG_Q,
  SG_W,
  SG_K,
  SG_X,
  SG_C,
  SG_V,
  SG_B,
  SG_I,
  SG_M,
  SG_N,
  SG_TAB_GRV,
  SG_A,
  SG_T,
  SG_Y,
  SG_O,
  SG_P,
  SG_S,
  SG_D,
  SG_1,
  SG_2,
  SG_3,
  SG_4,
  SG_5,
  SG_6,
  SG_7,
  SG_8,
  SG_9,
  SG_10,
  SG_MINS,
  SG_TILD,
  SG_U,
  SG_CAPS,
  SG_SPC1,
  SG_SPC2,
  SG_SPC3,
  SG_SPC4,
  SG_END,
  SG_RSFT,
  SG_SLSH,
  SG_SCLN,
  SG_F,
  SG_J,
  SG_H,
  SG_G,
};


enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,

  QUADRUPLE_TAP = 8,
  QUADRUPLE_HOLD = 9,

  QUINTUPLE_TAP = 10,
  QUINTUPLE_HOLD = 11,

  SEXTUPLE_TAP = 12,
  SEXTUPLE_HOLD = 13,

  SEPTUPLE_TAP = 14,
  SEPTUPLE_HOLD = 15,

  OCTUPLE_TAP = 16,
  OCTUPLE_HOLD = 17
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
  CT_PGUP,
  CT_PGDN,
  CT_AT,
  QD_A,
  QD_SPC,
  QD_Z,
  CT_TAB,
  QD_SBRC,
  CT_H,
  CT_G,
  QD_RCTL,
};


//tap dance actual-keymap kc defines
#define SG_RBRC TD(CT_RBRC_END)
#define SG_LBRC TD(CT_LBRC_HOME)
#define SG_Q TD(CT_Q_HOME)
#define SG_W TD(CT_W_END)
#define SG_K LT(_MISC,KC_K)
#define SG_X TD(CT_X_CUT)
#define SG_C TD(CT_C_COPY)
#define SG_V TD(CT_V_PASTE)
#define SG_B TD(CT_B_UNDER)
#define SG_I TD(CT_I_BACK)
#define SG_M TD(CT_M_UNDER)
#define SG_N TD(CT_N_PIPE)
#define SG_TAB_GRV TD(CT_TAB_GRV)
#define SG_A TD(CT_A_ALL)
#define SG_T TD(CT_T_AMP)
#define SG_Y TD(CT_Y_RED)
#define SG_O TD(CT_O_TILD)
#define SG_P TD(CT_P_MIN)
#define SG_D LT(_MISC,KC_D)
#define SG_1 TD(CT_F1)
#define SG_2 TD(CT_F2)
#define SG_3 TD(CT_F3)
#define SG_4 TD(CT_F4)
#define SG_5 TD(CT_F5)
#define SG_6 TD(CT_F6)
#define SG_7 TD(CT_F7)
#define SG_8 TD(CT_F8)
#define SG_9 TD(CT_F9)
#define SG_0 TD(CT_F10)
#define SG_MINS TD(CT_F11)
#define SG_TILD TD(CT_F12)
#define SG_AT TD(CT_AT)
#define SG_PGUP TD(CT_PGUP)
#define SG_PGDN TD(CT_PGDN)
#define Q_A TD(QD_A)
#define Q_SPC TD(QD_SPC)
#define Q_Z TD(QD_Z)
#define Q_RCTL TD(QD_RCTL)
#define SG_S MT(MOD_LCTL,KC_S)
#define SG_L MT(MOD_LCTL,KC_L)


//other key defines

#define SG_CAPS LCTL_T(KC_CAPS)
#define SG_SPC1 LT(_NUM,KC_SPC)  
#define SG_SPC2 LT(_NAV,KC_SPC)  
#define SG_SPC3 LT(_NAV,KC_ENT)
#define SG_SPC4 LT(_NUM,KC_BSPC)
#define SG_END  MT(MOD_LALT,KC_END)
#define SG_RSFT MT(MOD_RSFT,KC_INT1)
#define SG_SLSH MT(MOD_RSFT,KC_SLSH)
#define SG_SCLN ALT_T(KC_SEMICOLON)
#define SG_F SFT_T(KC_F) 
#define SG_J SFT_T(KC_J)
#define SG_Z CTL_T(KC_Z)
#define Q_SBRC TD(QD_SBRC)
#define SG_TAB TD(CT_TAB)
#define SG_G TD(CT_G)
#define SG_H TD(CT_H)

//Tap Dance Declarations (list of my tap dance configurations)






//int cur_dance (qk_tap_dance_state_t *state);
//tint hold_cur_dance (qk_tap_dance_state_t *state);
/*
void a_finished (qk_tap_dance_state_t *state, void *user_data);
void a_reset (qk_tap_dance_state_t *state, void *user_data);

void spc_finished (qk_tap_dance_state_t *state, void *user_data);
void spc_reset (qk_tap_dance_state_t *state, void *user_data);

void z_finished (qk_tap_dance_state_t *state, void *user_data);
void z_reset (qk_tap_dance_state_t *state, void *user_data);
*/



// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ansi_69_wrapper(...)          LAYOUT_ansi_69(__VA_ARGS__)
#define LAYOUT_ansi_68_wrapper(...)          LAYOUT_ansi_68(__VA_ARGS__)
//#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
//#define LAYOUT_ortho_5x5_wrapper(...)        LAYOUT_ortho_5x5(__VA_ARGS__)
//#define LAYOUT_ortho_5x10_wrapper(...)       LAYOUT_ortho_5x10(__VA_ARGS__)
//#define LAYOUT_ortho_5x15_wrapper(...)       LAYOUT_ortho_5x15(__VA_ARGS__)

// Blocks for each of the major keyboard layouts
// Organized so we can quickly adapt and modify all of themx
// at once, rather than for each keyboard, one at a time.
// And this allows for much cleaner blocks in the keymaps.

// NOTE: These are all the same length.  If you do a search/replace
//       then you need to add/remove underscores to keep thee
//       lengths consistent.


/* Qwerty
 * .--------------------------------------------------------------------------------------------------------.
 * | Esc   |   1  |   2  |   3  |  4   |   5  |   6  |   7  |   8  |   9  |   0  |  -=   | ^~  |  @`  | Enc.
 * |-------+------+------+------+------+-------------+------+------+------+------+-------+-----+------+------|
 * | TAB   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | [{    | ]}  | BSPC | Home |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------+-----+------+------|
 * | CAP   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;+  |   :*  |    Ent     | End  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------+-----+------+------|
 * |Sft    |   Z  |   X  |   C  |   V  |   B  |  B2  |   N  |   M  |   ,  |   .  |   /  |   \_ Shft   | Up   |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------+-----+------+------|
 * | LCTRL | LGUI | ALT  | ALT  | SUB  | SHIFT| SPACE| SUP  | RGUI | RALT | DEL  | CTRL  | ←   |  ↓   |  →   |
 * '--------------------------------------------------------------------------------------------------+------'
 */

#define _______________Alice65_Row__0_______________   KC_ESC,   SG_1,    SG_2,    SG_3,     SG_4,    SG_5,     SG_6,    SG_7,    SG_8,    SG_9,    SG_0,    SG_MINS, SG_TILD,  SG_AT, KC_MUTE
#define _______________Alice65_Row__1_______________   SG_TAB,   SG_Q,    SG_W,    KC_E,     KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    Q_SBRC, SG_RBRC, KC_BSPC, SG_PGUP
#define _______________Alice65_Row__2_______________   SG_CAPS,  Q_A,    SG_S,    SG_D,     SG_F,    SG_G,     SG_H,    SG_J,    SG_K,    SG_L, SG_SCLN, KC_QUOT, KC_ENT,           SG_PGDN
#define _______________Alice65_Row__3_______________   KC_LSFT,  Q_Z,    SG_X,    SG_C,     SG_V,    SG_B,     S(KC_INT1),    KC_N,    SG_M,    KC_COMM, KC_DOT,   SG_SLSH, SG_RSFT, KC_UP
#define _______________Alice65_Row__4_______________   Q_RCTL,  KC_LGUI, KC_LALT, SG_SPC1,          SG_SPC2, SG_SPC3,         SG_SPC4,  Q_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT 

#define _______________Alice65_Row__0NUM____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1NUM____________   S(C(KC_TAB)), C(KC_TAB), KC_MS_UP,  KC_MS_BTN1,  A(KC_LEFT),  KC_MS_WH_UP, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, S(KC_MINS), _______, _______, KC_PGUP
#define _______________Alice65_Row__2NUM____________   _______,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  A(KC_RGHT),  KC_MS_WH_DOWN, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_PAST, _______, KC_PGDN
#define _______________Alice65_Row__3NUM____________   _______, KC_MS_BTN2,  KC_MS_WH_DOWN, KC_MS_WH_UP, _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT,  KC_MS_BTN1, KC_MS_UP  
#define _______________Alice65_Row__4NUM____________   TO(_BL), KC_MS_WH_DOWN, KC_MS_WH_UP, _______,           _______, _______,         _______, TO(_BL),          KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT


#define _______________Alice65_Row__0NAV____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1NAV____________   S(C(KC_TAB)), C(KC_TAB), C(KC_LEFT), KC_UP, C(KC_RGHT),  _______, _______, _______, KC_UP, _______, _______, KC_RBRC, KC_BSLS, _______, KC_PGUP
#define _______________Alice65_Row__2NAV____________   _______, KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_BSPC, KC_LEFT,  KC_DOWN, KC_RIGHT, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3NAV____________   _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_APP, KC_MS_BTN2, KC_MS_BTN1, KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1, KC_MS_UP  
#define _______________Alice65_Row__4NAV____________   TO(_BL), KC_MS_WH_DOWN, KC_MS_WH_UP, QK_LEAD,           _______, _______,         _______, _______,          KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT

#define _______________Alice65_Row__0GBF____________   GRABURL,   REFRESH,  BOOKMARK1,  BOOKMARK2,  BOOKMARK3,  BOOKMARK4,    BOOKMARK5, BOOKMARK6, BOOKMARK7, BOOKMARK8, BOOKMARK9, BOOKMARK10, BM12,  RGB_TOG, _______
#define _______________Alice65_Row__1GBF____________   S(C(KC_TAB)), C(KC_TAB), KC_MS_UP,  KC_MS_BTN1,  A(KC_LEFT),  KC_F5, A(KC_LEFT), BOOKMARK1, BOOKMARK2, KC_MS_BTN1, _______, _______, _______, _______, KC_PGUP
#define _______________Alice65_Row__2GBF____________   KC_MS_BTN2,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  A(KC_RGHT),  KC_MS_BTN1, BM04, BM05, KC_MS_BTN1, BM06, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3GBF____________   _______, A(KC_LEFT), KC_MS_WH_UP, KC_MS_WH_DOWN, _______, _______, _______,  BOOKMARK8, BOOKMARK9, BOOKMARK10,  A(KC_LEFT), A(KC_RGHT), KC_MS_BTN1, KC_MS_UP  
#define _______________Alice65_Row__4GBF____________   TO(_BL), _______, _______, A(KC_LEFT),           KC_MS_BTN1, TO(_BL),         A(KC_RGHT), KC_MS_BTN1,          KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT

#define _______________Alice65_Row__0MISC___________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  S(KC_EQL), _______
#define _______________Alice65_Row__1MISC___________   _______, S(KC_1),    S(KC_2),   S(KC_3),  S(KC_4),  S(KC_5),    S(KC_6),  S(KC_7),  KC_RBRC,    KC_BSLS,  KC_MINUS,    S(KC_MINS), _______, _______, KC_PGUP
#define _______________Alice65_Row__2MISC___________   _______, S(KC_1),    S(KC_2),   S(KC_3),  S(KC_4),  S(KC_5),    S(KC_6),  S(KC_7),  S(KC_8),    S(KC_9),  KC_MINUS,    S(KC_MINS),  _______,            KC_PGDN
#define _______________Alice65_Row__3MISC___________   _______, _______, KC_F2, KC_F5, KC_F12, _______, _______, _______, S(KC_INT1), _______, _______, _______, KC_MS_BTN1, KC_MS_UP  
#define _______________Alice65_Row__4MISC___________   TO(_BL), _______, _______, _______,           _______, _______,         _______, TO(_BL),         KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT

#define _______________Alice65_Row__0FN_____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, KC_PGUP
#define _______________Alice65_Row__2FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4FN_____________   TO(_BL), _______, _______, _______,           _______, _______,         _______, TO(_BL),          _______, _______, _______  



/*
#define _______________Alice65_Row__0FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
#define _______________Alice65_Row__1FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______________Alice65_Row__2FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______________Alice65_Row__3FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4FN_____________   _______, _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  

#define _______________Ansi65__Row__0_______________   KC_ESC,   SG_1,    SG_2,    SG_3,     SG_4,    SG_5,     SG_6,    SG_7,    SG_8,    SG_9,    SG_0,    SG_MINS, SG_TILD,  SG_AT, KC_HOME
#define _______________Ansi65__Row__1_______________   KC_TAB,   SG_Q,    SG_W,    KC_E,     KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SG_LBRC, SG_RBRC, KC_BSPC, KC_DEL
#define _______________Ansi65__Row__2_______________   SG_CAPS,  SG_A,    KC_S,    SG_D,     SG_F,    KC_G,     KC_H,    SG_J,    SG_K,    KC_L, SG_SCLN, KC_QUOT, KC_ENT,           SG_END
#define _______________Ansi65__Row__3_______________   KC_LSFT,  SG_Z,    SG_X,    SG_C,     SG_V,    SG_B,     KC_N,    SG_M,    KC_COMM, KC_DOT,   SG_SLSH, SG_RSFT, KC_UP, QK_LEAD
#define _______________Ansi65__Row__4_______________   TG(_GBF),  KC_LGUI, KC_LALT,                              SG_SPC2,                  KC_RALT,  QK_LEAD,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
*/

#define   _______________Ansi65__Row__0_______________    KC_ESC, SG_1, SG_2, SG_3, SG_4, SG_5, SG_6, SG_7, SG_8, SG_9, SG_0, SG_MINS,  SG_TILD,  SG_AT,  SG_PGUP
#define   _______________Ansi65__Row__1_______________    SG_TAB, SG_Q, SG_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, Q_SBRC,  SG_RBRC,  KC_BSPC,  KC_DEL
#define   _______________Ansi65__Row__2_______________    SG_CAPS,  Q_A, SG_S, SG_D, SG_F, SG_G, SG_H, SG_J, SG_K, SG_L, SG_SCLN,  KC_QUOT,  KC_ENT,   SG_PGDN
#define   _______________Ansi65__Row__3_______________    KC_LSFT,  Q_Z, SG_X, SG_C, SG_V, SG_B, KC_N, SG_M, KC_COMM,  KC_DOT, SG_SLSH,  SG_RSFT,    KC_UP,  KC_LCTL
#define   _______________Ansi65__Row__4_______________    TG(_GBF), KC_LGUI,  KC_LALT,     LT(_NUM,KC_SPC),        KC_RALT,  QK_LEAD,  MO(_NAV), KC_LEFT,  KC_DOWN,  KC_RGHT
                                  
#define   _______________Ansi65__Row__NUM0____________    KC_ESC, KC_F12, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,  _______
#define   _______________Ansi65__Row__NUM1____________    C(S(KC_TAB)),  C(KC_TAB),  KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, _______,  KC_NUM, KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  KC_KP_EQUAL,    _______, _______, _______
#define   _______________Ansi65__Row__NUM2____________    _______,  _______,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  KC_BSPC,  KC_BSPC,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_PLUS, KC_PAST,  _______,    _______
#define   _______________Ansi65__Row__NUM3____________    _______,  _______,  _______,  KC_MS_WH_UP,  KC_MS_WH_DOWN,  _______,  KC_KP_0,  KC_KP_1, KC_KP_2,  KC_KP_3,  KC_KP_DOT,  KC_MS_BTN1,   KC_MS_UP, KC_MS_BTN2
#define   _______________Ansi65__Row__NUM4____________    TO(_BL),  _______,  _______,      _______,        KC_MENU,  KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
                                  
#define   _______________Ansi65__Row__NAV0____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__NAV1____________    _______,  KC_HOME,  KC_END, KC_UP,  KC_MENU,  _______,  _______,  KC_HOME,  KC_UP,  KC_PGUP,  KC_MENU,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__NAV2____________    _______,  C(KC_LSFT), KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__NAV3____________    _______,  C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  _______,  _______,  KC_END, _______,  KC_PGDN,  _______,  _______,    _______,  _______
#define   _______________Ansi65__Row__NAV4____________    TO(_BL),  _______,  _______,      _______,        _______,  _______,  _______,  _______,  _______,  _______
                                  
#define   _______________Ansi65__Row__GBF0____________    GRABURL,  REFRESH,  BOOKMARK1,  BOOKMARK2,  BOOKMARK3,  BOOKMARK4,  BOOKMARK5,  BOOKMARK6,  BOOKMARK7,  BOOKMARK8,  BOOKMARK9,  BOOKMARK10, _______,  _______,  RGB_TOG
#define   _______________Ansi65__Row__GBF1____________    C(S(KC_TAB)),  C(KC_TAB),  KC_MS_UP, KC_MS_BTN1, A(KC_LEFT), _______,  _______,  KC_HOME,  KC_UP,  KC_PGUP,  KC_MENU,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__GBF2____________    _______,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  A(KC_RIGHT),  KC_MS_BTN1, _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__GBF3____________    _______,  BM_BAHA,  BM_PROHARD,  BM_PROMAG,  BM_EWIYAR,  BM_RA, BM_BROD,    KC_END, _______,  KC_PGDN,  _______,  KC_MS_BTN1,   KC_MS_UP, KC_MS_BTN2
#define   _______________Ansi65__Row__GBF4____________    TO(_BL),  _______,  BM_JDROPS,      _______,        _______,  KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
                                  
#define   _______________Ansi65__Row__MSC0____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row__MSC1____________    _______, S(KC_1),    S(KC_2),   S(KC_3),  S(KC_4),  S(KC_5),    S(KC_6),     S(KC_7),    S(KC_8),    S(KC_9),  KC_MINUS,    S(KC_MINS),  S(KC_EQL),  _______,  _______
#define   _______________Ansi65__Row__MSC2____________    _______,   KC_1,  KC_2,  KC_3,  KC_4, KC_5,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_UP,  _______,  _______,    _______
#define   _______________Ansi65__Row__MSC3____________    _______,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
#define   _______________Ansi65__Row__MSC4____________    TO(_BL),  _______,  _______,      _______,        _______,  _______,  _______,  _______,  _______,  _______
                                  
#define   _______________Ansi65__Row___FN0____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row___FN1____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define   _______________Ansi65__Row___FN2____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______
#define   _______________Ansi65__Row___FN3____________    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
#define   _______________Ansi65__Row___FN4____________    TO(_BL),  _______,  _______,      _______,        _______,  _______,  _______,  _______,  _______,  _______

/* Single 4x4 board only
 * .-----------------------------------.
 * |   7    |   8    |   9    |  BSPC  |
 * |--------+--------+--------+--------|
 * |   4    |   5    |   6    | SPACE  |
 * |--------+--------+--------+--------|
 * |   1    |   2    |   3    | ENTER  |
 * |--------+--------+--------+--------|
 * |   0    |/ //_GK |   .    |   -    |
 * '-----------------------------------'
 */

#define _______________NUMPAD_Row__0_______________  KC_KP_7, KC_KP_8, KC_KP_9,   KC_BSPC
#define _______________NUMPAD_Row__1_______________  KC_KP_4, KC_KP_5, KC_KP_6,   KC_SPC
#define _______________NUMPAD_Row__2_______________  KC_KP_1, KC_KP_2, KC_KP_3,   KC_PENT
#define _______________NUMPAD_Row__3_______________  KC_KP_0, TD(LYR_TAP_DANCE), KC_KP_DOT, KC_PMNS






















/* Gherkin
 * .-----------------------------------------------------------------------------------------.
 * | Q//ESC | W      | E      | R      | T      | Y      | U      | I      | O      | P      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | A      | S      | D      | F      | G      | H      | J      | K      | L      | SPACE  |
 * |        |        |        |        |        |        |        |        |        |SFThold |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Z      | X      | C      | V/gNUM | B/gETC |  N/Fn  | M/gDIR | ,/GUI  | ./ALT  | BSPC   |
 * | SFThold|        |        |        |        |        |        |        |        |CTRLhold|
 * '-----------------------------------------------------------------------------------------'
 */
//#define _______________Gherkin_Row_0_______________			TD(TD_Q_ESC),	KC_W,	KC_E, 	KC_R, 			KC_T, 			KC_Y, 	KC_U, 			KC_I, 			KC_O, 			KC_P
//#define _______________Gherkin_Row_1_______________			KC_A, 			KC_S, 	KC_D, 	KC_F, 			KC_G, 			KC_H, 	KC_J, 			KC_K, 			KC_L, 			SFT_T(KC_SPC)
//#define _______________Gherkin_Row_2_______________			SFT_T(KC_Z), 	KC_X, 	KC_C, 	LT(gNUM,KC_V),	LT(gETC,KC_B),  LT(_FN,KC_N), 	LT(gDIR,KC_M), 	GUI_T(KC_COMM),	ALT_T(KC_DOT),	CTL_T(KC_BSPC)

/* Gherkin Directional Keys
 * .-----------------------------------------------------------------------------------------.
 * | TAB    |   up   |        | INS    |  CTRL  | SHIFT  | PgUp   | HOME   |  -     |  =     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | left   |  down  | right  | PrScr  | SHIFT  |  CTRL  | PgDn   | END    |  [     |  ]     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | P-Brk  |        |        |        |        |        |        | RGUI   | ALT    |  /     |
 * '-----------------------------------------------------------------------------------------'
 */

//#define _______________Gherkin_DIR_0_______________			KC_TAB,	 KC_UP,   _______, KC_INS,  KC_LCTL, KC_RSFT, KC_PGUP, KC_HOME, KC_MINS, KC_EQL
//#define _______________Gherkin_DIR_1_______________			KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_LSFT, KC_RCTL, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC
//#define _______________Gherkin_DIR_2_______________			KC_PAUS, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_LALT, KC_SLSH

/* Gherkin Numbers
 * .-----------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | F11    | F12    |        |        |        | ENTER  | SHIFT  | GUI    | ./ALT  | BSPC   |
 * |        |        |        |        |        |        |        |        |        |CTRLhold|
 * '-----------------------------------------------------------------------------------------'
 */
//#define _______________Gherkin_NUM_0_______________			KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_F9,         KC_F10
//#define _______________Gherkin_NUM_1_______________			KC_1,   KC_2,   KC_3,	KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,          KC_0
//#define _______________Gherkin_NUM_2_______________			KC_F11, KC_F12, _______,_______, _______, KC_ENT, KC_RSFT, KC_RGUI, ALT_T(KC_DOT), CTL_T(KC_BSPC)

/* Gherkin Et Cetera
 * .-----------------------------------------------------------------------------------------.
 * |  `     | mUP    |        |   ESC  | RESET  | SHIFT  | mScrDn | mScrUp |        |  \     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | mLeft  | mDown  | mRight |        | SHIFT  | mBtn3  | mBtn1  | mBtn2  |  ;     |  '     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Sft//Cp| CAPS   |        |        |        | C-A-D  | mScrL  | mScrR  | ALT    |  DEL   |
 * '-----------------------------------------------------------------------------------------'
 */
//#define _______________Gherkin_ETC_0_______________			KC_GRV, 		KC_MS_U, _______,KC_ESC,  QK_BOOT, KC_RSFT, 			KC_WH_D, KC_WH_U, _______, KC_BSLS
//#define _______________Gherkin_ETC_1_______________			KC_MS_L, 		KC_MS_D, KC_MS_R,_______, KC_LSFT, KC_BTN3, 			KC_BTN1, KC_BTN2, KC_SCLN, KC_QUOT
//#define _______________Gherkin_ETC_2_______________			TD(TD_SFT_CAPS),KC_CAPS, _______,_______, _______, LALT(LCTL(KC_DEL)),	KC_WH_L, KC_WH_R, KC_LALT, KC_DEL

/* Gherkin-Like
 * .-----------------------------------------------------------------------------------------------------------.
 * | ESC    | Q//ESC | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BSPC   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | SPACE  |  '     |
 * |        |        |        |        |        |        |        |        |        |        |SFThold |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |SFT/CAPS| Z      | X      | C      | V/NUM  | B/ETC  | N/Fn   | M/DIR  | ,/GUI  | ./ALT  | BSPC   | ENT/SFT|
 * |        |SFThold |        |        |        |        |        |        |        |        |CTRLhold|        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  | LGUI   | ALT    | ONEHAND|  NUM   | ETC    | SPACE  |  DIR   | RGUI   | ALT    | DEL    | CTRL   |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define _______________GherkinLike_0_______________     KC_ESC, _______________Gherkin_Row_0_______________, KC_BSPC
//#define _______________GherkinLike_1_______________     KC_TAB, _______________Gherkin_Row_1_______________, KC_QUOT
//#define _______________GherkinLike_2_______________     TD(TD_SFT_CAPS), SFT_T(KC_Z), KC_X, KC_C, LT(NUM, KC_V),LT(ETC, KC_B),LT(_FN,KC_N), LT(DIR, KC_M), GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_BSPC), SFT_T(KC_ENT)
//#define _______________GherkinLike_3_______________     KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, NUMBER, ETCETERA, KC_SPC,DIRECTION, KC_RGUI, KC_RALT, KC_DEL, KC_RCTL
//#define _______________GherkinLike_3_OneHand_______     KC_LCTL, KC_LGUI, KC_LALT, ONEHAND, NUMBER, ETCETERA, KC_SPC,DIRECTION, KC_RGUI, KC_RALT, ONEHAND, KC_RCTL



/* SUPRA
 * .-----------------------------------------------------------------------------------------------------------.
 * | RESET  | TAB    |   up   |        | INS    | CTRL   | SHIFT  | PgUp   | Home   |   -    |   =    |  DEL   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |  left  |  down  | right  | PrScr  | SHIFT  | CTRL   | PgDn   | End    |   [    |   ]    |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | P-Brk  |        |        |        |        |        |        | RGUI   | ALT    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define ________________SUPRA_Row_0________________   QK_BOOT, KC_TAB,  KC_UP,   _______, KC_INS,  KC_LCTL, KC_RSFT, KC_PGUP, KC_HOME, KC_MINS, KC_EQL,  KC_DEL
//#define ________________SUPRA_Row_1________________   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_LSFT, KC_RCTL, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_BSLS
//#define ________________SUPRA_Row_2________________   _______, KC_PAUS, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_RALT, _______, _______
//#define ________________SUPRA_Row_3________________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* SUBTER
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    |  DEL   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |    `   | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F11    | F12    |        |        |        |        |        | RGUI   | ./ALT  | BSPC   |        |
 * |        |        |        |        |        |        |        |        |        |        |CTRLhold|	       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | gherkin|        |        |        | ENTER  | SHIFT  |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define _______________SUBTER_Row__0_______________   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,  KC_F9,			KC_F10,			KC_DEL
//#define _______________SUBTER_Row__1_______________   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,   KC_9, 			KC_0,    		_______
//#define _______________SUBTER_Row__2_______________   _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______,  KC_RGUI,ALT_T(KC_DOT),  	CTL_T(KC_BSPC), _______
//#define _______________SUBTER_Row__3_______________   _______, _______, GHERKIN, _______, _______, _______, KC_ENT,  KC_LSFT,  _______,_______,			_______,		_______

/* Gherkin-Like Numbers
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | BSPC |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F11    | F12    |        |        |        | ENTER  | SHIFT  | RGUI   | ./ALT  | BSPC   |        |
 * |        |        |        |        |        |        |        |        |        |        |CTRLhold|	  	   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | ENTER  | SHIFT  | RGUI   |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define _______________NUMBERS_Row_0_______________   _______, _______________Gherkin_NUM_0_______________,  KC_BSPC
//#define _______________NUMBERS_Row_1_______________   _______, _______________Gherkin_NUM_1_______________,  _______
//#define _______________NUMBERS_Row_2_______________   _______, _______________Gherkin_NUM_2_______________,  _______
//#define _______________NUMBERS_Row_3_______________   _______, _______, _______, _______, _______, _______, KC_ENT, KC_RSFT, KC_RGUI, _______, _______, _______


/* Gherkin-Like Directional Keys
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | TAB    |   up   |        | INS    | CTRL   | SHIFT  | PgUp   | HOME   |  -     |  =     | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | left   |  down  | right  | PrScr  | SHIFT  | CTRL   | PgDn   | END    |  [     |  ]     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | P-Brk  |        |        |        |        |        |        | RGUI   | ALT    |  /     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | qwerty |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define _____________DIRECTIONS_Row__0_____________   _______, _______________Gherkin_DIR_0_______________, KC_DEL
//#define _____________DIRECTIONS_Row__1_____________   _______, _______________Gherkin_DIR_1_______________, _______
//#define _____________DIRECTIONS_Row__2_____________   _______, _______________Gherkin_DIR_2_______________, _______
//#define _____________DIRECTIONS_Row__3_____________   _______, _______, QWERTY, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* Gherkin-Like Et Cetera
 * .-----------------------------------------------------------------------------------------------------------.
 * |        |  `     | mUP    |        |        | RESET  | SHIFT  | mScrDn | mScrUp |        |  \     | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | mLeft  | mDown  | mRight |        | SHIFT  | mBtn3  | mBtn1  | mBtn2  |  ;     |  '     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | Sft//Cp|        |        |        |        | C-A-D  |mScrLeft| mScrRt | ALT    |  DEL   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | C-A-D  |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
//#define ______________ETCETERA_Row__0______________   _______, _______________Gherkin_ETC_0_______________, KC_DEL
//#define ______________ETCETERA_Row__1______________   _______, _______________Gherkin_ETC_1_______________, _______
//#define ______________ETCETERA_Row__2______________   _______, _______________Gherkin_ETC_2_______________, _______
//#define ______________ETCETERA_Row__3______________   _______, _______, _______, _______, _______, _______, LALT(LCTL(KC_DEL)), _______, _______, _______, _______, _______



/* Gherkin FN/Lighting
 * .-----------------------------------------------------------------------------------------------------.
 * | BL_breathe | BL_brite- | BL_brite+ | BL_toggle | BL_briteCyc | BL_briteMax |     |     |     |      |
 * |------------+-----------+-----------+-----------+-------------+-------------+-----+-----+-----+------|
 * | UG_breathe | UG_brite- | UG_brite+ | UG_toggle | UG_modeCycle|             |     |     |     |      |
 * |------------+-----------+-----------+-----------+-------------+-------------+-----+-----+-----+------|
 * |  UG_hue-   | UG_hue+   |  UG_sat-  |  UG_sat+  |             |             |     |     |     |QWERTY|
 * '-----------------------------------------------------------------------------------------------------'
 */
//#define _______________Gherkin_FN_0________________			BL_BRTG, BL_DOWN, BL_UP,   BL_TOGG, BL_STEP, BL_ON,   _______, _______, _______, _______
//#define _______________Gherkin_FN_1________________			RGB_M_B, RGB_VAD, RGB_VAI, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______
//#define _______________Gherkin_FN_2________________			RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, QWERTY
