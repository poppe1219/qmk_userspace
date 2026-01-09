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
    //L_NUM,
    L_SYM,
    L_NV, // Navigation
    L_FN, // Function buttons
    L_PTR
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER L_PTR


//const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
//    LAYOUT(
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
//                       '*', '*', '*',  '*', '*'
//    );

// Home Row Mods Base Layer Left
#define HR_A LGUI_T(KC_A)
#define HR_R LALT_T(KC_R)
#define HR_S LCTL_T(KC_S)
#define HR_T LSFT_T(KC_T)
#define HR_D ALGR_T(KC_D)

// Home Row Mods Base Layer Right
#define HR_N LSFT_T(KC_N)
#define HR_E LCTL_T(KC_E)
#define HR_I LALT_T(KC_I)
#define HR_O LGUI_T(KC_O)
#define HR_H ALGR_T(KC_H)

// Home Row Mods Sym Layer Right
#define HR_QUOT LSFT_T(KC_QUOT)
#define HR_LBRC LCTL_T(KC_LBRC)
#define HR_RBRC LALT_T(KC_RBRC)
#define HR_EQL LGUI_T(KC_EQL)
#define HR_MINS ALGR_T(KC_MINS)

// Home Row Mods Sym Layer Left
#define HR_0 LGUI_T(KC_0)
#define HR_3 LALT_T(KC_3)
#define HR_2 LCTL_T(KC_2)
#define HR_1 LSFT_T(KC_1)
#define HR_4 ALGR_T(KC_4)

// Thumb Row Mods
#define SPC_SYM LT(L_SYM, KC_SPC)
#define ENT_SYM LT(L_SYM, KC_ENT)
#define ESC_NV2 LT(L_NV, KC_ESC)
#define TAB_NV2 LT(L_NV, KC_TAB)

// Other Row Mods
#define DEL_FN LT(L_FN, KC_DEL)

// Universal Cut, Copy and Paste
#define C_CUT S(KC_DEL)
#define C_COPY C(KC_INS)
#define C_PASTE S(KC_INS)

const uint16_t PROGMEM boot_cmb1[] = {KC_QUOT, KC_G, COMBO_END};
const uint16_t PROGMEM boot_cmb2[] = {KC_M, KC_MINS, COMBO_END};
const uint16_t PROGMEM eeclr_cmb1[] = {KC_GRV, KC_B, COMBO_END};
const uint16_t PROGMEM eeclr_cmb2[] = {KC_J, MO(L_FN), COMBO_END};
const uint16_t PROGMEM to_base_cmb1[] = {KC_Z, HR_D, COMBO_END};
const uint16_t PROGMEM to_base_cmb2[] = {HR_H, KC_SLSH, COMBO_END};
const uint16_t PROGMEM caps_cmb[] = {KC_Z, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(boot_cmb1, QK_BOOT),
    COMBO(boot_cmb2, QK_BOOT),
    COMBO(eeclr_cmb1, EE_CLR),
    COMBO(eeclr_cmb2, EE_CLR),
    COMBO(to_base_cmb1, TO(L_BASE)),
    COMBO(to_base_cmb2, TO(L_BASE)),
    COMBO(caps_cmb, KC_CAPS),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      MO(L_FN),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  DEL_FN,
       KC_QUOT,    HR_A,    HR_R,    HR_S,    HR_T,    KC_G,       KC_M,    HR_N,    HR_E,    HR_I,    HR_O, KC_MINS,
     MO(L_PTR),    KC_Z,    KC_X,    KC_C,    HR_D,    KC_V,       KC_K,    HR_H, KC_COMM,  KC_DOT, KC_SLSH,  QK_REP,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BSPC, SPC_SYM, ESC_NV2,    TAB_NV2, ENT_SYM
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_0,    KC_8,    KC_8,    KC_7, XXXXXXX,    XXXXXXX, KC_PAST, KC_LPRN, KC_RPRN, _______,  KC_DEL,
       QK_LLCK,    HR_0,    HR_3,    HR_2,    HR_1, XXXXXXX,    XXXXXXX, HR_QUOT, HR_LBRC, HR_RBRC,  HR_EQL, XXXXXXX,
       KC_MENU,    KC_0,    KC_6,    KC_5,    HR_4, XXXXXXX,    XXXXXXX, HR_MINS, _______, _______, KC_BSLS, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC, _______,    _______,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_NV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_PGUP,    KC_0,    KC_8,    KC_8,    KC_7, XXXXXXX,    XXXXXXX,   C_CUT,  C_COPY, C_PASTE, XXXXXXX,  KC_DEL,
       KC_PGDN,    HR_0,    HR_3,    HR_2,    HR_1, XXXXXXX,    KC_HOME, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_END,
       KC_MENU,    KC_0,    KC_6,    KC_5,    HR_4, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC, _______,    _______,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_FN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_SCRL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
       QK_LLCK, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11,     KC_F12, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_CAPS,
       XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, KC_ALGR, KC_PAUS,    XXXXXXX, KC_ALGR, KC_PSCR,  KC_INS, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC,  KC_ESC,     KC_TAB,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_PTR] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT, XXXXXXX, XXXXXXX,
       QK_LLCK, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
       _______, XXXXXXX, DRGSCRL, SNIPING, KC_ALGR, XXXXXXX,    XXXXXXX, KC_ALGR, SNIPING, DRGSCRL, XXXXXXX, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN3, KC_BTN1, KC_BTN2,    KC_BTN2, KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  )
};
// clang-format on

void pointing_device_init_user(void) {
    set_auto_mouse_layer(L_PTR);
    set_auto_mouse_enable(true);
}
