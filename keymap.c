// Tim's keymap for the GRID-layout Planck with MX Lockswitch at bottom left corner

#include "planck.h"
#include "action.h"
#include "action_tapping.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _LOCK 5
#define _PLOVER 6
#define _ADJUST 16

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define COLEMAK M(_COLEMAK)	
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define LOCK MO(_LOCK)
#define PLOVER M(12)
#define EXT_PLV M(13)
#define TOG_OUT M(14)
#define M_BL 6

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Keymap definitions
#define RSPC_KEY KC_0
#define RCADET MT(MOD_LSFT, KC_RPRN) //Attempt to fix RSPC
#define CADEL LCTL(LALT(KC_DEL)) 


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPO |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock | Ctrl | GUI  | Alt  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {LOCK,    KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPO |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock | Ctrl | GUI  | Alt  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {LOCK,    KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPO |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock | Ctrl | GUI  | Alt  |Lower | Space| Enter|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC},
  {LOCK,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |  XX  |  XX  |  XX  |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |BL Tog|BL Dwn|BL Up | CADEL|  XX  |  XX  |   _  |   +  |  XX  |  XX  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | End  | PgDwn| PgUp | Home |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, BL_TOGG, BL_DEC,  BL_INC,  CADEL,   XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_PGUP, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  XX  |  XX  |  XX  |  XX  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |PrtScn|  XX  |MedPrv|MedNxt|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PSCR, XXXXXXX, KC_MPRV, KC_MNXT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY}
},



/* LOCK
 * ,-----------------------------------------------------------------------------------.
 * |      |  XX  |MsBtn3|  XX  |ScrlUp|  XX  |  XX  |  XX  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MsBtn2| MsUp |MsBtn1|SclDwn|  XX  |  Up  |  XX  |   4  |   5  |   6  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | MsLft| MsDwn|MsRght|  XX  | Left | Down | Right|   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  XX  |      |      |  XX  |   0  |   0  |   .  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
 [_LOCK] = {
  {_______, XXXXXXX, KC_BTN3, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,  KC_P8,  KC_P9,   KC_BSPC},
  {_______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX, KC_UP,   XXXXXXX, KC_P4,  KC_P5,  KC_P6,   KC_PENT},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_P1,  KC_P2,  KC_P3,   KC_PENT},
  {_______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, KC_P0,  KC_P0,  KC_PDOT, KC_PENT}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |	q
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  XX  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |  XX  |  XX  |   A  |   O  |  XX     XX  |   E  |   U  |  XX  |  XX  |  XX  |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {TOG_OUT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |Reset |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, RESET,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          break;
        case _COLEMAK:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_colemak, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_COLEMAK);
          }
          break;
        case _DVORAK:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_DVORAK);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case M_BL:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case 12:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              stop_all_notes();
              PLAY_NOTE_ARRAY(tone_plover, false, 0);
            #endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_PLOVER);
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
          }
        break;
        case 13:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
            #endif
            layer_off(_PLOVER);
          }
        break;
        case 14:
          if (record->event.pressed) {
            return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
