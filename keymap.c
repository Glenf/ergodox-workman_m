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
#define MEDIA 2 // Media
#define NUM 3
#define CODE 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* WORKMAN: Workman (Work in progress Man)
     *
     * (LEFT)
     * ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | Meh spc|
     * |--------+------+------+------+------+-------------|
     * |        |   Q  |   D  |   R  |   W  |   B  |      |
     * |--------+------+------+------+------+------|      |
     * |        |   A  |   S  |   H  |   T  |   G  |------|
     * |--------+------+------+------+------+------|CMD spc|
     * |        |   Z  |   X  |   M  |   C  |   V  |      |
     * `--------+------+------+------+------+-------------' ,-------------.
     *   |      |      |      |      |  LT(3, Esc) |        | Home | End  |
     *   `----------------------------------'        ,------|------|------|
     *                                               |      |      |      |
     *                                               | LT(1,|  Tab |------|
     *                                               |  Spc)|      |      |
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
        KC_NO,   KC_1,           KC_2,           KC_3,           KC_4,           KC_5,   MEH(KC_SPC),
        KC_NO,     KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,   KC_NO,
        KC_NO,     LCTL_T(KC_A),   LOPT_T(KC_S),   LCMD_T(KC_H),   LSFT_T(KC_T),   KC_G,
        KC_NO,      KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,   LGUI(KC_SPC),
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          LT(2, KC_ESC),
                                                                                        KC_NO,    KC_NO,
                                                                                                    KC_NO,
                                                                        LT(1, KC_SPC),  KC_TAB,     KC_NO,
        // (RIGHT)
                    KC_NO,  KC_6,   KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
                    KC_NO,  KC_J,   KC_F,           KC_U,           KC_P,           KC_QUOTE,      KC_NO,
                            KC_Y,   RSFT_T(KC_N),   RCMD_T(KC_E),   ROPT_T(KC_O),   RCTL_T(KC_I),   KC_NO,
                    KC_NO,  KC_K,   KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
                                    KC_DEL,         KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,      LT(3, KC_ENT),       LT(4, KC_BSPC)
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
        KC_NO,  RESET,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
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

    /* NUM: Numeric
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
     *                 |      |      |  7   |  8   |  9   |  -   |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|      |  4   |  5   |  6   |  +   |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |      |  1   |  2   |  3   | Enter|        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               |  0   |      |  .   |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------|      |      |
     * |      |      |      |
     * `--------------------'
     *
     */
    [NUM] = LAYOUT_ergodox(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,
        KC_NO,    KC_LBRC,    KC_7,    KC_8,    KC_9,        KC_RBRC,    KC_NO,
        KC_NO,    KC_SCLN,    KC_4,    KC_5,    KC_6,        KC_EQL,
        KC_NO,    KC_GRV,    KC_1,    KC_2,    KC_3,        KC_NUBS,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_DOT,
                                                                            KC_NO,    KC_NO,
                                                                                        KC_NO,
                                                                KC_0,    KC_MINUS,    KC_NO,


                    KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_NO,        KC_NO,     KC_NO,
                    KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_NO,        RESET,        KC_NO,
                                KC_NO,    U_TR,      U_TR,  U_TR,        U_TR,         KC_NO,
                    KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_NO,        KC_NO,        KC_NO,
                                            KC_TRNS,      KC_NO,  KC_NO,        KC_NO,            KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_NO,    KC_TRNS,    KC_TRNS
    ),


    /* SYMBOLS: Code
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
     *                 |      |      |      |      |      |      |        |
     *                 |------+------+------+------+------+------+--------|
     *                 |      |      |      |      |      |      |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |------|      |      |      |      |      |        |
     *                 |      |------+------+------+------+------+--------|
     *                 |      |      |      |      |      |      |        |
     * ,-------------. `-------------+------+------+------+------+--------'
     * |      |      |               |      |      |  .   |      |      |
     * |------+------+------.        `----------------------------------'
     * |      |      |      |
     * |------|      |      |
     * |      |      |      |
     * `--------------------'
     *
     */
    [CODE] = LAYOUT_ergodox(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
        KC_TRNS,    LSFT(KC_LBRC),    LSFT(KC_7),      LSFT(KC_8),        LSFT(KC_7),        LSFT(KC_RBRC),    KC_TRNS,
        KC_TRNS,    KC_COLN,    LSFT(KC_4),     LSFT(KC_5),        LSFT(KC_6),        KC_PLUS,
        KC_TRNS,    KC_TILDE,    LSFT(KC_1),    LSFT(KC_2),    KC_NUHS,    LSFT(KC_NUBS),    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        LSA(KC_2),
                                                                            KC_TRNS,    KC_TRNS,
                                                                                        KC_TRNS,
                                                                LSFT(KC_0),    LSFT(KC_MINS),    KC_TRNS,


                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RESET,    KC_TRNS,
                                KC_NO,    U_TR,    U_TR,    U_TR,    U_TR,    KC_TRNS,
                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
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
