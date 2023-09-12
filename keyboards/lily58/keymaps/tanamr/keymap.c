#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "led.h"
// #include "host.h"

enum custom_keycodes {
    REP = SAFE_RANGE,
    CTRL_TAB_MASHABLE,
    ALT_TAB_MASHABLE,
    ALT_TAB_SELECTOR
};

enum layer_number {
  _ROLLLA = 0,
  _SEHT,
  _QWERTY,
  _GAME,
  _GAMEFN,
  _SYMBOLS,
  _EXTEND,
  _RGB,
};

enum combos {
  KV_TO_Z,
};

const uint16_t PROGMEM kv_combo[] = {KC_K, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [KV_TO_Z] = COMBO(kv_combo, KC_Z),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ROLLLA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | mute | vol- | vol+ | play |CSspc |                    | win. | CTab | ATabM| ATabS| winV |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Y  |   O  |   U  |   B  |   .  |                    |   X  |   K  |   C  |   L  |   V  |  ;   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Extend|   I  |   A  |   E  |   N  |   ,  |-------.    ,-------|   M  |   H  |   S  |   R  |   T  |  -   |
 * |------+------+------+------+------+------|   Z   |    |WinSftS|------+------+------+------+------+------|
 * |LCtrl |OSLSym|   '  |   /  |   P  |   W  |-------|    |-------|   F  |   D  |   G  |   J  |   Q  |  RGB |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | REP  |LShift| /BackSP /       \Extend\  |Space | Sym  | Win  |
 *                   |(RCtrl)      |(OSM) |/       /         \      \ |      |(OSL) |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_ROLLLA] = LAYOUT(
  KC_ESC,   KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    C(S(KC_SPC)),                           LGUI(KC_DOT),      CTRL_TAB_MASHABLE,   ALT_TAB_MASHABLE,  ALT_TAB_SELECTOR,  LGUI(KC_V), KC_GRV,
  KC_TAB,   KC_Y,       KC_O,       KC_U,       KC_B,       KC_DOT,                                 KC_X,       KC_K,           KC_C,   KC_L,   KC_V,       KC_SCLN,
  MO(_EXTEND),    KC_I,       KC_A,       KC_E,       KC_N,       KC_COMM,                                KC_M,       KC_H,           KC_S,   KC_R,   KC_T,       KC_MINS,
  KC_LCTL,  OSL(_SYMBOLS),      KC_QUOT,    KC_SLSH,    KC_P,       KC_W,           KC_Z,   SGUI(KC_S),     KC_F,       KC_D,           KC_G,   KC_J,   KC_Q,       MO(_RGB),
                                KC_RCTL,    REP,    OSM(MOD_LSFT),  KC_BSPC,            MO(_EXTEND),      KC_SPC,     OSL(_SYMBOLS),      KC_RGUI
),

/* SEHT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | mute | vol- | vol+ | play |CSspc |                    | win. | CTab | ATabM| ATabS| winV |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   F  |   U  |   L  |   V  |   B  |                    |   Q  |   G  |   N  |   O  |   J  |  ;   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Extend|   S  |   E  |   H  |   T  |   K  |-------.    ,-------|   Y  |   D  |   R  |   A  |   I  |  .   |
 * |------+------+------+------+------+------|   Z   |    |WinSftS|------+------+------+------+------+------|
 * |LCtrl |OSLSym|   -  |   M  |   P  |   W  |-------|    |-------|   '  |   C  |   X  |   /  |   ,  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | REP  |LShift| /BackSP /       \Extend\  |Space | Sym  | Win  |
 *                   |(RCtrl)      |(OSM) |/       /         \      \ |      |(OSL) |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_SEHT] = LAYOUT(
  KC_ESC,   KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    C(S(KC_SPC)),                           LGUI(KC_DOT),      CTRL_TAB_MASHABLE,   ALT_TAB_MASHABLE,  ALT_TAB_SELECTOR,  LGUI(KC_V), KC_GRV,
  KC_TAB,   KC_F,       KC_U,       KC_L,       KC_V,       KC_B,                                 KC_Q,       KC_G,           KC_N,   KC_O,   KC_J,       KC_SCLN,
  MO(_EXTEND),    KC_S,       KC_E,       KC_H,       KC_T,       KC_K,                                KC_Y,       KC_D,           KC_R,   KC_A,   KC_I,       KC_DOT,
  KC_LCTL,  OSL(_SYMBOLS),      KC_MINS,    KC_M,    KC_P,       KC_W,           KC_Z,   SGUI(KC_S),     KC_QUOT,       KC_C,           KC_X,   KC_SLSH,   KC_COMM,       KC_ENT,
                                KC_RCTL,    REP,    OSM(MOD_LSFT),  KC_BSPC,            MO(_EXTEND),      KC_SPC,     OSL(_SYMBOLS),      KC_RGUI
),

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Ex/CL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /BackSP /       \      \  |Space |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,        KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  LT(_EXTEND,KC_CAPS), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,       KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                               _______, _______, _______, KC_BSPC,  _______,  KC_SPC, _______, _______
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |  Up  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GameFn|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  | Left |  Dn  |Right |   ;  |Enter |
 * |------+------+------+------+------+------|   H   |    |  F2   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |LCtrl |Space | /BackSP /       \   I  \  |   J  |   K  |   L  |
 *                   |(RCtrl)      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,    KC_U,    KC_UP,    KC_O,    KC_P,    KC_QUOT,
  MO(_GAMEFN), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_H, KC_F2, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
  KC_RCTL, KC_LCTL, KC_SPC, KC_BSPC, KC_I, KC_J, KC_K, KC_L
),

/* GameFn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |      |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------| TRNS |      |      |      |      |      |
 * |------+------+------+------+------+------| TRNS  |    |       |------+------+------+------+------+------|
 * |LCtrl |  F11 |  F12 |      |      | TRNS |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | Shift| Shift| /Rollla /       \      \  |      |      |      |
 *                   |(RCtrl)      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_GAMEFN] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_F1, KC_NO, KC_F3, KC_F4, KC_F5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_LCTL, KC_F11, KC_F12, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_RCTL, KC_LSFT, KC_LSFT, TO(_ROLLLA), KC_NO, KC_NO, KC_NO, KC_NO
),

/* Symbols/Numpad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  &   |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  |   |  !   |  {   |  }   |  $   |                    |  *   |  7   |  8   |  9   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Space|  \   |  @   |  (   |  )   |  <   |-------.    ,-------|  >   |  4   |  5   |  6   |  =   |  _   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  #   |  [   |  ]   |  %   |-------|    |-------|  _   |  1   |  2   |  3   |  ^   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | / Space /       \      \  |  0   |      |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMBOLS] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AMPR, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
  KC_TRNS, KC_PIPE, KC_EXLM, KC_LCBR, KC_RCBR, KC_DLR, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_TRNS,
  KC_SPC, KC_BSLS, KC_AT, KC_LPRN, KC_RPRN, KC_LT, KC_GT, KC_4, KC_5, KC_6, KC_EQL, KC_UNDS,
  KC_TRNS, KC_TRNS, KC_HASH, KC_LBRC, KC_RBRC, KC_PERC, KC_TRNS, KC_TRNS, KC_UNDS, KC_1, KC_2, KC_3, KC_CIRC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_0, KC_TRNS, KC_PDOT
),

/* Extend
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |QWERTY| GAME |ROLLLA| SEHT |      |                    | PgUp | Home |  Up  | End  |  Del |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | LWin |LShift| LCtrl|      |-------.    ,-------|PgDown| Left | Down | Right| Enter|WinSfS|
 * |------+------+------+------+------+------| BOOT  |    | SLEEP |------+------+------+------+------+------|
 * |      | CtrlZ| CtrlX| CtrlC| CtrlV|      |-------|    |-------| CtrlZ| CtrlV| CtrlC| CtrlX| Tab  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | Tab  | / BackSp/       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_EXTEND] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  KC_TRNS, TO(_QWERTY), TO(_GAME), TO(_ROLLLA), TO(_SEHT), KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DEL, KC_F12,
  KC_TRNS, KC_RCTL, KC_LGUI, KC_LSFT, KC_LCTL, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, SGUI(KC_S),
  KC_TRNS, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_NO, QK_BOOT, KC_SLEP, C(KC_Z), C(KC_V), C(KC_C), C(KC_X), KC_TAB, KC_NO,
  KC_NO, KC_NO, KC_TAB, KC_BSPC, KC_NO, KC_TRNS, KC_NO, KC_NO
),

/* RGB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |HueUp |SatUp |ValUp |ModeUp|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |HueDn |SatDn |ValDn |ModeDn|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |[RGB] |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | LSFT | /       /       \      \  | RGB  |      |      |
 *                   |      |      |      |/       /         \      \ |On/Off|      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RGB] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MODE_FORWARD, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MODE_REVERSE, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO
),

/* Blank
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

// [_BLANK] = LAYOUT(
//   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
// ),

};

const rgblight_segment_t PROGMEM rgb_layer_extend[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_WHITE},
    {7, 2, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_layer_shift[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_layer_green[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_layer_blue[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_layer_purple[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_layer_sym[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED},
    {9, 2, HSV_RED}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_green,
    rgb_layer_blue,
    rgb_layer_purple,
    rgb_layer_sym,
    rgb_layer_shift,
    rgb_layer_extend
);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
// #ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_host_led_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);
const char *read_mods_state(void);
static void tanamr_logo(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool scrollla = false;
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    oled_write_ln(read_host_led_state(), false);
    oled_write_ln(read_mods_state(), false);
    //oled_write_ln(read_timelog(), false);
    if (scrollla) {
        oled_scroll_set_area(0, 0);
        oled_scroll_right();
    } else {
        oled_scroll_off();
    }
  } else {
    // oled_write(read_logo(), false);
    tanamr_logo();
  }
    return false;
}

static void tanamr_logo(void){
    static const char PROGMEM my_logo[] = {
        0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3e, 0x3e, 0x3f,
        0x1f, 0x1e, 0x1e, 0xfe, 0xfe, 0xfc, 0x7c, 0x78, 0x78, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00,
        0xc0, 0xe0, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xf0,
        0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x10, 0x10, 0x10,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0xf8, 0xfe, 0xe7, 0xc7, 0x8f, 0x1f, 0x1f, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x00, 0x80, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x3f,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xc0, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0xc0, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0x00,
        0x01, 0x07, 0x0f, 0x0f, 0x1e, 0x1c, 0x38, 0x10, 0x34, 0x60, 0x40, 0x80, 0x80, 0x06, 0x26, 0x7e,
        0x3e, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xfb, 0x01, 0x1d, 0x3f, 0x3f, 0x07, 0x0f, 0x00, 0x03, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfe, 0x3f, 0x07, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xf8, 0x9c, 0x8c, 0x8e, 0xc6, 0xc6, 0xfe,
        0x7f, 0xff, 0xff, 0xc6, 0xc0, 0xe0, 0xe0, 0x70, 0x7c, 0x7f, 0x7f, 0x1f, 0x03, 0x01, 0x7f, 0xff,
        0xe0, 0xc0, 0xe0, 0xfc, 0x7e, 0x7f, 0x73, 0x39, 0x3d, 0x1f, 0x3f, 0x7f, 0xe0, 0xe0, 0xe0, 0xe0,
        0x70, 0x38, 0x3e, 0x7f, 0x3f, 0x0f, 0x03, 0x3f, 0x3f, 0x1f, 0x07, 0x03, 0x7f, 0xff, 0xff, 0xc0,
        0xc0, 0xf0, 0x7c, 0x3e, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0c, 0x1c, 0x18, 0x38, 0x38, 0x70, 0x60, 0x63, 0x4f, 0xd8,
        0xb0, 0x61, 0x40, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

// #define L_BASE 0
// #define L_QWER (1 << 1)
// #define L_GAME (1 << 2)
// #define L_GAMEFN (1 << 3)
// #define L_SYM (1 << 4)
// #define L_EXTEND (1 << 5)

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _ROLLLA:
    combo_enable();
    break;
  default:
    combo_disable();
    break;
  }

  rgblight_set_layer_state(0, layer_state_cmp(state, _GAME) || layer_state_cmp(state, _GAMEFN));
  rgblight_set_layer_state(1, layer_state_cmp(state, _SEHT));
  rgblight_set_layer_state(2, layer_state_cmp(state, _QWERTY));
  rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOLS));
  rgblight_set_layer_state(5, layer_state_cmp(state, _EXTEND));

  return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
  rgblight_set_layer_state(4, (mods & MOD_MASK_SHIFT));
}

char layer_state_str[24];

const char *read_layer_state(void) {
  scrollla = false;
  switch (get_highest_layer(layer_state))
  {
  case _ROLLLA:
    snprintf(layer_state_str, sizeof(layer_state_str), "rollla rollla rollla ");
    scrollla = true;
    break;
  case _SEHT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: seht-drai");
    break;
  case _GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    break;
  case _QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case _GAMEFN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game Fn");
    break;
  case _SYMBOLS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Sym/Numpad");
    break;
  case _EXTEND:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Extend");
    break;
  case _RGB:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RGB Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %u", layer_state);
  }

  return layer_state_str;
}

char host_led_state_str[24];
const char *read_host_led_state(void)
{
  led_t led_state = host_keyboard_led_state();
  snprintf(host_led_state_str, sizeof(host_led_state_str), "%s%s",
        led_state.caps_lock ? "CapsLk " : "",
        led_state.scroll_lock ? "ScrollLk" : ""
  );
  return host_led_state_str;
}

char mods_state_str[24];
const char *read_mods_state(void)
{
    uint8_t mods = get_mods() | get_oneshot_mods();
    snprintf(mods_state_str, sizeof(mods_state_str), "%s%s%s%s%s",
        mods ? "Mods: " : "",
        // mods & MOD_MASK_CTRL ? "C" : "",
        mods & MOD_BIT(KC_LCTL) ? "C" : "",
        mods & MOD_MASK_SHIFT ? "S" : "",
        // mods & MOD_MASK_ALT ? "A" : "",
        mods & (MOD_MASK_ALT | MOD_BIT(KC_RCTL)) ? "A" : "",
        mods & MOD_MASK_GUI ? "G" : ""
    );
    if (mods) {
        scrollla = false;
    }
    return mods_state_str;
}


// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
uint16_t pressed_keycode = KC_NO;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
  if (keycode != REP) {
    // Early return when holding down a pure layer key
    // to retain modifiers
    switch (keycode) {
      case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
      case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
      case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
      case QK_TO ... QK_TO_MAX:
      case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      case QK_MODS ... QK_MODS_MAX:
      case KC_BSPC: // backspace shouldn't repeat lmao
        return;
    }
    if (record->event.pressed) {
      last_modifier = get_mods() | get_oneshot_mods();
      switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
          last_keycode = GET_TAP_KC(keycode);
          break;
        default:
          last_keycode = keycode;
          break;
        }
    }
  } else { // keycode == REPEAT
    if (record->event.pressed) {
      pressed_keycode = last_keycode;
      register_mods(last_modifier);
      register_code16(pressed_keycode);
      unregister_mods(last_modifier);
    } else {
      unregister_code16(pressed_keycode);
    }
  }
}

bool alt_tab_mashing = false;
uint32_t alt_tab_mash_timer = 0;
bool ctrl_tab_mashing = false;
uint32_t ctrl_tab_mash_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
      case ALT_TAB_MASHABLE:
        alt_tab_mash_timer = timer_read(); // timer should start from keyup
        if (record->event.pressed) {
          if (!alt_tab_mashing) {
            alt_tab_mashing = true;
            register_code(KC_RALT);
          }
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;
      case CTRL_TAB_MASHABLE:
        ctrl_tab_mash_timer = timer_read(); // timer should start from keyup
        if (record->event.pressed) {
          if (!ctrl_tab_mashing) {
            ctrl_tab_mashing = true;
            register_code(KC_LCTL);
          }
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;
      case ALT_TAB_SELECTOR:
        // avoid possible mess with keyup situation. act on down only
        if (!record->event.pressed) {
          break;
        }
        if (alt_tab_mashing) {
          unregister_code(KC_RALT);
          alt_tab_mashing = false;
        } else if (ctrl_tab_mashing) {
          unregister_code(KC_LCTL);
          ctrl_tab_mashing = false;
        } else {
          tap_code16(RALT(KC_TAB));
        }
        break;
    }

    return true;
}

void matrix_scan_user(void) { // just bool checks, should hopefully not slow the scan rate much
  if (alt_tab_mashing) {
    if (timer_elapsed(alt_tab_mash_timer) > 1000) {
      unregister_code(KC_RALT);
      alt_tab_mashing = false;
    }
  } else if (ctrl_tab_mashing) {
    if (timer_elapsed(ctrl_tab_mash_timer) > 1000) {
      unregister_code(KC_LCTL);
      ctrl_tab_mashing = false;
    }
  }
}
