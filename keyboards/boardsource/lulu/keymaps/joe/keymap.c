// Copyright 2022 Cole Smith <cole@boardsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Joe's Lulu keymap
// - Via JSON (usevia.app) is source of truth for layout
// - RGB removed (hardware not functional)
// - Macros baked in: WS_NEXT = Ctrl+GUI+Right, WS_PREV = Ctrl+GUI+Left
// - SPLIT_USB_DETECT enabled in config.h to fix startup lag

#include QMK_KEYBOARD_H
#include "joe.h"

// ──────────────────────────────────────────────
// Custom keycodes
// ──────────────────────────────────────────────
enum custom_keycodes {
    WS_NEXT = SAFE_RANGE,  // Ctrl+GUI+Right  (next workspace)
    WS_PREV,               // Ctrl+GUI+Left   (prev workspace)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WS_NEXT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                tap_code(KC_RGHT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            return false;
        case WS_PREV:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}

// ──────────────────────────────────────────────
// Layer shortcuts
// ──────────────────────────────────────────────
#define FN    MO(_FN)
#define SYM   MO(_SYM)

// ──────────────────────────────────────────────
// Keymaps
// ──────────────────────────────────────────────

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (Layer 0)
 * Source: Via JSON layer 0
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LGUI |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | FN   | LCtl | / Enter /       \Space \  |BkSpc | SYM  |  ]   |
 *                   `----------------------------'           '------''--------------------'
 */
[_BASE] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, FN,      KC_LCTL, KC_ENT,  KC_SPC,  KC_BSPC, SYM,     KC_RBRC
),

/* FN (Layer 1)
 * Source: Via JSON layer 1
 * F-keys, navigation, media controls, print screen, workspace macros
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  =   | PgUp |Play  | Next | Prev |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps | PrSc |      |      |      |      |-------.    ,-------|RCtrl | PgDn |Right |  Up  | Down | Left |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |WS_PRV|WS_NXT|      |      |      |-------|    |-------|  End | Home |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | FN   |      | /       /       \ Del  \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______,                   KC_EQL,  KC_PGUP, KC_MPLY, KC_MNXT, KC_MPRV, _______,
    KC_CAPS, KC_PSCR, _______, _______, _______, _______,                   KC_RCTL, KC_PGDN, KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,
    _______, WS_PREV, WS_NEXT, _______, _______, _______, _______, _______, KC_END,  KC_HOME, _______, _______, _______, _______,
                               _______, _______, _______, _______, KC_DEL,  _______, _______, _______
),

/* SYM (Layer 2)
 * Source: Via JSON layer 2
 * Symbols, number row duplicate, arrow keys, goes to GAME layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |      |      |      |      |      |                    |      |      |      |      |      |TO(3) |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TO(0) |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |Right |  Up  | Down | Left |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  +=  |  -   |  =   |   [  |   ]  | App  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      | SYM  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYM] = LAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, TO(_GAME),
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_BASE),
    _______, _______, _______, _______, _______, _______,                   _______, KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_EQL), KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_APP,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

/* GAME (Layer 3)
 * Source: Via JSON layer 3
 * Standard QWERTY for gaming — no mod interference
 * Exit: press the top-right key (TO _BASE) or right thumb inner key
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TO(0) |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|TO(0)  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Space  /       \Enter \  |TO(0) |      |TO(0) |
 *                   `----------------------------'           '------''--------------------'
 *
 * Exit gaming mode: top-right key, left encoder button [TO(0)], or right thumb TO(0)
 */
[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_BASE),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TO(_BASE), XXXXXXX, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               _______, _______, _______, KC_SPC,  KC_ENT,  TO(_BASE), _______, TO(_BASE)
),

};

// ──────────────────────────────────────────────
// Encoder mappings
// Source: Via JSON encoders
// Left encoder:  Base=Vol, FN=RGB(removed→Page), SYM=RGB(removed→Page), Game=pass
// Right encoder: Base=PgUp/Dn, FN=RGB(removed→Page), SYM=RGB(removed→Page), Game=pass
// ──────────────────────────────────────────────
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_FN]   = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
    [_SYM]  = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
    [_GAME] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
};
#endif
