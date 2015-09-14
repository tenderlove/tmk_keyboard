#include "action_util.h"
#include "action_layer.h"
#define KC_SW0 KC_FN0
#define DEBUG_ACTION

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* TODO
       - L1 push goes to wrong layer (mouse instead of characters)
       - ~L2 stays in mouse layer
    */

    /* Keymap 0: Norman Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   D  |   F  |   K  |  Up  |           |  L0  |   J  |   U  |   R  |   L  |   :  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | BkSp   |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   '    |
     * |--------+------+------+------+------+------|  Dn  |           |  L1  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  | RShitf |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGui |   `  |      | ~L1  |  ~L2 |                                       | ~L2  | ~L1  |   [  |   ]  | RGui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  Lft | Rght |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | LCtrl| LAlt |------|       |------| Enter| Space|
     *                                 |      |      | End  |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     */


    // Norman Layer

    KEYMAP(
           EQL,  1,    2,    3,    4,    5, ESC,
           TAB,  Q,    W,    D,    F,    K, FN1,
           LCTL, A,    S,    E,    T,    G,
           LSFT, Z,    X,    C,    V,    B, NO,
           FN30,  FN4, TAB, LALT, LGUI,

                                            NO,  NO,
                                                HOME,
                                      SPC, ENT, MINS,
           //RIGHT
           NO,   6,    7,    8,    9,    0,    MINS,
           UP,   J,    U,    R,    L,    SCLN, BSLS,
                 Y,    N,    I,    O,    H,    QUOT,
           DOWN, P,    M,    COMM, DOT,  SLSH, RSFT,
                       RGUI, RALT, LBRC, RBRC, FN4,
           LEFT, RIGHT,
           PGUP,
           PGDN, FN27, BSPC
           ),

    // SYMBOLS
    KEYMAP(
           FN0,  F1,   F2,   F3,   F4,   F5,   ESC,
           TRNS, FN7,  FN8,  FN23, FN24, FN18, FN2,
           FN22, FN9,  FN10, FN15, FN16, GRV,
           TRNS, FN11, FN12, LBRC, RBRC, FN17, FN1,
           TRNS, TRNS, TRNS, TRNS, TRNS,

                                               TRNS, TRNS,
                                                     TRNS,
                                         TRNS, TRNS, TRNS,
        // right hand
           TRNS, F6,   F7,   F8,   F9,   F10,   F11,
           UP,    UP,       7,   8,    9,    FN14, F12,
                  DOWN,     4,   5,    6,    FN26, FN30,
           DOWN,  FN13,     1,   2,    3,    BSLS, TRNS,
                        TRNS,  DOT,    0,    EQL, TRNS,
           TRNS, TRNS,
           TRNS,
           TRNS, TRNS, TRNS
    ),
    KEYMAP(  // Layer2: Mouse Left/ Arrows Right
        // left hand
           NO,   NO,   BTN1, BTN2, BTN3, NO,   TRNS,
           NO,   NO,   WH_U, MS_U, WH_D, NO,   NO,
           NO,   NO,   MS_L, MS_D, MS_R, NO,
           NO,   NO,   BTN1, BTN2, BTN3, NO,   FN4,
           NO,   NO,   NO,   NO,   NO,
                                               NO,   NO,
                                                     NO,
                                         NO,   NO,   NO,
        // right hand
           NO,   NO,   BTN1, BTN2, BTN3, NO,   NO,
           FN5,  INS,  HOME, UP,   PGUP, NO,   NO,
                 DEL,  LEFT, DOWN, RGHT, NO,   NO,
           NO,   NO,   END,  DOWN, PGDN, NO,   NO,
                       TRNS, TRNS, NO,   NO,   NO,
           NO,   NO,
           NO,
           NO,   TRNS,   NO
    ),

    /* KEYMAP(  // LayerN: fully transparent */
    /*     // left hand */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*                                            TRNS, TRNS,  */
    /*                                                  TRNS,  */
    /*                                      TRNS, TRNS, TRNS, */
    /*     // right hand */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*              TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*                    TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS,  */
    /*        TRNS,  */
    /*        TRNS, TRNS, TRNS */
    /* ), */


    // BASE LAYERS

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key
    [1] = ACTION_LAYER_TOGGLE(1),                         // FN1 - Toggle 1
    [2] = ACTION_LAYER_TOGGLE(2),                         // FN2 - Toggle 2
    [3] = ACTION_LAYER_TOGGLE(3),                         // FN3 - Toggle 3
    [4] = ACTION_LAYER_TAP_TOGGLE(1),                     // FN4 - Momentary Layer 1
    [5] = ACTION_LAYER_MOMENTARY(2),                      // FN5 - Momentary L2

    // SYMBOLS
    ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),             // FN6 - "
    ACTION_MODS_KEY(MOD_LSFT, KC_1),                // FN7 - !
    ACTION_MODS_KEY(MOD_LSFT, KC_2),                // FN8 - @
    ACTION_MODS_KEY(MOD_LSFT, KC_3),                // FN9 - #
    ACTION_MODS_KEY(MOD_LSFT, KC_4),                // FN10 - $
    ACTION_MODS_KEY(MOD_LSFT, KC_5),                // FN11 - %
    ACTION_MODS_KEY(MOD_LSFT, KC_6),                // FN12 - ^
    ACTION_MODS_KEY(MOD_LSFT, KC_7),                // FN13 - &
    ACTION_MODS_KEY(MOD_LSFT, KC_8),                // FN14 - *
    ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN15 - (
    ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN16 - )
    ACTION_MODS_KEY(MOD_LSFT, KC_GRV),              // FN17 - ~
    ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),             // FN18 - |
    ACTION_MODS_KEY(MOD_LSFT, KC_MINS),             // FN19 - _
    ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN20 - <
    ACTION_MODS_KEY(MOD_LSFT, KC_DOT),              // FN21 - >
    ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),             // FN22 - :
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),             // FN23 - {
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),             // FN24 - }
    ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),             // FN25 - ?
    ACTION_MODS_KEY(MOD_LSFT, KC_EQL),              // FN26 - +

    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN27 - Control/esc on tap
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),            // FN28 - Control/esc on tap
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_A),            // FN28 - Control/esc on tap

    // Fancy tapping/toggling
    ACTION_LAYER_TAP_KEY(1, KC_GRV),                  // FN3 - Layer 1 when holding T key


};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
