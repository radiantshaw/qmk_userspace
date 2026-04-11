#include QMK_KEYBOARD_H

/*
 * Home Row Modifiers
 */
#define HRM_G_A LGUI_T(KC_A)
#define HRM_A_S LALT_T(KC_S)
#define HRM_C_D LCTL_T(KC_D)
#define HRM_S_F LSFT_T(KC_F)
#define HRM_S_J RSFT_T(KC_J)
#define HRM_C_K RCTL_T(KC_K)
#define HRM_A_L RALT_T(KC_L)
#define HRM_G_SCLN RGUI_T(KC_SCLN)

enum custom_keycodes {
  /*
   * Symbol sequences
   */
  SS_HDIR = SAFE_RANGE,
  SS_CDIR,
  SS_PDIR,
  SS_SHBG,
  SS_NEQ,
  SS_EQL,
  SS_SNEQ,
  SS_SEQL,
  SS_ARW,
  SS_FARW,
  SS_DCLN,
  SS_DAMP,
  SS_DPIP,
  SS_DAMA,
  SS_DPIA,
  SS_ESOA,
  SS_ESCA,
  SS_ESOP,
  SS_ESCP,
  SS_ESOB,
  SS_ESCB
};

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Grave |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | LG&A | LA&S | LC&D | LS&F |   G  |-------.    ,-------|   H  | RS&J | RC&K | RA&L | RG&; |  ]   |
 * |------+------+------+------+------+------|   \   |    |    '  |------+------+------+------+------+------|
 * | Tab  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI |Delete|LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6, KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
  KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y, KC_U,    KC_I,    KC_O,    KC_P,       KC_LBRC,
  KC_ESC,  HRM_G_A, HRM_A_S, HRM_C_D, HRM_S_F, KC_G,                   KC_H, HRM_S_J, HRM_C_K, HRM_A_L, HRM_G_SCLN, KC_RBRC,
  KC_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_BSLS, KC_QUOT, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_EQL,
                        KC_LGUI, KC_DEL, MO(_LOWER), KC_SPC,  KC_ENT,  OSL(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | N/A  | F1   | F2   | F3   | F4   | N/A  |                    | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | N/A  | F5   | F6   | F7   | F8   | N/A  |                    | Home |PageDn|PageUp| End  | N/A  | N/A  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | N/A  | LGUI | LAlt |LCTRL |LShift| N/A  |-------.    ,-------| Left | Down |  Up  |Right | N/A  | N/A  |
 * |------+------+------+------+------+------|  N/A  |    |  N/A  |------+------+------+------+------+------|
 * | N/A  | F9   | F10  | F11  | F12  | N/A  |-------|    |-------| N/A  |DTDown| DTUp |DTPrnt| N/A  | N/A  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | N/A  | N/A  | N/A  | / N/A   /       \ N/A  \  | N/A  | N/A  | N/A  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN, DT_UP,   DT_PRNT, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~/  | ../  |  #!  | !==  | ===  | N/A  |                    | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ./  | N/A  | N/A  |  !=  |  ==  | N/A  |                    | N/A  | N/A  |  \(  |  \)  | N/A  | N/A  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ->  |  =>  |  ::  | &&=  | ||=  | N/A  |-------.    ,-------| N/A  | N/A  |  \<  |  \>  | N/A  | N/A  |
 * |------+------+------+------+------+------|  N/A  |    |  N/A  |------+------+------+------+------+------|
 * | N/A  | N/A  | N/A  |  &&  |  ||  | N/A  |-------|    |-------| N/A  | N/A  |  \{  |  \}  | N/A  | N/A  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | N/A  | N/A  | N/A  | /N/A    /       \ N/A  \  | N/A  | N/A  | N/A  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  SS_HDIR, SS_PDIR, SS_SHBG, SS_SNEQ, SS_SEQL, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  SS_CDIR, XXXXXXX, XXXXXXX, SS_NEQ,  SS_EQL,  XXXXXXX,                   XXXXXXX, XXXXXXX, SS_ESOP, SS_ESCP, XXXXXXX, XXXXXXX,
  SS_ARW,  SS_FARW, SS_DCLN, SS_DAMA, SS_DPIA, XXXXXXX,                   XXXXXXX, XXXXXXX, SS_ESOA, SS_ESCA, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, SS_DAMP, SS_DPIP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SS_ESOB, SS_ESCB, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();

    switch (keycode) {
        case SS_HDIR:
          SEND_STRING("~/");
          return false;
        case SS_CDIR:
          SEND_STRING("./");
          return false;
        case SS_PDIR:
          SEND_STRING("../");
          return false;
        case SS_SHBG:
          SEND_STRING("#!");
          return false;
        case SS_NEQ:
          SEND_STRING("!=");
          return false;
        case SS_EQL:
          SEND_STRING("==");
          return false;
        case SS_SNEQ:
          SEND_STRING("!==");
          return false;
        case SS_SEQL:
          SEND_STRING("===");
          return false;
        case SS_ARW:
          SEND_STRING("->");
          return false;
        case SS_FARW:
          SEND_STRING("=>");
          return false;
        case SS_DCLN:
          SEND_STRING("::");
          return false;
        case SS_DAMP:
          SEND_STRING("&&");
          return false;
        case SS_DPIP:
          SEND_STRING("||");
          return false;
        case SS_DAMA:
          SEND_STRING("&&=");
          return false;
        case SS_DPIA:
          SEND_STRING("||=");
          return false;
        case SS_ESOA:
          SEND_STRING("\\<");
          return false;
        case SS_ESCA:
          SEND_STRING("\\>");
          return false;
        case SS_ESOP:
          SEND_STRING("\\(");
          return false;
        case SS_ESCP:
          SEND_STRING("\\)");
          return false;
        case SS_ESOB:
          SEND_STRING("\\{");
          return false;
        case SS_ESCB:
          SEND_STRING("\\}");
          return false;
    }
  }
  return true;
}
