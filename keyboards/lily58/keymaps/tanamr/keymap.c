#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "led.h"
// #include "host.h"

enum custom_keycodes {
    REP = SAFE_RANGE
};

enum layer_number {
  _ROLLLA = 0,
  _QWERTY,
  _GAME,
  _GAMEFN,
  _SYMBOLS,
  _EXTEND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ROLLLA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | mute | vol- | vol+ | play |CSspc |                    |      | win. |      |      | winV |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Y  |   O  |   U  |   B  |   .  |                    |   X  |   K  |   C  |   L  |   V  |  ;   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Extend|   I  |   A  |   E  |   N  |   ,  |-------.    ,-------|   M  |   H  |   S  |   R  |   T  |  -   |
 * |------+------+------+------+------+------|   Z   |    |WinSftS|------+------+------+------+------+------|
 * |LCtrl |  Sym |   '  |   /  |   P  |   W  |-------|    |-------|   F  |   D  |   G  |   J  |   Q  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | REP  |LShift| /BackSP /       \Extend\  |Space | Sym  | Win  |
 *                   |(RCtrl)      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_ROLLLA] = LAYOUT(
  KC_ESC,   KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    C(S(KC_SPC)),                           KC_NO,      LGUI(KC_DOT),   KC_NO,  KC_NO,  LGUI(KC_V), KC_GRV,
  KC_TAB,   KC_Y,       KC_O,       KC_U,       KC_B,       KC_DOT,                                 KC_X,       KC_K,           KC_C,   KC_L,   KC_V,       KC_SCLN,
  MO(5),    KC_I,       KC_A,       KC_E,       KC_N,       KC_COMM,                                KC_M,       KC_H,           KC_S,   KC_R,   KC_T,       KC_MINS,
  KC_LCTL,  MO(4),      KC_QUOT,    KC_SLSH,    KC_P,       KC_W,           KC_Z,   SGUI(KC_S),     KC_F,       KC_D,           KC_G,   KC_J,   KC_Q,       KC_ENT,
                                KC_RCTL,    REP,    OSM(MOD_LSFT),  KC_BSPC,            MO(5),      KC_SPC,     MO(4),      KC_RGUI
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
  LT(5,KC_CAPS), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,       KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                               _______, _______, _______, KC_BSPC,  _______,  KC_SPC, _______, _______
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GameFn|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|      | Left |  Dn  |Right |      |      |
 * |------+------+------+------+------+------|   H   |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |RShift|Space | / Enter /       \      \  |      |      |      |
 *                   |(RCtrl)      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
  MO(3), KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
  KC_NO, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_H, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_RCTL, KC_RSFT, KC_SPC, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO
),

/* GameFn
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Rollla /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_GAMEFN] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO
),

/* Symbols/Numpad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  &   |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  |   |  !   |  {   |  }   |  $   |                    |  *   |  7   |  8   |  9   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  \   |  @   |  (   |  )   |  <   |-------.    ,-------|  >   |  4   |  5   |  6   |  =   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  #   |  [   |  ]   |  %   |-------|    |-------|  _   |  1   |  2   |  3   |  ^   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |  0   |      |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMBOLS] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AMPR, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
  KC_TRNS, KC_PIPE, KC_EXLM, KC_LCBR, KC_RCBR, KC_DLR, KC_ASTR, KC_P7, KC_P8, KC_P9, KC_PLUS, KC_TRNS,
  KC_TRNS, KC_BSLS, KC_AT, KC_LPRN, KC_RPRN, KC_LT, KC_GT, KC_P4, KC_P5, KC_P6, KC_EQL, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_HASH, KC_LBRC, KC_RBRC, KC_PERC, KC_TRNS, KC_TRNS, KC_UNDS, KC_P1, KC_P2, KC_P3, KC_CIRC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS, KC_PDOT
),

/* Extend
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |QWERTY| GAME |ROLLLA|      |      |                    | PgUp | Home |  Up  | Down | End  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | LWin |LShift| LCtrl|      |-------.    ,-------|PgDown| Left | Down | Right| Enter|WinSfS|
 * |------+------+------+------+------+------| BOOT  |    | SLEEP |------+------+------+------+------+------|
 * |      | CtrlZ| CtrlX| CtrlC| CtrlV|      |-------|    |-------|      |      |      |      | Tab  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | Tab  | / BackSp/       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_EXTEND] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  KC_TRNS, TO(1), TO(2), TO(0), KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DEL, KC_F12,
  KC_TRNS, KC_RCTL, KC_LGUI, KC_LSFT, KC_LCTL, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, SGUI(KC_S),
  KC_TRNS, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_NO, QK_BOOT, KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO,
  KC_NO, KC_NO, KC_TAB, KC_BSPC, KC_NO, KC_TRNS, KC_NO, KC_NO
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

};

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

char layer_state_str[24];

const char *read_layer_state(void) {
  scrollla = false;
  switch (get_highest_layer(layer_state))
  {
  case _ROLLLA:
    snprintf(layer_state_str, sizeof(layer_state_str), "rollla rollla rollla ");
    scrollla = true;
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    return true;
}

// #endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
//}
