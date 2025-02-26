#pragma once

enum {
  TD_UNKNOWN = 0,
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
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

int dispatch_dance(
  tap_dance_state_t *state,
  uint16_t    tap,   // key to tap on single tap
  uint16_t    shift, // key to tap on shift + single tap
  const char* tap2,  // string to send on double tap
  const char* tap3,  // string to send on triple tap or NULL
  uint8_t     layer, // layer to activate on hold or zero for none
  uint8_t     mods,  // mods to activate on hold or zero for none
  uint16_t    hold   // key to hold on hold or zero for none
) {
  int decoded = decode_dance(state);
  switch (decoded) {
    case SINGLE_TAP:
      tap_or_shift(tap, shift);
      break;
    case SINGLE_HOLD:
      if (layer != 0) { layer_on(layer); }
      if (mods  != 0) { register_mods(mods); }
      if (hold  != 0) { register_code16(hold); }
      break;
    case DOUBLE_TAP:
      send_string(tap2);
      break;
    case TRIPLE_TAP:
      if (tap3 != NULL) { send_string(tap3); }
      break;
  }
  return decoded;
}
