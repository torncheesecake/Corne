# Ferris Sweep Graphite Layout (3x5 + 2)

This keymap mirrors the current website layout for Ferris Sweep.

## VIA-safe core

- Layers: `Base`, `Nav`, `Sym`, `Num`, `Fn`
- Thumb hold-layer model:
  - Left: `Space/NAV`, `Tab/NUM`
  - Right: `Enter/SYM`, `Bksp/FN`
- Graphite alpha positions are unchanged.
- Sweep remains intentionally minimal compared with Corne.

## Optional QMK-only

- Minimal combo set in `keymap.c` under `#ifdef COMBO_ENABLE`
- Optional Caps Word combo under `#ifdef CAPS_WORD_ENABLE`
- Enable in `rules.mk` by uncommenting:
  - `COMBO_ENABLE = yes`
  - `CAPS_WORD_ENABLE = yes`

## Build

```sh
qmk compile -kb ferris/sweep -km graphite_sweep
```
