/* Copyright (c) 2018 Tim Perkins */

#include "planck.h"

/* Use the MIT layout for the keymap */
#define KEYMAP_MIT LAYOUT_planck_mit

#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum tprk77_layers {
  LR_CLMK = 0,  /* COLEMAK (BASE) */
  LR_LWR  = 1,  /* LOWER */
  LR_RSE  = 2,  /* RAISE */
  LR_NAV  = 3   /* NAV */
};

enum tprk77_fns {
  MO_LWR  = KC_FN0,
  MO_RSE  = KC_FN1
};

enum tprk77_mod_keys {
  MD_HYPR = ALL_T(KC_NO),
  MD_MEH  = MEH_T(KC_NO),
  MD_CSPC = LCTL(KC_SPC),
  MD_CENT = LCTL(KC_ENT),
  MD_CBSP = LCTL(KC_BSPC),
  MD_MX   = LALT(KC_X),
  MD_CG   = LCTL(KC_G),
  MD_MW   = LALT(KC_W),
  MD_CW   = LCTL(KC_W),
  MD_CY   = LCTL(KC_Y),
  MD_CS   = LCTL(KC_S),
  MD_CR   = LCTL(KC_R),
  MD_CL   = LCTL(KC_L),
  MD_CK   = LCTL(KC_K),
  MD_CQUE = LCTL(KC_QUES),
  MD_CSLS = LCTL(KC_SLSH),
  MD_MO   = LALT(KC_O),
  MD_MSO  = LALT(LSFT(KC_O))
};

#define SR SAFE_RANGE

enum tprk77_keys {
  MC_0P0 = SR,  /* 0.0 */
  MC_PI,        /* 3.14159265358979323846 (As defined in "math.h") */
  MC_CXCF,      /* C-x C-f (Open file) */
  MC_CXCS,      /* C-x C-s (Save file) */
  MC_CXB,       /* C-x b   (Switch buffer) */
  MC_CXK,       /* C-x k   (Kill buffer) */
  MC_CCO        /* C-c o   (Jump to window) */
};

#undef SR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * COLEMAK (BASE) LAYER:
   *
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Nav  | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [LR_CLMK] = KEYMAP_MIT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, MO_LWR,      KC_SPC,       MO_RSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /*
   * LOWER LAYER:
   *
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | XXXX |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|  U   |  L   |  F   |  E   |  Pi  |  +   |  -   |  ,   |  .   | 0.0  | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Nav  | GUI  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  | Right|
   * `-----------------------------------------------------------------------------------'
   */
  [LR_LWR] = KEYMAP_MIT(
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
      KC_LSFT, KC_U,    KC_L,    KC_F,    KC_E,    MC_PI,   KC_PLUS, KC_MINS, KC_COMM, KC_DOT,  MC_0P0,  KC_ENT,
      KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, MO_LWR,      KC_SPC,       MO_RSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /*
   * RAISE LAYER:
   *
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |  \   |  -   |  <   |  >   |  `   |  ?   |  [   |  ]   |  :   |  ;   | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |  !   |  =   |  (   |  )   |  "   |  '   |  {   |  }   |  _   |  #   | XXXX |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|  $   |  @   |  /   |  *   |  +   |  ~   |  &   |  |   |  ^   |  %   | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Nav  | GUI  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  | Right|
   * `-----------------------------------------------------------------------------------'
   */
  [LR_RSE] = KEYMAP_MIT(
      KC_TAB,  KC_BSLS, KC_MINS, KC_LABK, KC_RABK, KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_COLN, KC_SCLN, KC_BSPC,
      KC_LCTL, KC_EXLM, KC_EQL,  KC_LPRN, KC_RPRN, KC_DQT,  KC_QUOT, KC_LCBR, KC_RCBR, KC_UNDS, KC_HASH, XXXXXXX,
      KC_LSFT, KC_DLR,  KC_AT,   KC_SLSH, KC_ASTR, KC_PLUS, KC_TILD, KC_AMPR, KC_PIPE, KC_CIRC, KC_PERC, KC_ENT,
      KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, MO_LWR,      KC_SPC,       MO_RSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /*
   * NAV LAYER:
   *
   * ,-----------------------------------------------------------------------------------.
   * | Tab  | C-?  | M-S-o| M-o  | M-x  | C-g  | PgUp | Home |  Up  | End  | XXXX | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl | C-l  | M-w  | C-w  | C-y  | Del  | PgDn | Left | Down | Right| XXXX | XXXX |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift| C-/  | C-r  | C-s  | C-x b| C-x k| C-k  | XXXX | XXXX | XXXX | XXXX | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Nav  | GUI  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  | Right|
   * `-----------------------------------------------------------------------------------'
   */
  [LR_NAV] = KEYMAP_MIT(
      KC_TAB,  MD_CQUE, MD_MSO,  MD_MO,   MD_MX,   MD_CG,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_BSPC,
      KC_LCTL, MD_CL,   MD_MW,   MD_CW,   MD_CY,   KC_DEL,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      KC_LSFT, MD_CSLS, MD_CR,   MD_CS,   MC_CXB,  MC_CXK,  MD_CK,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
      KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, MO_LWR,      KC_SPC,       MO_RSE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  )
};

const uint16_t PROGMEM fn_actions[] = {
  /* MO_LWR */  [0] = ACTION_LAYER_MOMENTARY(LR_LWR),
  /* MO_RSE */  [1] = ACTION_LAYER_MOMENTARY(LR_RSE)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  update_tri_layer(LR_LWR, LR_RSE, LR_NAV);
  if (record->event.pressed) {
    switch (keycode) {
      case MC_0P0:
        SEND_STRING("0.0");
        return false;
      case MC_PI:
        SEND_STRING("3.14159265358979323846");
        return false;
      case MC_CXCF:
        SEND_STRING(SS_LCTRL("xf"));
        return false;
      case MC_CXCS:
        SEND_STRING(SS_LCTRL("xs"));
        return false;
      case MC_CXB:
        SEND_STRING(SS_LCTRL("x") "b");
        return false;
      case MC_CXK:
        SEND_STRING(SS_LCTRL("x") "k");
        return false;
      case MC_CCO:
        SEND_STRING(SS_LCTRL("c") "o");
        return false;
    }
  }
  return true;
}

void matrix_init_user(void)
{
  /* Do nothing */
}

void matrix_scan_user(void)
{
  /* Do nothing */
}

  /*
   * LAYER TEMPLATE:
   *
   * ,-----------------------------------------------------------------------------------.
   * | Tab  | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Nav  | GUI  | Alt  | Lower|    Space    | Raise| Left | Down |  Up  | Right|
   * `-----------------------------------------------------------------------------------'
   */
