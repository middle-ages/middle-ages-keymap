#pragma once

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6,
  TD_UNKNOWN = 7
};

typedef struct {bool is_press_action; int state;} tap;

int decode_dance(tap_dance_state_t *state) {
  return state->count == 1
    ? state->pressed
      ? SINGLE_HOLD: SINGLE_TAP
    : state->count == 2
      ? state->pressed
        ? DOUBLE_HOLD: DOUBLE_TAP
    : state->count == 3
      ? (state->interrupted || !state->pressed)
        ? TRIPLE_TAP: TRIPLE_HOLD
    : TD_UNKNOWN;
}

// tap first given code or second if shift is pressed
void tap_or_shift(uint16_t tap, uint16_t shift) {
  if (get_mods() & MOD_MASK_SHIFT) {
    tap_code16(shift);
  } else {
    tap_code16(tap);
  }
}
