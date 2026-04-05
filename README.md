# Graphite Split Layout Site

Static GitHub Pages-ready keyboard layout reference for **Corne v3 Choc** and **Ferris Sweep** using **Graphite** alphas with Miryoku-inspired layer organisation.

## Site Structure

- `index.html`: Main page, using Vue + Tailwind CDN with inline page styles
- `app-keyboards-graphite.json`: Main editable source for both keyboard modes
- `assets/`: Optional folder for future static assets

## Firmware Sync (QMK)

The website is the source of truth. Firmware files are now aligned to the current site layout.

- Corne keymap:
  - `qmk_firmware/keyboards/crkbd/keymaps/graphite_corne/keymap.c`
  - `qmk_firmware/keyboards/crkbd/keymaps/graphite_corne/config.h`
  - `qmk_firmware/keyboards/crkbd/keymaps/graphite_corne/rules.mk`
  - `qmk_firmware/keyboards/crkbd/keymaps/graphite_corne/readme.md`
- Ferris Sweep keymap:
  - `qmk_firmware/keyboards/ferris/sweep/keymaps/graphite_sweep/keymap.c`
  - `qmk_firmware/keyboards/ferris/sweep/keymaps/graphite_sweep/rules.mk`
  - `qmk_firmware/keyboards/ferris/sweep/keymaps/graphite_sweep/readme.md`

These keymaps mirror the same five-layer model used on the site:

- `Base`
- `Nav`
- `Sym`
- `Num`
- `Fn`

Thumb hold-layer behaviour is mapped exactly from the site definitions.

### VIA-safe vs QMK-only in firmware

VIA-safe core:

- Base/Nav/Sym/Num/Fn layers
- Thumb hold-layer model (`LT(...)`) matching site tap/hold roles

QMK-only optional features:

- Combos (`COMBO_ENABLE`)
- Caps Word combo (`CAPS_WORD_ENABLE`)

Both are implemented in `keymap.c` behind `#ifdef` guards and are disabled by default in `rules.mk`.

### Practical notes

- Corne includes explicit outer-column editing anchors as shown on the site.
- Sweep stays intentionally minimal and does not inherit Corne-specific extra-column behaviour.
- VIA enablement for Sweep can depend on target support in your QMK tree, so it is left commented in Sweep `rules.mk`.
- Corne uses 5 layers with VIA, so `config.h` sets `DYNAMIC_KEYMAP_LAYER_COUNT 5`.

## Supported Keyboards

- `Corne v3 Choc` (3x6 + 3)
- `Ferris Sweep` (3x5 + 2)

Both use Graphite as the alpha basis but keep board-specific geometry and practical layer behaviour.

## Chosen Thumb Strategy (Miryoku-inspired, practical)

Corne thumbs:

- Left: `Ctrl`, `Space (hold NAV)`, `Tab (hold NUM)`
- Right: `Enter (hold SYM)`, `Backspace (hold FN)`, `Shift`

Sweep thumbs:

- Left: `Space (hold NAV)`, `Tab (hold NUM)`
- Right: `Enter (hold SYM)`, `Backspace (hold FN)`

Why:

- Keeps highest-frequency actions on thumbs first (Space, Enter, Backspace)
- Preserves Miryoku-style hold layers without overloading learning complexity
- Keeps Corne richer for daily use while Sweep stays minimal and realistic

## Miryoku-style Adaptations for Graphite

- Miryoku-like layer model: `Base`, `Nav`, `Sym`, `Num`, `Fn`
- Graphite alpha positions are fixed on each board's Base layer
- Layers are practical rather than maximal
- Minimal combos only, focused on real editing/navigation gains

## VIA-safe vs QMK-only

Corne VIA-safe (core):

- Base/Nav/Sym/Num/Fn
- Thumb holds: `Space/NAV`, `Tab/NUM`, `Enter/SYM`, `Bksp/FN`

Sweep VIA-safe (core):

- Base/Nav/Sym/Num/Fn
- Thumb holds: `Space/NAV`, `Tab/NUM`, `Enter/SYM`, `Bksp/FN`

Optional QMK-only enhancements (both boards):

- Minimal combo behaviours
- Caps Word combo

## Publishing to GitHub Pages

1. Push this folder to a GitHub repository.
2. Ensure `index.html` is at repository root (already set).
3. In GitHub: `Settings` -> `Pages`.
4. Under `Build and deployment`:
   - Source: `Deploy from a branch`
   - Branch: `main` (or your default branch)
   - Folder: `/ (root)`
5. Save and wait for deployment.
6. Open the published URL shown in the Pages settings.

## Local Use

Open `index.html` directly in a browser, or run a static server:

```sh
python3 -m http.server 8000
```

Then visit `http://localhost:8000`.

Note: `index.html` now includes an embedded JSON fallback, so direct `file://` opening works even when browser fetch restrictions block local JSON requests.

## Editing the Layout

Most edits should go in `app-keyboards-graphite.json`:

- `keyboards[].keyboardLayout` for board geometry
- `keyboards[].layerData.base/nav/sym/num/fn` for layer content
- `keyboards[].combos` and `keyboards[].tooltips` for optional QMK combo reference

`index.html` follows the original Corne page model (Vue rendering + JSON fetch), so most layout changes stay data-only.

## Visual Fidelity Simplification Note

A focused fidelity pass was applied to make the site closer to a keyboard reference page style:

- Reduced surrounding UI and removed extra panel-heavy sections
- Integrated layer controls directly into the keyboard block
- Tightened spacing, key sizing, and stagger proportions for denser scanning
- Increased key label legibility and reduced decorative chrome
- Kept combo support lightweight and optional, so the keyboard remains the primary focus

## Usability Review Update

After a focused real-world pass for Graphite learning and daily use:

- **Thumb choices:** kept as-is because they already prioritise high-frequency actions (`Space`, `Enter`, `Backspace`) plus clear layer access, with `Ctrl` and `Shift` retained for practical modifier use.
- **Layer choices:** simplified `Nav` to remove duplicate placements and keep a cleaner right-hand navigation cluster; `Num` now uses a more consistent right-hand numpad pattern (`789 / 456 / 1230`) with only light left-hand operators.
- **Miryoku-inspired parts:** opposite-hand layer usage from thumb holds, compact layered model (`Base/Nav/Sym/Num/Fn`), and minimal high-value combos.
- **Intentional Graphite/learning adaptations:** avoided home-row mod complexity, reduced layer redundancy, and preferred repeatable positional patterns over clever but harder-to-learn mappings.

## Reference-Model Refactor

The implementation now follows the original Corne page approach more closely:

- Vue-based key rendering from a fetched JSON config
- Tailwind CDN styling with compact keyboard cards and light interaction
- Layer switching and combo toggle behaviour aligned to the original interaction model
- Keyboard-first page flow with minimal extra UI


## Final Layout Logic (Current)

- **Corne logic:** richer daily-use setup with `Ctrl` and `Shift` dedicated on thumbs, plus four layer-hold thumbs.
- **Sweep logic:** reduced-thumb minimal setup (`Space/NAV`, `Tab/NUM`, `Enter/SYM`, `Bksp/FN`) to match Sweep constraints cleanly.
- **Miryoku-inspired parts:** thumb-held layer access, opposite-hand workflow, compact 5-layer model.
- **Graphite-learning adaptations:** no home-row mod overload, minimal high-value combos only, and repeatable key positions prioritised over cleverness.

## Visual Fidelity Correction Pass

- Added role-based key styling (alpha, home-row, thumb, hold-layer, layer-context, combo highlight) so the board is no longer flat.
- Replaced visible dot placeholders on blank keys with quiet empty placeholders that preserve spacing and silhouette.
- Reworked split-board presentation into one cohesive keyboard shell instead of two separate card-like panels.
- Improved stagger/spacing and thumb-cluster placement so Corne and Sweep silhouettes read more like real hardware.
- Tightened tap vs hold label hierarchy for quicker scanning while configuring in VIA/QMK.

## Final Quality Pass

- Corne now uses the outer sixth column intentionally on Base (`Esc`, `Tab`, `` ` ``, `;`, `Bksp`, `Enter`, `Delete`) to reduce friction in daily use.
- Corne layer labels and tooltips were tightened so high-value keys such as `Tab`, `[`, `]`, and `;` are explicit and easy to scan.
- Sweep remains intentionally simpler than Corne, with fewer moving parts and the same Graphite core.
- Combo guidance stays minimal and practical: `Esc`, `Tab`, `Delete`, plus optional `Caps Word` in QMK.

## Visual QoL Polish Pass

- Added a cleaner role-based visual system for alpha, home-row, thumb, hold-layer, editing-anchor, and combo-highlight keys.
- Improved tap vs hold readability: tap labels are now stronger and larger, hold labels are secondary and compact.
- Added subtle layer-aware shell tinting and an active-layer indicator to improve at-a-glance orientation.
- Tightened spacing and control sizing so the keyboard remains the dominant, always-open reference element.
- Added a lightweight dark-mode toggle for long sessions, with no layout logic changes.

## Final UI Refinement

- Refined light and dark palettes for clearer contrast while keeping role colours subtle and functional.
- Improved split-board cohesion with tighter half/thumb spacing and a softer central divider cue.
- Standardised button and text rhythm for cleaner scanning and reduced visual noise.
- Smoothed hover/focus behaviour to stay responsive but unobtrusive during daily reference use.

## Strong Visual Redesign Pass

- Introduced a more product-like keyboard shell treatment with stronger silhouette, layered depth, and a clearer centre split.
- Upgraded role-based colours so alpha, home-row, thumbs, editing anchors, held keys, and combo states are more immediately distinguishable.
- Redesigned selectors and toggles into pill controls with clearer active states and better focus/hover feedback.
- Added a richer, restrained page backdrop and improved keycap tactility to make the keyboard feel more intentional while staying practical.

## Practical QoL Features

- Added `Reset View` to return quickly to a known baseline (`Corne`, `Base`, light theme, combos off).
- Added `Copy View Link` so current keyboard/layer/theme/toggle state can be shared or reopened directly.
- View state is reflected in URL query parameters and restored on page load.

## Typography and Styling Refinement

- Upgraded typography with a cleaner premium sans stack (`Manrope` with sensible fallbacks) and clearer heading/metadata hierarchy.
- Refined spacing rhythm, panel treatment, and controls for a more deliberate, less prototype-like feel.
- Removed `Learning Mode` and `Hold Emphasis` controls to reduce clutter and keep the page keyboard-first.
- Kept practical controls: keyboard selector, layer selector, dark/light, combos toggle, reset, and copy-view-link.
