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

V2.1

Change log:
*/

#include QMK_KEYBOARD_H
#include <string.h>
#include <math.h> 

enum crkbd_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCT
};

enum custum_keycodes {
    VIM_WRAP_PRN = SAFE_RANGE,
    VIM_W,
    VIM_WQ,
    AUTO_PRN
    /* TMUX_L, */
    /* TMUX_R */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(_LOWER),  KC_SPC, RSFT_T(KC_ENT),MO(_RAISE), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, C(KC_A), C(KC_S), C(KC_C), C(KC_V), KC_PSCREEN,                   TERM_ON, KC_HOME,   KC_UP,  KC_END, C(KC_B),  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,G(KC_LEFT),C(KC_Y),C(KC_Z),G(KC_RIGHT),C(KC_X),                   TERM_OFF, KC_LEFT, KC_DOWN,KC_RIGHT, DM_REC1, DM_RSTP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            RESET, _______,  KC_SPC,  RSFT_T(KC_ENT),MO(_FUNCT),KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,  KC_EQL, KC_LPRN, KC_LCBR, KC_LABK,                      KC_RABK, KC_RCBR, KC_RPRN, DM_PLY1, XXXXXXX,KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_TILD, XXXXXXX, KC_MINS, KC_BSLS, KC_LBRC,                      KC_RBRC, KC_UNDS, KC_PLUS, XXXXXXX, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(_FUNCT),LSFT_T(KC_SPC),KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNCT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX,   VIM_W,AUTO_PRN, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,VIM_WRAP_PRN,VIM_WQ, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {

            // wraps a word in () in vim
            case VIM_WRAP_PRN:
                tap_code(KC_ESC);
                SEND_STRING("bcw()");
                tap_code(KC_ESC);
                SEND_STRING("Pla");
                break;

            // :w and enter 
            case VIM_W:
                tap_code(KC_ESC);
                SEND_STRING(":w");
                tap_code(KC_ENT);
                break;

            // :wq and enter 
            case VIM_WQ:
                tap_code(KC_ESC);
                SEND_STRING(":wq");
                tap_code(KC_ENT);
                break;

            case AUTO_PRN: 
                SEND_STRING("()");
                tap_code(KC_LEFT);
                break;

            /* // ctr-b + left arrow */
            /* case TMUX_L: */
            /*     register_code(KC_LCTL); */
            /*     tap_code(KC_B); */
            /*     unregister_code(KC_LCTL); */
            /*     tap_code(KC_LEFT); */
            /*     break; */

            /* // ctr-b + right arrow */
            /* case TMUX_R: */
            /*     register_code(KC_LCTL); */
            /*     tap_code(KC_B); */
            /*     unregister_code(KC_LCTL); */
            /*     tap_code(KC_RIGHT); */
            /*     break; */
        }// switch
    }// if
    return true;
}


