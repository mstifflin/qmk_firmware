#include QMK_KEYBOARD_H
#include "version.h"

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
#define LAYER_MISC_CTRL 2
#define LAYER_NUM_PAD 3
#define LAYER_WINDOWS 4

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
  TEAL_LIGHTS,
  BLUE_LIGHTS,
  GREEN_LIGHTS,
  ORANGE_LIGHTS,
  PURPLE_LIGHTS,
  RED_LIGHTS,
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
    KC_ESC   , KC_1   , KC_2          , KC_3          , KC_4          , KC_5          , _______       ,
    KC_TAB   , KC_Q   , KC_W          , KC_E          , KC_R          , KC_T          , KC_LBRACKET   ,
    KC_LCTRL , KC_A   , KC_S          , KC_D          , KC_F          , KC_G          ,
    KC_LSHIFT, KC_Z,    KC_X          , KC_C          , KC_V          , KC_B          , KC_RBRACKET   ,
    KC_LCTRL , KC_LALT, _______       , KC_LCTRL      , KC_LALT       ,

                                                                             MO(LAYER_NUM_PAD),          KC_SPACE,
                                                                                                  KC_AUDIO_VOL_UP,
                                                                    KC_LGUI, MO(LAYER_MISC_CTRL), KC_AUDIO_VOL_DOWN,

    // Right hand
    _______    , KC_6   , KC_7          , KC_8          , KC_9          , KC_0          , KC_BSPACE     ,
    KC_EQUAL   , KC_Y   , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLASH     ,
                 KC_H   , KC_J          , KC_K          , KC_L          , KC_SCOLON     , KC_QUOTE      ,
    KC_MINUS   , KC_N   , KC_M          , KC_COMMA      , KC_DOT        , KC_SLASH      , KC_LSHIFT     ,
    KC_GRV,      _______, _______       , _______       , KC_LCTRL      ,

    KC_MPRV, KC_CAPSLOCK,
    KC_MNXT,
    KC_MPLY, MO(LAYER_MOUSE_CTRL), LT(LAYER_MISC_CTRL, KC_SPACE)
   ),

  [LAYER_WINDOWS] = LAYOUT_ergodox(
    // Left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LGUI, KC_LALT,
                                                 _______, _______,
                                                          _______,
                                       KC_SPACE, _______, _______,

    // Right hand
    _______, _______, _______, _______ , _______ , _______, _______ ,
    _______, _______, _______, _______ , _______ , _______, _______ ,
             _______, _______, _______ , _______ , _______ , _______,
    _______, _______, _______, _______ , _______ , _______, _______ ,
    _______, _______, _______, _______ , _______ ,

    _______, _______,
    _______,
    _______, _______, _______
  ),

  [LAYER_MISC_CTRL] = LAYOUT_ergodox(
    // Left hand
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    // Right hand
    KC_F7,   KC_F8,   KC_F9,     KC_F10,   KC_F11,   KC_F12,  KC_DEL,
    _______, KC_LBRC, KC_MINUS,  KC_EQUAL, KC_RBRC , KC_PIPE, _______ ,
             KC_LEFT, KC_DOWN,   KC_UP,    KC_RIGHT, _______, KC_ENTER,
    _______, KC_HOME, KC_PGDOWN, KC_PGUP,  KC_END,   _______, _______ ,
    _______, _______, _______ ,  _______ , TG(LAYER_WINDOWS) ,

    _______, _______,
    _______,
    _______, _______, _______
  ),

  [LAYER_NUM_PAD] = LAYOUT_ergodox(
    // Left hand
    TEAL_LIGHTS    , BLUE_LIGHTS    , GREEN_LIGHTS   , ORANGE_LIGHTS  , PURPLE_LIGHTS  , RED_LIGHTS     , _______        ,
    _______        , RGB_MOD        , RGB_SLD        , RGB_VAD        , RGB_VAI        , _______        , _______        ,
    _______        , RGB_TOG        , RGB_HUD        , RGB_HUI        , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        , _______        , _______        ,
    _______        , _______        , _______        , _______        , _______        ,

                     _______        , _______        ,
                                      _______        ,
    _______        , _______        , _______        ,

    // Right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    _______, _______, _______,
             KC_4,    KC_5,    KC_6,    _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, KC_0  , _______
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
    _______            , KC_F6              , KC_F7              , KC_F8              , KC_F9              , KC_F10      , _______,
    _______            , _______            , _______            , KC_MS_WH_UP        , _______            , _______     , _______,
                         _______            , KC_MS_WH_LEFT      , KC_MS_WH_DOWN      , KC_MS_WH_RIGHT     , _______     , _______,
    _______            , _______            , KC_MS_ACCEL0       , KC_MS_ACCEL1       , KC_MS_ACCEL2       , _______     , _______,
    _______            , _______            , _______            , _______            , _______            ,
    _______            , _______            ,
    _______            ,
    _______            , _______            , _______
  ),
};

rgblight_config_t rgblight_config;
bool disable_layer_color = 1;

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
    case TEAL_LIGHTS:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(130,237,128);
        #endif
      }
      return false;
    case BLUE_LIGHTS:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(172,255,255);
        #endif
      }
      return false;
    case GREEN_LIGHTS:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case ORANGE_LIGHTS:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(27,255,255);
        #endif
      }
      return false;
    case PURPLE_LIGHTS:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(215,255,128);
        #endif
      }
      return false;
    case RED_LIGHTS:
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
