#pragma once

enum planck_layers {
  _L0_BASE,
  _L1_LOWER,
  _L2_OS,
  _L3_SYM,
  _L4_RAISE,
  _L5_UNICODE,
  _L6_NAV,
  _L7_MOUSE,
  _L8_ADJUST,
  _L9_HELP     // internal layer used for showing per-layer help
};

enum planck_keycodes {                  // layers toggle keys
  L1 = SAFE_RANGE,                      //         1. LOWER
  L2,                                   //         2. OS
  L3,                                   //         3. SYM
  L4,                                   //         4. RAISE
  L5,                                   //         5. UNICODE
  L6,                                   //         6. NAV
                                        //         7. MOUSE (toggled in tap-dance)
                                        //         8. ADJUST = LOWER + RAISE
                                        //
                                        // layer help keys on _L9_HELP
  HELP0,                                // layer 1 help
  HELP1,                                //       2
  HELP2,                                //       3
  HELP3,                                //       4
  HELP4,                                //       5
  HELP5,                                //       6
  HELP6,                                //       7
  HELP7,                                //       8
  HELP8,                                //
                                        // custom mod-tap keycodes
                                        //         TAP              SHIFT
  ATAMP,                                //          @                 &
  ATHAS,                                //          *                 #
  UNDER,                                //          _                 ⌃
  CTRLA,                                //         ⌃a
                                        //
  FIRST_MACRO,                          // macros
  CWLFT,                                //  1. ⌃w←
  CWRGT,                                //  2. ⌃w→
  CWUP,                                 //  3. ⌃w↑
  CWDN,                                 //  4. ⌃w↓
  M_ARR,                                //  5. “-” “>”
  M_DARR,                               //  6. “=” “>”
  M_EQL,                                //  7. “=” “=” “=”
  M_NEQL,                               //  8. “!” “=” “=”
  M_LEQL,                               //  9. “<” “=”
  M_MEQL,                               // 10. “>” “=”
  M_VTL,                                // 11. “g” “T”
  M_VTR,                                // 12. “g” “t”
  LAST_MACRO,                           //
                                        //
  FIRST_UNICODE_MACRO,                  // unicode macros
  M_DQL,                                //  • “
  M_DQR,                                //  • ”
  M_SQL,                                //  • ‘
  M_SQR,                                //  • ’
  M_NO,                                 //  • ❌
  M_YES,                                //  • ✅
                                        //
  M_1_1, M_1_2, M_1_3, M_1_4, M_1_5, M_1_6, M_1_7, M_1_8, M_1_9, M_1_10, M_1_11, M_1_12,
  M_2_1, M_2_2, M_2_3, M_2_4, M_2_5, M_2_6, M_2_7, M_2_8, M_2_9, M_2_10, M_2_11, M_2_12,
  M_3_1, M_3_2, M_3_3, M_3_4, M_3_5, M_3_6, M_3_7, M_3_8, M_3_9, M_3_10, M_3_11, M_3_12,
                                                                                 M_4_12,
  LAST_UNICODE_MACRO,                   //
};                                      //
                                        //
enum {                                  // tap-dance keycodes               TAP²           TAP³
  COS,                                  //          :                        ;              ;
  ETQ,                                  //          ⎋     L7_MOUSE    ~     ⌃wq         ⎋:wa\nqa\n
  DRX,                                  //          $       ⌃         !     ⌃w
  CPA,                                  //         ⌃p       ✦               ⌃a⎋
  BEQ                                   //          \       ⌥         |     ⎋:
};                                      //
                                        //
                                        //         TAP     HOLD     SHIFT
                                        //
                                        // custom mod-tap keys
#define L2     LT(_L2_OS,      UNDER)   //          _     L2_OS
#define SFT1   SFT_T(ATAMP)             //          @     ⇧           &
#define MTA    ALT_T(ATHAS)             //          *     ⎇           #
#define MTCA   LCA_T(CTRLA)             //          ⌃a    ⌃⎇
                                        //
                                        // layer mod-tap keys
#define L1     LT(_L1_LOWER,   KC_PPLS) //          +     L1_LOWER
#define L3     LT(_L3_SYM,     KC_SPC)  //          ␣     L3_SYM
#define L4     LT(_L4_RAISE,   KC_PMNS) //          -     L4_RAISE
#define L5     LT(_L5_UNICODE, KC_F19)  //        F19     L5_UNICODE
#define L6     LT(_L6_NAV,     KC_TAB)  //          ⇥     L6_NAV
#define HELP   OSL(_L9_HELP)            // one-shot help layer
                                        // mod-tap keys
                                        //         TAP     HOLD     SHIFT
#define SFT2   SFT_T(KC_Z)              //          z     ⇧           Z
#define SFT3   SFT_T(KC_SLSH)           //          /     ⇧           ?
#define SFT4   SFT_T(KC_QUOT)           //          '     ⇧           "
#define MTCS   C_S_T(KC_ENT)            //          ⎆     ⇪
                                        // mods inside layers
#define MC     KC_LCTL                  //                ⌃
#define MA     KC_LALT                  //                ⎇
#define MCA    LCTL(KC_LALT)            //               ⌃⎇
                                        // ⇧ motions
#define SLFT   S(KC_LEFT)               //          ⇧←
#define SDN    S(KC_DOWN)               //          ⇧↓
#define SUP    S(KC_UP)                 //          ⇧↑
#define SRGT   S(KC_RGHT)               //          ⇧→
#define SHOM   S(KC_HOME)               //          ⇧↗
#define SPDN   S(KC_PGDN)               //          ⇧⇟
#define SPUP   S(KC_PGUP)               //          ⇧⇞
#define SHEND  S(KC_END)                //          ⇧↖
                                        // ⌃◆ motions
#define CGLFT C(G(KC_LEFT))             //          ⌃◆←
#define CGDN  C(G(KC_DOWN))             //          ⌃◆↓
#define CGUP  C(G(KC_UP))               //          ⌃◆↑
#define CGRGT C(G(KC_RGHT))             //          ⌃◆→
                                        // ⇥ mods
#define CBTB   C(S(KC_TAB))             //          ⌃⇤
#define CTB    C(KC_TAB)                //          ⇥⌃
#define ABTB   A(S(KC_TAB))             //          ⌥⇥
#define ATB    A(KC_TAB)                //          ⎇⇥
#define GTAB   G(KC_TAB)                //          ◆⇥
                                        // tap-dance keys
#define TDCOS TD(COS)                   //          :                 ;      ;             ::
#define TDETQ TD(ETQ)                   //          ⎋     L7_MOUSE    ~     ⌃wq         ⎋:wa\n:qa\n
#define TDDRX TD(DRX)                   //          $      CTRL       !     ⌃w
#define TDCPA TD(CPA)                   //         ⌃p       ✦               ⌃a⎋
#define TDBEQ TD(BEQ)                   //          \       ⌥         |     ⎋:
                                        // modded keys
#define SCC    S(C(KC_C))               //          ⇪c
#define SCV    S(C(KC_V))               //          ⇪v
#define CS6    LCTL(KC_CIRC)            //          ⇪6
#define SGS    S(G(KC_S))               //          ⇧◆s
#define AF4    A(KC_F4)                 //          ⎇F4
#define SF5    S(KC_F5)                 //          ⇧F5
