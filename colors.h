#pragma once

#define LAYER_LED_BEGIN 5 // led indexes:
#define LAYER_LED_END   9 //    6 5 4 3
#define MOD_LED_BEGIN   0 //       0
#define MOD_LED_END     5 //    7 8 1 2

#define CLR_OFF     0x00, 0x00, 0x00
#define CLR_DIM     0x03, 0x05, 0x06
#define CLR_WHITE   0xFF, 0xFF, 0xFF
#define CLR_PINK    0xFF, 0x00, 0xEF
#define CLR_RED     0xFF, 0x00, 0x00
#define CLR_ORANGE  0xFF, 0x2C, 0x00
#define CLR_YELLOW  0xFF, 0xFF, 0x00
#define CLR_GREEN   0x00, 0xFF, 0x00
#define CLR_CYAN    0x00, 0xEF, 0xFF
#define CLR_BLUE    0x00, 0x00, 0xFF
#define CLR_PURPLE  0x5A, 0x00, 0xFF

uint8_t layer_colors[] = {
  CLR_DIM,    // L0
  CLR_RED,    // L1
  CLR_ORANGE, // L2
  CLR_YELLOW, // L3
  CLR_GREEN,  // L4
  CLR_CYAN,   // L5
  CLR_BLUE,   // L6
  CLR_PURPLE  // L7
};

void set_mod_rgb(uint8_t r, uint8_t g, uint8_t b) {
  rgblight_setrgb_range(r, g, b, MOD_LED_BEGIN, MOD_LED_END);
}

void set_layer_rgb(uint8_t r, uint8_t g, uint8_t b) {
  rgblight_setrgb_range(r, g, b, LAYER_LED_BEGIN, LAYER_LED_END);
}

void set_gui_mod_rgb(void) {
  int i = MOD_LED_BEGIN;
  rgblight_setrgb_range(CLR_PINK, i + 0, i + 1);
  rgblight_setrgb_range(CLR_PINK, i + 3, i + 4);
  rgblight_setrgb_range(CLR_PINK, i + 4, i + 5);
}

/**
 * S (shift)  C (ctrl)   A (alt)
 *    ❎         ❌         ❌  RED
 *    ❌         ❎         ❌  GREEN
 *    ❌         ❌         ❎  BLUE
 *
 *    ❎         ❎         ❌  YELLOW = RED  + GREEN
 *    ❎         ❌         ❎  PURPLE = RED  + BLUE
 *    ❌         ❎         ❎    CYAN = BLUE + GREEN
 *    ❎         ❎         ❎   WHITE = RED  + GREEN + BLUE
 */
void set_mod_indicator(void) {
  bool shift = get_mods() & MOD_MASK_SHIFT;
  bool ctrl = get_mods() & MOD_MASK_CTRL;
  bool alt = get_mods() & MOD_MASK_ALT;
  bool gui = get_mods() & MOD_MASK_GUI;

  if (!shift && !ctrl && !alt && !gui) {
    set_mod_rgb(CLR_DIM);
  } else if (shift && !ctrl && alt) {
    set_mod_rgb(CLR_PURPLE);
  } else {
    set_mod_rgb(shift ? 0xFF: 0x00, ctrl ? 0xFF: 0x00, alt ? 0xFF: 0x00);
  }

  if (gui) {
    set_gui_mod_rgb();
  }
}

void set_layer_indicator(layer_state_t state) {
  uint8_t layer = IS_LAYER_ON_STATE(state, _L1_LOWER)
               && IS_LAYER_ON_STATE(state, _L4_RAISE)
               ?  8
               :  get_highest_layer(state);

  if (layer==8) {
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
  } else if (layer==7) {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    set_layer_rgb(CLR_PURPLE);
  } else {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    set_layer_rgb(layer_colors[layer * 3], layer_colors[layer * 3 + 1], layer_colors[layer * 3 + 2]);
  }
}

void set_dim_light(void) {
  rgblight_setrgb(CLR_DIM);
}

void set_step_light(int step) {
  rgblight_setrgb_range(CLR_RED, 7, 8);

  if (step > 0) {
    rgblight_setrgb_range(CLR_ORANGE, 8, 9);
    if (step > 1) {
      rgblight_setrgb_range(CLR_YELLOW, 1, 2);
      if (step > 2) {
        rgblight_setrgb_range(CLR_GREEN, 2, 3);
      }
    }
  }
}
