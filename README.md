# ⌨️ Corne (crkbd) — Configuración QMK personalizada para programación

Keymap optimizado para desarrollo de software sobre el teclado split **Corne (crkbd)** con trackpad **Cirque Pinnacle** integrado en el lado derecho.

---

## Características principales

- **4 capas** diseñadas para programación: BASE, NAV, SYM y ADJUST
- **Home Row Mods** — modificadores en la fila home sin perder teclas
- **Trackpad Cirque Pinnacle 40 mm** con tap, scroll de 2 dedos y capa de mouse automática
- **RGB** con múltiples efectos y límite de brillo para la vida útil de los LEDs
- **Encoders rotativos** con funciones distintas por capa
- Layout **US International** para escribir ñ, acentos y caracteres especiales en español

---

## Estructura de archivos

```
keyboards/crkbd/keymaps/<tu-keymap>/
├── config.h      # Parámetros del firmware (timings, RGB, trackpad)
├── keymap.c      # Definición de capas, HRM y encoders
└── rules.mk      # Features habilitadas (OLED, pointing device, mouse keys)
```

---

## Capas

### Capa 0 — BASE

Layout QWERTY con **Home Row Mods** en la fila home izquierda.

```
┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
│  Tab  │ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │  ⌫    │
├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
│ Ctrl  │A/⇧│S/⌃│D/⌥│F/⌘│ G │           │ H │ J │ K │ L │ ; │  '    │
├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
│ Shift │ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │  Esc  │
└───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
                    ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
                    │  GUI  │ MO(1) │ Space │ │ Enter │ MO(2) │ RAlt  │
                    └───────┴───────┴───────┘ └───────┴───────┴───────┘
```

#### Home Row Mods

| Tecla | Tap | Hold |
|-------|-----|------|
| A     | `a` | Shift |
| S     | `s` | Ctrl  |
| D     | `d` | Alt   |
| F     | `f` | GUI   |

> **Tip:** Mantén pulsada la tecla home el tiempo definido en `TAPPING_TERM` (200 ms) para activar el modificador. Usa `PERMISSIVE_HOLD` para que funcione correctamente al escribir rápido.

---

### Capa 1 — NAV

Números en la fila superior. Navegación completa en la mano derecha para combinarla libremente con los HRM de la izquierda (Shift+flecha = selección, Ctrl+flecha = palabra a palabra, etc.).

```
┌───────┬────┬────┬────┬────┬────┐           ┌────┬────┬────┬────┬────┬───────┐
│  Tab  │ 1  │ 2  │ 3  │ 4  │ 5  │           │ 6  │ 7  │ 8  │ 9  │ 0  │  ⌫    │
├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
│ Ctrl  │ F1 │ F2 │ F3 │ F4 │ F6 │           │ ←  │ ↓  │ ↑  │ →  │F12 │       │
├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
│ Shift │ F6 │ F7 │ F8 │ F9 │F10 │           │Hom │PgDn│PgUp│End │F11 │       │
└───────┴────┴────┴────┴────┴────┘           └────┴────┴────┴────┴────┴───────┘
                    ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
                    │       │  ▼▼▼  │ Space │ │ Enter │ MO(3) │ RAlt  │
                    └───────┴───────┴───────┘ └───────┴───────┴───────┘
```

---

### Capa 2 — SYM

Símbolos balanceados: brackets y agrupadores en la mano izquierda, operadores y puntuación en la derecha.

```
┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
│  Tab  │ ! │ @ │ # │ $ │ % │           │ ^ │ & │ * │ - │ = │  Del  │
├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
│ Ctrl  │ { │ } │ ( │ ) │ ` │           │ | │ _ │ + │ : │ \ │  "    │
├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
│ Shift │ [ │ ] │ < │ > │ ~ │           │ / │ ? │   │   │ ; │  '    │
└───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
                    ┌───────┬───────┬───────┐ ┌───────┬───────┬───────┐
                    │  GUI  │ MO(3) │ Space │ │ Enter │  ▼▼▼  │ RAlt  │
                    └───────┴───────┴───────┘ └───────┴───────┴───────┘
```

---

### Capa 3 — ADJUST

Se activa manteniendo `MO(1)` y `MO(2)` simultáneamente.

```
┌───────┬────┬────┬────┬────┬────┐           ┌────┬────┬────┬────┬────┬───────┐
│ BOOT  │    │    │    │    │    │           │    │    │    │    │    │       │
├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
│RGB Tog│Hue+│Sat+│Val+│    │    │           │ ⏮  │ ⏹  │ ⏯  │ ⏭  │    │       │
├───────┼────┼────┼────┼────┼────┤           ├────┼────┼────┼────┼────┼───────┤
│RGB Mod│Hue-│Sat-│Val-│    │CpWd│           │Vol-│Mute│Vol+│    │    │       │
└───────┴────┴────┴────┴────┴────┘           └────┴────┴────┴────┴────┴───────┘
```

**Caps Word** (`CW_TOGG`): activa mayúsculas automáticas para escribir constantes (`MY_CONSTANT`, `MAX_VALUE`). Se desactiva sola al pulsar Space, Enter o un símbolo no alfanumérico.

---

## Encoders rotativos

| Capa | Encoder 1 | Encoder 2 | Encoder 3 | Encoder 4 |
|------|-----------|-----------|-----------|-----------|
| BASE | Vol −/+ | Pista ant/sig | RGB brillo | Zoom − / Zoom + (Ctrl −/+) |
| NAV  | Vol −/+ | Undo / Redo | RGB brillo | Línea ↓ / ↑ |
| SYM  | Vol −/+ | Tab ant/sig (Ctrl+Shift+Tab / Ctrl+Tab) | RGB brillo | → / ← |
| ADJUST | Vol −/+ | Pista ant/sig | Modo RGB | RGB brillo |

---

## Trackpad Cirque Pinnacle

| Gesto | Acción |
|-------|--------|
| Tap 1 dedo | Click izquierdo |
| Deslizar 2 dedos | Scroll vertical y horizontal |

### Configuración relevante (`config.h`)

```c
#define CIRQUE_PINNACLE_DIAMETER_MM 40      // Trackpad de 40 mm
#define CIRQUE_PINNACLE_TAP_ENABLE          // Tap = click izquierdo
#define SCROLL_DIVISOR_H 8.0               // Velocidad scroll horizontal
#define SCROLL_DIVISOR_V 8.0               // Velocidad scroll vertical
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
```

> **Ajuste de velocidad:** reduce `SCROLL_DIVISOR_*` (p. ej. a `4.0`) para scroll más rápido, auméntalo para scroll más lento.

### Orientación e inversión

Si el trackpad no está alineado con el movimiento esperado, descomenta las líneas correspondientes en `config.h`:

```c
//#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_ROTATION_180
//#define POINTING_DEVICE_ROTATION_270
//#define POINTING_DEVICE_INVERT_X
//#define POINTING_DEVICE_INVERT_Y
```

---

## RGB

Los efectos habilitados son: Breathing, Rainbow Mood, Rainbow Swirl, Snake, Knight, Christmas, Static Gradient, RGB Test, Alternating y Twinkle.

El brillo máximo está limitado a **120/255** (`RGBLIGHT_LIMIT_VAL 120`) para proteger los LEDs y reducir consumo.

---

## Layout US International y caracteres en español

El modificador `RAlt` (AltGr) permite escribir caracteres del español sin cambiar el layout del sistema operativo.

| Caracter | Combinación |
|----------|-------------|
| ñ | AltGr + N |
| á é í ó ú | AltGr + vocal |
| ü | AltGr + Y |
| ¡ | AltGr + 1 |
| ¿ | AltGr + / |

---

## Compilar y flashear

```bash
# Compilar
qmk compile -kb crkbd -km <tu-keymap>

# Flashear (el teclado debe estar en modo bootloader)
qmk flash -kb crkbd -km <tu-keymap>
```

Para entrar en modo bootloader pulsa `QK_BOOT` (disponible en la capa ADJUST, esquina superior izquierda).

---

## Parámetros clave (`config.h`)

| Parámetro | Valor | Descripción |
|-----------|-------|-------------|
| `TAPPING_TERM` | 200 ms | Tiempo máximo de tap para HRM |
| `PERMISSIVE_HOLD` | — | Activa el hold al soltar otra tecla dentro del tapping term |
| `MASTER_RIGHT` | — | El lado derecho es el maestro (donde va el USB) |
| `AUTO_MOUSE_TIME` | 600 ms | Tiempo sin movimiento para desactivar la capa de mouse |
| `RGBLIGHT_LIMIT_VAL` | 120 | Brillo máximo RGB |
| `SCROLL_DIVISOR_H/V` | 8.0 | Divisor de velocidad de scroll |

---

## Features habilitadas (`rules.mk`)

```makefile
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
OLED_ENABLE            = yes
MOUSEKEY_ENABLE        = yes
```
