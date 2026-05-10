/*
 * Keymap optimizado para programación — Corne (crkbd)
 * Layout: US International (para ñ, acentos, ü con AltGr)
 *
 * Capas:
 *   0 BASE    — QWERTY con Esc en thumb izquierdo, ⌫ en posición de P
 *   1 NAV     — Números, F1-F12, Home/End/PgUp/PgDn, flechas
 *   2 SYM     — Símbolos balanceados: brackets izquierda, operadores derecha
 *   3 ADJUST  — RGB, media, boot
 *
 * Cambios vs layout original:
 *   - Esc movido a thumb izquierdo (ideal para Vim/terminal)
 *   - ⌫ movido a posición P (meñique derecho, más natural)
 *   - Del en esquina inferior derecha como respaldo
 *   - Home/End/PgUp/PgDn en home row izquierda de capa 1
 *   - F1-F12 completas en capa 1 (F1-F5+F11 izquierda, F6-F10+F12 derecha)
 *   - {} [] () movidos a mano izquierda en capa 2 (home row y fila inferior)
 *   - < > añadidos en capa 2 izquierda (útiles para HTML/JSX/generics)
 *   - Operadores de código en derecha: | _ + : \ " / ?
 *
 * Inglés Internacional (AltGr = RAlt):
 *   ñ  = AltGr + N       á é í ó ú = AltGr + vocal
 *   ü  = AltGr + Y       ¡ = AltGr + 1    ¿ = AltGr + /
 *   «» = AltGr + [ ]
 *
 * Copyright 2019 @foostan / 2020 Drashna Jaelre — GPLv2+
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 0: BASE
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │   ⌫   │  ← meñique derecho (antes en esquina)
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │   '   │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Ctrl  │ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │  Del  │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  Esc  │ MO(1) │ Space │ │ Enter │ MO(2) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     *                       ↑ Esc en thumb: perfecto para Vim y terminal
     * ─────────────────────────────────────────────────────────────────────*/
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,   MO(1),  KC_SPC,    KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 1: NAV — Números, teclas de función, navegación
     *
     * ┌───────┬────┬────┬────┬────┬────┐           ┌───┬───┬───┬───┬─────┬───────┐
     * │  Tab  │ 1  │ 2  │ 3  │ 4  │ 5  │           │ 6 │ 7 │ 8 │ 9 │  0  │   ⌫   │
     * ├───────┼────┼────┼────┼────┼────┤           ├───┼───┼───┼───┼─────┼───────┤
     * │  Ctrl │Home│PgDn│PgUp│ End│F11 │           │ ← │ ↓ │ ↑ │ → │ F12 │       │
     * ├───────┼────┼────┼────┼────┼────┤           ├───┼───┼───┼───┼─────┼───────┤
     * │ Shift │ F1 │ F2 │ F3 │ F4 │ F5 │           │F6 │F7 │F8 │F9 │ F10 │       │
     * └───────┴────┴────┴────┴────┴────┘           └───┴───┴───┴───┴─────┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │  ▼▼▼  │ Space │ │ Enter │ MO(3) │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     *
     * Home/End/PgUp/PgDn en home row izquierda — navegación sin mover manos
     * Combinaciones útiles:
     *   Ctrl+Home/End    → inicio/fin del archivo
     *   Shift+flechas    → selección de texto
     *   Ctrl+flechas     → saltar palabras
     * ─────────────────────────────────────────────────────────────────────*/
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_F11,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,    KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),

    /* ─────────────────────────────────────────────────────────────────────
     * Capa 2: SYM — Símbolos balanceados para programación
     *
     * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
     * │  Tab  │ ! │ @ │ # │ $ │ % │           │ ^ │ & │ * │ - │ = │   ⌫   │
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │  Ctrl │ { │ } │ ( │ ) │ ` │           │ | │ _ │ + │ : │ \ │   "   │  ← : y " muy usados en código
     * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
     * │ Shift │ [ │ ] │ < │ > │ ~ │           │ / │ ? │   │   │ ; │   '   │
     * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │ MO(3) │ Space │ │ Enter │  ▼▼▼  │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
     *
     * Lógica de distribución:
     *   Izquierda home row: {} ()  — pares que se abren juntos, se cierran con derecha
     *   Izquierda fila inf: [] <> — idem para arrays y generics/HTML
     *   Derecha: operadores binarios | _ + : \ y puntuación ; '
     *
     * Nota: KC_LABK = < (less-than), KC_RABK = > (greater-than)
     *       KC_DQUO = "  KC_COLN = :
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
     * Se activa con MO(1)+MO(2) simultáneos (ambos thumbs de capa)
     *
     * ┌───────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │ BOOT  │      │      │      │      │      │       │      │      │      │      │      │      │
     * ├───────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │TogRGB │HueUp │SatUp │ValUp │      │      │       │ Prev │ Stop │ Play │ Next │      │      │
     * ├───────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │NextMod│HueDn │SatDn │ValDn │      │      │       │VolDn │ Mute │VolUp │      │      │      │
     * └───────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                     ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
     *                     │  GUI  │  ▼▼▼  │ Space │ │ Enter │  ▼▼▼  │ RAlt  │
     *                     └───────┴───────┴───────┘ └───────┴───────┴───────┘
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
    )
};

/* ─────────────────────────────────────────────────────────────────────────
 * Encoder map — comportamiento diferenciado por capa
 *
 * Capa 0 BASE:   Vol / Media / RGB brillo / Scroll horizontal
 * Capa 1 NAV:    Vol / Historial (Undo/Redo) / RGB brillo / Navegación líneas
 * Capa 2 SYM:    Vol / Tab siguiente/anterior / RGB brillo / Scroll horizontal
 * Capa 3 ADJUST: Vol / Media / RGB brillo / RGB modo
 *
 * Ajusta según los encoders físicos que tengas montados.
 * ─────────────────────────────────────────────────────────────────────────*/
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Capa 0: volumen | media prev/next | RGB brillo | scroll horizontal
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
    // Capa 1 NAV: volumen | undo/redo | RGB brillo | línea arriba/abajo
    [1] = {
        ENCODER_CCW_CW(KC_VOLD,    KC_VOLU),
        ENCODER_CCW_CW(C(KC_Z),    C(KC_Y)),
        ENCODER_CCW_CW(RM_VALD,    RM_VALU),
        ENCODER_CCW_CW(KC_DOWN,    KC_UP),
    },
    // Capa 2 SYM: volumen | tab prev/next (navegador/editor) | RGB brillo | scroll horizontal
    [2] = {
        ENCODER_CCW_CW(KC_VOLD,          KC_VOLU),
        ENCODER_CCW_CW(C(S(KC_TAB)),     C(KC_TAB)),
        ENCODER_CCW_CW(RM_VALD,          RM_VALU),
        ENCODER_CCW_CW(KC_RGHT,          KC_LEFT),
    },
    // Capa 3 ADJUST: volumen | media | RGB siguiente modo | RGB brillo
    [3] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_NEXT, RM_PREV),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
    },
};
#endif
