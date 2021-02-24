#include "ergodox_ez.h"
// #include "debug.h"s
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    RGB_SLD,
};

// Define layer names
#define WORKMAN 0 // Workman layer
#define CODE 2 // code
#define MOUSE 3 // mouse
#define NORDIC 4 //nordic mappings
#define QWERY 5 // QWERTY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* WORKMAN: Workman (Needs update)
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |   `    |   !  |   @  |   #  |   $  |   %  | Meh spc|
     * |--------+------+------+------+------+-------------|
     * | Tab    |   Q  |   D  |   R  |   W  |   B  | TT(3)|
     * |--------+------+------+------+------+------|      |
     * | Esc    |   A  |   S  |   H  |   T  |   G  |------|
     * |--------+------+------+------+------+------|CMD spc|
     * | LShift |   Z  |   X  |   M  |   C  |   V  |      |
     * `--------+------+------+------+------+-------------' ,-------------.
     *   | CTRL |      |      |  OPT |  CMD |               | Home | End  |
     *   `----------------------------------'        ,------|------|------|
     *                                               |      |      | TT(1)|
     *                                               | Space|  Tab |------|
     *                                               |      |      | TT(2)|
     *                                               `--------------------'
     *
     * (RIGHT)
     *
     *                 ,--------------------------------------------------.
     *                 | TT(5)|   ^  |   &  |   *  |   (  |   )  |   -    |
     *                 |------+------+------+------+------+------+--------|
     *                 |      |   J  |   F  |   U  |   P  |   ;  |   =    |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|   Y  |   N  |   E  |   O  |   I  |   '    |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |   K  |   L  |   ,  |   .  |   /  | RShift |
     * ,-------------. `-------------+------+------+------+------+--------'
     * | PgUp | PgDn |               | CMD L| OPT D|  UP  | RIGHT|   \  |
     * |------+------+------.        `----------------------------------'
     * | TT(2)|      |      |
     * |------|Enter |BckSpc|
     * | TT(1)|      |      |
     * `--------------------'
     *
     */
    [WORKMAN] = LAYOUT_ergodox(
        // (LEFT)
        KC_GRAVE,   KC_EXLM,    KC_AT,  KC_HASH,    KC_DLR,     KC_PERC,    MEH(KC_SPC),
        KC_TAB,     KC_Q,       KC_D,   KC_R,       KC_W,       KC_B,       TT(3),
        KC_ESC,     KC_A,       KC_S,   KC_H,       KC_T,       KC_G,
        KC_LSHIFT,  KC_Z,       KC_X,   KC_M,       KC_C,       KC_V,       LGUI(KC_SPC),
        KC_LCTRL,   KC_NO,      KC_NO,  KC_LALT,    KC_LGUI,
                                                                            KC_HOME,    KC_END,
                                                                                        TT(1),
                                                                KC_SPC,     KC_TAB,     TT(2),
        // (RIGHT)
                    TT(5),  KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_MINS,
                    KC_NO,  KC_J,       KC_F,       KC_U,       KC_P,       KC_SCOLON,  KC_EQUAL,
                            KC_Y,       KC_N,       KC_E,       KC_O,       KC_I,       KC_QUOTE,
                    KC_NO,  KC_K,       KC_L,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSHIFT,
                                        RGUI_T(KC_LEFT),    RALT_T(KC_DOWN),    KC_UP,  KC_RIGHT,      KC_BSLASH,
        KC_PGUP,    KC_PGDOWN,
        TT(2),
        TT(1),      KC_ENTER,   KC_BSPC
    ),

    /* CODE 2: Code
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |
     * |--------+------+------+------+------+-------------|
     * |        |  !   |  @   |  {   |  }   |  |   |      |
     * |--------+------+------+------+------+------|      |
     * |        |  #   |  $   |  (   |  )   |  `   |------|
     * |--------+------+------+------+------+------|      |
     * |        |  %   |  ^   |  [   |  ]   |  ~   |      |
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
     *                 |      |      |      |  =   |  /   |  *   |        |
     *                 |------+------+------+------+------+------+--------|
     *                 |      |      |  7   |  8   |  9   |  -   |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|      |  4   |  5   |  6   |  +   |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |      |  1   |  2   |  3   | Enter|        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               |  ,   |  0   |  .   |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------|      |      |
     * |      |      |      |
     * `--------------------'
     *
     */
    [CODE] = LAYOUT_ergodox(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_EXLM,    KC_AT,      KC_LCBR,        KC_RCBR,        KC_PIPE,    KC_TRNS,
        KC_TRNS,    KC_HASH,    KC_DLR,     KC_LPRN,        KC_RPRN,        KC_GRAVE,
        KC_TRNS,    KC_PERC,    KC_CIRC,    KC_LBRACKET,    KC_RBRACKET,    KC_TILD,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
                                                                            KC_TRNS,    KC_TRNS,
                                                                                        KC_TRNS,
                                                                KC_TRNS,    KC_TRNS,    KC_TRNS,


                    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_EQUAL, KC_KP_SLASH,    KC_KP_ASTERISK,     KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_KP_7,      KC_KP_8,  KC_KP_9,        KC_KP_MINUS,        KC_TRNS,
                                KC_TRNS,    KC_KP_4,      KC_KP_5,  KC_KP_6,        KC_KP_PLUS,         KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_KP_1,      KC_KP_2,  KC_KP_3,        KC_KP_ENTER,        KC_TRNS,
                                            KC_KP_COMMA,  KC_KP_0,  KC_KP_DOT,      KC_TRNS,            KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    /* MOUSE: Mouse and media
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |
     * |--------+------+------+------+------+-------------|
     * | Bright |      | LClck| MUp  | RClck|      |      |
     * |--------+------+------+------+------+------|      |
     * |  Dim   |      | MRght| MDwn | MLft |      |------|
     * |--------+------+------+------+------+------|      |
     * |        |      | Cut  | Copy | Paste|      |      |
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
     *                 |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
     *                 |------+------+------+------+------+------+--------|
     *                 |      |      |      | WUp  |      |      |  F12   |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|      | WLft | WDwn | WRght|      |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |      | Acc0 | Acc1 | Acc2 |      |        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               | Mute | Vol- | Vol+ |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------|      |      |
     * |      |      |      |
     * `--------------------'
     *
     */
    [MOUSE] = LAYOUT_ergodox(
    KC_TRNS,  KC_F1,    KC_F2,      KC_F3,      KC_F4,        KC_F5,    KC_TRNS,
    KC_F15,   KC_TRNS,  KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,   KC_TRNS,  KC_TRNS,
    KC_F14,   KC_TRNS,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_CUT,     KC_COPY,    KC_PASTE,     KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                            KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,
                                                KC_TRNS,    KC_TRNS,    KC_TRNS,

                        KC_TRNS,    KC_F6,      KC_F7,          KC_F8,              KC_F9,            KC_F10,   KC_F11,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_MS_WH_UP,        KC_TRNS,          KC_TRNS,  KC_F12,
                                    KC_TRNS,    KC_MS_WH_LEFT,  KC_MS_WH_DOWN,      KC_MS_WH_RIGHT,   KC_TRNS,  KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_MS_ACCEL0,   KC_MS_ACCEL1,       KC_MS_ACCEL2,     KC_TRNS,  KC_TRNS,
                                                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /* NORDIC: Nordic, maps ÅÄÖ to right hand. Needs OS support
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
                                                                            KC_TRNS,    KC_TRNS,  KC_TRNS,


        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  NO_OSLH,  NO_AA,
                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  NO_AE,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /* QWERTY: Default QWERTY with symbols
    *
    * (LEFT)
    * ,--------------------------------------------------.
    * |   `    |   !  |   @  |   #  |   $  |   %  | Meh spc|
    * |--------+------+------+------+------+-------------|
    * | Esc    |   Q  |   W  |   E  |   R  |   T  | TT(4)|
    * |--------+------+------+------+------+------|      |
    * | Tab    |   A  |   S  |   D  |   F  |   G  |------|
    * |--------+------+------+------+------+------|      |
    * | LShift |   Z  |   X  |   C  |   V  |   B  |      |
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
    *                 |      |   ^  |   &  |   *  |   (  |   )  |   -    |
    *                 |------+------+------+------+------+------+--------|
    *                 | TT(3)|   Y  |   U  |   I  |   O  |   P  |   \    |
    *                 |      |------+------+------+------+------+--------|
    *                 |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    *                 | Meh  |------+------+------+------+------+--------|
    *                 |      |   N  |   M  |   ,  |   .  |   /  | RShift |
    * ,-------------. `-------------+------+------+------+------+--------'
    * | PgUp | PgDn |               | ◀︎ CMD| ▲ OPT|   ▼  |   ▶  | TT(5)|
    * |------+------+------.        `----------------------------------'
    * |      |      |      |
    * |------|Space |Enter |
    * | TT(2)|      |      |
    * `--------------------'
    *
    */

    [QWERTY] = LAYOUT_ergodox(
    // (LEFT)
    KC_GRAVE,   KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,   KC_PERC,  MEH(KC_SPC),
    KC_ESC,     KC_Q,     KC_W,   KC_R,     KC_T,     KC_Y,     TT(4),
    KC_TAB,     KC_A,     KC_S,   KC_D,     KC_F,     KC_G,
    KC_LSHIFT,  KC_Z,     KC_X,   KC_C,     KC_V,     KC_B,     LGUI(KC_SPC),
    KC_LCTRL,   KC_NO,    KC_NO,  KC_LALT,  KC_LGUI,
                                                                          KC_HOME,  KC_END,
                                                                                    KC_NO,
                                                                KC_BSPC,  KC_SPC,   TT(1),
    // (RIGHT)
                          KC_NO,    KC_CIRC,  KC_AMPR,         KC_ASTR,          KC_LPRN,  KC_RPRN,    KC_MINS,
                          TT(3),    KC_Y,     KC_U,            KC_I,             KC_O,     KC_P,       KC_BSLASH,
                                    KC_H,     KC_J,            KC_K,             KC_L,     KC_SCOLON,  KC_QUOTE,
                          KC_NO,    KC_N,     KC_M,            KC_COMMA,         KC_DOT,   KC_SLASH,   KC_RSHIFT,
                                              GUI_T(KC_LEFT),  RALT_T(KC_DOWN),  KC_UP,    KC_RIGHT,   TT(5),
    KC_PGUP,  KC_PGDOWN,
    KC_NO,
    TT(2),    KC_SPC,     KC_ENTER
    ),

};

const uint16_t PROGMEM fn_actions[] = {[1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
