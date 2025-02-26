#pragma once

static tap l7_tap_state   = {.is_press_action = true, .state = 0};
static tap ctrl_tap_state = {.is_press_action = true, .state = 0};
static tap meh_tap_state  = {.is_press_action = true, .state = 0};
static tap salt_tap_state = {.is_press_action = true, .state = 0};

void dance_semicolon(tap_dance_state_t *state, void *user_data) {
  SEND_STRING(state->count == 1 ? ";": state->count == 2 ? ":" : "::");
}

void l7_finished (tap_dance_state_t *state, void *user_data) {
  l7_tap_state.state = decode_dance(state);
  switch (l7_tap_state.state) {
    case SINGLE_TAP:
      tap_or_shift(KC_ESC, KC_GRV);
      break;
    case SINGLE_HOLD:
      layer_on(_L7_MOUSE);
      break;
    case DOUBLE_TAP:
      SEND_STRING(SS_LCTL("w") "q");
      break;
    case TRIPLE_TAP:
      SEND_STRING("\e:wa\n:qa\n");
      break;
  }
}

void l7_reset (tap_dance_state_t *state, void *user_data) {
  if (l7_tap_state.state == SINGLE_HOLD) {
    layer_off(_L7_MOUSE);
  }
  l7_tap_state.state = 0;
}

void ctrl_finished (tap_dance_state_t *state, void *user_data) {
  ctrl_tap_state.state = decode_dance(state);
  switch (ctrl_tap_state.state) {
    case SINGLE_TAP:
      tap_or_shift(KC_DLR, KC_EXLM);
      break;
    case SINGLE_HOLD:
      register_code16(KC_LCTL);
      break;
    case DOUBLE_TAP:
      SEND_STRING(SS_LCTL("w"));
      break;
  }
}

void ctrl_reset (tap_dance_state_t *state, void *user_data) {
  if (ctrl_tap_state.state == SINGLE_HOLD) {
    unregister_code16(KC_LCTL);
  }
  ctrl_tap_state.state = 0;
}

void meh_finished (tap_dance_state_t *state, void *user_data) {
  meh_tap_state.state = decode_dance(state);
  switch (meh_tap_state.state) {
    case SINGLE_TAP:
      SEND_STRING(SS_LCTL("p"));
      break;
    case SINGLE_HOLD:
      register_code16(KC_MEH);
      break;
    case DOUBLE_TAP:
      SEND_STRING(SS_LCTL("a") "\e");
      break;
  }
}

void meh_reset (tap_dance_state_t *state, void *user_data) {
  if (meh_tap_state.state == SINGLE_HOLD) {
    unregister_code16(KC_MEH);
  }
  meh_tap_state.state = 0;
}

void salt_finished (tap_dance_state_t *state, void *user_data) {
  salt_tap_state.state = decode_dance(state);
  switch (salt_tap_state.state) {
    case SINGLE_TAP:
      tap_or_shift(KC_BSLS, KC_PIPE);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_LSFT | MOD_LALT);
      break;
    case DOUBLE_TAP:
      SEND_STRING("\e:");
      break;
  }
}

void salt_reset (tap_dance_state_t *state, void *user_data) {
  if (salt_tap_state.state == SINGLE_HOLD) {
      unregister_mods(MOD_LSFT | MOD_LALT);
  }
  salt_tap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  // tap=;, shift=:, tap₂=:, tap₃=::
  [COS] = ACTION_TAP_DANCE_FN(dance_semicolon),

  // tap=escape, shift=~, hold=L₇, tap₂=⌃wq, tap₃=⎋:wa\nqa\n
  [ETQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l7_finished, l7_reset),

  // tap=$, shift=!, hold=⌃, tap₂=⌃w
  [DRX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),

  // tap=⌃p, hold=✦, tap₂=⌃a⎋
  [CPA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, meh_finished, meh_reset),

  // tap=\, shift=|, hold=⌥, tap₂=⎋:
  [BEQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, salt_finished, salt_reset)
};

