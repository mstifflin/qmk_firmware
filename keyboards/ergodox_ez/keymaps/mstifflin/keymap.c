#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

#define LAYER_BASE 0
#define LAYER_MOUSE_CTRL 1
#define LAYER_LIGHT_CTRL 2
#define LAYER_SYMBOL 3

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  HSV_215_255_128,
  HSV_0_255_255,
};

/* Keymap
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox(
    // Left hand
    KC_GRV        , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , _______       ,
    KC_TAB        , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , _______       ,
    KC_ESC        , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          ,
    KC_LSHIFT     , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , _______       ,
    _______       , KC_LCTRL      , KC_LALT       , KC_LGUI       , MO(1)         ,
    _______       , _______       ,
    _______       ,
    KC_BSPACE     , _______       , _______       ,

    // Right hand
    KC_PGUP       , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINUS      ,
    KC_LBRACKET   , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLASH     ,
                    KC_H          , KC_J          , KC_K          , KC_L          , KC_SCOLON     , KC_QUOTE      ,
    KC_RBRACKET   , KC_N          , KC_M          , KC_COMMA      , KC_DOT        , KC_SLASH      , KC_LSHIFT     ,
    KC_SPACE      , MO(2)         , KC_HYPR       , _______       , KC_LCTRL      ,
    KC_KP_MINUS   , KC_KP_ASTERISK,
    KC_KP_PLUS    ,
    KC_EQUAL      , _______       , KC_ENTER
  ),

  [LAYER_MOUSE_CTRL] = LAYOUT_ergodox(
    // Left hand
    _______            , KC_F1              , KC_F2              , KC_F3              , KC_F4              , KC_F5              , _______            ,
    _______            , _______            , _______            , KC_MS_UP           , _______            , _______            , _______            ,
    _______            , _______            , KC_MS_LEFT         , KC_MS_DOWN         , KC_MS_RIGHT        , _______            ,
    _______            , _______            , _______            , _______            , _______            , _______            , _______            ,
    _______            , _______            , _______            , _______            , _______            ,
    KC_MS_BTN3         , _______            ,
    _______            ,
    KC_MS_BTN1         , KC_MS_BTN2         , _______            ,

    // Right hand
    _______            , KC_F6              , KC_F7              , KC_F8              , KC_F9              , KC_F10             , KC_MEDIA_PLAY_PAUSE,
    _______            , _______            , _______            , KC_MS_WH_UP        , KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_UP    ,
                         _______            , KC_MS_WH_LEFT      , KC_MS_WH_DOWN      , KC_MS_WH_RIGHT     , _______            , KC_AUDIO_VOL_DOWN  ,
    _______            , _______            , KC_MS_ACCEL0       , KC_MS_ACCEL1       , KC_MS_ACCEL2       , _______            , KC_AUDIO_MUTE      ,
    _______            , _______            , _______            , _______            , _______            ,
    _______            , _______            ,
    _______            ,
    _______            , _______            , _______
  ),

  [LAYER_LIGHT_CTRL] = LAYOUT_ergodox(
    // Left hand
    _______        , _______        , HSV_172_255_255, HSV_86_255_128 , HSV_27_255_255 , HSV_215_255_128, HSV_0_255_255  ,
    _______        , _______        , _______        , _______        , _______        , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        ,
    RGB_MOD        , RGB_SLD        ,
    _______        ,
    RGB_VAD        , RGB_VAI        , _______        ,

    // Right hand
    _______        , _______        , _______        , _______        , _______        , _______        , _______        ,
    _______        , _______        , KC_HOME        , _______        , KC_END         , _______        , _______        ,
                     KC_LEFT        , KC_DOWN        , KC_UP          , KC_RIGHT       , _______        , _______        ,
    _______        , _______        , KC_PGUP        , _______        , KC_PGDOWN      , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        ,
    RGB_TOG        , _______        ,
    _______        ,
    _______        , RGB_HUD        , RGB_HUI
  ),
};

rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(172,255,255);
        #endif
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(27,255,255);
        #endif
      }
      return false;
    case HSV_215_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(215,255,128);
        #endif
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

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
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
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
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(130,237,217);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,230,217);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};
