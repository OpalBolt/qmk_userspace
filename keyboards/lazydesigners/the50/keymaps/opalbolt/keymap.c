#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _NU,
  _FN
};

// Act as Shift on hold and as CapsLock on tap
#define SFT_CPS LSFT_T(KC_CAPS)
#define SFT_MSP RSFT_T(KC_MPLY)
#define SPA_NU  LT(_NU, KC_SPC)
#define CRT_test LCTL_T(KC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *  ,-----------------------------------------------------------. ,--------------.
 *  |Esc | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bspc| | 7  | 8  | 9  |
 *  |-----------------------------------------------------------| |--------------|
 *  | Tab  | A  | S  | D  | F  | G  | H  | J  | K  | L  | Enter | | 4  | 5  | 6  |
 *  |-----------------------------------------------------------| |--------------|
 *  |Shift | Z  | X  | C  | V  | B  | N  | M  | ,  | .  |SftPly | | 1  | 2  | 3  |
 *  |-----------------------------------------------------------| |--------------|
 *  | Ctrl |Gui | Alt  |  NU+Spc |     Spc    | -   | =  |  /   | | 0  | .  |Entr|
 *  `-----------------------------------------------------------' `--------------'
 */

[_QWERTY] = LAYOUT(
QK_GESC, KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,     KC_P7, KC_P8,   KC_P9,
KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,        KC_ENT,           KC_P4, KC_P5,   KC_P6,
KC_RSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,             KC_COMM, KC_DOT,  SFT_MSP,     KC_P1, KC_P2,   KC_P3,
KC_LCTL, KC_LGUI, KC_LALT,       SPA_NU,            KC_SPC,                      KC_MINS, KC_EQL,  KC_SLSH,     KC_P0, KC_PDOT, KC_PENT
),

/* NU (Numbers/Navigation)
 *  ,-----------------------------------------------------------. ,--------------.
 *  | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |Bspc| |Home|PgUp|Caps|
 *  |-----------------------------------------------------------| |--------------|
 *  |    |    |    |    |    |    |Left|Down| Up |Rght|   Del   | |End |PgDn|    |
 *  |-----------------------------------------------------------| |--------------|
 *  | Shift  |    |    |    |    |    | [  | ]  | ;  | '  |     | |    |    |    |
 *  |-----------------------------------------------------------| |--------------|
 *  | Ctrl|Gui |  Alt |            |            |  FN |    | \  | |    |    |BOOT|
 *  `-----------------------------------------------------------' `--------------'
 */

[_NU] = LAYOUT(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,     KC_HOME, KC_PGUP, KC_CAPS,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_DEL,           KC_END,  KC_PGDN, XXXXXXX,
KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,          KC_SCLN, KC_QUOT, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
KC_LCTL, KC_LGUI, KC_LALT,          XXXXXXX,            XXXXXXX,                 MO(_FN), XXXXXXX, KC_BSLS,     XXXXXXX, XXXXXXX, QK_BOOT
),

/* FN (Function Keys)
 *  ,-----------------------------------------------------------. ,--------------.
 *  |    | F1 | F2 | F3 | F4 | F5 | F6 |    |    |    |Ins |Del | |Home|PgUp|    |
 *  |-----------------------------------------------------------| |--------------|
 *  |      | F7 | F8 | F9 |F10 |F11 |F12 |    |    |    |       | |End |PgDn|    |
 *  |-----------------------------------------------------------| |--------------|
 *  | Shift  |    |    |    |    |    |    |    |    |    |     | |    |    |    |
 *  |-----------------------------------------------------------| |--------------|
 *  |EEPRST|    |      |    XXX   |      XXX   |     |    |     | |    |    |    |
 *  `-----------------------------------------------------------' `--------------'
 */

[_FN] = LAYOUT(
XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,      KC_HOME, KC_PGUP, XXXXXXX,
XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,     KC_END,  KC_PGDN, XXXXXXX,
KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
EE_CLR,  XXXXXXX, XXXXXXX,          XXXXXXX,            XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
)
};

bool led_update_user(led_t led_state) {
  // Turn LED On/Off for Caps Lock
  if (led_state.caps_lock) {
    the50_led_on();
  } else {
    the50_led_off();
  }
  return false;
}
