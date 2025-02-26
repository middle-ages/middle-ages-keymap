#pragma once

void help0(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 0 Tap\n");
  SEND_STRING("|  Esc  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   \\   |\n");
  SEND_STRING("|  Tab  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |\n");
  SEND_STRING("|   @   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   '   |\n");
  SEND_STRING("|   $   |  Gui  |   *   | Bspace|   +   |   _   | Space |   -   |Delete |Compose|Ctrl-a |Ctrl-p |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 0 Shift\n");
  SEND_STRING("|   ~   |       |       |       |       |       |       |       |       |       |       |   |   |\n");
  SEND_STRING("|BackTab|       |       |       |       |       |       |       |       |       |   :   |       |\n");
  SEND_STRING("|   &   |       |       |       |       |       |       |       |   <   |   >   |   ?   |   \"   |\n");
  SEND_STRING("|   !   |       |   #   |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 0 Hold\n");
  SEND_STRING("|Layer 7|       |       |       |       |       |       |       |       |       |       |SftAlt |\n");
  SEND_STRING("|Layer 6|       |       |       |       |       |       |       |       |       |       |SftCtrl|\n");
  SEND_STRING("| Shift | Shift |       |       |       |       |       |       |       |       | Shift | Shift |\n");
  SEND_STRING("| Ctrl  |  Gui  |  Alt  |       |Layer 1|Layer 2|Layer 3|Layer 4|       |Layer 5|CtrlAlt|  Meh  |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 0 Double Tap\n");
  SEND_STRING("|Ctrl-wq|       |       |       |       |       |       |       |       |       |       |Esc :  |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |   :   |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|Ctrl-w |       |       |       |       |       |       |       |       |       |       |TmuxCpy|\n");
}

void help1(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 1: Lower\n");
  SEND_STRING("|CapsWrd|   (   |  )    |   6   |   7   |   9   |CtlWLft|CtlWDwn|CtlWUp |CtlWRgt|   {   |   }   |\n");
  SEND_STRING("|       |       |       |   4   |   5   |   6   |       |       |       |       |   [   |   ]   |\n");
  SEND_STRING("|       |       |       |   1   |   2   |   3   |       |       |       |  App  | Vol+  | Vol-  |\n");
  SEND_STRING("|       |       |       |   0   |       |CtlBTab|CtlTab |       |       |       |       |       |\n");
}

void help2(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 2: Os\n");
  SEND_STRING("|       |SCtrl-t|Ctrl-t |       |       |       |       |       |       |       |       |Gui-Tab|\n");
  SEND_STRING("|       |       |SGui-s |       |       |       |CGuiLft|CGuiDwn|CGuiUp |CGuiRgt|       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |SCtrl-6|Ctrl-o |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |AltBTab|AltTab |       |       |       |       |\n");
}

void help3(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 3: Sym\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |   %   |   =   |   `   |   ^   |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |  gT   |  gt   |       |       |       |\n");
}

void help4(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 4: Raise\n");
  SEND_STRING("|       |       |       |  F6   |  F7   |  F9   |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |  F4   |  F5   |  F6   |       |       |       |       |       |       |\n");
  SEND_STRING("|       |  F12  |  F11  |  F1   |  F2   |  F3   |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |  F0   |       |       |       |       |       |       |       |       |\n");
}

void help5(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 5: Unicode\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
}

void help6(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 6: Nav\n");
  SEND_STRING("|       |       |       |       |       |S-Home | Home  |PgDown | PgUp  | End   |S-End  |Insert |\n");
  SEND_STRING("|       | Ctrl  |  Alt  |       |       |S-Left | Left  | Down  |  Up   | Right |S-Right|       |\n");
  SEND_STRING("|       |CtrlAlt|       |       |       |       |       |S-Down | S-Up  |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |S-PgDwn|S-PgUp |       |       |       |\n");
}

void help7(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |Layer 7: Mouse\n");
  SEND_STRING("|       |       |       |       |       |MidLeft| MidUp |MidDown|MidRght|       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |M-Left | M-Up  |M-Down |M-Right|       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |Button1|Button2|Button3|       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
}

void help8(void) {
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       | Boot  |Layer 8: Adjust\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |       |       |\n");
  SEND_STRING("|       |       |       |       |       |       |       |       |       |       |Bright+|Bright-|\n");
  SEND_STRING("| Sleep |       |       |       |       |       |       |       |       |TTermPr|TTerm- |TTerm+ |\n");
}

/*
  raise₄┊    “   ”  F7  F8  F9");
        ┊           F4  F5  F6                      ->
        ┊   F12 F11 F1  F2  F3  ⇪6  ^o  <=␣ >=␣ !== =>
        ┊           F10             L4          ===
unicode₅┊ ∅  ∧  ∨  ±  ⊑  ⊆  ⇐  ⇔  ↔  ⇒  ⊇  ⊒
        ┊ ⤕  ∩  ∪  ∈  ⊏  ⊂  ←  ↓  ↑  →  ⊃  ⊐
        ┊ ¬  ⚬  🞄  ç  ℕ  ℝ  ∀  ∃  ≤  ≥  ≠  ÷
        ┊ ⎈                         L5     ×
*/

