#pragma once

char* help_lines[] = {
  "#0 Base layer tap",
  "|  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \\   |",
  "|  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |",
  "|   @   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   '   |",
  "|   $   |  Gui  |   *   | Bspace|   +   |   _   | Space |   -   |Delete |Compose|Ctrl-a |Ctrl-p |",
  "#0 Tap shifted",
  "|  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \\   |",
  "|  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |",
  "|   @   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   '   |",
  "|   $   |  Gui  |   *   | Bspace|   +   |   _   | Space |   -   |Delete |Compose|Ctrl-a |Ctrl-p |",
  "#0 Hold",
  "|Layer 7|       |       |       |       |       |       |       |       |       |       |SftAlt |",
  "|Layer 6|       |       |       |       |       |       |       |       |       |       |SftCtrl|",
  "| Shift | Shift |       |       |       |       |       |       |       |       | Shift | Shift |",
  "| Ctrl  |  Gui  |  Alt  |       |Layer 1|Layer 2|Layer 3|Layer 4|       |Layer 5|CtrlAlt|  Meh  |",
  "#0 Double tap",
  "|Ctrl-wq|       |       |       |       |       |       |       |       |       |       |Esc :  |",
  "|       |       |       |       |       |       |       |       |       |       |   :   |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|Ctrl-w |       |       |       |       |       |       |       |       |       |       |TmuxEsc|",
  "#1 Lower",
  "|CapsWrd|   (   |  )    |   6   |   7   |   9   |CtlWLft|CtlWDwn|CtlWUp |CtlWRgt|   {   |   }   |",
  "|       |       |       |   4   |   5   |   6   |       |       |       |       |   [   |   ]   |",
  "|       |       |       |   1   |   2   |   3   |       |       |       |  App  | Vol+  | Vol-  |",
  "|       |       |       |   0   |       |CtlBTab|CtlTab |       |       |       |       |       |",
  "#2 Os",
  "|       |       |       |       |       |       |       |       |       |       |       |Gui-Tab|",
  "|       |       |SGui-s |       |       |       |CGuiLft|CGuiDwn|CGuiUp |CGuiRgt|       |       |",
  "|       |       |       |       |       |       |SCtrl-6|Ctrl-o |       |       |       |       |",
  "|       |       |       |       |       |       |AltBTab|AltTab |       |       |       |       |",
  "#3 Sym",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |   %   |   =   |   `   |   ^   |       |       |       |",
  "|       |       |       |       |       |       |       |  gT   |  gt   |       |       |       |",
  "#4 Raise",
  "|       |       |       |  F6   |  F7   |  F9   |       |       |       |       |       |       |",
  "|       |       |       |  F4   |  F5   |  F6   |       |       |       |       |       |  - >  |",
  "|       |  F12  |  F11  |  F1   |  F2   |  F3   |       |       |  < =  |  > =  | ! = = |  = >  |",
  "|       |       |       |  F0   |       |       |       |       |       |       | = = = |       |",
  "#5 Unicode",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "#6 Nav",
  "|       |       |       |       |       |S-Home | Home  |PgDown | PgUp  | End   |S-End  |Insert |",
  "|       | Ctrl  |  Alt  |       |       |S-Left | Left  | Down  |  Up   | Right |S-Right|       |",
  "|       |CtrlAlt|       |       |       |       |       |S-Down | S-Up  |       |       |       |",
  "|       |       |       |       |       |       |       |S-PgDwn|S-PgUp |       |       |       |",
  "#7 Mouse",
  "|       |       |       |       |       |MidLeft| MidUp |MidDown|MidRght|       |       |       |",
  "|       |       |       |       |       |M-Left | M-Up  |M-Down |M-Right|       |       |       |",
  "|       |       |       |       |       |Button1|Button2|Button3|       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "#8 Adjust",
  "|       |       |       |       |       |       |       |       |       |       |       | Boot  |",
  "|       |       |       |       |       |       |       |       |       |       |       |       |",
  "|       |       |       |       |       |       |       |       |       |       |Bright+|Bright-|",
  "| Sleep |       |       |       |       |       |       |       |       |TTermPr|TTerm- |TTerm+ |"
};

void send_layer_lines(uint8_t from) {
  int i = 0;
  for (i = 0; i < 5; ++i) {
    send_string(help_lines[from + i]);
    SEND_STRING_DELAY("\n", 100);
  }
}

void dispatch_help(uint16_t key_code) {
  int index = key_code - HELP0;
  if (index == 0) {
    int i = 0;
    for (i = 0; i < 4; ++i) {
      send_layer_lines(i * 5);
    }
  } else {
    send_layer_lines((index - 1) * 5 + 4 * 5);
  }
}

/*
∅  ∧  ∨  ±  ⊑  ⊆  ⇐  ⇔  ↔  ⇒  ⊇  ⊒
⤕  ∩  ∪  ∈  ⊏  ⊂  ←  ↓  ↑  →  ⊃  ⊐
¬  ⚬  🞄  ç  ℕ  ℝ  ∀  ∃  ≤  ≥  ≠  ÷
⎈                         L5     ×
*/

