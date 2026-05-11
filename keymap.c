/*
 * Keymap optimizado para programación — Corne (crkbd)
 * Layout: US International (para ñ, acentos, ü con AltGr)
 *
 * Capas:
 *   0 BASE    — QWERTY con Esc en thumb izquierdo, ⌫ en posición de P
 *   1 NAV     — Números, F1-F12, Home/End/PgUp/PgDn, flechas
 *   2 SYM     — Símbolos balanceados: brackets izquierda, operadores derecha
 *   3 ADJUST  — RGB, media, boot
 *   4 MOUSE   — Auto mouse layer: clics, scroll, drag (se activa al mover trackpad)
 *
 * Trackpad Cirque Pinnacle (lado derecho):
 *   - Tap 1 dedo        → click izquierdo
 *   - 2 dedos deslizar  → scroll vertical y horizontal
 *   - Capa MOUSE auto   → BTN1/BTN2/BTN3 accesibles con el pulgar izquierdo
 *
 * Inglés Internacional (AltGr = RAlt):
 *   ñ  = AltGr + N       á é í ó ú = AltGr + vocal
 *   ü  = AltGr + Y       ¡ = AltGr + 1    ¿ = AltGr + /
 *
 * Copyright 2019 @foostan / 2020 Drashna Jaelre — GPLv2+
 */

#include QMK_KEYBOARD_H

/* ─── Auto mouse layer ───────────────────────────────────────────────────────
 * Se activa automáticamente al detectar movimiento del trackpad.
 * Requiere AUTO_MOUSE_ENABLE = yes en rules.mk
 * ─────────────────────────────────────────────────────────────────────────*/
#define AUTO_MOUSE_DEFAULT_LAYER 4

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(AUTO_MOUSE_DEFAULT_LAYER);
    set_auto_mouse_enable(true);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 0: BASE
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │  ⌫    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │  Ctrl │ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │  '    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │  Esc  │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │ MO(1) │ Space │ │ Enter │ MO(2) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     * ─────────────────────────────────────────────────────────────────────*/
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,    KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 1: NAV — Números, teclas de función, navegación
     *
     * ┌───────┬────┬────┬────┬────┬────┐           ┌───┬───┬───┬───┬─────┬───────┐
     * │  Tab  │ 1  │ 2  │ 3  │ 4  │ 5  │           │ 6 │ 7 │ 8 │ 9 │  0  │  Del  │
     * ├───────┼────┼────┼────┼────┼────┤           ├───┼───┼───┼───┼─────┼───────┤
     * │  Ctrl │Home│PgDn│PgUp│ End│F11 │           │ ← │ ↓ │ ↑ │ → │ F12 │       │
     * ├───────┼────┼────┼────┼────┼────┤           ├───┼───┼───┼───┼─────┼───────┤
     * │ Shift │ F1 │ F2 │ F3 │ F4 │ F5 │           │F6 │F7 │F8 │F9 │ F10 │       │
     * └───────┴────┴────┴────┴────┴────┘           └───┴───┴───┴───┴─────┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │       │  ▼▼▼  │ Space │ │ Enter │ MO(3) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     * ─────────────────────────────────────────────────────────────────────*/
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_F11,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_F12, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,    KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 2: SYM — Símbolos balanceados para programación
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ ! │ @ │ # │ $ │ % │           │ ^ │ & │ * │ - │ = │  ⌫    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │  Ctrl │ { │ } │ ( │ ) │ ` │           │ | │ _ │ + │ : │ \ │  "    │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ [ │ ] │ < │ > │ ~ │           │ / │ ? │   │   │ ; │  '    │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │ MO(3) │ Space │ │ Enter │  ▼▼▼  │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     * ─────────────────────────────────────────────────────────────────────*/
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,  KC_GRV,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_COLN, KC_BSLS, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_TILD,                      KC_SLSH, KC_QUES, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,    KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 3: ADJUST — RGB, media, boot
     * Se activa con MO(1)+MO(2) simultáneos
     * ─────────────────────────────────────────────────────────────────────*/
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 4: MOUSE — Auto mouse layer
     *
     * Se activa AUTOMÁTICAMENTE al mover el trackpad.
     * Se desactiva sola al dejar de mover el cursor (~600ms timeout).
     *
     * Thumbs izquierdos:  BTN2 (clic derecho) | BTN1 (clic izq) | BTN3 (medio)
     * Thumbs derechos:    BTN1 (clic izq)     | BTN2 (clic der) | —
     *
     * Los clics están duplicados en ambas mitades para que puedas hacer
     * clic con cualquier pulgar sin importar qué mano mueve el trackpad.
     *
     * Todas las demás teclas son XXXXXXX — al presionar cualquier tecla
     * normal la capa se desactiva inmediatamente y la tecla funciona normal.
     * ─────────────────────────────────────────────────────────────────────*/
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN2, MS_BTN1, MS_BTN3,   MS_BTN1, MS_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    )
};

/* ─────────────────────────────────────────────────────────────────────────
 * Encoder map — 5 capas incluyendo MOUSE
 * ─────────────────────────────────────────────────────────────────────────*/
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
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
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
    },
    [4] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
};
#endif
