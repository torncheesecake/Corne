#include QMK_KEYBOARD_H
#include <string.h>

enum layer_names {
    _BASE,
    _NAV,
    _SYM,
    _NUM,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // VIA-safe core: Base (Graphite) + thumb hold-layer model.
    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,      KC_F,    KC_O,    KC_U,    KC_J,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_N,    KC_R,    KC_T,    KC_S,    KC_G,      KC_Y,    KC_H,    KC_A,    KC_E,    KC_I,    KC_ENT,
        KC_GRV,  KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,      KC_K,    KC_P,    KC_DOT,  KC_QUOT, KC_SLSH, KC_DEL,
                                   KC_LCTL, LT(_NAV, KC_SPC), LT(_NUM, KC_TAB), LT(_SYM, KC_ENT), LT(_FN, KC_BSPC), KC_LSFT
    ),

    // VIA-safe core: Navigation.
    // Outer columns are intentional editing anchors for lower layer churn.
    [_NAV] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_TAB,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,    KC_NO,   KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_DEL,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
                                   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO
    ),

    // VIA-safe core: Symbols.
    [_SYM] = LAYOUT_split_3x6_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,   KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD, KC_BSLS, KC_PIPE,
        KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,   KC_SCLN, KC_COLN, KC_QUOT, KC_DQUO, KC_SLSH, KC_QUES,
        KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_LT,   KC_GT,     KC_COMM, KC_DOT,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
                                   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO
    ),

    // VIA-safe core: Numbers.
    [_NUM] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_BSPC,
        KC_NO,   KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_NO,     KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_ENT,
        KC_NO,   KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_1,    KC_2,    KC_3,    KC_0,    KC_DEL,
                                   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO
    ),

    // VIA-safe core: Function/media/system.
    [_FN] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,   KC_PSCR,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_PAUS,
                                   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO
    )
};

// Optional QMK-only enhancements: minimal high-value combos.
#ifdef COMBO_ENABLE
enum combo_events {
    CMB_DEL,
#ifdef CAPS_WORD_ENABLE
    CMB_CAPS_WORD,
#endif
    CMB_COUNT
};

const uint16_t PROGMEM cmb_del[]       = {KC_E,    KC_I,    COMBO_END};
#ifdef CAPS_WORD_ENABLE
const uint16_t PROGMEM cmb_caps_word[] = {LT(_NAV, KC_SPC), LT(_SYM, KC_ENT), COMBO_END};
#endif

combo_t key_combos[CMB_COUNT] = {
    [CMB_DEL] = COMBO(cmb_del, KC_DEL),
#ifdef CAPS_WORD_ENABLE
    [CMB_CAPS_WORD] = COMBO(cmb_caps_word, QK_CAPS_WORD),
#endif
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_set_brightness(200);
    return rotation;
}

static void big_glyph(char c, uint8_t out[7]) {
    memset(out, 0, 7);
    switch (c) {
        case 'A': { uint8_t t[7] = {0x04, 0x0A, 0x11, 0x1F, 0x11, 0x11, 0x11}; memcpy(out, t, 7); } break;
        case 'B': { uint8_t t[7] = {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}; memcpy(out, t, 7); } break;
        case 'C': { uint8_t t[7] = {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E}; memcpy(out, t, 7); } break;
        case 'E': { uint8_t t[7] = {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}; memcpy(out, t, 7); } break;
        case 'F': { uint8_t t[7] = {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}; memcpy(out, t, 7); } break;
        case 'G': { uint8_t t[7] = {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0E}; memcpy(out, t, 7); } break;
        case 'H': { uint8_t t[7] = {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}; memcpy(out, t, 7); } break;
        case 'I': { uint8_t t[7] = {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}; memcpy(out, t, 7); } break;
        case 'L': { uint8_t t[7] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}; memcpy(out, t, 7); } break;
        case 'M': { uint8_t t[7] = {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}; memcpy(out, t, 7); } break;
        case 'N': { uint8_t t[7] = {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}; memcpy(out, t, 7); } break;
        case 'O': { uint8_t t[7] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}; memcpy(out, t, 7); } break;
        case 'P': { uint8_t t[7] = {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}; memcpy(out, t, 7); } break;
        case 'R': { uint8_t t[7] = {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11}; memcpy(out, t, 7); } break;
        case 'S': { uint8_t t[7] = {0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E}; memcpy(out, t, 7); } break;
        case 'T': { uint8_t t[7] = {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}; memcpy(out, t, 7); } break;
        case 'U': { uint8_t t[7] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}; memcpy(out, t, 7); } break;
        case 'V': { uint8_t t[7] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04}; memcpy(out, t, 7); } break;
        case 'Y': { uint8_t t[7] = {0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04}; memcpy(out, t, 7); } break;
        default: break;
    }
}

static void draw_big_char(uint8_t x, uint8_t y, char c) {
    uint8_t rows[7];
    big_glyph(c, rows);
    for (uint8_t r = 0; r < 7; r++) {
        for (uint8_t col = 0; col < 5; col++) {
            bool on = (rows[r] >> (4 - col)) & 1;
            if (!on) continue;
            uint8_t px = x + (col * 2);
            uint8_t py = y + (r * 2);
            oled_write_pixel(px, py, true);
            oled_write_pixel(px + 1, py, true);
            oled_write_pixel(px, py + 1, true);
            oled_write_pixel(px + 1, py + 1, true);
        }
    }
}

static void draw_big_text(uint8_t x, uint8_t y, const char *txt) {
    while (*txt) {
        if (*txt == ' ') {
            x += 6;
        } else {
            draw_big_char(x, y, *txt);
            x += 12;
        }
        txt++;
    }
}

static const char *layer_text(uint8_t layer) {
    switch (layer) {
        case _BASE: return "BASE";
        case _NAV:  return "NAV";
        case _SYM:  return "SYM";
        case _NUM:  return "NUM";
        case _FN:   return "FN";
        default:    return "UNKN";
    }
}

bool oled_task_user(void) {
    const uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    const led_t leds = host_keyboard_led_state();

    oled_clear();

    if (!is_keyboard_master()) {
        draw_big_text(4, 8, "GRAPHITE");
        return false;
    }

    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln(layer_text(layer), false);

    oled_set_cursor(0, 1);
    oled_write_P(PSTR("Caps "), false);
    oled_write_P(leds.caps_lock ? PSTR("On") : PSTR("Off"), false);
    oled_write_P(PSTR(", Num "), false);
    oled_write_ln_P(leds.num_lock ? PSTR("ON ") : PSTR("OFF"), false);

    oled_set_cursor(0, 2);
    oled_write_P(PSTR("WPM "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    oled_write_ln_P(PSTR(""), false);

    return false;
}
#endif
