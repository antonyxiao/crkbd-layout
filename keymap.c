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

V1.1

Chage log:
    - removed text dispay
*/

#include QMK_KEYBOARD_H
#include <string.h>
#include <math.h>

// variables of custom keycodes
enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    P_EMAIL,
    DBL_EQL,
    AUTO_PRN,
    AUTO_DQT,
    AUTO_CBRK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,                      KC_SCLN,    KC_Q,    KC_U,    KC_D,    KC_J,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_S,    KC_H,    KC_N,    KC_T, KC_COMM,                       KC_DOT,    KC_A,    KC_E,    KC_O,    KC_I, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_F,    KC_M,    KC_C,    KC_V, KC_SLSH,                         KC_G,    KC_P,    KC_X,    KC_K,    KC_Y,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LGUI,MO(2), KC_SPC,   RSFT_T(KC_ENT),MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(2),  KC_SPC, RSFT_T(KC_ENT),MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, C(KC_A), C(KC_S), C(KC_C), C(KC_V), KC_PSCREEN,                   XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,G(KC_LEFT),C(KC_Y),C(KC_Z),G(KC_RIGHT),C(KC_X),                    XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  KC_SPC,  RSFT_T(KC_ENT),MO(4),KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,  KC_EQL, KC_LPRN, KC_LCBR, KC_LABK,                      KC_RABK, KC_RCBR, KC_RPRN, DBL_EQL,   TG(5),  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_TILD, XXXXXXX, KC_MINS, KC_BSLS, KC_LBRC,                      KC_RBRC, KC_UNDS, KC_PLUS, XXXXXXX, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(4),LSFT_T(KC_SPC),KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX,AUTO_PRN,AUTO_CBRK,P_EMAIL,                        EMAIL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,AUTO_DQT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   DF(1),                        DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_SPC, _______,   TG(5)
                                      //`--------------------------'  `--------------------------'
  )
};

 #ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_master) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }// else
}// oled_init_user

#define L_BASE 0
/* #define L_HALMAK 2 */
#define L_LOWER 4
#define L_RAISE 8
#define L_ADJUST 16
/* #define L_SIX 18 */

void oled_render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("DFLT"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("LOWR"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("RISE"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:// 20
        case L_ADJUST|L_RAISE:// 22
        case L_ADJUST|L_LOWER|L_RAISE:// 24 28
            oled_write_ln_P(PSTR("MACR"), false);
            break;
        /* case L_HALMAK: */
        /*     oled_write_P(PSTR("HALMK"), false); */
        /*     break; */
        /* case L_SIX: */
        /*     oled_write_ln_P(PSTR("SIX"), false); */
        /*     break; */
        default:
            oled_write_P(PSTR("OTHER"), false);
            break;
    }// switch
    oled_write_ln_P(PSTR(""), false);
}// oled_render_layer_state

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

// master side keylog
void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }

    if (keycode < 60) {
            name = code_to_name[keycode];
    }// if

    if ((keycode >= 40 && keycode <= 43) || (keycode >= 224 && keycode <= 230)) {
        // update keylog
        char* modStr = "";
        switch (keycode) {
        case 40:
            modStr = "ENTER";
            break;
        case 41:
            modStr = "ESC  ";
            break;
        case 42:
            modStr = "BSPC ";
            break;
        case 43:
            modStr = "TAB  ";
            break;
        case 224:
            modStr = "CTRL ";
            break;
        case 225:
            modStr = "SHIFT";
            break;
        case 227:
            modStr = "SUPER";
            break;
        case 230:
            modStr = "ALT  ";
            break;
        default:
            break;
        }// switch

        if ((floor(log10(abs(keycode))) + 1) < 4) {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\nk%2d\n\n%s",
                 record->event.key.row, record->event.key.col, keycode, modStr);
        } else if ((floor(log10(abs(keycode))) + 1) < 5) {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\nk%2d\n%s",
                 record->event.key.row, record->event.key.col, keycode, modStr);
        } else {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\n%2d\n%s",
                 record->event.key.row, record->event.key.col, keycode, modStr);
        }// else
    } else {
        if ((floor(log10(abs(keycode))) + 1) < 4) {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\nk%2d\n\n%c    ",
                 record->event.key.row, record->event.key.col, keycode, name);
        } else if ((floor(log10(abs(keycode))) + 1) < 5) {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\nk%2d\n%c    ",
                 record->event.key.row, record->event.key.col, keycode, name);
        } else {
            snprintf(keylog_str, sizeof(keylog_str), "%dx%d\n%2d\n%c    ",
                 record->event.key.row, record->event.key.col, keycode, name);
        } // else
    }// else
}// set_keylog

// master side
void oled_render_keylog(void) {
        oled_write(keylog_str, false);
}// oled_render_keylog

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
    }// else
}// render_bootmagic_status

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0
    };
    oled_write_P(crkbd_logo, false);
}// oled_render_logo

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }// else
}// oled_task_user

/* custom keycodes */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
        
        // custom keycodes
        switch (keycode) {
        case EMAIL:
            SEND_STRING("antonyxiao16@gmail.com");
            break;
        case P_EMAIL:
            SEND_STRING("debangsw@163.com");
            break;
        case DBL_EQL:
            SEND_STRING("==");
            break;
        case AUTO_PRN:
            SEND_STRING("()");
            tap_code(KC_LEFT);
            break;
        case AUTO_DQT:
            SEND_STRING("\"\"");
            tap_code(KC_LEFT);
            break;
        case AUTO_CBRK:
            SEND_STRING("{}");
            tap_code(KC_LEFT);
            break;
        default:
            break;
        }// switch
    }// if
    return true;
}// process_record_user


/* combo */
// enum combo_events {
//         TAB_CTL_ESC,
//         BSPC_QUOT_DEL,
//         IU_ING
// };
//
// const uint16_t PROGMEM exit_combo[] = {KC_TAB, KC_LCTL, COMBO_END};
// const uint16_t PROGMEM del_combo[] = {KC_BSPC, KC_QUOT, COMBO_END};
// const uint16_t PROGMEM ing_combo[] = {KC_I, KC_U, COMBO_END};
//
// combo_t key_combos[COMBO_COUNT] = {
//         [TAB_CTL_ESC] = COMBO_ACTION(exit_combo),
//         [BSPC_QUOT_DEL] = COMBO_ACTION(del_combo),
//         [IU_ING] = COMBO_ACTION(ing_combo),
// };
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//         switch(combo_index) {
//         case TAB_CTL_ESC:
//                 if (pressed) {
//                         tap_code16(KC_ESC);
//                 }
//                 break;
//         case BSPC_QUOT_DEL:
//                 if (pressed) {
//                         tap_code16(KC_DEL);
//                 }
//                 break;
//         case IU_ING:
//                 if (pressed) {
//                         SEND_STRING("ing");
//                 }
//                 break;
//         default:
//                 break;
//         }
// }
#endif // OLED_DRIVER_ENABLE
