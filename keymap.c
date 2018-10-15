#include "ergodox_ez.h"
// #include "debug.h"s
#include "action_layer.h"
#include "version.h"
// #include "keymap_german.h"
// #include "keymap_nordic.h"
#include "keymap_swedish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,

};

// Define layer names
#define WORKMAN 0 // default layer
#define SHIFTED 1 // shifted layer
#define CODE 2 // code
#define NUMPAD 3 // numpad
#define MOUSE 4 // mouse
#define NORDIC 5 //nordic mappings


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* WRKM 0: Workman (Need update)
   *
   * (LEFT)
   * ,--------------------------------------------------.
   * |   `    |   !  |   @  |   #  |   4  |   5  | Meh spc|
   * |--------+------+------+------+------+-------------|
   * | Esc    |   Q  |   D  |   R  |   W  |   B  | TT(4)|
   * |--------+------+------+------+------+------|      |
   * | Tab    |   A  |   S  |   H  |   T  |   G  |------|
   * |--------+------+------+------+------+------|      |
   * | LShift |   Z  |   X  |   M  |   C  |   V  |      |
   * `--------+------+------+------+------+-------------' ,-------------.
   *   | CTRL |      |      |  OPT |  CMD |               | Home | End  |
   *   `----------------------------------'        ,------|------|------|
   *                                               |      |      |      |
   *                                               |Bckspc| Space|------|
   *                                               |      |      | TT(1)|
   *                                               `--------------------'
   *
   * (RIGHT)
   *
   *                 ,--------------------------------------------------.
   *                 |      |   6  |   7  |   8  |   9  |   0  |   -    |
   *                 |------+------+------+------+------+------+--------|
   *                 | TT(3)|   J  |   F  |   U  |   P  |   ;  |   =    |
   *                 |      |------+------+------+------+------+--------|
   *                 |------|   Y  |   N  |   E  |   O  |   I  |   '    |
   *                 | Meh  |------+------+------+------+------+--------|
   *                 |      |   K  |   L  |   ,  |   .  |   /  | RShift |
   * ,-------------. `-------------+------+------+------+------+--------'
   * | PgUp | PgDn |               | CMD  | OPT  |  \   |      | TT(5)|
   * |------+------+------.        `----------------------------------'
   * |      |      |      |
   * |------|Space |Enter |
   * | TT(2)|      |      |
   * `--------------------'
   *
   */

  [WORKMAN] = LAYOUT_ergodox(
    // (LEFT)
    KC_GRAVE,   KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,   KC_PERC,  MEH(KC_SPC),
    KC_ESC,     KC_Q,     KC_D,   KC_R,     KC_W,     KC_B,     TT(4),
    KC_TAB,     KC_A,     KC_S,   KC_H,     KC_T,     KC_Q,
    KC_LSHIFT,  KC_Z,     KC_X,   KC_M,     KC_C,     KC_V,     LGUI(KC_SPC),
    KC_LCTRL,   KC_NO,    KC_NO,  KC_LALT,  KC_LGUI,

                                                                          KC_HOME,  KC_END,
                                                                                    KC_NO,
                                                                KC_BSPC,  KC_SPC,   TT(1),
    // (RIGHT)
                          KC_NO,    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,    KC_RPRN,    KC_MINS,
                          TT(3),    KC_J,     KC_F,     KC_U,     KC_P,       KC_SCOLON,  KC_EQL,
                                    KC_Y,     KC_N,     KC_E,     KC_O,       KC_I,       KC_QUOTE,
                          KC_NO,    KC_K,     KC_L,     KC_COMMA, KC_DOT,     KC_SLASH,   KC_RSHIFT,
                                              KC_RGUI,  KC_RALT,  KC_BSLASH,  KC_NO,      TT(5),
    KC_PGUP,  KC_PGDOWN,
    KC_NO,
    TT(2),    KC_SPC,     KC_ENTER
  ),

  /* SHFT 1: Shifted layer
   *
   * (LEFT)
   * ,--------------------------------------------------.
   * |        |   1  |   2  |   3  |   4  |   5  |      |
   * |--------+------+------+------+------+-------------|
   * |        |      |      |      |      |      |      |
   * |--------+------+------+------+------+------|      |
   * |        |      |      |      |      |      |------|
   * |--------+------+------+------+------+------|      |
   * |        |      |      |      |      |      |      |
   * `--------+------+------+------+------+-------------' ,-------------.
   *   |      |      |      |      |      |               |      |      |
   *   `----------------------------------'        ,------|------|------|
   *                                               |      |      |      |
   *                                               |      |      |------|
   *                                               |      |      |      |
   *                                               `--------------------'
   *
   * (RIGHT)
   *
   *                 ,--------------------------------------------------.
   *                 |      |   6  |   7  |   8  |   9  |   0  |        |
   *                 |------+------+------+------+------+------+--------|
   *                 |      |      |      |      |      |      |        |
   *                 |      |------+------+------+------+------+--------|
   *                 |------|      |      |      |      |      |        |
   *                 |      |------+------+------+------+------+--------|
   *                 |      |      |      |      |      |      |        |
   * ,-------------. `-------------+------+------+------+------+--------'
   * |      |      |               |      |      |      |      |      |
   * |------+------+------.        `----------------------------------'
   * |      |      |      |
   * |------|      |      |
   * |      |      |      |
   * `--------------------'
   *
   */
  [SHIFTED] = LAYOUT_ergodox(
    // (LEFT)
    KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                              KC_TRNS,  KC_TRNS,  KC_TRNS,

    // (RIGHT)
                        KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS

  ),
  /* CODE 2: Code
   *
   * (LEFT)
   * ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |
   * |--------+------+------+------+------+-------------|
   * |        |      |      |  {   |  }   |      |      |
   * |--------+------+------+------+------+------|      |
   * |        |      |      |  (   |  )   |      |------|
   * |--------+------+------+------+------+------|      |
   * |        |      |      |  [   |  ]   |      |      |
   * `--------+------+------+------+------+-------------' ,-------------.
   *   |      |      |      |      |      |               |      |      |
   *   `----------------------------------'        ,------|------|------|
   *                                               |      |      |      |
   *                                               |      |      |------|
   *                                               |      |      |      |
   *                                               `--------------------'
   *
   * (RIGHT)
   *
   *                 ,--------------------------------------------------.
   *                 |      |      |      |      |      |      |        |
   *                 |------+------+------+------+------+------+--------|
   *                 |      |      |      |      |      |      |        |
   *                 |      |------+------+------+------+------+--------|
   *                 |------|  ◀︎   |  ▲   |  ▼   |  ▶   |      |        |
   *                 |      |------+------+------+------+------+--------|
   *                 |      |      |      |      |      |      |        |
   * ,-------------. `-------------+------+------+------+------+--------'
   * |      |      |               |      |      |      |      |      |
   * |------+------+------.        `----------------------------------'
   * |      |      |      |
   * |------|      |      |
   * |      |      |      |
   * `--------------------'
   *
   */

  [CODE] = LAYOUT_ergodox(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LCBR,      KC_RCBR,      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LPRN,      KC_RPRN,      KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRACKET,  KC_RBRACKET,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,
                                                                                  KC_TRNS,  KC_TRNS,
                                                                                            KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,


    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
              KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [NUMPAD] = LAYOUT_ergodox(KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_EQUAL,KC_KP_SLASH,KC_KP_ASTERISK,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_MINUS,KC_TRNS,KC_TRNS,KC_4,KC_KP_5,KC_KP_6,KC_KP_PLUS,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_ENTER,KC_TRNS,KC_KP_COMMA,KC_0,KC_KP_DOT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

  [MOUSE] = LAYOUT_ergodox(KC_TRNS,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRNS,KC_F15,KC_TRNS,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_TRNS,KC_TRNS,KC_F14,KC_TRNS,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRNS,KC_TRNS,KC_TRNS,KC_CUT,KC_COPY,KC_PASTE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_WH_UP,KC_TRNS,KC_TRNS,KC_F12,KC_TRNS,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,KC_TRNS,KC_TRNS,KC_AUDIO_MUTE,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),

  /* NORDIC 5: Nordic, maps ÅÄÖ to right hand. Needs OS support
   *
   * (LEFT)
   * ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |
   * |--------+------+------+------+------+-------------|
   * |        |      |      |      |      |      |      |
   * |--------+------+------+------+------+------|      |
   * |        |      |      |      |      |      |------|
   * |--------+------+------+------+------+------|      |
   * |        |      |      |      |      |      |      |
   * `--------+------+------+------+------+-------------' ,-------------.
   *   |      |      |      |      |      |               |      |      |
   *   `----------------------------------'        ,------|------|------|
   *                                               |      |      |      |
   *                                               |      |      |------|
   *                                               |      |      |      |
   *                                               `--------------------'
   *
   * (RIGHT)
   *
   *                 ,--------------------------------------------------.
   *                 |      |      |      |      |      |      |        |
   *                 |------+------+------+------+------+------+--------|
   *                 |      |      |      |      |      |  Ö   |  Å     |
   *                 |      |------+------+------+------+------+--------|
   *                 |------|      |      |      |      |      |  Ä     |
   *                 |      |------+------+------+------+------+--------|
   *                 |      |      |      |      |      |      |        |
   * ,-------------. `-------------+------+------+------+------+--------'
   * |      |      |               |      |      |      |      |      |
   * |------+------+------.        `----------------------------------'
   * |      |      |      |
   * |------|      |      |
   * |      |      |      |
   * `--------------------'
   *
   */

  [NORDIC] = LAYOUT_ergodox(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
                                                                                  KC_TRNS,  KC_TRNS,
                                                                                            KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,


    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  NO_OSLH,  NO_AA,
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  NO_AE,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    // Led 1 = Red
    // Led 2 = Green
    // Led 3 = Blue

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
