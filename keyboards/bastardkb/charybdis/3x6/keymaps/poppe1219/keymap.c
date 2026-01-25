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
#include "sendstring_swedish.h"


enum charybdis_keymap_layers {
    L_BASE = 0,
    L_NV, // Navigation
    L_VIM, // Vim navigation
    L_SYM, // Symbols
    L_SPE, // Special
    L_FN, // Function buttons
    L_PTR
};

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER L_PTR

enum custom_keycodes {
    M_TILDE = SAFE_RANGE,
    M_CFLEX,
    M_GRAVE,
    M_TEST1,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_TILDE: // Counteract dead key in Swedish layout: Home folder in terminals.
        if (record->event.pressed) {
            SEND_STRING("~");
        }
        break;
    case M_CFLEX:  // Counteract dead key in Swedish layout: Start, regex and vim
        if (record->event.pressed) {
            SEND_STRING("^");
        }
        break;
    case M_GRAVE: // Counteract dead key in Swedish layout: Backtick
        if (record->event.pressed) {
            SEND_STRING("`");
        }
        break;
    case M_TEST1:
        if (record->event.pressed) {
            //SEND_STRING("$,@,+,[,],{,},?,.,µ,€,£,;,:,¨,´,ä,å,ö,Ä,Å,Ö,");
            send_unicode_string("¯\\_(ツ)_/¯");
        }
        break;
  }
  return true;
};

// Home Row Mods Base Layer Left
#define HR_A LGUI_T(KC_A)
#define HR_R LALT_T(KC_R)
#define HR_S LCTL_T(KC_S)
#define HR_T LSFT_T(KC_T)
#define HR_D ALGR_T(KC_D)

// Home Row Mods Base Layer Right
#define HR_N RSFT_T(KC_N)
#define HR_E RCTL_T(KC_E)
#define HR_I LALT_T(KC_I)
#define HR_O RGUI_T(KC_O)
#define HR_H ALGR_T(KC_H)

// Home Row Mods NV, Navigation
#define HR_LEFT RSFT_T(KC_LEFT)
#define HR_DOWN RCTL_T(KC_DOWN)
#define HR_UP LALT_T(KC_UP)
#define HR_RGHT RGUI_T(KC_RGHT)

// Home Row Mods Sym Layer Left
#define HR_0 LGUI_T(KC_0)
#define HR_3 LALT_T(KC_3)
#define HR_2 LCTL_T(KC_2)
#define HR_1 LSFT_T(KC_1)
#define HR_4 ALGR_T(KC_4)

// Layer toggles
#define SPC_SYM LT(L_SYM, KC_SPC)
#define ENT_SYM LT(L_SYM, KC_ENT)
#define ESC_VIM LT(L_VIM, KC_ESC)
#define TAB_NV LT(L_NV, KC_TAB)
#define ESC_SPE LT(L_SPE, KC_ESC)
#define X_PTR LT(L_PTR, KC_X)
#define DOT_PTR LT(L_PTR, SE_DOT)

// Common Cut, Copy and Paste
#define C_CUT S(KC_DEL)
#define C_COPY C(KC_INS)
#define C_PASTE S(KC_INS)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ESC_SPE,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, SE_ODIA, SE_ARNG,
       SE_DQUO,    HR_A,    HR_R,    HR_S,    HR_T,    KC_G,       KC_M,    HR_N,    HR_E,    HR_I,    HR_O, SE_ADIA,
      MO(L_FN),    KC_Z,    X_PTR,   KC_C,    HR_D,    KC_V,       KC_K,    HR_H, SE_COMM, DOT_PTR, SE_MINS, MO(L_FN),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BSPC, SPC_SYM, ESC_VIM,     TAB_NV, ENT_SYM
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_NV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,    KC_0,    KC_9,    KC_8,    KC_7, SE_ASTR,    XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
       XXXXXXX,    KC_0,    KC_3,    KC_2,    KC_1, SE_MINS,    KC_HOME, HR_LEFT, HR_DOWN,   HR_UP, HR_RGHT,  KC_END,
        KC_APP,    KC_0,    KC_6,    KC_5,    KC_4, SE_PLUS,    XXXXXXX, KC_ALGR, _______, _______, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC, _______,     KC_TAB,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_VIM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,    KC_0,    KC_9,    KC_8,    KC_7, XXXXXXX,    KC_PGUP,    KC_G, C(KC_D), C(KC_U), S(KC_G), XXXXXXX,
       XXXXXXX,    KC_0,    KC_3,    KC_2,    KC_1, XXXXXXX,    M_CFLEX,    KC_H,    KC_J,    KC_K,    KC_L,  SE_DLR,
       XXXXXXX,    KC_0,    KC_6,    KC_5,    KC_4, XXXXXXX,    KC_PGDN,    KC_B, XXXXXXX,    KC_E,    KC_W, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC,  KC_ESC,    _______,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, SE_HASH, SE_AMPR, SE_PERC, SE_QUOT, XXXXXXX,    XXXXXXX, SE_ASTR, SE_LPRN, SE_RPRN, SE_SCLN, XXXXXXX,
       M_CFLEX, M_TILDE, SE_SLSH, SE_BSLS, SE_DQUO,  SE_DLR,    M_GRAVE, SE_MINS, SE_LCBR, SE_RCBR, SE_COLN, XXXXXXX,
         SE_AT, SE_PIPE, SE_LABK, SE_RABK,  SE_EQL, XXXXXXX,    XXXXXXX, SE_PLUS, SE_LBRC, SE_RBRC, SE_QUES, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC,  KC_ESC,     KC_TAB, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_SPE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, SE_ACUT, SE_DIAE, SE_TILD,  SE_GRV, SE_CIRC,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, SE_SECT, SE_EURO,  SE_PND, SE_CURR, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, SE_HALF, SE_MICR, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC,  KC_ESC,     KC_TAB,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_FN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, QK_BOOT,    QK_BOOT,   C_CUT,  C_COPY, C_PASTE, XXXXXXX, KC_SCRL,
       XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_PAUS,
       _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  EE_CLR,     EE_CLR, KC_ALGR, KC_PSCR,  KC_INS, XXXXXXX, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,  KC_SPC,  KC_ESC,     KC_TAB,  KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_PTR] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, C_PASTE,  C_COPY,   C_CUT, QK_BOOT,    QK_BOOT,   C_CUT,  C_COPY, C_PASTE, XXXXXXX, XXXXXXX,
       QK_LLCK, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
       XXXXXXX, DRGSCRL, _______, SNIPING, XXXXXXX,  EE_CLR,     EE_CLR, XXXXXXX, SNIPING, _______, DRGSCRL, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, KC_BTN1, KC_BTN2,    KC_BTN2, KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  )
};
// clang-format on

enum combo_events {
  BOOT_CMB1,
  BOOT_CMB2,
  EECLR_CMB1,
  EECLR_CMB2,
  TOBASE_CMB1,
  TOBASE_CMB2,
  CAPS_CMB,
  SHRUG_CMB1,
  SHRUG_CMB2,
  SHRUG_CMB3,
};

const uint16_t PROGMEM caps_cmb[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM lang_cmb[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM shrug_cmb1[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM shrug_cmb2[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM shrug_cmb3[] = {KC_W, KC_Y, COMBO_END};

combo_t key_combos[] = {
  [CAPS_CMB] = COMBO_ACTION(caps_cmb),
  [SHRUG_CMB1] = COMBO_ACTION(shrug_cmb1),
  [SHRUG_CMB2] = COMBO_ACTION(shrug_cmb2),
  [SHRUG_CMB3] = COMBO_ACTION(shrug_cmb3),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_CMB:
      if (pressed) {
        tap_code16(KC_CAPS);
      }
      break;
    case SHRUG_CMB1:
      if (pressed) {
        tap_code16(UC(0x30C4));
      }
    case SHRUG_CMB2:
      if (pressed) {
        send_string("¯ \\ _ ( ツ ) _ / ¯");
      }
    case SHRUG_CMB3:
      if (pressed) {
        send_unicode_string("¯\\_(ツ)_/¯");
      }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
 
