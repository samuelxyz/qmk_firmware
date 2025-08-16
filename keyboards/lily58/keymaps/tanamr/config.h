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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define ONESHOT_TIMEOUT 500

#define COMBO_TERM 25
#define COMBO_COUNT 1

#undef RGBLED_NUM
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_SLEEP
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 14
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 7, 7 }
#define RGBLIGHT_LED_MAP { 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 10, 11, 12, 13}
#define RGBLIGHT_LIMIT_VAL 255
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 10
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 17
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_RETAIN_VAL
#define SPLIT_LAYER_STATE_ENABLE

#define OLED_TIMEOUT 10000
#define OLED_FADE_OUT
// #define OLED_FADE_OUT_INTERVAL 3
// #define OLED_SCROLL_TIMEOUT 5000
#define OLED_BRIGHTNESS 200
#define OLED_UPDATE_INTERVAL 5

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
