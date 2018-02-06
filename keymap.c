#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  __  |  Gui |  Alt | Lower|    Space    | Raise| Mute | Prev | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,         KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,   KC_K,         KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,   KC_COMM,      KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, _______, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_AUDIO_MUTE, KC_MPRV, KC_MPLY, KC_MNXT}
},
/* Note: Because the Planck offers the Grid and MIT layouts, but uses a universal PCB, KC_SPC (Spacebar) must be listed twice here. */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Bksp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |  Alt |      |    Space    |      | Left |  Up  | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LCTL, _______, _______, KC_LALT, _______, KC_SPC,  KC_SPC,  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |  End |      |      | Home |      |  Ins |      | PrSc |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |  Del |      |      |      |      |      | ScLk |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |  Alt |      |             |      | Left |  Up  | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,        KC_F11,     KC_F12},
  {_______, _______, _______, KC_END,    _______, _______, KC_HOME, _______, KC_INSERT, _______,       KC_PSCREEN, _______},
  {KC_LSFT, _______, _______, KC_DELETE, _______, _______, _______, _______, _______,   KC_SCROLLLOCK, _______,    _______},
  {KC_LCTL, _______, _______, KC_LALT,   _______, _______, _______, _______, KC_LEFT,   KC_UP,         KC_DOWN,    KC_RIGHT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Qwerty|      |      |      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | AudOn|AudOff|      |      |      |             |      |Voice+|Voice-| MusOn|MusOff|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  { QWERTY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, MUV_IN,  MUV_DE,  MU_ON,   MU_OFF}
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
