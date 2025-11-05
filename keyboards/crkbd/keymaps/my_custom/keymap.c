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

// Tap Dance declarations
enum {
    TD_U_PAREN,   // KC_U двойное нажатие -> LSFT(KC_0) = (
    TD_I_F20,     // KC_I двойное нажатие -> KC_F20
    TD_O_F22,     // KC_O двойное нажатие -> KC_F22
    TD_P_F24,     // KC_P двойное нажатие -> KC_F24
    TD_R_PAREN,   // KC_R двойное нажатие -> LSFT(KC_9) = )
    TD_E_F19,     // KC_E двойное нажатие -> KC_F19
    TD_W_F21,     // KC_W двойное нажатие -> KC_F21
    TD_Q_F23,     // KC_Q двойное нажатие -> KC_F23
    TD_G_P1,      // KC_G двойное нажатие -> KC_P1
    TD_B_P2,      // KC_B двойное нажатие -> KC_P2
    TD_MO1_P1,    // MO(1) одинарное -> активирует слой 1, двойное -> KC_P1
    TD_MO2_P2,    // MO(2) одинарное -> активирует слой 2, двойное -> KC_P2
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_U_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_U, LSFT(KC_0)),  // одинарное: U, двойное: Shift+0 = (
    [TD_I_F20] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_F20),
    [TD_O_F22] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_F22),
    [TD_P_F24] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_F24),
    [TD_R_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_R, LSFT(KC_9)),  // одинарное: R, двойное: Shift+9 = )
    [TD_E_F19] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_F19),
    [TD_W_F21] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_F21),
    [TD_Q_F23] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_F23),
    [TD_G_P1] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_P1),
    [TD_B_P2] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_P2),
    [TD_MO1_P1] = ACTION_TAP_DANCE_DOUBLE(MO(1), KC_P1),  // одинарное: MO(1), двойное: KC_P1
    [TD_MO2_P2] = ACTION_TAP_DANCE_DOUBLE(MO(2), KC_P2),  // одинарное: MO(2), двойное: KC_P2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  LGUI_T(KC_ESC), KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LALT_T(KC_TAB), KC_A, KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_QUOT,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(1),  KC_ENT,     KC_SPC,   MO(2), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,------------------------------------------------ё-------.                 ,--_------------------------------------)------------/-------.
    KC_DEL,    KC_F1,  KC_F2,   KC_F3,  KC_F4,   KC_GRV,                       KC_MINUS,   KC_7,   KC_8,    KC_9,   KC_EQUAL, KC_KP_SLASH,
  //|--------+--------+--------+--------+--------+--------|                    |----!---+--------+--------+--------+----]---+----|---|
    KC_LALT,  KC_F5,    KC_F6,   KC_F7,   KC_F8, LSFT(KC_MINUS),                    KC_F18, KC_4,  KC_5,     KC_6,    KC_0, KC_P5,
  //|--------+-------+--------+--------+--------+--------|                    |---:----+--------+--------+--------+-----}---+---0----|
    KC_LSFT,  KC_F9,  KC_F10,   KC_F11, KC_F12,  LALT(KC_LSFT),                         LSFT(KC_1),    KC_1,  KC_2,     KC_3,   KC_PLUS,   KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, _______,  KC_ENT,     KC_SPC, MO(3), KC_BSPC  
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,--\-----------(--------------@---------;--------*-------+=----.            ,-<------>--------------------------------------------.
     KC_BACKSLASH, KC_EQUAL, KC_F13, KC_F16, LSFT(KC_8), KC_P3,          KC_HOME,   KC_END,  KC_UP,   XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+----[---+---№----+----#---+---"----+---'----|                   |--------+--------+--------+--------+--------+--------|
      KC_LALT, KC_P4,   KC_F15,  KC_P6, KC_F14,  KC_P1,                    KC_PAGE_UP,  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_INS,
  //|--------+---{-----+----%---+--- ~ -+-----$--+----`--|                     |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_P7, LSFT(KC_5), KC_P8, KC_F17,  KC_P2,                   KC_PAGE_DOWN, KC_P1, KC_P2, KC_P3, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(3),  KC_ENT,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_F23, KC_F21, KC_F19, LSFT(KC_9), XXXXXXX,                      XXXXXXX, LSFT(KC_0), KC_F20, KC_F22, KC_F24, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, KC_NUM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
