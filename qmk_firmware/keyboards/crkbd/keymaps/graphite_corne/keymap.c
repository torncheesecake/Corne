#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,      KC_F,    KC_O,    KC_U,    KC_J,    KC_COMM, KC_SCLN,
        KC_TAB,  KC_N,    KC_R,    KC_T,    KC_S,    KC_G,      KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    KC_MINS,
        KC_GRV,  KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,      KC_K,    KC_P,    KC_DOT,  KC_QUOT, KC_SLSH, KC_BSLS,
                                   KC_LCTL, KC_SPC,  MO(_SYM),  KC_ENT,  KC_BSPC, KC_LSFT
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        KC_LABK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RABK,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,  KC_PLUS,
        _______, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, KC_LCBR,   KC_RCBR, KC_BSLS, KC_PIPE, KC_LABK, KC_RABK, _______,
                                   _______, _______, MO(_NAV),  _______, _______, _______
    ),

    [_NAV] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_TAB,  KC_HOME, KC_PGUP, KC_PGDN, XXXXXXX,   XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______,   _______, _______, _______
    )
};
