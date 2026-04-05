# Corne Graphite Layout (3x6 + 3)

This keymap mirrors the current website layout for Corne.

## VIA-safe core

- Layers: `Base`, `Nav`, `Sym`, `Num`, `Fn`
- Thumb hold-layer model:
  - Left: `Ctrl`, `Space/NAV`, `Tab/NUM`
  - Right: `Enter/SYM`, `Bksp/FN`, `Shift`
- Graphite alpha positions are unchanged.
- Outer column anchors are intentional:
  - Base: `Esc`, `Tab`, `` ` ``, `;`, `Bksp`, `Enter`, `Delete`
  - Nav/Num/Fn keep practical editing anchors where defined on the site.

## Optional QMK-only

- Minimal combo set in `keymap.c` under `#ifdef COMBO_ENABLE`
- Optional Caps Word combo under `#ifdef CAPS_WORD_ENABLE`
- Enable in `rules.mk` by uncommenting:
  - `COMBO_ENABLE = yes`
  - `CAPS_WORD_ENABLE = yes`

## Build

```sh
qmk compile -kb crkbd -km graphite_corne
```
