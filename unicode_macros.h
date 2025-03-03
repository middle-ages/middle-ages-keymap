
#pragma once

char* unicode_macros[] = {
  "“", "”",
  "‘", "’",
  "❌", "✅",
  "∅", "∧", "∨", "±", "⊑", "⊆", "⇐", "⇔", "↔", "⇒", "⊇", "⊒",
  "⤕", "∩", "∪", "∈", "⊏", "⊂", "←", "↓", "↑", "→", "⊃", "⊐",
  "¬", "⚬", "🞄", "ç", "ℕ", "ℝ", "∀", "∃", "≤", "≥", "≠", "÷",
  "×"
};

void dispatch_unicode_macro(uint16_t key_code) {
  send_unicode_string(unicode_macros[key_code - FIRST_UNICODE_MACRO - 1]);
}

