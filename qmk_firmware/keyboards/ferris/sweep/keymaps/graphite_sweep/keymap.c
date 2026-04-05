#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _SYM,
    _NUM,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // VIA-safe core: Base (Graphite) + thumb hold-layer model.
    [_BASE] = LAYOUT_split_3x5_2(
        KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,      KC_F,    KC_O,    KC_U,    KC_J,    KC_SCLN,
        KC_N,    KC_R,    KC_T,    KC_S,    KC_G,      KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,
        KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,      KC_K,    KC_P,    KC_DOT,  KC_QUOT, KC_SLSH,
                          LT(_NAV, KC_SPC), LT(_NUM, KC_TAB), LT(_SYM, KC_ENT), LT(_FN, KC_BSPC)
    ),

    // VIA-safe core: Navigation.
    [_NAV] = LAYOUT_split_3x5_2(
        KC_ESC,  KC_TAB,  KC_NO,   KC_NO,   KC_NO,     KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_DEL,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,     KC_NO
    ),

    // VIA-safe core: Symbols.
    [_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LT,     KC_BSLS, KC_PIPE, KC_COLN, KC_SCLN, KC_DQUO,
        KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_GT,     KC_SLSH, KC_QUES, KC_COMM, KC_DOT,  KC_QUOT,
                          KC_NO,   KC_NO,   KC_NO,     KC_NO
    ),

    // VIA-safe core: Numbers.
    [_NUM] = LAYOUT_split_3x5_2(
        KC_NO,   KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO,   KC_EQL,  KC_NO,   KC_NO,   KC_NO,     KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_1,    KC_2,    KC_3,    KC_0,    KC_DOT,
                          KC_NO,   KC_NO,   KC_NO,     KC_NO
    ),

    // VIA-safe core: Function/media.
    [_FN] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_F6,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_F12,  KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,     KC_NO
    ),
};

// Optional QMK-only enhancements: minimal high-value combos.
#ifdef COMBO_ENABLE
enum combo_events {
    CMB_ESC,
    CMB_TAB,
    CMB_DEL,
#ifdef CAPS_WORD_ENABLE
    CMB_CAPS_WORD,
#endif
    CMB_COUNT
};

const uint16_t PROGMEM cmb_esc[]       = {KC_R,    KC_T,    COMBO_END};
const uint16_t PROGMEM cmb_tab[]       = {KC_H,    KC_A,    COMBO_END};
const uint16_t PROGMEM cmb_del[]       = {KC_E,    KC_I,    COMBO_END};
#ifdef CAPS_WORD_ENABLE
const uint16_t PROGMEM cmb_caps_word[] = {LT(_NAV, KC_SPC), LT(_SYM, KC_ENT), COMBO_END};
#endif

combo_t key_combos[CMB_COUNT] = {
    [CMB_ESC] = COMBO(cmb_esc, KC_ESC),
    [CMB_TAB] = COMBO(cmb_tab, KC_TAB),
    [CMB_DEL] = COMBO(cmb_del, KC_DEL),
#ifdef CAPS_WORD_ENABLE
    [CMB_CAPS_WORD] = COMBO(cmb_caps_word, QK_CAPS_WORD),
#endif
};
#endif
