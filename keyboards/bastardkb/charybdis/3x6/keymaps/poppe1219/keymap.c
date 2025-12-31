/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum charybdis_keymap_layers {
    L_BASE = 0,
    L_NUM,
    L_NAV,
    L_PNTR,
    L_FN
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER L_PNTR

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

//const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
//    LAYOUT(
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//                       '*', '*', '*',  '*', '*'
//    );

// Home Row Mods Base Layer Left
#define HRM_A LGUI_T(KC_A)
#define HRM_R LALT_T(KC_R)
#define HRM_S LCTL_T(KC_S)
#define HRM_T LSFT_T(KC_T)
#define HRM_Z ALGR_T(KC_Z)

// Home Row Mods Base Layer Right
#define HRM_N LSFT_T(KC_N)
#define HRM_E LCTL_T(KC_E)
#define HRM_I LALT_T(KC_I)
#define HRM_O LGUI_T(KC_O)
#define HRM_SLSH ALGR_T(KC_SLSH)

#define SPC_NUM LT(LT_NUM, KC_SPC)
#define ENT_NUM LT(LT_NUM, KC_ENT)
#define ESC_NAV LT(LT_NAV, KC_ESC)
#define TAB_NAV LT(LT_NAV, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_GRV,   HRM_A,   HRM_R,   HRM_S,   HRM_T,    KC_G,       KC_M,   HRM_N,   HRM_E,   HRM_I,   HRM_O, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     TO(L_NUM),   HRM_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, HRM_SLSH, TO(L_NAV),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BSPC, SPC_NUM, ESC_NAV,    TAB_NAV, ENT_NUM
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_BASE), KC_PAST, KC_QUOT, KC_SCLN, KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSLS,  KC_EQL, KC_PSLS, _______,
//AltGr                     Auml     Ouml    Aring                                           Acute
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     TO(L_NAV), KC_ALGR,  KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, HRM_SLSH,  TO(L_FN),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_BASE), KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    KC_HOME, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_END,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_PNTR), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(LN_PNTR),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_PNTR] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PSCR, KC_CAPS, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_BASE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(L_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      TO(L_FN), XXXXXXX, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, XXXXXXX, TO(L_FN),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN1, KC_BTN2, KC_BTN3,    KC_BTN2, KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_FN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,     KC_F8,   KC_F9,  KC_F10, KC_F11,   KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_BASE), KC_PAST, KC_QUOT, KC_SCLN, KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSLS,  KC_EQL, KC_PSLS, TO(L_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
    TO(L_BASE), XXXXXXX,  KC_GRV, KC_MINS, KC_LALT, KC_LGUI,    KC_RGUI, KC_RALT, KC_COMM,  KC_DOT, KC_SLSH, TO(L_BASE),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  )
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(L_PNTR);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(L_PNTR);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
