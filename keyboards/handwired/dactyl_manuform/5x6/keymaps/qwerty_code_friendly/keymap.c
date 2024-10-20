/* -*- Mode:C; c-basic-offset:2; tab-width:2; indent-tabs-mode:nil; evil-indent-convert-tabs:t; -*- */

// qmk compile -kb handwired/dactyl_manuform/5x6 -km qwerty_code_friendly -dfu

#include QMK_KEYBOARD_H
#include "version.h"

#define CFQ_USE_DYNAMIC_MACRO
#define CFQ_USE_COLEMAK_MOD_DH

/* Tap layer keys for other keys. */
#define CFQ_USE_TAP_LAYER 200
// #define CFQ_USE_TAP_LAYER_PENDING

enum layer_names {
    LAYER_BASE = 0, /* default layer */
    LAYER_KPAD = 1, /* keypad */
    LAYER_DIRS = 2, /* directional keys */
    LAYER_WORD = 3, /* F-Keys & Words */
    LAYER_FKEY = 4, /* Function keys. */

    LAYER_SYMB = 5, /* Symbols */

    LAYER_BASE_COLMAK_DH = 8, /* Colmak layer. */

    LAYER_BLNK = 6, /* Blank. */
};

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
    M_BTICK_PAIR,

    M_SPEECH2TXT_A,
    M_SPEECH2TXT_B,

#ifdef CFQ_USE_COLEMAK_MOD_DH
    M_COLMAK_SWAP,
#endif

    /* Hyper + Arrow keys. */
    M_HYP_L,
    M_HYP_R,
    M_HYP_U,
    M_MYP_D,

    /* allow user defined words for each character:
     * use CFQ_WORD_[A-Z] defines. */
    M_WORD_A,
    M_WORD_B,
    M_WORD_C,
    M_WORD_D,
    M_WORD_E,
    M_WORD_F,
    M_WORD_G,
    M_WORD_H,
    M_WORD_I,
    M_WORD_J,
    M_WORD_K,
    M_WORD_L,
    M_WORD_M,
    M_WORD_N,
    M_WORD_O,
    M_WORD_P,
    M_WORD_Q,
    M_WORD_R,
    M_WORD_S,
    M_WORD_T,
    M_WORD_U,
    M_WORD_V,
    M_WORD_W,
    M_WORD_X,
    M_WORD_Y,
    M_WORD_Z,

#ifdef CFQ_USE_DYNAMIC_MACRO
    DYNAMIC_MACRO_RANGE,
#endif
};

#ifdef CFQ_USE_DYNAMIC_MACRO
/* pass. */
#else
/* avoid ifdef's in keymap */
#    define DYN_REC_START1 KC_TRNS
#    define DYN_REC_START2 KC_TRNS
#    define DYN_MACRO_PLAY1 KC_TRNS
#    define DYN_MACRO_PLAY2 KC_TRNS
#    define DYN_REC_STOP KC_TRNS
#endif

#ifndef CFQ_WORD_A
#    define CFQ_WORD_A ""
#endif
#ifndef CFQ_WORD_B
#    define CFQ_WORD_B ""
#endif
#ifndef CFQ_WORD_C
#    define CFQ_WORD_C ""
#endif
#ifndef CFQ_WORD_D
#    define CFQ_WORD_D ""
#endif
#ifndef CFQ_WORD_E
#    define CFQ_WORD_E ""
#endif
#ifndef CFQ_WORD_F
#    define CFQ_WORD_F ""
#endif
#ifndef CFQ_WORD_G
#    define CFQ_WORD_G ""
#endif
#ifndef CFQ_WORD_H
#    define CFQ_WORD_H ""
#endif
#ifndef CFQ_WORD_I
#    define CFQ_WORD_I ""
#endif
#ifndef CFQ_WORD_J
#    define CFQ_WORD_J ""
#endif
#ifndef CFQ_WORD_K
#    define CFQ_WORD_K ""
#endif
#ifndef CFQ_WORD_L
#    define CFQ_WORD_L ""
#endif
#ifndef CFQ_WORD_M
#    define CFQ_WORD_M ""
#endif
#ifndef CFQ_WORD_N
#    define CFQ_WORD_N ""
#endif
#ifndef CFQ_WORD_O
#    define CFQ_WORD_O ""
#endif
#ifndef CFQ_WORD_P
#    define CFQ_WORD_P ""
#endif
#ifndef CFQ_WORD_Q
#    define CFQ_WORD_Q ""
#endif
#ifndef CFQ_WORD_R
#    define CFQ_WORD_R ""
#endif
#ifndef CFQ_WORD_S
#    define CFQ_WORD_S ""
#endif
#ifndef CFQ_WORD_T
#    define CFQ_WORD_T ""
#endif
#ifndef CFQ_WORD_U
#    define CFQ_WORD_U ""
#endif
#ifndef CFQ_WORD_V
#    define CFQ_WORD_V ""
#endif
#ifndef CFQ_WORD_W
#    define CFQ_WORD_W ""
#endif
#ifndef CFQ_WORD_X
#    define CFQ_WORD_X ""
#endif
#ifndef CFQ_WORD_Y
#    define CFQ_WORD_Y ""
#endif
#ifndef CFQ_WORD_Z
#    define CFQ_WORD_Z ""
#endif

/* lower and title capitals versions (setup at start). */
static char *cfq_word_lut[2][26] = {
    {
        /* clang-format off */
    CFQ_WORD_A, CFQ_WORD_B, CFQ_WORD_C, CFQ_WORD_D, CFQ_WORD_E, CFQ_WORD_F,
    CFQ_WORD_G, CFQ_WORD_H, CFQ_WORD_I, CFQ_WORD_J, CFQ_WORD_K, CFQ_WORD_L,
    CFQ_WORD_M, CFQ_WORD_N, CFQ_WORD_O, CFQ_WORD_P, CFQ_WORD_Q, CFQ_WORD_R,
    CFQ_WORD_S, CFQ_WORD_T, CFQ_WORD_U, CFQ_WORD_V, CFQ_WORD_W, CFQ_WORD_X,
    CFQ_WORD_Y, CFQ_WORD_Z,
  },
    /* clang-format on */
    {NULL},
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * .-----------------------------------------.       .-----------------------------------------.
 * | Grv  |   !  |   @  |   #  |   $  |   %  |       |   ^  |   &  |   *  |   -  |   =  |BSpace|
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |       |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |       |   H  |   J  |   K  |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |       |   N  |   M  |   ,  |   .  |  /   | Delt |
 * '------+------+------+------+------+------'       '------+------+------+------+------+------'
 *               |SPTT_A|SPTT_B|                                   |   ?  |   ?  |
 *               '-------------'                                   '-------------'
 *
 *               .------+------. .-------------.   .-------------. .------+------.
 *               |Space |   (  | |   [  | Alt/{|   |}/~L4 |  ]   | |  )   |Enter |
 *               '-------------' |------+------|   |------+------| '-------------'
 *                               |L1/Hom| Ctrl |   | LGui |L2/End|
 *                               '-------------'   '-------------'
 */
  [LAYER_BASE] = LAYOUT_5x6(
         KC_GRV,        KC_EXLM,          KC_AT,        KC_HASH,         KC_DLR,        KC_PERC, /*  */        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINS,         KC_EQL,        KC_BSPC,
         KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T, /*  */           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,        KC_BSLS,
         KC_ESC,           KC_A,           KC_S,           KC_D,           KC_F,           KC_G, /*  */           KC_H,           KC_J,           KC_K,           KC_L,        KC_SCLN,        KC_QUOT,
        KC_LSFT,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B, /*  */           KC_N,           KC_M,        KC_COMM,         KC_DOT,        KC_SLSH,         KC_DEL,
                                 M_SPEECH2TXT_A, M_SPEECH2TXT_B,                                 /*  */                                         KC_STOP,       KC_EXEC,
                                                                         KC_SPC,        KC_LPRN, /*  */        KC_RPRN,         KC_ENT,
                                                                        KC_LBRC,        KC_LALT, /*  */ MO(LAYER_FKEY),        KC_RBRC,
                                                                 MO(LAYER_KPAD),        KC_LCTL, /*  */        KC_LGUI,  MO(LAYER_DIRS)
  ),

/* Keymap 2: FKeys, macro, media & mouse keys
 *
 * .-----------------------------------------.       .-----------------------------------------.
 * |      |      |      |      |      |      |       |      |MWhlDn|MWhlUp|      |      |App   |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |       | Home | PgDn | PgUp | End  |      |Menu  |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      |       | Left | Down | Up   |Right |      |Search|
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      | Rclk | Mclk | Lclk |      |       | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------'       '------+------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * '----------------------------------'                     '----------------------------------'
 *               .------+------. .-------------.   .-------------. .------+------.
 *               | Stop |      | | Rec1 | Rec2 |   | Run1 | Run2 | |      |      |
 *               '-------------' |------+------|   |------+------| '-------------'
 *                               |      |      |   |      |      |
 *                               '-------------'   '-------------'
 */
  [LAYER_DIRS] = LAYOUT_5x6(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_WH_D,        KC_WH_U,        KC_TRNS,        KC_TRNS,         KC_APP,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_U,        KC_TRNS,        KC_TRNS, /* */        KC_HOME,        KC_PGDN,        KC_PGUP,         KC_END,        KC_TRNS,        KC_MENU,
        KC_TRNS,        KC_TRNS,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_TRNS, /* */        KC_LEFT,        KC_DOWN,          KC_UP,        KC_RGHT,        KC_TRNS,  KC_WWW_SEARCH,
        KC_TRNS,        KC_TRNS,        KC_BTN2,        KC_BTN3,        KC_BTN1,        KC_TRNS, /* */        M_HYP_L,        M_MYP_D,        M_HYP_U,        M_HYP_R,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,                                 /* */                                        KC_TRNS,        KC_TRNS,
                                                                        DM_RSTP,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        DM_REC1,        DM_REC2, /* */        DM_PLY1,        DM_PLY2,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS 
  ),

/* Keymap 1: KeyPad, Locks & Bracket Pairs
 *
 * .-----------------------------------------.       .-----------------------------------------.
 * |  ``  |PrtScn|ScrlLk|CapsLk|Break | MPrv |       |      |NumLck|   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      |      |      | MNxt |       |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |COLMAK|      |  -   |  _   |  ->  |VolUp |       |      |   4  |   5  |   6  |   +  |  ''  |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      |      | Play |VolDn |       |      |   1  |   2  |   3  | Enter|      |
 * '------+------+------+------+------+------'       '------+------+------+------+------+------'
 *               | MRwd | MFwd |                                   |      |   .  |
 *               '-------------'                                   '-------------'
 *               .------+------. .-------------.   .-------------. .------+------.
 *               |      |  ()  | |  []  |Alt/{}|   |  }{  |  ][  | |  )(  |  0   |
 *               '-------------' |------+------|   |------+------| '-------------'
 *                               |      |      |   |      |      |
 *                               '-------------'   '-------------'
 */
  [LAYER_KPAD] = LAYOUT_5x6(
   M_BTICK_PAIR,KC_PRINT_SCREEN, KC_SCROLL_LOCK,   KC_CAPS_LOCK,       KC_PAUSE,        KC_MPRV, /* */        KC_TRNS,    KC_NUM_LOCK,    KC_KP_SLASH, KC_KP_ASTERISK,    KC_KP_MINUS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MNXT, /* */        KC_TRNS,        KC_KP_7,        KC_KP_8,        KC_KP_9,     KC_KP_PLUS,        KC_TRNS, 
  M_COLMAK_SWAP,        KC_TRNS,        KC_MINS,        KC_UNDS, M_ARROW_RMINUS,        KC_VOLU, /* */        KC_TRNS,        KC_KP_4,        KC_KP_5,        KC_KP_6,     KC_KP_PLUS,   M_QUOTE_PAIR, 
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MPLY,        KC_VOLD, /* */        KC_TRNS,        KC_KP_1,        KC_KP_2,        KC_KP_3,    KC_KP_ENTER,        KC_TRNS,
                                        KC_MRWD,        KC_MFFD,                                 /* */                                        KC_TRNS,      KC_KP_DOT,
                                                                        KC_TRNS, M_BRACK_IN_PRN, /* */M_BRACK_OUT_PRN,        KC_KP_0,
                                                                 M_BRACK_IN_BRC,        KC_TRNS, /* */        KC_TRNS,M_BRACK_OUT_BRC,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS 
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
  [LAYER_WORD] = LAYOUT_5x6(
        KC_TRNS,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5, /* */           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,        KC_TRNS,
        KC_TRNS,       M_WORD_Q,       M_WORD_W,       M_WORD_E,       M_WORD_R,       M_WORD_T, /* */       M_WORD_Y,       M_WORD_U,       M_WORD_I,       M_WORD_O,       M_WORD_P,        KC_TRNS,
        KC_TRNS,       M_WORD_A,       M_WORD_S,       M_WORD_D,       M_WORD_F,       M_WORD_G, /* */       M_WORD_H,       M_WORD_J,       M_WORD_K,       M_WORD_L,        KC_TRNS,        KC_TRNS,
        KC_TRNS,       M_WORD_Z,       M_WORD_X,       M_WORD_C,       M_WORD_V,       M_WORD_B, /* */       M_WORD_N,       M_WORD_M,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,                                 /* */                                        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS 
  ),

/* Keymap 4: F-Keys
 *
 * .-----------------------------------------.       .-----------------------------------------.
 * |      |      |      |      |      |      |       |      |  F10 |  F11 |  F12 |      |      |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |  F1  |  F2  |  F3  |      |      |
 * |------+------+------+------+------+------'       '------+------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * '----------------------------------'                     '----------------------------------'
 *               .------+------. .-------------.   .-------------. .------+------.
 *               |      |      | |      |      |   |      |      | |      |      |
 *               '-------------' |------+------|   |------+------| '-------------'
 *                               |      |      |   |      |      |
 *                               '-------------'   '-------------'
 */
  [LAYER_FKEY] = LAYOUT_5x6(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,         KC_F10,         KC_F11,         KC_F12,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,          KC_F7,          KC_F8,          KC_F9,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,          KC_F4,          KC_F5,          KC_F6,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,          KC_F1,          KC_F2,          KC_F3,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,                                 /* */                                        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS 
  ),
  
  [LAYER_BLNK] = LAYOUT_5x6(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                        KC_TRNS,        KC_TRNS,                                 /* */                                        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS, /* */        KC_TRNS,        KC_TRNS 
  ),
};

/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    /* Use layer 3 when 1 & 2 are pressed. */
    state = update_tri_layer_state(state, LAYER_KPAD, LAYER_DIRS, LAYER_WORD);
    return state;
}

#ifdef CFQ_USE_TAP_LAYER
static struct {
    uint8_t  time;
    uint16_t keycode;
#    ifdef CFQ_USE_TAP_LAYER_PENDING
    bool pending;
#    endif
} cfq_tap_detect;

#    define IS_KEYCODE_PENDING(kc) ((kc == KC_LALT) || (kc == KC_LCTL) || (kc == KC_LGUI) || (kc == KC_RGUI))

#endif

#define WITHOUT_MODS(...)                   \
    do {                                    \
        uint8_t _real_mods = get_mods();    \
        clear_mods();                       \
        {__VA_ARGS__} set_mods(_real_mods); \
    } while (0)

#define WITHOUT_SHIFT(...)                       \
    do {                                         \
        uint8_t _real_mods = get_mods();         \
        if (_real_mods & MOD_BIT(KC_LSFT)) {     \
            SEND_STRING(SS_UP(X_LEFT_SHIFT));    \
        }                                        \
        if (_real_mods & MOD_BIT(KC_RSFT)) {     \
            SEND_STRING(SS_UP(X_RIGHT_SHIFT));   \
        }                                        \
        { __VA_ARGS__ }                          \
        if (_real_mods & MOD_BIT(KC_LSFT)) {     \
            SEND_STRING(SS_DOWN(X_LEFT_SHIFT));  \
        }                                        \
        if (_real_mods & MOD_BIT(KC_RSFT)) {     \
            SEND_STRING(SS_DOWN(X_RIGHT_SHIFT)); \
        }                                        \
    } while (0)

#define WITHOUT_MOD_BITS(mods, ...)         \
    do {                                    \
        uint8_t _real_mods = get_mods();    \
        del_mods(mods);                     \
        {__VA_ARGS__} set_mods(_real_mods); \
    } while (0)

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
#ifdef RGBSPS_ENABLE
    led_set_default_layer_indicator();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CFQ_USE_TAP_LAYER
    {
#    ifdef CFQ_USE_TAP_LAYER_PENDING
        /* If we press a key while awaiting a tap event,
         * favor the hold action so we can use this for modifiers. */
        if (record->event.pressed && cfq_tap_detect.pending) {
            register_code(cfq_tap_detect.keycode);
            cfq_tap_detect.pending = false;
        }
#    endif

        bool is_tap = false;
        if (record->event.pressed) {
            cfq_tap_detect.keycode = keycode;
            cfq_tap_detect.time    = 0;

#    ifdef CFQ_USE_TAP_LAYER_PENDING
            if (IS_KEYCODE_PENDING(keycode)) {
                cfq_tap_detect.pending = true;
                return false;
            }
#    endif
        } else {
            if (cfq_tap_detect.time < CFQ_USE_TAP_LAYER) {
                /* Released within tap-time. */
                if (cfq_tap_detect.keycode == keycode) {
                    /* Pressed and released the same key within the tap-time. */
                    is_tap = true;
                }
                cfq_tap_detect.time = CFQ_USE_TAP_LAYER;

#    ifdef CFQ_USE_TAP_LAYER_PENDING
                cfq_tap_detect.pending = false;
#    endif
            }
        }

        if (is_tap) {
            if (keycode == MO(LAYER_KPAD)) {
                if ((layer_state & ~(1UL << LAYER_KPAD)) == 0) {
                    SEND_STRING(SS_TAP(X_HOME));
                    return true;
                }
            } else if (keycode == MO(LAYER_FKEY)) {
                if (layer_state_is(LAYER_KPAD)) {
                    SEND_STRING("}{" SS_TAP(X_LEFT));
                    return true;
                }
                SEND_STRING("}");
                return true;
            } else if (keycode == MO(LAYER_DIRS)) {
                if ((layer_state & ~(1UL << LAYER_DIRS)) == 0) {
                    SEND_STRING(SS_TAP(X_END));
                    return true;
                }
            }
#    if 0 /* Interesting but not good for gaining new muscle memory. */
      else if (keycode == MO(LAYER_FKEY)) {
        if ((layer_state & ~(1UL << LAYER_FKEY)) == 0) {
          SEND_STRING(SS_TAP(X_ESCAPE));
          return true;
        }
      }
      else if (keycode == KC_LALT) {
        SEND_STRING(SS_UP(X_LATL) SS_TAP(X_DELETE));
        WITHOUT_MOD_BITS(MOD_BIT(KC_LALT), {SEND_STRING(SS_TAP(X_DELETE));});
        return true;
      }
#    endif
            else if (keycode == KC_LALT) {
#    ifndef CFQ_USE_TAP_LAYER_PENDING
                SEND_STRING(SS_UP(X_LALT));
#    endif
                if (layer_state_is(LAYER_KPAD)) {
                    SEND_STRING("{}" SS_TAP(X_LEFT));
                    return false;
                }
                SEND_STRING("{");
                return false;
            }
#    if 0
      else if (keycode == KC_LGUI) {
#        ifndef CFQ_USE_TAP_LAYER_PENDING
        SEND_STRING(SS_UP(X_LGUI));
#        endif
        if (layer_state_is(LAYER_KPAD)) {
          SEND_STRING("}{" SS_TAP(X_LEFT));
          return false;
        }
        SEND_STRING("}");
        return false;
      }
#    endif
#    if 0 /* Nifty but disabled for now, since it's possible to tap by accident. */
      else if (keycode == KC_LCTL) {
#        ifndef CFQ_USE_TAP_LAYER_PENDING
        SEND_STRING(SS_UP(X_LCTL));
#        endif
        // if (layer_state_is(LAYER_KPAD)) {
        //   SEND_STRING("()" SS_TAP(X_LEFT));
        //   return false;
        // }
        SEND_STRING("_");
        return false;
      }
      else if (keycode == KC_RGUI) {
#        ifndef CFQ_USE_TAP_LAYER_PENDING
        SEND_STRING(SS_UP(X_RGUI));
#        endif
        // if (layer_state_is(LAYER_KPAD)) {
        //   SEND_STRING(")(" SS_TAP(X_LEFT));
        //   return false;
        // }
        SEND_STRING("-");
        return false;
      }
#    endif /* `if 0` */
        }
    }
#endif

    switch (keycode) {
        case M_HYP_L: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RGUI) SS_DOWN(X_LEFT));
            } else {
                SEND_STRING(SS_UP(X_LEFT) SS_UP(X_RGUI));
            }
            return false;
        }
        case M_HYP_R: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RGUI) SS_DOWN(X_RIGHT));
            } else {
                SEND_STRING(SS_UP(X_RIGHT) SS_UP(X_RGUI));
            }
            return false;
        }
        case M_HYP_U: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RGUI) SS_DOWN(X_UP));
            } else {
                SEND_STRING(SS_UP(X_UP) SS_UP(X_RGUI));
            }
            return false;
        }
        case M_MYP_D: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RGUI) SS_DOWN(X_DOWN));
            } else {
                SEND_STRING(SS_UP(X_DOWN) SS_UP(X_RGUI));
            }
            return false;
        }
        case M_SPEECH2TXT_A: {
            if (record->event.pressed) {
                WITHOUT_MODS({ SEND_STRING(SS_TAP(X_F15)); });
            } else {
                WITHOUT_MODS({ SEND_STRING(SS_TAP(X_F16)); });
            }
            return false;
        }
        case M_SPEECH2TXT_B: {
            if (record->event.pressed) {
                WITHOUT_MODS({ SEND_STRING(SS_TAP(X_F17)); });
            } else {
                WITHOUT_MODS({ SEND_STRING(SS_TAP(X_F18)); });
            }
            return false;
        }
#ifdef CFQ_USE_COLEMAK_MOD_DH
        case M_COLMAK_SWAP: {
            if (record->event.pressed) {
                if (default_layer_state == 1UL << LAYER_BASE_COLMAK_DH) {
                    persistent_default_layer_set(1UL << LAYER_BASE);
                } else {
                    persistent_default_layer_set(1UL << LAYER_BASE_COLMAK_DH);
                }
            }
            return false;
        }
#endif
            /* dynamically generate these. */
        case M_BRACK_IN_CBR: { /* {} */
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_BRACK_IN_PRN: { /* () */
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_BRACK_IN_BRC: { /* [] */
            if (record->event.pressed) {
                if (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) {
                    WITHOUT_SHIFT({
                        SEND_STRING("{}");
                        SEND_STRING(SS_TAP(X_LEFT));
                    });
                } else {
                    SEND_STRING("[]" SS_TAP(X_LEFT));
                }
                return false;
            }
            break;
        }
        case M_BRACK_IN_ANG: { /* <> */
            if (record->event.pressed) {
                SEND_STRING("<>" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_BRACK_OUT_CBR: { /* }{ */
            if (record->event.pressed) {
                SEND_STRING("}{" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_BRACK_OUT_PRN: { /* )( */
            if (record->event.pressed) {
                SEND_STRING(")(" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_BRACK_OUT_BRC: { /* ][ */
            if (record->event.pressed) {
                if (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) {
                    WITHOUT_SHIFT({
                        SEND_STRING("}{");
                        SEND_STRING(SS_TAP(X_LEFT));
                    });
                } else {
                    SEND_STRING("][" SS_TAP(X_LEFT));
                }
                return false;
            }
            break;
        }
        case M_BRACK_OUT_ANG: { /* >< */
            if (record->event.pressed) {
                SEND_STRING("><" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
        case M_ARROW_LMINUS: { /* <- */
            if (record->event.pressed) {
                SEND_STRING("<-");
                return false;
            }
            break;
        }
        case M_ARROW_RMINUS: { /* -> */
            if (record->event.pressed) {
                SEND_STRING("->");
                return false;
            }
            break;
        }
        case M_ARROW_LEQL: { /* <= */
            if (record->event.pressed) {
                SEND_STRING("<=");
                return false;
            }
            break;
        }
        case M_ARROW_REQL: { /* => */
            if (record->event.pressed) {
                SEND_STRING("=>");
                return false;
            }
            break;
        }
        case M_QUOTE_PAIR: { /* '' */
            if (record->event.pressed) {
                if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    SEND_STRING(SS_TAP(X_QUOTE) SS_TAP(X_QUOTE));
                    WITHOUT_SHIFT({ SEND_STRING(SS_TAP(X_LEFT)); });
                    return false;
                } else {
                    WITHOUT_MODS({ SEND_STRING("''" SS_TAP(X_LEFT)); });
                    return false;
                }

                return false;
            }
            break;
        }
        case M_BTICK_PAIR: { /* `` */
            if (record->event.pressed) {
                SEND_STRING("``" SS_TAP(X_LEFT));
                return false;
            }
            break;
        }
#ifdef CFQ_USE_SHIFT_QUOTES
        case KC_LEFT_SHIFT: { /* '' */
            if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_RSFT)))) {
                WITHOUT_MODS({ SEND_STRING("''" SS_TAP(X_LEFT) SS_DOWN(X_RIGHT_SHIFT) SS_DOWN(X_LEFT_SHIFT)); });
                return false;
                break;
                case KC_RIGHT_SHIFT: /* "" */
                    if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_LSFT)))) {
                        WITHOUT_MODS({ SEND_STRING("\x22\x22" SS_TAP(X_LEFT) SS_DOWN(X_LEFT_SHIFT) SS_DOWN(X_RIGHT_SHIFT)); });
                    }
                    return false;
            }
            break;
        }
#endif /* CFQ_USE_SHIFT_QUOTES */
        case M_WORD_A ... M_WORD_Z: {
            uint8_t     shift_index = (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) ? 1 : 0;
            const char *word        = cfq_word_lut[shift_index][keycode - M_WORD_A];
            if (record->event.pressed) {
                if (*word) {
                    WITHOUT_MODS({ send_string(word); });
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
#ifdef CFQ_USE_COLEMAK_MOD_DH
    uint16_t *src;
    uint16_t *dst;
    src = (uint16_t *)(void *)&keymaps[LAYER_BASE][0][0];
    dst = (uint16_t *)(void *)&keymaps[LAYER_BASE_COLMAK_DH][0][0];
    /* Load keys from a COLMAK-DH. */
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (*dst == KC_TRNS) {
                *dst = *src;
            }
            src++;
            dst++;
        }
    }
#endif
}

/* Runs constantly in the background, in a loop. */
void matrix_scan_user(void) {
#ifdef CFQ_USE_TAP_LAYER
    if (cfq_tap_detect.time != CFQ_USE_TAP_LAYER) {
        cfq_tap_detect.time++;
#    ifdef CFQ_USE_TAP_LAYER_PENDING
        if (cfq_tap_detect.time == CFQ_USE_TAP_LAYER) {
            if (cfq_tap_detect.pending) {
                cfq_tap_detect.pending = false;
                register_code(cfq_tap_detect.keycode);
            }
        }
#    endif
    }
#endif
}
