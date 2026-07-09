// Copyright 2022 Cole Smith <cole@boardsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Joe's Lily58 keymap (Boardsource Lulu DIY, CONVERT_TO=blok)
// Build: qmk compile -kb lily58 -km joe -e CONVERT_TO=blok

#include QMK_KEYBOARD_H
#include "joe.h"

// ──────────────────────────────────────────────
// Custom keycodes
// ──────────────────────────────────────────────
enum custom_keycodes {
    WS_NEXT = SAFE_RANGE,  // Ctrl+GUI+Right  (next workspace)
    WS_PREV,               // Ctrl+GUI+Left   (prev workspace)
    CAD,                   // Ctrl+Alt+Del    (Windows login macro)
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
        case CAD:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
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

/* BASE (Layer 0) */
[_BASE] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, FN,      KC_LCTL, KC_ENT,  KC_SPC,  KC_BSPC,  SYM,    KC_RALT
),

/* FUN-NUM (Layer 1) */
[_FN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, TO(_GAME),
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, TO(_BASE),
    KC_CAPS, KC_PSCR, _______,    CAD, _______, _______,                    XXXXXXX, KC_1,    KC_2,    KC_3,    _______, _______,
    _______, WS_PREV, WS_NEXT, _______, _______, _______, _______, _______, XXXXXXX, KC_0,    _______, _______, _______, _______,
                               _______, _______, _______, _______, _______,  KC_DEL, _______, _______
),

/* SYM (Layer 2) */
[_SYM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_PGUP,  KC_INS, KC_MPRV, KC_MNXT, KC_MPLY,  KC_EQL,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, KC_HOME, KC_END,
                               _______, _______, _______, _______, _______,  KC_DEL, _______,  _______
),

/* GAME (Layer 3) */
[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG(_GAME),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LALT, FN,      KC_LCTL, KC_SPC,  KC_ENT,  KC_BSPC, SYM,     KC_RALT
),

};

// ──────────────────────────────────────────────
// Encoder mappings
// Left:  Base=Vol, others=transparent
// Right: Base=PgUp/Dn, others=transparent
// ──────────────────────────────────────────────
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_FN]   = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
    [_SYM]  = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
    [_GAME] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) },
};
#endif
