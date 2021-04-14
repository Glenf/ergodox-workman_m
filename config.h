/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// #define NO_DEBUG
// #define NO_PRINT
// #define NO_ACTION_TAPPING
#define TAPPING_TERM 200


// Define shorthands for some keys
#define U_RDO SCMD(KC_Z) // redo
#define U_UND LCMD(KC_Z) // undo
#define U_CPY LCMD(KC_C) // copy
#define U_CUT LCMD(KC_X) // cut
#define U_PST LCMD(KC_V) // paste
#define U_PWH SCMD(KC_V) // paste with history (custom Alfred.app mapping)

#define U_MIC HYPR(KC_M) // Mic mute

#define U_TR KC_TRNS
