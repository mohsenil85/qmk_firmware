#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE  0 // default layer
#define CLMK  1 // colemak
#define NMFN  2 // numpad, function
#define SYMB  3 // symbols 
#define LMIR  4 // left mirror
#define CRWL  5 // DCSS
#define MOUS  6 // mouse keys
#define META  7 // keyboard control

/*

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  /   |           |   '  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Del/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |Ret/Ctrl|
 * |--------+------+------+------+------+------|  ,   |           |   .  |------+------+------+------+------+--------|
 * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   -  |   =  |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |META  | Hype | LMIR | Opt  | Cmd  |                                       |  Cmd  | Opt | Right|  Dn  | Left  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Enter| Esc  |       | VolUp|VolDn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | MOUS |       | Mute |        |      |
 *                                 | Del  |  Tab |------|       |------| Enter  | SPC  |
 *                                 |      |      | NMFN |       | NMFN |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
        KC_GRV,         KC_1,    KC_2,     KC_3,    KC_4,   KC_5,   KC_LBRC,
        KC_TAB,         KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,   KC_SLSH,
        CTL_T(KC_BSPC), KC_A,    KC_S,     KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,   KC_COMM,
        MO(META),       KC_HYPR, MO(LMIR), KC_LALT, KC_LGUI,
	                                                 KC_ENT, KC_ESC,
                                                               MO(MOUS),
                                                KC_BSPC,KC_TAB,MO(NMFN),
        // right hand
             KC_RBRC, KC_6,  KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
             KC_QUOT, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
                      KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  CTL_T(KC_ENT),
	     KC_DOT,  KC_N,  KC_M,    KC_MINS, KC_EQL,  KC_UP,    KC_RSFT,
                             KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN,  KC_RGHT,
             KC_VOLD,KC_VOLU,
             KC_MUTE,
	     MO(NMFN),KC_ENT, KC_SPC

			  ),

/*

*/

/* Keymap CLMK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  q   |  w   |  f   |  p   |  g   |      |           |      |  j   |  l   |  u   |  y   |  ;   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  a   |  r   |  s   |  t   |  d   |------|           |------|  h   |  n   |  e   |  i   |  o   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  z   |  x   |  c   |  v   |  b   |      |           |      |  k   |  m   |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[CLMK] = LAYOUT_ergodox(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_TRNS,
     KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D, 
     KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                         KC_TRNS, KC_TRNS,
                                                  KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
     KC_TRNS,  KC_K,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS,
     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS
 ),

/*

*/


/* Keymap 1: Numpad/ Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |MClik |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F11  |  F12 |  F13 | F14  | F15  |      |           |      |  np+ |   7  |   8  |   9  | np*  |   Ins  |
 * |--------+------+------+------+------+------| RClik|           | Tab  |------+------+------+------+------+--------|
 * |  Caps  | F16  | F17  |  F18 | F19  | F20  |------|           |------| np-  |   4  |   5  |   6  | np/  |  Ret   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LShft ( | PrScr| SclLk| Paus |      |KC_APP| LClik|           |      |   0  |   1  |   2  |   3  | PgUp | RSft ) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | Home | PgDn | End   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Spc  |       | BrDn | BrUp |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MsLk |       | MsLk |      |      |
 *                                 |      |      |------|       |------| KEnt |      |
 *                                 |      |      | FnLk |       | FnLk |      |      |
 *                                 `--------------------'       `--------------------'
 */
// numpad / function
[NMFN] = LAYOUT_ergodox(
       // left hand
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_BTN3,
       KC_TRNS, KC_F11,  KC_F12,  KC_F13, KC_F14, KC_F15, KC_BTN2,
       KC_CAPS, KC_F16,  KC_F17,  KC_F18, KC_F19, KC_F20,
       SC_LSPO, KC_PSCR, KC_SCRL, KC_PAUS, KC_NO, KC_APP, KC_BTN1,
       KC_TRNS,KC_TRNS,TG(LMIR),KC_TRNS,KC_TRNS,
                                                  KC_LCTL, KC_SPC,
                                                         TG(MOUS),

       KC_TRNS,KC_TRNS,TG(NMFN),
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_DEL,
       KC_TAB,  KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST,  KC_INS,
                KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PSLS,  KC_ENT,
       KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PGUP,  SC_RCPC,
                         KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END,
       KC_BRID,KC_BRIU,
       TG(MOUS),
       TG(NMFN), KC_PENT, KC_TRNS
),

/*

*/

/* Keymap 2: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   @  |  #   |  $   |  %   |      |           |      |  ^   |   &  |  *   |  {   |  }   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShft/(|      |      |      |      |      |      |           |      |      |      |      |      |      |RShift/)|
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
       SC_LSPO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SC_RCPC,
                          KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/*

*/

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

/*

*/


/* Keymap Crawl
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  ,   |   .  |           |   B  |      |      |      |      |      |        |
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

[CRWL] = LAYOUT_ergodox(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_DOT,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
   // right hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_B,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),

/*

*/

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
 
 
/*

*/  
  

/* Keymap 7: Keyboard control
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BASE  | CLMK | SYMB | LMIR | CRWL | MOUS |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | MR1  | MP1  |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MR2  | MP2  |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MQ   |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |NORM  | SWAP |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |BOOTLD|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[META] = LAYOUT_ergodox(
			TO(BASE), TG(1), TG(2), TG(3), TG(4), TG(5), KC_NO, 
       KC_NO, DM_REC1, DM_PLY1, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, DM_REC2, DM_PLY2, KC_NO, KC_NO, KC_NO,
       KC_NO, DM_RSTP, KC_NO, KC_NO, KC_NO, LED_LEVEL, KC_NO,
       KC_NO, KC_NO, KC_NO, AG_NORM, AG_SWAP,
                                           QK_BOOT, KC_NO,
                                                    KC_NO,
                                  KC_NO, KC_NO, KC_NO,
    // right hand
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_NO
),

/*

*/

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
    case CRWL:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case MOUS:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case CLMK:
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

/*

*/

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
