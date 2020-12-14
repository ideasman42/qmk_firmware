/* -*- Mode:C; c-basic-offset:2; tab-width:2; indent-tabs-mode:nil; evil-indent-convert-tabs:t; -*- */

#include QMK_KEYBOARD_H
#include "version.h"

/* TODO: move outside of this file. */
#define LAYOUT_dactyl(                                                  \
                                                                        \
    k00,k01,k02,k03,k04,k05,                                            \
    k10,k11,k12,k13,k14,k15,                                            \
    k20,k21,k22,k23,k24,k25,                                            \
    k30,k31,k32,k33,k34,k35,                                            \
    k40,k41,k42,k43,k44,                                                \
                            k51,k52,                                    \
                                k53,                                    \
                        k45,k55,k54,                                    \
                                                                        \
            k06,k07,k08,k09,k0A,k0B,                                    \
            k16,k17,k18,k19,k1A,k1B,                                    \
            k26,k27,k28,k29,k2A,k2B,                                    \
            k36,k37,k38,k39,k3A,k3B,                                    \
                k47,k48,k49,k4A,k4B,                                    \
    k59,k5A,                                                            \
    k58,                                                                \
    k57,k56,k46 )                                                       \
                                                                        \
   /* matrix positions */                                               \
   {                                                                    \
     { k00, k01, k02, k03, k04, k05 }, \
     { k10, k11, k12, k13, k14, k15 }, \
     { k20, k21, k22, k23, k24, k25 }, \
     { k30, k31, k32, k33, k34, k35 }, \
     { k40, k41, k42, k43, k44, k45 }, \
     { KC_NO, k51, k52, k53, k54, k55 }, \
\
     {k06, k07, k08, k09, k0A, k0B }, \
     {k16, k17, k18, k19, k1A, k1B }, \
     {k26, k27, k28, k29, k2A, k2B }, \
     {k36, k37, k38, k39, k3A, k3B }, \
     {k46, k47, k48, k49, k4A, k4B }, \
     {k56, k57, k58, k59, k5A, KC_NO }, \
   }

#define CFQ_USE_DYNAMIC_MACRO

/* Tap layer keys for other keys. */
#define CFQ_USE_TAP_LAYER 200

#define LAYER_BASE 0 /* default layer */
#define LAYER_KPAD 1 /* keypad */
#define LAYER_MDIA 2 /* media keys */
#define LAYER_WORD 3 /* F-Keys & Words */
#define LAYER_DIRS 4 /* Arrow keys */
#define LAYER_SYMB 5 /* Symbols */
#define LAYER_BLNK 6 /* Blank. */

enum custom_keycodes {
  /* Ensure these codes start after the highest keycode defined in Quantum. */
  PLACEHOLDER = SAFE_RANGE,

  M_BRACK_IN_CBR,
  M_BRACK_IN_PRN,
  M_BRACK_IN_BRC,
  M_BRACK_IN_ANG,
  M_BRACK_OUT_CBR,
  M_BRACK_OUT_PRN,
  M_BRACK_OUT_BRC,
  M_BRACK_OUT_ANG,
  M_ARROW_RMINUS,
  M_ARROW_LMINUS,
  M_ARROW_REQL,
  M_ARROW_LEQL,
  M_QUOTE_PAIR,

  /* allow user defined words for each character:
   * use CFQ_WORD_[A-Z] defines. */
  M_WORD_A, M_WORD_B, M_WORD_C, M_WORD_D, M_WORD_E, M_WORD_F,
  M_WORD_G, M_WORD_H, M_WORD_I, M_WORD_J, M_WORD_K, M_WORD_L,
  M_WORD_M, M_WORD_N, M_WORD_O, M_WORD_P, M_WORD_Q, M_WORD_R,
  M_WORD_S, M_WORD_T, M_WORD_U, M_WORD_V, M_WORD_W, M_WORD_X,
  M_WORD_Y, M_WORD_Z,

#ifdef CFQ_USE_DYNAMIC_MACRO
  DYNAMIC_MACRO_RANGE,
#endif
};

#ifdef CFQ_USE_DYNAMIC_MACRO
#  include "dynamic_macro.h"
#else
   /* avoid ifdef's in keymap */
#  define DYN_REC_START1 KC_TRNS
#  define DYN_REC_START2 KC_TRNS
#  define DYN_MACRO_PLAY1 KC_TRNS
#  define DYN_MACRO_PLAY2 KC_TRNS
#  define DYN_REC_STOP KC_TRNS
#endif

#ifndef CFQ_WORD_A
#define CFQ_WORD_A ""
#endif
#ifndef CFQ_WORD_B
#define CFQ_WORD_B ""
#endif
#ifndef CFQ_WORD_C
#define CFQ_WORD_C ""
#endif
#ifndef CFQ_WORD_D
#define CFQ_WORD_D ""
#endif
#ifndef CFQ_WORD_E
#define CFQ_WORD_E ""
#endif
#ifndef CFQ_WORD_F
#define CFQ_WORD_F ""
#endif
#ifndef CFQ_WORD_G
#define CFQ_WORD_G ""
#endif
#ifndef CFQ_WORD_H
#define CFQ_WORD_H ""
#endif
#ifndef CFQ_WORD_I
#define CFQ_WORD_I ""
#endif
#ifndef CFQ_WORD_J
#define CFQ_WORD_J ""
#endif
#ifndef CFQ_WORD_K
#define CFQ_WORD_K ""
#endif
#ifndef CFQ_WORD_L
#define CFQ_WORD_L ""
#endif
#ifndef CFQ_WORD_M
#define CFQ_WORD_M ""
#endif
#ifndef CFQ_WORD_N
#define CFQ_WORD_N ""
#endif
#ifndef CFQ_WORD_O
#define CFQ_WORD_O ""
#endif
#ifndef CFQ_WORD_P
#define CFQ_WORD_P ""
#endif
#ifndef CFQ_WORD_Q
#define CFQ_WORD_Q ""
#endif
#ifndef CFQ_WORD_R
#define CFQ_WORD_R ""
#endif
#ifndef CFQ_WORD_S
#define CFQ_WORD_S ""
#endif
#ifndef CFQ_WORD_T
#define CFQ_WORD_T ""
#endif
#ifndef CFQ_WORD_U
#define CFQ_WORD_U ""
#endif
#ifndef CFQ_WORD_V
#define CFQ_WORD_V ""
#endif
#ifndef CFQ_WORD_W
#define CFQ_WORD_W ""
#endif
#ifndef CFQ_WORD_X
#define CFQ_WORD_X ""
#endif
#ifndef CFQ_WORD_Y
#define CFQ_WORD_Y ""
#endif
#ifndef CFQ_WORD_Z
#define CFQ_WORD_Z ""
#endif

/* lower and title capitals versions (setup at start). */
static char *cfq_word_lut[2][26] = {
  {
    CFQ_WORD_A, CFQ_WORD_B, CFQ_WORD_C, CFQ_WORD_D, CFQ_WORD_E, CFQ_WORD_F,
    CFQ_WORD_G, CFQ_WORD_H, CFQ_WORD_I, CFQ_WORD_J, CFQ_WORD_K, CFQ_WORD_L,
    CFQ_WORD_M, CFQ_WORD_N, CFQ_WORD_O, CFQ_WORD_P, CFQ_WORD_Q, CFQ_WORD_R,
    CFQ_WORD_S, CFQ_WORD_T, CFQ_WORD_U, CFQ_WORD_V, CFQ_WORD_W, CFQ_WORD_X,
    CFQ_WORD_Y, CFQ_WORD_Z,
  },
  {NULL}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * .-----------------------------------------.       .-----------------------------------------.
 * | Grv  |   !  |   @  |   #  |   $  |   %  |       |   ^  |   &  |   *  |   -  |   =  |BSpace|
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |       |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |Esc/AR|   A  |   S  |   D  |   F  |   G  |       |   H  |   J  |   K  |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |       |   N  |   M  |   ,  |   .  |  /   | Delt |
 * '------+------+------+------+------+------'       '------+------+------+------+------+------'
 *               |Super |ScrLck|                                   | PgUp | PgDn |
 *               '-------------'                                   '-------------'
 *
 *               .------+------. .-------------.  .-------------. .------+------.
 *               |Space |  [   | |   (  |   {  |  |  }   |  )   | |   ]  |Enter |
 *               '-------------' |------+------|  |------+------| '-------------'
 *                               |L1/Hom| Ctrl |  | Alt  |L2/End|
 *                               '-------------'  '-------------'
 *
 * PG/HME: HJKL for page up down, home, end.
 * Esc/Ar: HJKL for arrow keys (tab escapes)
 */

/* Keymap 0: Basic layer
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * | Grv  |   !  |   @  |   #  |   $  |   %  |        |   ^  |   &  |   *  |   -  |   =  |BSpace|
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |        |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |Esc/AR|   A  |   S  |   D  |   F  |   G  |        |   H  |   J  |   K  |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |        |   N  |   M  |   ,  |   .  |  /   | Delt |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |Super |ScrLck|      |                      |      | PgUp | PgDn |      |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |   (  |   {  |  |  }   |  )   |
 *                         .------+------+------|  |------+------+------.
 *                         |      |tap:  |   [  |  |  ]   |tap:  |      |
 *                         |Space | Home |------|  |------| End  |Enter |
 *                         |      | ~L1  | Ctrl |  | Alt  | ~L2  |      |
 *                         '--------------------'  '--------------------'
 */
[LAYER_BASE] = LAYOUT_dactyl(  // layer 0 : default
  /* left hand */
         KC_GRV,        KC_EXLM,          KC_AT,        KC_HASH,         KC_DLR,        KC_PERC,
         KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
 MO(LAYER_DIRS),           KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LSFT,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,
        KC_TRNS,        KC_TRNS,        KC_LGUI,        KC_SLCK,        KC_TRNS,
                                                                        KC_LPRN,        KC_LCBR,
                                                                                        KC_LBRC,
                                                         KC_SPC, MO(LAYER_KPAD),       KC_LCTRL,

  /* right hand */
        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINS,         KC_EQL,        KC_BSPC,
           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,        KC_BSLS,
           KC_H,           KC_J,           KC_K,           KC_L,        KC_SCLN,        KC_QUOT,
           KC_N,           KC_M,        KC_COMM,         KC_DOT,        KC_SLSH,        KC_DELT,
                        KC_TRNS,        KC_PGUP,        KC_PGDN,        KC_TRNS,        KC_TRNS,
        KC_RCBR,        KC_RPRN,
        KC_RBRC,
        KC_LALT, MO(LAYER_MDIA),         KC_ENT
    ),
/* Keymap 1: KeyPad, Locks & Bracket Pairs
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |PrtScn|ScrlLk|CapsLk|Break |      |      |        |      |NumLck|   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |  ->  |        |      |   4  |   5  |   6  |   +  |  ''  |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |   _  |        |      |   1  |   2  |   3  | Enter|      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |   .  | Enter|      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |  ()  |  {}  |  |  }{  |  )(  |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      |  []  |  |  ][  |      |      |
 *                         |      |      |------|  |------|      |  0   |
 *                         |      |      |      |  |      |      |      |
 *                         '--------------------'  '--------------------'
 */
// SYMBOLS
[LAYER_KPAD] = LAYOUT_dactyl(
  /* left hand */
     KC_PSCREEN,  KC_SCROLLLOCK,    KC_CAPSLOCK,       KC_PAUSE,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, M_ARROW_RMINUS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_UNDS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                 M_BRACK_IN_PRN, M_BRACK_IN_CBR,
                                                                                 M_BRACK_IN_BRC,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,
  /* right hand */
        KC_TRNS,        KC_NLCK,    KC_KP_SLASH, KC_KP_ASTERISK,    KC_KP_MINUS,        KC_TRNS,
        KC_TRNS,        KC_KP_7,        KC_KP_8,        KC_KP_9,     KC_KP_PLUS,        KC_TRNS,
        KC_TRNS,        KC_KP_4,        KC_KP_5,        KC_KP_6,     KC_KP_PLUS,   M_QUOTE_PAIR,
        KC_TRNS,        KC_KP_1,        KC_KP_2,        KC_KP_3,    KC_KP_ENTER,        KC_TRNS,
                        KC_TRNS,        KC_TRNS,      KC_KP_DOT,    KC_KP_ENTER,        KC_TRNS,
       M_BRACK_OUT_CBR, M_BRACK_OUT_PRN,
       M_BRACK_OUT_BRC,
       KC_TRNS,         KC_TRNS,     KC_KP_0
),
/* Keymap 2: FKeys, macro, media & mouse keys
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |      |      |      |      |      |      |        | Mute |  F10 |  F11 |  F12 |      |App   |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |        | Play |  F7  |  F8  |  F9  |      |Menu  |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|MWhlUp|        |VolUp |  F4  |  F5  |  F6  |      |Search|
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      | Rclk | Mclk | Lclk |MWhlDn|        |VolDn |  F1  |  F2  |  F3  |      |      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |  F14 |  F15 |  F16 |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                | Rec1 | Rec2 |  | MRwd | MFwd |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      | Run1 |  | MPrv |      |      |
 *                         | Stop |      |------|  |------|      | F13  |
 *                         |      |      | Run2 |  | MNxt |      |      |
 *                         '--------------------'  '--------------------'
 *
 */
// MEDIA AND MOUSE
[LAYER_MDIA] = LAYOUT_dactyl(
  /* left hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_U,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_WH_U,
        KC_TRNS,        KC_TRNS,        KC_BTN2,        KC_BTN3,        KC_BTN1,        KC_WH_D,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        DM_REC1,        DM_REC2,
                                                                                        DM_PLY1,
                                                        DM_RSTP,        KC_TRNS,        DM_PLY2,
  /* right hand */
        KC_MUTE,         KC_F10,         KC_F11,         KC_F12,        KC_TRNS,         KC_APP,
        KC_MPLY,          KC_F7,          KC_F8,          KC_F9,        KC_TRNS,        KC_MENU,
        KC_VOLU,          KC_F4,          KC_F5,          KC_F6,        KC_TRNS,  KC_WWW_SEARCH,
        KC_VOLD,          KC_F1,          KC_F2,          KC_F3,        KC_TRNS,        KC_TRNS,
                        KC_TRNS,         KC_F14,         KC_F15,         KC_F16,        KC_TRNS,
        KC_MRWD,        KC_MFFD,
        KC_MPRV,
        KC_MNXT,        KC_TRNS,         KC_F13
),
/* Keymap 3: Entire Words (one for each key) & Numbers
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |        |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |        |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |        |   H  |   J  |   K  |   L  |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |        |   N  |   M  |      |      |      |      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |      |      |  |      |      |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      |      |  |      |      |      |
 *                         |      |      |------|  |------|      |      |
 *                         |      |      |      |  |      |      |      |
 *                         '--------------------'  '--------------------'
 */
// MEDIA AND MOUSE
[LAYER_WORD] = LAYOUT_dactyl(
  /* left hand */
        KC_TRNS,           KC_1,           KC_2,           KC_3,           KC_4,            KC_5,
        KC_TRNS,       M_WORD_Q,       M_WORD_W,       M_WORD_E,       M_WORD_R,        M_WORD_T,
        KC_TRNS,       M_WORD_A,       M_WORD_S,       M_WORD_D,       M_WORD_F,        M_WORD_G,
        KC_TRNS,       M_WORD_Z,       M_WORD_X,       M_WORD_C,       M_WORD_V,        M_WORD_B,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,         KC_TRNS,
                                                                                         KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,         KC_TRNS,
  /* right hand */
           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,         KC_TRNS,
       M_WORD_Y,       M_WORD_U,       M_WORD_I,       M_WORD_O,       M_WORD_P,         KC_TRNS,
       M_WORD_H,       M_WORD_J,       M_WORD_K,       M_WORD_L,        KC_TRNS,         KC_TRNS,
       M_WORD_N,       M_WORD_M,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
),

/* Keymap 4: Arrows
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        | Left | Down | Up   |Right |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |      |      |  |      |      |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      |      |  |      |      |      |
 *                         |      |      |------|  |------|      |      |
 *                         |      |      |      |  |      |      |      |
 *                         '--------------------'  '--------------------'
 */
// MEDIA AND MOUSE
[LAYER_DIRS] = LAYOUT_dactyl(
  /* left hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,         KC_TRNS,
                                                                                         KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,         KC_TRNS,
  /* right hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_LEFT,        KC_DOWN,          KC_UP,        KC_RGHT,        KC_TRNS,         KC_TRNS,
        KC_HOME,        KC_PGDN,        KC_PGUP,         KC_END,        KC_TRNS,         KC_TRNS,
                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
),

/* Keymap 5: Blank
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |   &  |   *  |   -  |   =  |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |   ^  |   %  |   $  |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |   !  |   @  |   #  |      |      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |      |      |  |      |      |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      |      |  |      |      |      |
 *                         |      |      |------|  |------|      | Grv  |
 *                         |      |      |      |  |      |      |      |
 *                         '--------------------'  '--------------------'
 */
// Symbols.
[LAYER_SYMB] = LAYOUT_dactyl(
  /* left hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,         KC_TRNS,
                                                                                         KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,         KC_TRNS,
  /* right hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_AMPR,        KC_ASTR,        KC_MINS,         KC_EQL,         KC_TRNS,
        KC_TRNS,        KC_CIRC,        KC_PERC,         KC_DLR,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_EXLM,          KC_AT,        KC_HASH,        KC_TRNS,         KC_TRNS,
                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
),


/* Keymap 6: Blank
 *
 * .-----------------------------------------.        .-----------------------------------------.
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------|        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |      |      |      |      |      |      |
 * |------+------+------+------+------+------'        '------+------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * '----------------------------------'                      '----------------------------------'
 *                                .-------------.  .-------------.
 *                                |      |      |  |      |      |
 *                         .------+------+------|  |------+------+------.
 *                         |      |      |      |  |      |      |      |
 *                         |      |      |------|  |------|      |      |
 *                         |      |      |      |  |      |      |      |
 *                         '--------------------'  '--------------------'
 */
// Blank.
[LAYER_BLNK] = LAYOUT_dactyl(
  /* left hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,         KC_TRNS,
                                                                                         KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,         KC_TRNS,
  /* right hand */
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_HOME,        KC_PGDN,        KC_PGUP,         KC_END,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS
),

};

uint32_t layer_state_set_user(uint32_t state) {
  /* Use layer 3 when 1 & 2 are pressed. */
  state = update_tri_layer_state(state, LAYER_KPAD, LAYER_MDIA, LAYER_WORD);
  return state;
}

#ifdef CFQ_USE_TAP_LAYER
static struct {
  uint8_t time;
  uint16_t keycode;
} cfq_tap_detect;
#endif

#define WITHOUT_MODS(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

#define WITHOUT_SHIFT(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    del_mods(MOD_BIT(KC_LSFT)); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

#define WITHOUT_MOD_BITS(mods, ...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    del_mods(mods); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CFQ_USE_DYNAMIC_MACRO
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
#endif

#ifdef CFQ_USE_TAP_LAYER
  {
    bool is_tap = false;
    if (record->event.pressed) {
      cfq_tap_detect.keycode = keycode;
      cfq_tap_detect.time = 0;
    }
    else {
      if (cfq_tap_detect.time < CFQ_USE_TAP_LAYER) {
        /* Released within tap-time. */
        if (cfq_tap_detect.keycode == keycode) {
          /* Pressed and released the same key within the tap-time. */
          is_tap = true;
        }
        cfq_tap_detect.time = CFQ_USE_TAP_LAYER;
      }
    }

    if (is_tap) {
      if (keycode == MO(LAYER_KPAD)) {
        if ((layer_state & ~(1UL << LAYER_KPAD)) == 0){
          // WITHOUT_SHIFT({SEND_STRING("_");});
          SEND_STRING(SS_TAP(X_HOME));
          return true;
        }
      }
      else if (keycode == MO(LAYER_MDIA)) {
        if ((layer_state & ~(1UL << LAYER_MDIA)) == 0) {
          // WITHOUT_MODS({SEND_STRING("->");});
          SEND_STRING(SS_TAP(X_END));
          return true;
        }
      }
      else if (keycode == MO(LAYER_DIRS)) {
        if ((layer_state & ~(1UL << LAYER_DIRS)) == 0) {
          SEND_STRING(SS_TAP(X_ESCAPE));
          return true;
        }
      }
#if 0 /* Interesting but not good for gaining new muscle memory. */
      else if (keycode == KC_LALT) {
        SEND_STRING(SS_UP(X_LATL) SS_TAP(X_DELETE));
        WITHOUT_MOD_BITS(MOD_BIT(KC_LALT), {SEND_STRING(SS_TAP(X_DELETE));});
        return true;
      }
      else if (keycode == KC_LCTL) {
        WITHOUT_MOD_BITS(MOD_BIT(KC_LCTL), {SEND_STRING(SS_TAP(X_BSPACE));});
        return true;
      }
#endif

    }
  }
#endif

  switch (keycode) {
    /* dynamically generate these. */
    case M_BRACK_IN_CBR:  /* {} */
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACK_IN_PRN:  /* () */
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACK_IN_BRC:  /* [] */
      if (record->event.pressed) {
        if (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) {
          WITHOUT_MODS({
            SEND_STRING("{}" SS_TAP(X_LEFT));
          });
        }
        else {
          SEND_STRING("[]" SS_TAP(X_LEFT));
        }
        return false;
      }
      break;
    case M_BRACK_IN_ANG:  /* <> */
      if (record->event.pressed) {
        SEND_STRING("<>" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACK_OUT_CBR:  /* }{ */
      if (record->event.pressed) {
        SEND_STRING("}{" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACK_OUT_PRN:  /* )( */
      if (record->event.pressed) {
        SEND_STRING(")(" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACK_OUT_BRC:  /* ][ */
      if (record->event.pressed) {
        if (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) {
          WITHOUT_MODS({
            SEND_STRING("}{" SS_TAP(X_LEFT));
          });
        }
        else {
          SEND_STRING("][" SS_TAP(X_LEFT));
        }
        return false;
      }
      break;
    case M_BRACK_OUT_ANG:  /* >< */
      if (record->event.pressed) {
        SEND_STRING("><" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_ARROW_LMINUS:  /* <- */
      if (record->event.pressed) {
        SEND_STRING("<-");
        return false;
      }
      break;
    case M_ARROW_RMINUS:  /* -> */
      if (record->event.pressed) {
        SEND_STRING("->");
        return false;
      }
      break;
    case M_ARROW_LEQL:  /* <= */
      if (record->event.pressed) {
        SEND_STRING("<=");
        return false;
      }
      break;
    case M_ARROW_REQL:  /* => */
      if (record->event.pressed) {
        SEND_STRING("=>");
        return false;
      }
      break;
    case M_QUOTE_PAIR:  /* '' */
      if (record->event.pressed) {
        if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
          const uint8_t mods = keyboard_report->mods;
          SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_QUOTE));

          if (mods & MOD_BIT(KC_LSFT)) {SEND_STRING(SS_UP(X_LSHIFT));}
          if (mods & MOD_BIT(KC_RSFT)) {SEND_STRING(SS_UP(X_RSHIFT));}

          SEND_STRING(SS_TAP(X_LEFT));

          if (mods & MOD_BIT(KC_LSFT)) {SEND_STRING(SS_DOWN(X_LSHIFT));}
          if (mods & MOD_BIT(KC_RSFT)) {SEND_STRING(SS_DOWN(X_RSHIFT));}

          return false;
        }
        else {
          SEND_STRING("''" SS_TAP(X_LEFT));
          return false;
        }

        return false;
      }
      break;

#ifdef CFQ_USE_SHIFT_QUOTES
    case KC_LSHIFT:  /* '' */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_RSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("''" SS_TAP(X_LEFT) SS_DOWN(X_RSHIFT) SS_DOWN(X_LSHIFT));
          });
        return false;
      }
      break;
    case KC_RSHIFT:  /* "" */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_LSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("\x22\x22" SS_TAP(X_LEFT) SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT));
          });
        return false;
      }
      break;
#endif  /* CFQ_USE_SHIFT_QUOTES */
    case M_WORD_A...M_WORD_Z:
    {
      uint8_t shift_index = (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) ? 1 : 0;
      const char *word = cfq_word_lut[shift_index][keycode - M_WORD_A];
      if (record->event.pressed) {
        if (*word) {
          WITHOUT_MODS({
              send_string(word);
            });
        }
        return false;
      }
      break;
    }
  }

  return true;
}


/* Runs just one time when the keyboard initializes. */
void matrix_init_user(void) {

}

/* Runs constantly in the background, in a loop. */
void matrix_scan_user(void) {

#ifdef CFQ_USE_TAP_LAYER
  if (cfq_tap_detect.time != CFQ_USE_TAP_LAYER) {
    cfq_tap_detect.time++;
  }
#endif

}
