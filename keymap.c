#include QMK_KEYBOARD_H

#include "print.h"

#include "keyboards/planck/rev7/keymaps/eilara/helpers.h"
#include "keyboards/planck/rev7/keymaps/eilara/keys.h"
#include "keyboards/planck/rev7/keymaps/eilara/colors.h"
#include "keyboards/planck/rev7/keymaps/eilara/layers.h"
#include "keyboards/planck/rev7/keymaps/eilara/tap_dance.h"
#include "keyboards/planck/rev7/keymaps/eilara/help.h"

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {4, 6, 12};

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

  switch (keycode) {
    // macros
    case HELP:
      if (pressed) {
        help();
        return false;
      }
      break;

    // ⌃w arrows
    case CWLFT:
      if (pressed) {
        SEND_STRING(SS_LCTL("w") SS_TAP(X_LEFT));
        return false;
      }
      break;
    case CWRGT:
      if (pressed) {
        SEND_STRING(SS_LCTL("w") SS_TAP(X_RIGHT));
        return false;
      }
      break;
    case CWUP:
      if (pressed) {
        SEND_STRING(SS_LCTL("w") SS_TAP(X_UP));
        return false;
      }
      break;
    case CWDN:
      if (pressed) {
        SEND_STRING(SS_LCTL("w") SS_TAP(X_DOWN));
        return false;
      }
      break;

    // programming bigrams and trigrams
    case M_ARR:
      if (pressed) {
        SEND_STRING("->");
        return false;
      }
      break;
    case M_DARR:
      if (pressed) {
        SEND_STRING(" => ");
        return false;
      }
      break;
    case M_EQL:
      if (pressed) {
        SEND_STRING(" === ");
        return false;
      }
      break;
    case M_NEQL:
      if (pressed) {
        SEND_STRING(" !== ");
        return false;
      }
      break;
    case M_LEQL:
      if (pressed) {
        SEND_STRING(" <= ");
        return false;
      }
      break;
    case M_MEQL:
      if (pressed) {
        SEND_STRING(" >= ");
        return false;
      }
      break;

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
  if (!is_caps_word_on()) {
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
    rgblight_setrgb(CLR_PINK);
  }
}
