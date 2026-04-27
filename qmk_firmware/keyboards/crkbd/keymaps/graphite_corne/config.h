#pragma once

// VIA default dynamic layers are lower on some targets.
// This keymap uses 5 layers (Base/Nav/Sym/Num/Fn).
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Force plain, readable OLED text rendering.
#define OLED_DISPLAY_128X32
#define OLED_FONT_H "drivers/oled/glcdfont.c"
