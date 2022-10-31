
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_QWER (1 << 1)
#define L_GAME (1 << 2)
#define L_GAMEFN (1 << 3)
#define L_SYM (1 << 4)
#define L_EXTEND (1 << 5)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Rollla rollla rollla!");
    break;
  case L_GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    break;
  case L_QWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case L_GAMEFN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game Fn");
    break;
  case L_SYM:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Sym/Numpad");
    break;
  case L_EXTEND:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Extend");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %u", layer_state);
  }

  return layer_state_str;
}
