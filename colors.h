#pragma once

#define LAYER_LED_BEGIN 4 // led indexes:
#define LAYER_LED_END   9 //    6 5 4 3
#define MOD_LED_BEGIN   0 //       0
#define MOD_LED_END     4 //    7 8 1 2

#define CLR_OFF    0x00, 0x00, 0x00
#define CLR_DIM    0x03, 0x05, 0x06
#define CLR_WHITE  0xFF, 0xFF, 0xFF
#define CLR_PINK   0xFF, 0x00, 0xEF

uint8_t layer_colors[] = {
  CLR_DIM,          // L0 white
  0xFF, 0x00, 0x00, // L1 red
  0xFF, 0x2C, 0x00, // L2 orange
  0xFF, 0xFF, 0x00, // L3 yellow
  0x00, 0xFF, 0x00, // L4 green
  0x00, 0xEF, 0xFF, // L5 cyan
  0x00, 0x00, 0xFF, // L6 blue
  0x5A, 0x00, 0xFF  // L7 purple
};

/**
 * S (shift)  C (ctrl)   A (alt)
 *    ❎         ❌         ❌  RED
 *    ❌         ❎         ❌  GREEN
 *    ❌         ❌         ❎  BLUE
 *
 *    ❎         ❎         ❌  YELLOW = RED  + GREEN
 *    ❎         ❌         ❎    PINK = RED  + BLUE
 *    ❌         ❎         ❎    CYAN = BLUE + GREEN
 *    ❎         ❎         ❎   WHITE = RED  + GREEN + BLUE
 */
void set_mod_indicator(bool shift, bool ctrl, bool alt) {
  if (!shift && !ctrl && !alt) {
    rgblight_setrgb_range(
      CLR_DIM,
      MOD_LED_BEGIN,
      MOD_LED_END
    );
  } else {
    rgblight_setrgb_range(
      shift ? 0xFF: 0x00,
      ctrl ? 0xFF: 0x00,
      alt ? 0xFF: 0x00,
      MOD_LED_BEGIN,
      MOD_LED_END
    );
  }
}

void set_layer_indicator(layer_state_t state) {
  uint8_t layer = IS_LAYER_ON_STATE(state, _L1_LOWER)
               && IS_LAYER_ON_STATE(state, _L4_RAISE)
               ?  8
               :  get_highest_layer(state);

  if (layer==8) {
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
  } else {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb_range(
      layer_colors[layer * 3],
      layer_colors[layer * 3 + 1],
      layer_colors[layer * 3 + 2],
      LAYER_LED_BEGIN,
      LAYER_LED_END
    );
  }
}

