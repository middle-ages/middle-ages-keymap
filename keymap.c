#include QMK_KEYBOARD_H

#include "print.h"

#include "./helpers.h"
#include "./keys.h"
#include "./colors.h"
#include "./layers.h"
#include "./tap_dance.h"
#include "./macros.h"
#include "./help.h"

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {4, 6, 12};
bool is_one_shot_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;
  if (pressed && record->tap.count) { // custom mod/layer-taps
    switch (keycode) { //                   tap  shift hold
      case L2: //                            _          L2
        tap_code16(KC_UNDS);
        return false;
      case SFT1: //                          @     &    ⇧₁
        tap_or_shift(KC_AT, KC_AMPR);
        return false;
      case MTA: //                           *     #    ⎇
        tap_or_shift(KC_PAST, KC_HASH);
        return false;
      case MTCA: //                          ⌃a         ⌃⎇
        tap_code16(C(KC_A));
        return false;
    }
  }

  if (keycode >= FIRST_MACRO && keycode <= LAST_MACRO) {
    if (pressed) { dispatch_macro(keycode); }
    return false;
  }

  if (keycode >= HELP0 && keycode <= HELP8) {
    if (pressed) { dispatch_help(keycode); }
    return false;
  }

  switch (keycode) {
    // unicode
    case M_DQL:
      if (pressed) {
        send_unicode_string(" “");
        return false;
      }
      break;
    case M_DQR:
      if (pressed) {
        send_unicode_string("” ");
        return false;
      }
      break;

    // effects
    case QK_BOOT: // effect on reset
      if (pressed) {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      }
      break;
  }
  return true;
}

// set mod indicator
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!is_caps_word_on()) {
    set_mod_indicator(
      get_mods() & MOD_MASK_SHIFT,
      get_mods() & MOD_MASK_CTRL,
      get_mods() & MOD_MASK_ALT
    );
  }
}

// set layer indicator and tri layer
layer_state_t layer_state_set_user(layer_state_t state) {
  if (!is_caps_word_on() && !is_one_shot_on) {
    set_layer_indicator(state);
  }
  return update_tri_layer_state(state, _L1_LOWER, _L4_RAISE, _L8_ADJUST);
}

// snake animation on caps word
void caps_word_set_user(bool active) {
  if (active) {
    rgblight_mode(RGBLIGHT_MODE_SNAKE);
  } else {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(CLR_DIM);
  }
}

// breathing animation on help
void oneshot_layer_changed_user(uint8_t layer) {
  if (layer == _L9_HELP) {
    is_one_shot_on = true;
    rgblight_mode(RGBLIGHT_MODE_BREATHING + 3);
  }

  if (!layer) {
    is_one_shot_on = false;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(CLR_DIM);
  }
}
