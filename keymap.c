#include "ergodox_ez.h"
// #include "debug.h"s
#include "action_layer.h"
#include "version.h"
#include "keymap_finnish.h"

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    RGB_SLD,
};

// Define layer names
#define WORKMAN 0 // Workman layer
#define NAV 1 // Navigation
#define CODE 2 // Code
#define MEDIA 3 // Media

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* WORKMAN: Workman (Work in progress Man)
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | Meh spc|
     * |--------+------+------+------+------+-------------|
     * | Tab    |   Q  |   D  |   R  |   W  |   B  |      |
     * |--------+------+------+------+------+------|      |
     * | Esc    |   A  |   S  |   H  |   T  |   G  |------|
     * |--------+------+------+------+------+------|CMD spc|
     * | LShift |   Z  |   X  |   M  |   C  |   V  |      |
     * `--------+------+------+------+------+-------------' ,-------------.
     *   |      |      |      |      |  LT(3, Esc) |        | Home | End  |
     *   `----------------------------------'        ,------|------|------|
     *                                               |      |      |      |
     *                                               | LT(1,|  Tab |------|
     *                                               |  Spc)|      | LT(3, Esc)|
     *                                               `--------------------'
     *
     * (RIGHT)
     *
     *                 ,--------------------------------------------------.
     *                 |      |   6  |   7  |   8  |   9  |   0  |   -    |
     *                 |------+------+------+------+------+------+--------|
     *                 |      |   J  |   F  |   U  |   P  |   ;  |   =    |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|   Y  |   N  |   E  |   O  |   I  |   '    |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |   K  |   L  |   ,  |   .  |   /  |   -    |
     * ,-------------. `-------------+------+------+------+------+--------'
     * | PgUp | PgDn |               | Del  |      |      |      |   \  |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------|Enter |LT(2, BckSpc)|
     * |      |      |      |
     * `--------------------'
     *
     */
    [WORKMAN] = LAYOUT_ergodox(
        // (LEFT)
        KC_GRAVE,   KC_1,           KC_2,           KC_3,           KC_4,           KC_5,   MEH(KC_SPC),
        KC_TAB,     KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,   KC_NO,
        KC_ESC,     LCTL_T(KC_A),   LOPT_T(KC_S),   LCMD_T(KC_H),   LSFT_T(KC_T),   KC_G,
        KC_NO,      KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,   LGUI(KC_SPC),
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          LT(3, KC_ESC),
                                                                                        KC_HOME,    KC_END,
                                                                                                    KC_NO,
                                                                        LT(1, KC_SPC),  KC_TAB,     LT(3, KC_ESC),
        // (RIGHT)
                    KC_NO,  KC_6,   KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
                    KC_NO,  KC_J,   KC_F,           KC_U,           KC_P,           KC_SCOLON,      KC_EQUAL,
                            KC_Y,   RSFT_T(KC_N),   RCMD_T(KC_E),   ROPT_T(KC_O),   RCTL_T(KC_I),   KC_QUOTE,
                    KC_NO,  KC_K,   KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_MINS,
                                    KC_DEL,         KC_NO,          KC_NO,          KC_NO,          KC_BSLASH,
        KC_PGUP,    KC_PGDOWN,
        KC_NO,
        KC_NO,      KC_ENTER,       LT(2, KC_BSPC)
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

    /* MEDIA: Media keys
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |
     * |--------+------+------+------+------+-------------|
     * |        | RESET|      |      |      |      |      |
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
     *                 |      |      |  Mic | Bri- | Bri+ |      |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|      | Prev | Vol- | Vol+ | Next |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |      |      |      |      |      |        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               | Mute |      |      |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------| STOP | PLAY |
     * |      |      |      |
     * `--------------------'
     *
     */
    [MEDIA] = LAYOUT_ergodox(
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,  RESET,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,
        KC_TRNS,  KC_TRNS,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,    KC_TRNS,
                                                                            KC_TRNS,
                                                        KC_NO,  KC_NO,      KC_TRNS,

                    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    KC_TRNS,    KC_TRNS,    U_MIC,          KC_BRID,    KC_BRIU,    KC_TRNS,    KC_TRNS,
                                KC_NO,      KC_MPRV,        KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_TRNS,
                    KC_TRNS,    KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                                            KC_AUDIO_MUTE,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_MSTP,    KC_MPLY
    ),

    /* Nav: Navigation layer
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
     *                 |      | Redo |  Cut | Copy | Paste| Undo |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |------| LEFT | DOWN |  UP  | RIGHT| PWH  |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      | Home | PGUp | PgDn |  End |      |        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               | Del  |      |      |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------| Enter| Bspc |
     * |      |      |      |
     * `--------------------'
     *
     */
    [NAV] = LAYOUT_ergodox(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  U_TR,   U_TR,   U_TR,   U_TR,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                                KC_NO,  KC_NO,
                                                        KC_NO,
                                        KC_NO,  KC_NO,  KC_NO,

        KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,  U_RDO,      U_CUT,      U_CPY,      U_PST,      U_UND,  KC_NO,
                KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    U_PWH,  KC_NO,
        KC_NO,  KC_HOME,    KC_PGDOWN,  KC_PGUP,    KC_END,     KC_NO,  KC_NO,
                            KC_DEL,     KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,  KC_NO,
        KC_NO,
        KC_NO,  KC_ENTER,  KC_BSPC
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
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_1_on();
            break;
        case 3:
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }
    return state;
};
