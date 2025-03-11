#pragma once

static tap l7_tap_state   = {.is_press_action = true, .state = 0};
static tap ctrl_tap_state = {.is_press_action = true, .state = 0};
static tap meh_tap_state  = {.is_press_action = true, .state = 0};
static tap salt_tap_state = {.is_press_action = true, .state = 0};
static tap sft4_tap_state = {.is_press_action = true, .state = 0};

void dance_semicolon(tap_dance_state_t *state, void *user_data) {
  SEND_STRING(state->count == 1 ? ";": state->count == 2 ? ":" : "::");
}

void l7_finished(tap_dance_state_t *state, void *user_data) {
  l7_tap_state.state = dispatch_dance(
    state, KC_ESC, KC_GRV, SS_LCTL("w") "q", "\e:wa\n:qa\n", _L7_MOUSE, 0, 0
  );
  set_mod_indicator();
}

void l7_reset(tap_dance_state_t *state, void *user_data) {
  if (l7_tap_state.state == SINGLE_HOLD) { layer_off(_L7_MOUSE); }
  l7_tap_state.state = 0;
  set_mod_indicator();
}

void ctrl_finished(tap_dance_state_t *state, void *user_data) {
  ctrl_tap_state.state = dispatch_dance(
    state, KC_DLR, KC_EXLM, SS_LCTL("w"), NULL, 0, 0, KC_LCTL
  );
  set_mod_indicator();
}

void ctrl_reset(tap_dance_state_t *state, void *user_data) {
  if (ctrl_tap_state.state == SINGLE_HOLD) { unregister_code16(KC_LCTL); }
  ctrl_tap_state.state = 0;
  set_mod_indicator();
}

void meh_finished(tap_dance_state_t *state, void *user_data) {
  meh_tap_state.state = dispatch_dance(
    state, C(KC_P), S(C(KC_P)), SS_LCTL("a") "\e", NULL, 0, 0, KC_MEH
  );
  set_mod_rgb(CLR_WHITE);
}

void meh_reset(tap_dance_state_t *state, void *user_data) {
  if (meh_tap_state.state == SINGLE_HOLD) { unregister_code16(KC_MEH); }
  meh_tap_state.state = 0;
  set_mod_indicator();
}

void salt_finished(tap_dance_state_t *state, void *user_data) {
  salt_tap_state.state = dispatch_dance(
    state, KC_BSLS, KC_PIPE, "\e:", NULL, 0, MOD_LSFT, 0
  );
  set_mod_indicator();
}

void salt_reset(tap_dance_state_t *state, void *user_data) {
  if (salt_tap_state.state == SINGLE_HOLD) { unregister_mods(MOD_LSFT); }
  salt_tap_state.state = 0;
  set_mod_indicator();
}

void sft4_finished(tap_dance_state_t *state, void *user_data) {
  sft4_tap_state.state = dispatch_dance(
    state, KC_QUOT, S(KC_QUOT), SS_LSFT(SS_LCTL("p")), "''", 0, MOD_LSFT, 0
  );
  set_mod_indicator();
}

void sft4_reset(tap_dance_state_t *state, void *user_data) {
  if (sft4_tap_state.state == SINGLE_HOLD) { unregister_mods(MOD_LSFT); }
  sft4_tap_state.state = 0;
  set_mod_indicator();
}

tap_dance_action_t tap_dance_actions[] = {
  // tap=;, shift=:, tap₂=:, tap₃=::
  [COS] = ACTION_TAP_DANCE_FN(dance_semicolon),

  // tap=escape, shift=~, hold=L₇, tap₂=⌃wq, tap₃=⎋:wa\nqa\n
  [ETQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l7_finished, l7_reset),

  // tap=$, shift=!, hold=⌃, tap₂=⌃w
  [DRX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),

  // tap=⌃p, shift=⇪p, hold=✦, tap₂=⌃a⎋
  [CPA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, meh_finished, meh_reset),

  // tap=\, shift=|, hold=⌥, tap₂=⎋:
  [BEQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, salt_finished, salt_reset),

  // tap=\, shift=", hold=⇧, tap₂=⇪p
  [SFT4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft4_finished, sft4_reset)
};

