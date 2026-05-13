/*
 * Keymap optimizado para programación — Corne (crkbd)
 * Layout: US International (para ñ, acentos, ü con AltGr)
 *
 * Capas:
 *   0 BASE    — QWERTY + Home Row Mods en A-S-D-F
 *   1 NAV     — Números, F1-F12, navegación centralizada en mano derecha
 *   2 SYM     — Símbolos balanceados: brackets izquierda, operadores derecha
 *   3 ADJUST  — RGB, media, boot, Caps Word
 *
 * Home Row Mods (hold = modificador, tap = letra):
 *   A → Shift   S → Ctrl   D → Alt   F → GUI
 *   Tapping term recomendado: 200ms  (config.h: #define TAPPING_TERM 200)
 *   Para evitar activación accidental al escribir rápido, también añadir en config.h:
 *     #define PERMISSIVE_HOLD
 *
 * Trackpad Cirque Pinnacle (lado derecho):
 *   - Tap 1 dedo        → click izquierdo
 *   - 2 dedos deslizar  → scroll vertical y horizontal
 *
 * Inglés Internacional (AltGr = RAlt):
 *   ñ  = AltGr + N       á é í ó ú = AltGr + vocal
 *   ü  = AltGr + Y       ¡ = AltGr + 1    ¿ = AltGr + /
 *
 * Copyright 2019 @foostan / 2020 Drashna Jaelre — GPLv2+
 */

#include QMK_KEYBOARD_H

/* ─── Home Row Mod aliases ───────────────────────────────────────────────────
 * LSFT_T(KC_A) : tap = A,   hold = Shift
 * LCTL_T(KC_S) : tap = S,   hold = Ctrl
 * LALT_T(KC_D) : tap = D,   hold = Alt
 * LGUI_T(KC_F) : tap = F,   hold = GUI
 * ─────────────────────────────────────────────────────────────────────────*/
#define HRM_A  LSFT_T(KC_A)
#define HRM_S  LCTL_T(KC_S)
#define HRM_D  LALT_T(KC_D)
#define HRM_F  LGUI_T(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 0: BASE
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │  ⌫    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Ctrl  │A/⇧│S/⌃│D/⌥│F/⌘│ G │           │ H │ J │ K │ L │ ; │  '    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │  Esc  │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │ MO(1) │ Space │ │ Enter │ MO(2) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     *
     * Fila home izquierda — Mod-Tap (tap = letra, hold = modificador):
     *   A/⇧ = tap A  | hold Shift
     *   S/⌃ = tap S  | hold Ctrl
     *   D/⌥ = tap D  | hold Alt
     *   F/⌘ = tap F  | hold GUI
     * ─────────────────────────────────────────────────────────────────────*/
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,    KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 1: NAV — Números, teclas de función, navegación en mano derecha
     *
     * ┌───────┬────┬────┬────┬────┬────┐           ┌────┬────┬────┬────┬────┬───────┐
     * │  Tab  │ 1  │ 2  │ 3  │ 4  │ 5  │           │ 6  │ 7  │ 8  │ 9  │ 0  │  ⌫    │
     * ├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
     * │ Ctrl  │ F1 │ F2 │ F3 │ F4 │ F5 │           │ ←  │ ↓  │ ↑  │ →  │    │       │
     * ├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
     * │ Shift │ F6 │ F7 │ F8 │ F9 │F10 │           │Hom │PgDn│PgUp│End │F11 │ F12   │
     * └───────┴────┴────┴────┴────┴────┘           └────┴────┴────┴────┴────┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │       │  ▼▼▼  │ Space │ │ Enter │ MO(3) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     *
     * Mano derecha concentra toda la navegación:
     *   Fila home  → flechas + F11/F12
     *   Fila inf   → Home/PgDn/PgUp/End + F10
     * Mano izquierda queda libre para HRM (Shift+flechas = selección, etc.)
     * ─────────────────────────────────────────────────────────────────────*/
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_NO,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,    KC_ENT,   MO(3), KC_LALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 2: SYM — Símbolos balanceados para programación
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ ! │ @ │ # │ $ │ % │           │ ^ │ & │ * │ - │ = │  ⌫    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Ctrl  │ { │ } │ ( │ ) │ ` │           │ | │ _ │ + │ : │ ; │  "    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ [ │ ] │ < │ > │ ~ │           │ / │ ? │ \ │   │   │  '    │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │ MO(3) │ Space │ │ Enter │  ▼▼▼  │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     * ─────────────────────────────────────────────────────────────────────*/
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,  KC_GRV,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_COLN, KC_SCLN, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_TILD,                      KC_SLSH, KC_QUES, KC_BSLS, XXXXXXX, XXXXXXX, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,    KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 3: ADJUST — RGB, media, boot, Caps Word
     * Se activa con MO(1)+MO(2) simultáneos
     *
     * CW_TOGG = Caps Word: mayúsculas automáticas mientras escribes el
     *           identificador; se desactiva solo con Space, Enter o símbolos.
     *           Ideal para constantes: MY_CONSTANT, MAX_VALUE, etc.
     *           Requiere en config.h: #define CAPS_WORD_IDLE_TIMEOUT 5000
     * ─────────────────────────────────────────────────────────────────────*/
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, CW_TOGG,                      KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
    )
};

/* ─────────────────────────────────────────────────────────────────────────
 * Encoder map — 4 capas
 *
 * BASE encoder 3: zoom in/out (Ctrl +/-)  ← antes era brillo RGB
 *   Navegador, VS Code, iTerm, etc. responden a Ctrl+= / Ctrl+-
 * ─────────────────────────────────────────────────────────────────────────*/
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD,      KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV,      KC_MNXT),
        ENCODER_CCW_CW(RM_VALD,      RM_VALU),
        ENCODER_CCW_CW(C(KC_MINS),   C(KC_EQL)),   // Zoom out / Zoom in
    },
    [1] = {
        ENCODER_CCW_CW(KC_VOLD,      KC_VOLU),
        ENCODER_CCW_CW(C(KC_Z),      C(KC_Y)),
        ENCODER_CCW_CW(RM_VALD,      RM_VALU),
        ENCODER_CCW_CW(KC_DOWN,      KC_UP),
    },
    [2] = {
        ENCODER_CCW_CW(KC_VOLD,      KC_VOLU),
        ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)),
        ENCODER_CCW_CW(RM_VALD,      RM_VALU),
        ENCODER_CCW_CW(KC_RGHT,      KC_LEFT),
    },
    [3] = {
        ENCODER_CCW_CW(KC_VOLD,      KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV,      KC_MNXT),
        ENCODER_CCW_CW(RM_NEXT,      RM_PREV),
        ENCODER_CCW_CW(RM_VALD,      RM_VALU),
    },
};
#endif
