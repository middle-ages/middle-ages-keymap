#pragma once

const char* PROGMEM help_lines[] = {
  "|  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \\   |Base layer tap",
  "|  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |",
  "|   @   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   '   |",
  "|   $   |  Gui  |   *   | Bspace|   +   |   _   | Space |   -   |Delete |Compose|Ctrl-a |Ctrl-p |",
  "|  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \\   |Base layer shifted tap",
  "|  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |",
  "|   @   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   '   |",
  "|   $   |  Gui  |   *   | Bspace|   +   |   _   | Space |   -   |Delete |Compose|Ctrl-a |Ctrl-p |",
  "|Layer 7|       |       |       |       |       |       |       |       |       |       |SftAlt |Base layer hold",
  "|Layer 6|       |       |       |       |       |       |       |       |       |       |SftCtrl|",
  "| Shift | Shift |       |       |       |       |       |       |       |       | Shift | Shift |",
  "| Ctrl  |  Gui  |  Alt  |       |Layer 1|Layer 2|Layer 3|Layer 4|       |Layer 5|CtrlAlt|  Meh  |",
  "|Ctrl-wq|       |       |       |       |       |       |       |       |       |       |Esc :  |Base layer double tap",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |SCtrl-P|",
  "|Ctrl-w |       |       |       |       |       |       |       |       |       |       |TmuxEsc|",
  "|CapsWrd|   (   |  )    |   6   |   7   |   9   |CtlWLft|CtlWDwn|CtlWUp |CtlWRgt|   {   |   }   |1. Lower",
  "|       |       |       |   4   |   5   |   6   |       |       |       |       |   [   |   ]   |",
  "|       |       |       |   1   |   2   |   3   |       |       |       |  App  | Vol+  | Vol-  |",
  "|       |       |       |   0   |       |CtlBTab|CtlTab |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |Gui-Tab|2. Os",
  "|       |       |SGui-s |       |       |       |CGuiLft|CGuiDwn|CGuiUp |CGuiRgt|       |       |",
  "|       |       |       |       |       |       |Ctrl-o |       |       |       |       |       |",
  "|       |       |       |       |       |       |  gT   |  gt   |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |3. Sym",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |   %   |   =   |   `   |   ^   |       |       |       |",
  "|       |       |       |       |       |       |       |AltBTab|AltTab |       |       |       |",
  "|       |       |       |  F6   |  F7   |  F9   |       |       |       |       |       |       |4. Raise",
  "|       |       |       |  F4   |  F5   |  F6   |       |       |       |       |       |  - >  |",
  "|       |  F12  |  F11  |  F1   |  F2   |  F3   |       |       |  < =  |  > =  | ! = = |  = >  |",
  "|       |       |       |  F0   |       |       |       |       |       |       | = = = |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |5. Unicode",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |S-Home | Home  |PgDown | PgUp  | End   |S-End  |Insert |6. Nav",
  "|       | Ctrl  |  Alt  |       |       |S-Left | Left  | Down  |  Up   | Right |S-Right|       |",
  "|       |CtrlAlt|       |       |       |       |       |S-Down | S-Up  |       |       |       |",
  "|       |       |       |       |       |       |       |S-PgDwn|S-PgUp |       |       |       |",
  "|       |       |       |       |       |MidLeft| MidUp |MidDown|MidRght|       |       |       |7. Mouse",
  "|       |       |       |       |       |M-Left | M-Up  |M-Down |M-Right|       |       |       |",
  "|       |       |       |       |       |Button1|Button2|Button3|       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       | Boot  |8. Adjust",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       | Help  |       |       |       |Bright+|Bright-|",
  "| Sleep |       |       |       |       |       |       |       |       |TTermPr|TTerm- |TTerm+ |"
};

void send_layer_lines(uint8_t from) {
  int i = 0;
  for (i = 0; i < 4; ++i) {
    set_step_light(i);
    send_string(help_lines[from + i]);
    SEND_STRING_DELAY("\n", 50);
  }
}

void dispatch_help(uint16_t key_code) {
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb(CLR_DIM);
  int index = key_code - HELP0;
  if (index == 0) {
    int i = 0;
    for (i = 0; i < 4; ++i) {
      send_layer_lines(i * 4);
      rgblight_setrgb(CLR_DIM);
    }
  } else {
    send_layer_lines((index - 1) * 4 + 4 * 4);
  }
  rgblight_setrgb(CLR_DIM);
}

/*
∅  ∧  ∨  ±  ⊑  ⊆  ⇐  ⇔  ↔  ⇒  ⊇  ⊒
⤕  ∩  ∪  ∈  ⊏  ⊂  ←  ↓  ↑  →  ⊃  ⊐
¬  ⚬  🞄  ç  ℕ  ℝ  ∀  ∃  ≤  ≥  ≠  ÷
⎈                         L5     ×
*/

