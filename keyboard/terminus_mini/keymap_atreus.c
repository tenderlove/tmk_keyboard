#include "keymap_common.h"
#include <avr/wdt.h> // for wdt_enabl😋e

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Norman */
  KEYMAP(  TAB,    Q,    W,    D,    F,    K,    J,    U,    R,    L, SCLN, BSLS, \
	  LCTL,    A,    S,    E,    T,    G,    Y,    N,    I,    O,    H, QUOT, \
	  LSFT,    Z,    X,    C,    V,    B,    P,    M, COMM,  DOT, SLSH, RSFT, \
	   FN0,   NO, LGUI,   NO,  SPC,        ENT,       RGUI,   NO, FN19,  FN0 )

};

enum function_id {
  BOOTLOADER,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
  [0] = ACTION_LAYER_TAP_TOGGLE(1),  // to Fn overlay

  // other
  [19] = ACTION_FUNCTION(BOOTLOADER),
};
