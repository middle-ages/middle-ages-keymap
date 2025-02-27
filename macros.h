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
};

void dispatch_macro(uint16_t key_code) {
  send_string(macros[key_code - FIRST_MACRO]);
}
