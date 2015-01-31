#include "keymap_common.h"
#include <avr/wdt.h> // for wdt_enable

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Norman */
  KEYMAP(Q,    W,   D,    F,     K,               J,    U,    R,    L,    SCLN, \
         A,    S,   E,    T,     G,               Y,    N,    I,    O,    H, \
         Z,    X,   C,    V,     B,         FN20, P,    M,    COMM, DOT,  QUOT, \
         LSFT, TAB, LALT, LGUI,  SPC,  ENT,       BSPC, FN0,  BSLS, SLSH, RSFT),

  /* 1: fn with software-dvorak-ized punctuation */
  KEYMAP(FN6,  FN7,  FN4,  FN5,  FN17,            UP,   7,    8,    9,  FN8, \
         FN8,  FN9,  FN2,  FN3,  GRV,             DOWN, 4,    5,    6,  FN1, \
         FN10, FN11, LBRC, RBRC, FN15,      TRNS, FN11, 1,    2,    3, BSLS,  \
         FN19, FN18, MINS, FN16, TRNS, TRNS,      TRNS, TRNS, DOT,  0, EQL ) \
};

enum function_id {
  BOOTLOADER,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  keyevent_t event = record->event;

  if (id == BOOTLOADER) {
    clear_keyboard();
    print("\n\nJump to bootloader... ");
    _delay_ms(250);

    *(uint16_t *)0x0800 = 0x7777; // these two are a-star-specific
    wdt_enable(WDTO_120MS);

    bootloader_jump(); // should not return
    print("not supported.\n");
  }
}

// looks like all normally-shifted keys need to be listed here
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay

  // row 1
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),  // +
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_9),    // (
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_0),    // )
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // }

  // row 2
  [6] = ACTION_MODS_KEY(MOD_LSFT, KC_1),    // !
  [7] = ACTION_MODS_KEY(MOD_LSFT, KC_2),    // @
  [8] = ACTION_MODS_KEY(MOD_LSFT, KC_3),    // #
  [9] = ACTION_MODS_KEY(MOD_LSFT, KC_4),    // $
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_5),   // %
  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_6),   // ^
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_7),   // &
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_8),   // *
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH), // ?
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV), // ~

  // row 3
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // _
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS), // |
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_INSERT), // for pasting

  // other
  [19] = ACTION_FUNCTION(BOOTLOADER),
  [20] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN27 - Control/esc on tap
};
