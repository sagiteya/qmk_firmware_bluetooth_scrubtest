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
};


//Tap Dance Declarations (list of my tap dance configurations)
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

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

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
#define SG_S LT(_MISC,KC_S)
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
#define SG_AT TD(CT_F12)

//other key defines

#define SG_CAPS LCTL_T(KC_CAPS)
#define SG_SPC1 LT(_NAV,KC_SPC)  
#define SG_SPC2 LT(_NAV,KC_SPC)  
#define SG_SPC3 LT(_NAV,KC_ENT)
#define SG_SPC4 LT(_NUM,KC_BSPC)
#define SG_END  MT(MOD_LALT,KC_END)
#define SG_RSFT MT(MOD_RSFT,KC_INT1)
#define SG_SLSH MT(MOD_RSFT,KC_SLSH)
#define SG_SCLN CTL_T(KC_SEMICOLON)
#define SG_F SFT_T(KC_F) 
#define SG_J SFT_T(KC_J)
#define SG_Z CTL_T(KC_Z)

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
// Organized so we can quickly adapt and modify all of them
// at once, rather than for each keyboard, one at a time.
// And this allows for much cleaner blocks in the keymaps.

// NOTE: These are all the same length.  If you do a search/replace
//       then you need to add/remove underscores to keep the
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
#define _______________Alice65_Row__1_______________   KC_TAB,   SG_Q,    SG_W,    KC_E,     KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SG_LBRC, SG_RBRC, KC_BSPC, KC_HOME
#define _______________Alice65_Row__2_______________   SG_CAPS,  SG_A,    KC_S,    SG_D,     SG_F,    KC_G,     KC_H,    SG_J,    SG_K,    KC_L, SG_SCLN, KC_QUOT, KC_ENT,           SG_END
#define _______________Alice65_Row__3_______________   KC_LSFT,  SG_Z,    SG_X,    SG_C,     SG_V,    SG_B,     S(KC_INT1),    KC_N,    KC_M,    KC_COMM, KC_DOT,   SG_SLSH, SG_RSFT, KC_UP
#define _______________Alice65_Row__4_______________   TG(_GBF),  KC_LGUI, KC_LALT, SG_SPC1,          SG_SPC2, SG_SPC3,         SG_SPC4,  KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT 

#define _______________Alice65_Row__0NUM____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1NUM____________   S(C(KC_TAB)), C(KC_TAB), KC_MS_WH_UP, KC_MS_BTN2, KC_MS_BTN1,  KC_MS_BTN1, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, _______, _______, KC_DEL, KC_PGUP
#define _______________Alice65_Row__2NUM____________   _______,  KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_PAST, _______, KC_PGDN
#define _______________Alice65_Row__3NUM____________   _______, KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT,  SG_SLSH, _______  
#define _______________Alice65_Row__4NUM____________   KC_MS_WH_UP, KC_MS_WH_DOWN, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  


#define _______________Alice65_Row__0NAV____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1NAV____________   S(C(KC_TAB)), C(KC_TAB), KC_END, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, KC_PGUP
#define _______________Alice65_Row__2NAV____________   _______, KC_HOME, KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3NAV____________   _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN1, KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN, KC_MS_RIGHT, _______, _______  
#define _______________Alice65_Row__4NAV____________   KC_MS_WH_UP, KC_MS_WH_DOWN, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  

#define _______________Alice65_Row__0GBF____________   GRABURL,   REFRESH,  BOOKMARK1,  BOOKMARK2,  BOOKMARK3,  BOOKMARK4,    _______, _______, _______, _______, _______,   _______, _______,  RGB_TOG, _______
#define _______________Alice65_Row__1GBF____________   S(C(KC_TAB)), C(KC_TAB), KC_MS_UP,  KC_MS_BTN1,  A(KC_LEFT),  KC_F5, _______, _______,_______,_______, _______, _______, _______, KC_DEL, KC_PGUP
#define _______________Alice65_Row__2GBF____________   _______,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  A(KC_RGHT),  KC_MS_BTN1, _______, _______, _______, _______, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3GBF____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4GBF____________   TG(_GBF), _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  

#define _______________Alice65_Row__0MISC___________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1MISC___________   _______, S(KC_1),    S(KC_2),   S(KC_3),  S(KC_4),  S(KC_5),    S(KC_6),     S(KC_7),    S(KC_8),    S(KC_9),  KC_MINUS,    S(KC_MINS),  S(KC_EQL),  KC_DEL, KC_PGUP
#define _______________Alice65_Row__2MISC___________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3MISC___________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4MISC___________   _______, _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  

#define _______________Alice65_Row__0FN_____________   KC_ESC,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,    KC_F11, KC_F12,  _______, _______
#define _______________Alice65_Row__1FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, KC_PGUP
#define _______________Alice65_Row__2FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN
#define _______________Alice65_Row__3FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4FN_____________   _______, _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  

/*
#define _______________Alice65_Row__0FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
#define _______________Alice65_Row__1FN_____________   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______________Alice65_Row__2FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______________Alice65_Row__3FN_____________   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  
#define _______________Alice65_Row__4FN_____________   _______, _______, _______, _______,           _______, _______,         _______, _______,          _______, _______, _______  
*/
#define _______________Ansi65__Row__0_______________   KC_ESC,   KC_1,    KC_2,    KC_3,     KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_LBRC, KC_HOME
#define _______________Ansi65__Row__1_______________   KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_RBRC, KC_BSLS, KC_BSPC, KC_DEL
#define _______________Ansi65__Row__2_______________   KC_CAPS,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,           KC_END
#define _______________Ansi65__Row__3_______________   KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN   
#define _______________Ansi65__Row__4_______________   KC_LCTL,  KC_LGUI, KC_LALT,                              KC_SPACE,                  KC_RALT,  KC_NO,   KC_RCTL, KC_RGHT, KC_DOWN, KC_RGHT 


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
