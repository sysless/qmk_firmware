/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRV, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,                     KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, LT(2, KC_TAB), LT(4, KC_SPC),    LT(5, KC_ENT),   LT(3, KC_BSPC), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [2] = LAYOUT_split_3x6_3(KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_MINS, KC_EQL, KC_BSLS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [3] = LAYOUT_split_3x6_3(KC_TRNS, KC_NO, KC_P7, KC_P8, KC_P9, KC_PAST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS),
  [4] = LAYOUT_split_3x6_3(KC_TRNS, KC_BRID, KC_BRIU, RGB_VAD, RGB_VAI, RGB_TOG, KC_MPLY, KC_MRWD, KC_UP, KC_MFFD, KC_VOLU, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, RGB_MOD, KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_TRNS, TG(1), KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [5] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,240,240,112,120,124,126,255,207,  7,  7, 15, 31,254,252, 60, 60, 56, 56, 56, 56,120,120,120,112,112,112,112,240,240,240,224,224,248,252,254,254,252,248,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,252,248,248,240,  0,  0,  0,  0,255,255,255,  3,  0,  3, 31,252,224,  0, 31,255,192,  0,  0,  0,127,255,  0,  0,120,120,252,252,120,  0,  0,192,224,224,224,224,224,224,224,224, 96, 97,111,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  7,  7, 14,  0, 62, 63,127,255,255,255, 30,192,248,127,  3,  0,248,255,  3,  0,  0,  0,254,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 31, 31, 31, 31, 31, 31, 31, 31,158,252,255,255, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15, 15, 14, 14, 62,126,255,243,224,224,240,248,127, 63, 60, 60, 28, 28, 28, 28, 28, 30, 30, 14, 14, 14, 14, 14, 15, 15,  7,  7,  7,  7,  7,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_text(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,248,248,252,252,252,252,252,252,252,252,  0,  0,  0,  0,  0,  0,224,240,248,124,124,124,124,124, 60, 62, 62, 31, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,240,248,248,252,252,252,254,254,254,254,254,252,252,252,248,248,240,224,192,128,  0,  0,128,192,224,240,248,252,252,252,254,254,254,254,252,252,252,248,240,252,252,252,252,252,252,252,  0,  0,252,252,252,252,255,255,255,255,255,255,255,252,252,252,252,252,  0,128,192,224,240,248,248,252,252,252,124,126,126,126,124,252,252,252,248,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,  3,  1,  0,  0,  0,  0,  0,  1,  3,135,199,199,199,199,199,199,  0,120,255,255,255,255,255,255,199,  1,  1,  0,  0,  0,  0,  1,131,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,254,255,255,255,255,255,255,255,125,124,124,124,124,124,124,124,125,127,127,127,127,127,127,127,126,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 31, 63, 63,127,127,255,254,254,252,252,252,254,254,255,127,127, 63, 63, 31, 15,  3,  0,  0,  3, 15, 31, 63,127,127,255,255,254,252,252,252,254,254,127,127, 63,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,127,  0,  0,  0,  0,  0,  1,  7, 15, 31, 63,127,127,127,255,254,252,252,252,252,252,252,254,254,254,126,126, 62, 30, 14,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();
    } else {
        render_text();
    }
    return false;
}

#endif // OLED_ENABLE

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max && index != NO_LED) {
                  if (keymap_key_to_keycode(layer, (keypos_t){col,row}) == KC_CAPS) rgb_matrix_set_color(index, RGB_RED);
                  if (layer == 4 &&
                      keymap_key_to_keycode(layer, (keypos_t){col,row}) >= KC_RIGHT &&
                      keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_UP) {
                        rgb_matrix_set_color(index, RGB_GREEN);
                  } else if (layer == 2 && 
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) >= KC_EXLM &&
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_RPRN) {
                        rgb_matrix_set_color(index, RGB_BLUE);
                  } else if (layer == 3 &&
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) >= KC_P1 &&
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_P9) {
                        rgb_matrix_set_color(index, RGB_CYAN);
                  } else if (layer == 5 &&
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) >= KC_1 &&
                             keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_0) {
                        rgb_matrix_set_color(index, RGB_CYAN);
                  }
                }
            }
        }
        for (uint8_t i = led_min; i <= led_max; i++) {
          if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
            if (layer == 4) rgb_matrix_set_color(i, RGB_GREEN);
            else if (layer == 2) rgb_matrix_set_color(i, RGB_BLUE);
            else if (layer == 3 || layer == 5) rgb_matrix_set_color(i, RGB_CYAN);
          }
        }
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(10, 255, 255);
}

