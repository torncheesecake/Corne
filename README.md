# Corne Graphite Layout Site

Static GitHub Pages-ready keyboard layout reference for **Corne v3 Choc (42-key, 3x6 + 3)** using **Graphite** alphas and Miryoku-style layer organisation.

## Site Structure

- `index.html`: Main page, using Vue + Tailwind CDN with inline page styles
- `app-corne-graphite.json`: Main editable source for keys, layers, tooltips, and combos
- `assets/`: Optional folder for future static assets

## Chosen Thumb Strategy (Miryoku-inspired, practical)

Base thumbs are tuned for daily use first, layer access second:

- Left: `Ctrl`, `Space (hold NAV)`, `Tab (hold NUM)`
- Right: `Enter (hold SYM)`, `Backspace (hold FN)`, `Shift`

Why this strategy:

- Keeps highest-frequency actions on thumbs: Space, Enter, Backspace
- Keeps layer entry on thumbs in a Miryoku-style hold pattern
- Avoids overloading home row while you are still learning Graphite
- Retains Ctrl/Shift where they are immediately useful

## Miryoku-style Adaptations for Graphite on Corne

- Miryoku-like layer model: `Base`, `Nav`, `Sym`, `Num`, `Fn`
- Graphite alpha positions are fixed on Base
- Layers are practical rather than maximal
- Minimal combos only, focused on real editing/navigation gains

## VIA-safe vs QMK-only

VIA-safe (core):

- Base/Nav/Sym/Num/Fn layer layouts
- Simple layer key approach represented in the visual reference

Optional QMK-only enhancements:

- Combo behaviours
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

Most edits should go in `app-corne-graphite.json`:

- `layerData.base/nav/sym/num/fn` for layer content
- `keyboardLayout.leftThumbKeys/rightThumbKeys` and base thumb values for thumb behaviour
- `combos` and `tooltips` for optional QMK combo reference

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

- **Thumb logic:** `Ctrl`, `Space/NAV`, `Tab/NUM` on left and `Enter/SYM`, `Bksp/FN`, `Shift` on right for high-frequency actions first, layers second.
- **Layer logic:** Base for Graphite learning, Nav for movement/editing, Sym for punctuation/operators, Num as right-hand numpad pattern with light left-hand operators, Fn for function/media.
- **Miryoku-inspired parts:** thumb-held layer access and opposite-hand workflow with a compact 5-layer model.
- **Graphite-learning adaptations:** no home-row mod overload, minimal high-value combos only, and repeatable key positions prioritised over cleverness.
