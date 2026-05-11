/*
 * config.h — Corne (crkbd) optimizado para programación
 *
 * Copyright 2012 Jun Wako / 2015 Jack Humbert — GPLv2+
 */

#pragma once

// #undef MASTER_LEFT
#define MASTER_RIGHT

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

/* ─── RGB ────────────────────────────────────────────────────────────────*/
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

/* ─── Split ──────────────────────────────────────────────────────────────*/
#define SPLIT_USB_DETECT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

/* ─── Cirque Pinnacle ────────────────────────────────────────────────────*/
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY

// Tap para click izquierdo con 1 dedo
#define CIRQUE_PINNACLE_TAP_ENABLE

// Scroll con 2 dedos — velocidad: número mayor = scroll más lento
// 8.0 es un buen punto de partida; baja a 4.0 si quieres scroll más rápido
#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// Rotación e inversión — descomenta si el trackpad no está alineado
//#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_ROTATION_180
//#define POINTING_DEVICE_ROTATION_270
//#define POINTING_DEVICE_INVERT_X
//#define POINTING_DEVICE_INVERT_Y

// Gestos — scroll con 2 dedos activo
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

/* ─── Auto mouse layer ───────────────────────────────────────────────────
 * La capa MOUSE (4) se activa al detectar movimiento en el trackpad
 * y se desactiva automáticamente tras este timeout sin movimiento.
 * 600ms es cómodo para uso normal; baja a 400ms si te parece lento.
 * ─────────────────────────────────────────────────────────────────────*/
#define AUTO_MOUSE_TIME 600
