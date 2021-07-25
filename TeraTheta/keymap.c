/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include "TeraTheta.h"

// Tap Dance declarations
enum {
    TD_CAPS = 0,   // Single tap: (), Double tap: {}, Triple tap: []
    TD_CMD,        // Single tap: Copy, Double tap: Paste
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [MACOS] = LAYOUT(
        KC_ESC,      KC_F1,       KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,      KC_1,        KC_2,       KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,      KC_Q,        KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        TD(TD_CAPS), KC_A,        KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,                  KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,     KC_LOPT,     TD(TD_CMD),                            KC_SPC,                             TD(TD_CMD), KC_ROPT, TT_FN,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WINDOWS] = LAYOUT(
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,          _______,
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,          _______,
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,          _______,
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          _______,
        _______,                 _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,
        _______,     TD(TD_CMD), KC_LALT,                                _______,                            KC_RALT, TD(TD_CMD), _______, _______, _______, _______
    ),

    [FUNCTIONS] = LAYOUT(
        _______,     KC_SEC1,    KC_SEC2,     KC_SEC3, KC_SEC4, KC_SEC5, _______, KC_CAPW, KC_CPYW, KC_CAPP, KC_CPYP,     KC_MPRV, KC_MNXT, KC_MPLY,              _______,
        _______,     KC_MAC,     KC_WIN,      _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,       KC_PMNS, KC_PPLS, _______,              _______,
        UC_FLIP,     _______,    _______,     RGB_MOD, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______,     _______, _______,   RESET,              _______,
        UC_SHRG,     _______,    RGB_SPI,     RGB_SAI, _______, OS_GIT,  RGB_HUI, KC_P1,   KC_P2,   KC_P3,   _______,     _______,          _______,              KC_BTN1,
        UC_DISA,                 _______,     _______, _______, _______, RGB_VAI, _______, KC_P0,   KC_PDOT, _______,     _______,          _______,     KC_MS_U, KC_BTN2,
        _______,     _______,    _______,                                RGB_TOG,                            _______,     _______, _______, KC_MS_L,     KC_MS_D, KC_MS_R
    ),

    [GIT] = LAYOUT(
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,              _______,
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,              _______,
        _______,     _______,    _______,     _______, _______, _______, _______, _______, _______, _______,  G_PULL,      G_PUSH, _______, _______,              _______,
        _______,       G_ADD,     G_STAT,      G_DIFF, _______, _______, _______, _______, _______,   G_LOG, _______,     _______,          _______,              _______,
        _______,                 _______,     _______,  G_COMM, G_CHECK, G_BRANH, _______, _______, _______, _______,     _______,          _______,    _______,  _______,
        _______,     _______,    _______,                                _______,                            _______,     _______, _______, _______,    _______,  _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}

// void rgb_matrix_indicators_user(void) {
//    led_t led_state = host_keyboard_led_state();
//    if (led_state.caps_lock) {
//        rgb_matrix_set_color(3, 0xFF, 0xFF, 0xFF);
//    }
// }

void rgb_matrix_indicators_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        for (uint8_t i = 82; i < 98; i++) {
            rgb_matrix_set_color(i, 0xFF, 0x00, 0x00);
        }
    }
}

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;
 
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->pressed) return TRIPLE_HOLD;
    else return TRIPLE_TAP;
  }
  else return 6; //magic number. 
}

static tap tap_state = {
  .is_press_action = true,
  .state = 0
};

void caps_finished (qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP: register_code(KC_LSFT); tap_code(KC_9); tap_code(KC_0); break;    // ()
        case DOUBLE_TAP: register_code(KC_LSFT); tap_code(KC_LBRC); tap_code(KC_RBRC); break; // {}
        case TRIPLE_TAP: tap_code(KC_LBRC); tap_code(KC_RBRC); break; // []
    }
}

void caps_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case SINGLE_TAP: 
        case DOUBLE_TAP: unregister_code(KC_LSFT); tap_code(KC_LEFT); break;
        case TRIPLE_TAP: tap_code(KC_LEFT); break;
    }
  tap_state.state = 0;
}

void cmd_finished (qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP: // Copy
            if (layer_state_is(MACOS)) {
                register_code(KC_LCMD);
                register_code(KC_C);
                break;
            } else {
                register_code(KC_LCTL);
                register_code(KC_C);
                break;
            }
        case SINGLE_HOLD: // Cmd
            register_code(KC_LCMD); 
            break;
        case DOUBLE_TAP: // Paste
            if (layer_state_is(MACOS)) {
                register_code(KC_LCMD); 
                register_code(KC_V);
                break;
            } else {
                register_code(KC_LCTL);
                register_code(KC_V);
                break;
            }
    }
}
void cmd_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case SINGLE_TAP: // Copy
            if (layer_state_is(MACOS)) {
                unregister_code(KC_C);
                unregister_code(KC_LCMD);
                break;
            } else {
                unregister_code(KC_C);
                unregister_code(KC_LCTL);
                break;
            }
        case SINGLE_HOLD: // Cmd
            unregister_code(KC_LCMD); 
            break;
        case DOUBLE_TAP: // Paste
            if (layer_state_is(MACOS)) {
                unregister_code(KC_V); 
                unregister_code(KC_LCMD);
                break;
            } else {
                unregister_code(KC_V);
                unregister_code(KC_LCTL);
                break;
            }
    }
  tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset),
    [TD_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cmd_finished, cmd_reset),
};