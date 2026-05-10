/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #undef MASTER_LEFT
#define MASTER_RIGHT

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

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

#define SPLIT_USB_DETECT

#define SPLIT_POINTING_ENABLE // This is to enable the pointing device on the slave side of a split keyboard.
#define POINTING_DEVICE_RIGHT // Specifies in which side is the pointing device

//# Size (default is 40)
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY

//# If rotation is needed
//#define POINTING_DEVICE_ROTATION_90
//#define POINTING_DEVICE_INVERT_X
//#define POINTING_DEVICE_INVERT_Y


//# Gestures
// #define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define CIRQUE_PINNACLE_TAP_ENABLE