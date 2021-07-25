/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

#pragma once
#include QMK_KEYBOARD_H

enum layout_names {
    MACOS = 0,  // Base Layout for MacOS: The main keyboard layout that has all the characters
    WINDOWS,    // Base Layout for Windows
    FUNCTIONS,  // Function Layout: The function key activated layout with default functions and
                // some added ones
    GIT,        // GIT Layout: GIT shortcuts and macros
    SECRETS,    // Layer with secrets
};

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE,  // Hold to copy, tap to paste
    KC_MAC,
    KC_WIN,

    // Secrets
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,

    // Unicodes
    UC_FLIP,
    UC_SHRG,
    UC_DISA,
};

enum git_macros {
    // The start of this enum should always be equal to end of custom_keycodes + 1
    G_INIT = UC_DISA + 1,     // git init
    G_CLONE,                  // git clone
    G_CONF,                   // git config --global
    G_ADD,                    // git add
    G_DIFF,                   // git diff
    G_RESET,                  // git reset
    G_REBAS,                  // git rebase
    G_BRANH,                  // git branch
    G_CHECK,                  // git checkout
    G_MERGE,                  // git merge
    G_REMTE,                  // git remote add
    G_FETCH,                  // git fetch
    G_PULL,                   // git pull
    G_PUSH,                   // git push
    G_COMM,                   // git commit
    G_STAT,                   // git status
    G_LOG,                    // git log
    NEW_SAFE_RANGE,
};

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define OS_GIT OSL(GIT)
#define TT_FN TT(FUNCTIONS)

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

// One Shot Keys
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)