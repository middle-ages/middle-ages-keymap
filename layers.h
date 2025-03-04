#pragma once

// clang-format off
/**
 *     Tap₀ ┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┳━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━┓ Shift₀
 *          ┃ ⎋ ┊ Q ┊ W ┊ E ┊ R ┊ T ┊ Y ┊ U ┊ I ┊ O ┊ P ┊ \ ┃ ~ ┊                                       ┊ | ┃
 *          ┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╂───┤                                   ┌───┼───┨
 *          ┃ ⇥ ┊ A ┊ S ┊ D ┊ F ┊ G ┊ H ┊ J ┊ K ┊ L ┊ ; ┊ ⎆ ┃ ⇤ ┊                                   ┊ : ┊   ┃
 *          ┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╂───┤                           ┌───┬───┼───┼───┨
 *          ┃ @ ┊ Z ┊ X ┊ C ┊ V ┊ B ┊ N ┊ M ┊ , ┊ . ┊ / ┊ ' ┃ & ┊                           ┊ < ┊ > ┊ ? ┊ " ┃
 *          ┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╂───┤   ┌───┐                   └───┴───┴───┴───┨
 *          ┃ $ ┊ ◆ ┊ * ┊ ⌫ ┊ + ┊ _ ┊ ␣ ┊ - ┊ ⌦ ┊⎄  ┊⌃a ┊⌃p ┃ ! ┊   ┊ # ┊                                   ┃
 *          ┣━━━┿━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┿━━━╋━━━┿━━━┷━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━┫
 *    Hold₀ ┃L7 ┊                                       ┊ ⌥ ┃vwq┊                                       ┊◆⇥ ┃ Double Tap₀
 *          ┠───┤                                       ├───╂───┤                                   ┌───┼───┨
 *          ┃L6 ┊                                       ┊ ⇪ ┃⎋: ┊                                   ┊ : ┊   ┃
 *          ┠───┼───┐                               ┌───┼───╂───┘                                   └───┼───┨
 *          ┃ ⇧ ┊ ⇧ ┊                               ┊ ⇧ ┊ ⇧ ┃                                           ┊⇪p ┃
 *          ┠───┼───┼───┐   ┌───┬───┬───┬───┐   ┌───┼───┼───╂───┐                                       ├───┨
 *          ┃ ⌃ ┊ ◆ ┊ ⎇ ┊   ┊L1 ┊L2 ┊L3 ┊L4 ┊   ┊L5 ┊⌃⎇ ┊ ✦ ┃⌃w ┊                                       ┊⌃a⎋┃
 *          ┗━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┷━━━┻━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━┛
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_L0_BASE] = LAYOUT_planck_grid(
  TDETQ,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TDBEQ,
  L6,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TDCOS,   MTCS,
  SFT1,    SFT2,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT3,    SFT4,
  TDDRX,   KC_LGUI, MTA,     KC_BSPC, L1,      L2,      L3,      L4,      KC_DEL,  L5,      MTCA,    TDCPA
),
/**
 *   Lower₁ ┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┓
 *          ┃ 🄰 ┊ ( ┊ ) ┊ 7 ┊ 8 ┊ 9 ┊⌃w←┊⌃w↓┊⌃w↑┊⌃w→┊ { ┊ } ┃
 *          ┠───┴───┴───┼───┼───┼───┼───┴───┴───┴───┼───┼───┨
 *          ┃           ┊ 4 ┊ 5 ┊ 6 ┊               ┊ [ ┊ ] ┃
 *          ┃           ├───┼───┼───┼               └───┴───┨
 *          ┃           ┊ 1 ┊ 2 ┊ 3 ┊                       ┃
 *          ┃           ├───┼───┼───┼───┐       ┌───┬───┬───┨
 *          ┃           ┊ 0 ┊L1 ┊⌃⇤ ┊⌃⇥ ┊       ┊ ▤ ┊ 🔉┊🔊 ┃
 *          ┗━━━━━━━━━━━┷━━━┷━━━┷━━━┷━━━┷━━━━━━━┷━━━┷━━━┷━━━┛
 */
[_L1_LOWER] = LAYOUT_planck_grid(
  CW_TOGG, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    CWLFT,   CWDN,    CWUP,    CWRGT,   KC_LCBR, KC_RCBR,
  _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, KC_LBRC, KC_RBRC,
  _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_0,    _______, CBTB,    CTB,     _______, _______, KC_APP,  KC_VOLD, KC_VOLU
),
/**
 *      Os₂ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━┓
 *          ┃                                           ┊◆⇥ ┃
 *          ┃       ┌───┐           ┌───┬───┬───┬───┐   └───┨
 *          ┃       ┊📷 ┊           ┊⌃◆←┊⌃◆↓┊⌃◆↑┊⌃◆→┊       ┃
 *          ┃       └───┼───┬───┬───┼───┼───┴───┴───┘       ┃
 *          ┃           ┊ ⟳ ┊ ⤺ ┊ ⤻ ┊⌃o ┊                   ┃
 *          ┃           └───┴───┼───┼───┼───┐               ┃
 *          ┃                   ┊L2 ┊gT ┊gt ┊               ┃
 *          ┗━━━━━━━━━━━━━━━━━━━┷━━━┷━━━┷━━━┷━━━━━━━━━━━━━━━┛
 *
 */
[_L2_OS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, GTAB,
  _______, _______, SGS,     _______, _______, _______, CGLFT,   CGDN,    CGUP,    CGRGT,   _______, _______,
  _______, _______, _______, SF5,     QK_AREP, QK_REP,  CS6,     C(KC_O), _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, M_VTL,   M_VTR,   _______, _______, _______, _______
),
/**
 *     Sym₃ ┏━━━┯━━━┯━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 *          ┃   ┊ ‘ ┊ ’ ┊                                   ┃
 *          ┃   └───┴───┘                           ┌───┬───┨
 *          ┃                                       ┊❌ ┊✅ ┃
 *          ┃                   ┌───┬───┬───┬───┐   └───┴───┨
 *          ┃                   ┊ % ┊ = ┊ ` ┊ ^ ┊           ┃
 *          ┃                   └───┼───┼───┼───┤           ┃
 *          ┃                       ┊L3 ┊⎇⇤ ┊⎇⇥ ┊           ┃
 *          ┗━━━━━━━━━━━━━━━━━━━━━━━┷━━━┷━━━┷━━━┷━━━━━━━━━━━┛
 */
[_L3_SYM] = LAYOUT_planck_grid(
  _______, M_SQL,   M_SQR,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_NO,    M_YES,
  _______, _______, _______, _______, _______, KC_PERC, KC_EQL,  KC_GRV,  KC_CIRC, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, ABTB,    ATB,     _______, _______, _______
),
/**
 *   Raise₄ ┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━━━━━━━━━━━━━━━━━━━━━┓
 *          ┃   ┊ “ ┊ ” ┊F7 ┊F8 ┊F9 ┊                       ┃
 *          ┃   └───┴───┼───┼───┼───┤                   ┌───┨
 *          ┃           ┊F4 ┊F5 ┊F6 ┊                   ┊->␣┃
 *          ┃   ┌───┬───┼───┼───┼───┤       ┌───┬───┬───┼───┨
 *          ┃   ┊F12┊F11┊F1 ┊F2 ┊F3 ┊       ┊<=␣┊>=␣┊!==┊=>␣┃
 *          ┃   └───┴───┼───┼───┴───┘   ┌───┼───┴───┼───┼───┨
 *          ┃           ┊F10┊           ┊L4 ┊       ┊===┊   ┃
 *          ┗━━━━━━━━━━━┷━━━┷━━━━━━━━━━━┷━━━┷━━━━━━━┷━━━┷━━━┛
 */
[_L4_RAISE] = LAYOUT_planck_grid(
  _______, M_DQL,   M_DQR,   KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, M_ARR,
  _______, KC_F12,  KC_F11,  KC_F1,   KC_F2,   KC_F3,   _______, _______, M_LEQL,  M_MEQL,  M_NEQL,  M_DARR,
  _______, _______, _______, KC_F10,  _______, _______, _______, _______, _______, _______, M_EQL, _______
),
/**
 * Unicode₅ ┏━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┓
 *          ┃ ∅ ┊ ∧ ┊ ∨ ┊ ± ┊ ⊑ ┊ ⊆ ┊ ⇐ ┊ ⇔ ┊ ↔ ┊ ⇒ ┊ ⊇ ┊ ⊒ ┃
 *          ┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┨
 *          ┃ ⤕ ┊ ∩ ┊ ∪ ┊ ∈ ┊ ⊏ ┊ ⊂ ┊ ← ┊ ↓ ┊ ↑ ┊ → ┊ ⊃ ┊ ⊐ ┃
 *          ┠───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┨
 *          ┃ ¬ ┊ ⚬ ┊ 🞄 ┊ ç ┊ ℕ ┊ ℝ ┊ ∀ ┊ ∃ ┊ ≤ ┊ ≥ ┊ ≠ ┊ ÷ ┃
 *          ┠───┼───┴───┴───┴───┴───┴───┴───┴───┴───┴───┼───┨
 *          ┃ ⎈ ┊                                       ┊ × ┃
 *          ┗━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━┛
 */
[_L5_UNICODE] = LAYOUT_planck_grid(
  M_1_1,   M_1_2,   M_1_3,   M_1_4,   M_1_5,   M_1_6,   M_1_7,   M_1_8,   M_1_9,   M_1_10,   M_1_11, M_1_12,
  M_2_1,   M_2_2,   M_2_3,   M_2_4,   M_2_5,   M_2_6,   M_2_7,   M_2_8,   M_2_9,   M_2_10,   M_2_11, M_2_12,
  M_3_1,   M_3_2,   M_3_3,   M_3_4,   M_3_5,   M_3_6,   M_3_7,   M_3_8,   M_3_9,   M_3_10,   M_3_11, M_3_12,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M_4_12
),
/**
 *     Nav₆ ┏━━━━━━━━━━━━━━━━━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┯━━━┓
 *          ┃                   ┊⇧↖ ┊ ↖ ┊ ⇟ ┊ ⇞ ┊ ↗ ┊⇧↗ ┊ ⎀ ┃
 *          ┠───┬───┬───┐       ├───┼───┼───┼───┼───┼───┼───┨
 *          ┃L6 ┊ ⌃ ┊ ⎇ ┊       ┊⇧← ┊ ← ┊ ↓ ┊ ↑ ┊ → ┊⇧→ ┊   ┃
 *          ┠───┼───┼───┘       └───┴───┼───┼───┼───┴───┘   ┃
 *          ┃   ┊⌃⎇ ┊                   ┊⇧↓ ┊⇧↑ ┊           ┃
 *          ┃   └───┘                   ├───┼───┤           ┃
 *          ┃                           ┊⇧⇟ ┊⇧⇞ ┊           ┃
 *          ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━┷━━━┷━━━━━━━━━━━┛
 */
[_L6_NAV] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, SHOM,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  SHEND,   KC_INS,
  _______, MC,      MA,      _______, _______, SLFT,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SRGT,    _______,
  _______, MCA,     _______, _______, _______, _______, _______, SDN,     SUP,     _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, SPDN,    SPUP,    _______, _______, _______
),
/**
 *   Mouse₇ ┏━━━┯━━━┯━━━━━━━━━━━━━━━┯━━━┯━━━┯━━━┯━━━┯━━━━━━━┓
 *          ┃L7 ┊⎇F4┊               ┊🖯 ←┊🖯 ↓┊🖯 ↑┊🖯 →┊       ┃
 *          ┠───┼───┤               ├───┼───┼───┼───┤       ┃
 *          ┃   ┊ ⎙ ┊               ┊🖱←┊🖱↓┊🖱↑┊🖱→┊       ┃
 *          ┃   ├───┤               ├───┼───┼───┼───┘       ┃
 *          ┃   ┊ ⎉ ┊               ┊Mb₁┊Mb₂┊Mb₃┊           ┃
 *          ┃   ├───┤               └───┴───┴───┘           ┃
 *          ┃   ┊ ⎊ ┊                                       ┃
 *          ┗━━━┷━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 */
[_L7_MOUSE] = LAYOUT_planck_grid(
  _______, AF4,     _______, _______, _______, _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, QK_BOOT,
  _______, KC_PSCR, _______, _______, _______, _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______,
  _______, KC_BRK,  _______, _______, _______, _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______, _______,
  _______, KC_SCRL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/**
 *  Adjust₈ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━┯━━━┓
 *          ┃                                       ┊Clr┊Rst┃
 *          ┠───┬───┬───┐           ┌───┐   ┌───┬───┼───┼───┨
 *          ┃🔊T┊🔊-┊🔊+┊           ┊Hlp┊   ┊🔆⁺┊🔆⁻┊🔆⤺┊🔆⤻┃
 *          ┠───┴───┴───┘           └───┘   └───┴───┼───┼───┨
 *          ┃                                       ┊🔆-┊🔆+┃
 *          ┠───┐            ┌───┐      ┌───┐   ┌───┼───┼───┨
 *          ┃ ☾ ┊            ┊L8 ┊      ┊L8 ┊   ┊T⎙ ┊TT-┊TT+┃
 *          ┗━━━┷━━━━━━━━━━━━┷━━━┷━━━━━━┷━━━┷━━━┷━━━┷━━━┷━━━┛
 */
[_L8_ADJUST] = LAYOUT_planck_grid(
  UG_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, EE_CLR,  QK_BOOT,
  AU_TOGG, AU_OFF,  AU_ON,   _______, _______, _______, HELP,    _______, UG_SPDD, UG_SPDU, UG_PREV, UG_NEXT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, UG_VALD, UG_VALU,
  KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, DT_PRNT, DT_DOWN, DT_UP
),
/**
 *    Help₉ ┏━━━━━━━━━━━┯━━━┯━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 *          ┃           ┊ 7 ┊ 8 ┊                           ┃
 *          ┃           ├───┼───┼───┐                       ┃
 *          ┃           ┊ 4 ┊ 5 ┊ 6 ┊                       ┃
 *          ┃           ├───┼───┼───┤                       ┃
 *          ┃           ┊ 1 ┊ 2 ┊ 3 ┊                       ┃
 *          ┃           ├───┼───┴───┘                       ┃
 *          ┃           ┊ 0 ┊                               ┃
 *          ┗━━━━━━━━━━━┷━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 */
[_L9_HELP] = LAYOUT_planck_grid(
  _______, _______, _______, HELP7,   HELP8,   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, HELP4,   HELP5,   HELP6,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, HELP1,   HELP2,   HELP3,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, HELP0,   _______, _______, _______, _______, _______, _______, _______, _______
)
};
// clang-format on

/**
 *   ⇧ shift       ⌃ ctrl         ⎇ alt         ◆ gui           ⇪ ⌃⇧          ⌥ ⇧⎇          ✦ ⇪⎇        vwq ⎋:wq⎆     Rst KC_BOOT     Hlp Help
 *   ← KC_LEFT     ↓ KC_DOWN      ↑ KC _UP      → KC_RGHT       ↖ KC_HOME     ⇞ KC_PGUP     ⇟ KC_PGDN     ↗ KC_END      ⟳ S(KC_F5)      ⎈ leader-negate
 * 🖯 ← MS_WHLL   🖯 ↓ MS_WHLD    🖯 ↑ MS_WHLU   🖯 → MS_WHLR     🖱← MS_LEFT   🖱↓ MS_DOWN   🖱↑ MS_UP     🖱→ MS_RGHT     ⎀ KC_INS        ⎆ KC_ENT
 * Mb₁ MS_BTN1   Mb₂ MS_BTN2    Mb₃ MS_BTN3    ⎄  KC_F19        ⎉ KC_BRK      ▤ KC_APP     ⎙  KC_PSCR     ☾ KC_SLEP     ␣ KC_SPC        ⎋ KC_ESC
 *   ⌫ KC_BSPC     ⌦ KC_DEL       ⇥ KC_TAB      ⇤ S(KC_TAB)     ⤺ QK_AREP     ⤻ QK_REP    🔆- UG_VALD   🔆+ UG_VALU    📷 S(G(KC_S))    🔒KC_SCRL
 *  🔉 KC_VOLD    🔊 KC_VOLU    TT- DT_DOWN   TT+ DT_UP      TT⎙  DT_PRNT     🄰 CW_TOGG   Clr EE_CLR
 * 🔉T AU_TOGG   🔊- AU_OFF     🔊+ AU_ON
 */

