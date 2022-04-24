#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE  0 // default layer
#define NMFN  1 // numpad, function
#define SYMB  2 // symbols 
#define LMIR  3 // left mirror
#define DVRK  4 // dvorak
#define MOUS  5 // mouse keys
#define MDIA  6 // media keys
#define META  7 // keyboard control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  /   |           |   '  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |Ret/Ctrl|
 * |--------+------+------+------+------+------|  ,   |           |   .  |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   -  |   =  |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |META  | NMFN | LMIR | Opt  | Cmd  |                                       |  Up  | Down | Right|  Dn  | Left  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Back | Enter|       | VolUp|VolDn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | MOUS |       | Mute |        |      |
 *                                 | Del  |  Tab |------|       |------| Enter  | Space|
 *                                 |      |      |NMFN  |       |NMFN  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LBRC,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_SLSH,
        CTL_T(KC_ESC),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   KC_COMM,
        MO(META),       TG(NMFN),     MO(LMIR),KC_LALT,KC_LGUI,
                                              LGUI(KC_LBRC),  KC_ENT,
	                                                     MO(MOUS),
                                              KC_BSPC,KC_TAB,MO(NMFN),
        // right hand
             KC_RBRC,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_BSPC,
             KC_QUOT,  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_BSLS,
                       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  CTL_T(KC_ENT),
	     KC_DOT,   KC_N,   KC_M,   KC_MINS,KC_EQL, KC_UP,    KC_RSFT,
                               KC_RALT,KC_RGUI,KC_LEFT,KC_DOWN,  KC_RGHT,
             KC_VOLD,KC_VOLU,
             KC_MUTE,
	     MO(NMFN),KC_ENT, KC_SPC
    ),
/* Keymap 1: Numpad/ Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |MClik |           |  np- |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F11  |  F12 |  F13 | F14  | F15  |      |           |      |  np/ |   7  |   8  |   9  |SysRq |   Ins  |
 * |--------+------+------+------+------+------| RClik|           | Tab  |------+------+------+------+------+--------|
 * |  Caps  | F16  | F17  |  F18 | F19  | F20  |------|           |------| np*  |   4  |   5  |   6  | scrlk|  Ret   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LShft ( | F21  |  F22 |  F23 | F24  |KC_APP| LClik|           | np+  |   0  |   1  |   2  |   3  | PgUp | RSft ) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | Home | PgDn | End   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Frwd | Spc  |       | BrDn | BrUp |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MsLk |       | MsLk |      |      |
 *                                 |      |      |------|       |------| KEnt |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// numpad / function
[NMFN] = LAYOUT_ergodox(
       // left hand
       KC_ESC,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_BTN3,
       KC_TRNS,KC_F11,KC_F12, KC_F13, KC_F14, KC_F15, KC_BTN2,
       KC_CAPS,KC_F16,KC_F17, KC_F18, KC_F19, KC_F20,
       KC_LSPO,KC_F21,KC_F22, KC_F23, KC_F24, KC_APP,KC_BTN1,
       KC_TRNS,KC_TRNS,TG(LMIR),KC_TRNS,KC_TRNS,
                                      LGUI(KC_RBRC), KC_SPC,
                                              TG(MOUS),
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_PMNS, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_INS,
       KC_TAB,  KC_PSLS, KC_P7,    KC_P8,   KC_P9,   KC_PSCR, KC_DEL,
                KC_PAST, KC_P4,    KC_P5,   KC_P6,   KC_SCRL, KC_ENT,
       KC_PPLS, KC_P0,   KC_P1,    KC_P2,   KC_P3,   KC_PGUP, KC_RCPC,
                         KC_TRNS,  KC_TRNS, KC_HOME, KC_PGDN, KC_END,
       KC_BRID,KC_BRIU,
       TG(MOUS),
       KC_TRNS, KC_PENT, KC_TRNS
),

/* Keymap 2: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   @  |  #   |  $   |  %   |      |           |      |  ^   |   &  |  *   |  {   |  }   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SYMB] = LAYOUT_ergodox(
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


// Keymap 3: Left Mirror
/*
*,--------------------------------------------------.           ,--------------------------------------------------.
*|  Del   |  6   |  7   |  8   |  9   |  0   |  ]   |           |      |      |      |      |      |      |        |
*|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
*|   \    |   Y  |  U   |   I  |  O   |  P   |      |           |      |      |      |      |      |      |        |
*|--------+------+------+------+------+------|  '   |           |      |------+------+------+------+------+--------|
*|   Ent  |  H   |  J   |  K   |  L   |  ;   |------|           |------|      |      |      |      |      |        |
*|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*|        |  N   |  M   |  _   |  +   |      |  .   |           |      |      |      |      |      |      |        |
*`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*  |      |      |      |      |      |                                       |      |      |      |      |      |
*  `----------------------------------'                                       `----------------------------------'
*                                       ,-------------.       ,-------------.
*                                       |      |      |       |      |      |
*                                ,------|------|------|       |------+------+------.
*                                |      |      |      |       |      |      |      |
*                                |      |      |------|       |------|      |      |
*                                |      |      |      |       |      |      |      |
*                                `--------------------'       `--------------------'
*/

[LMIR] = LAYOUT_ergodox(
      KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
      KC_BSLS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_QUOT,
      KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
      KC_TRNS, KC_N,    KC_M,    KC_MINS, KC_EQL, KC_TRNS, KC_DOT,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
   // right hand
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),




/* Keymap Dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  -   |   =  |  ;   |  P   |  Y   |      |           |      |  F   |  G   |  C   |  R   |   Z  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   I  |  U   |------|           |------|  D   |  H   |   T  |  N   |   S  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   L  |  Q   |   J  |  K   |  B   |      |           |      |  M   |  W   |   V  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[DVRK] = LAYOUT_ergodox(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_MINS, KC_EQL,  KC_SCLN, KC_P,    KC_Y, KC_TRNS,
      KC_TRNS, KC_A,    KC_O,    KC_E,    KC_I,    KC_U, 
      KC_TRNS, KC_L,    KC_Q,    KC_J,    KC_K,    KC_B, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
   // right hand
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_F, KC_G, KC_C, KC_R, KC_Z, KC_TRNS,
                KC_D, KC_H, KC_T, KC_N, KC_S, KC_TRNS,
      KC_TRNS,  KC_M, KC_W, KC_V, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),


/* Keymap Mouse Layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Acc1 | Copy | Paste|NewTab|Close | Focus| Back   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Acc2 | m1   |  m2  | m3   |  m4  |  m5  |  Frwd  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| mLf  |  mDn | mUp  | mRt  | Esc  |        |
 * |--------+------+------+------+------+------|      |           | Acc3 |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | mwLf | mwDn | mwUp |  mRt |  mUp |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |  mLf |  mDn |  mRt   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  m1  |  m2  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

  [MOUS] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_ACL0,  LGUI(KC_C), LGUI(KC_V), LGUI(KC_T), LGUI(KC_W), LGUI(KC_L), LGUI(KC_LBRC),
       KC_ACL1,  KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, LGUI(KC_RBRC),
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ESC,  KC_TRNS,
       KC_ACL2,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2
   ),
 
 
  


/* Keymap 7: Keyboard control
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | BASE | SYMB | LMIR | DVRK | MOUS | MDIA |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[META] = LAYOUT_ergodox(
       KC_NO, TO(BASE), TG(2), TG(3), TG(4), TG(5), TG(6),
       KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


//end keymaps
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case NMFN:
      ergodox_right_led_1_on();
      break;
    case SYMB:
      ergodox_right_led_2_on();
      break;
    case LMIR:
      ergodox_right_led_3_on();
      break;
    case DVRK:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case MOUS:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case META:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }

};

/* Keymap X: Template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

/*[X] = LAYOUT_ergodox(
*      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
*      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*                                          KC_TRNS, KC_TRNS,
*                                                   KC_TRNS,
*                                 KC_TRNS, KC_TRNS, KC_TRNS,
*   // right hand
*      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
*      KC_TRNS, KC_TRNS,
*      KC_TRNS,
*      KC_TRNS, KC_TRNS, KC_TRNS
*  ),
*
*
*/
