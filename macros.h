#pragma once

char* macros[] = {
  SS_LCTL("w") SS_TAP(X_LEFT),
  SS_LCTL("w") SS_TAP(X_RIGHT),
  SS_LCTL("w") SS_TAP(X_UP),
  SS_LCTL("w") SS_TAP(X_DOWN),
  "->",
  " => ",
  " === ",
  " !== ",
  " <= ",
  " >= ",
  "gT", // vim previous tab
  "gt", // vim next tab
};

void dispatch_macro(uint16_t key_code) {
  send_string(macros[key_code - FIRST_MACRO - 1]);
}

