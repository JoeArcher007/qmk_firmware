// oled.c — Joe's Lulu OLED logic
// Left side (master): layer name, caps lock state, WPM
// Right side (slave):  logo — paste your QLE byte array in render_logo()

#include QMK_KEYBOARD_H
#include "joe.h"  // shared header, see joe.h

// ──────────────────────────────────────────────
// Right side: Logo
// Replace the byte array below with your QLE output
// ──────────────────────────────────────────────
static void render_logo(void) {
    // QLE output goes here — replace this placeholder
    // static const char PROGMEM my_logo[] = { ... };
    // oled_write_raw_P(my_logo, sizeof(my_logo));

    // Placeholder until you have your QLE graphic
    oled_write_P(PSTR("LILY58"), false);
}

// ──────────────────────────────────────────────
// Left side: Layer + Caps + WPM
// ──────────────────────────────────────────────
static void render_layer_status(void) {
    // Line 1: static label
    oled_write_P(PSTR("LAYER\n"), false);

    // Line 2: active layer name
    switch (get_highest_layer(layer_state)) {
        case _BASE: oled_write_P(PSTR("Base \n"), false); break;
        case _FN:   oled_write_P(PSTR("Fn   \n"), false); break;
        case _SYM:  oled_write_P(PSTR("Sym  \n"), false); break;
        case _GAME: oled_write_P(PSTR("Game \n"), false); break;
        default:    oled_write_P(PSTR("???? \n"), false); break;
    }

    // Spacer
    oled_write_P(PSTR("\n"), false);

    // Line 3: Caps Lock
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("CAPS\n"),                              false);
    oled_write_P(led_state.caps_lock ? PSTR("ON   \n")
                                     : PSTR("off  \n"),      false);

    // Spacer
    oled_write_P(PSTR("\n"), false);

    // Line 4: WPM
    oled_write_P(PSTR("WPM\n"), false);

    // get_current_wpm() returns uint8_t (0–255)
    // We format it manually since oled_write has no printf
    uint8_t wpm = get_current_wpm();
    char wpm_str[6];
    wpm_str[0] = (wpm / 100)       + '0';
    wpm_str[1] = (wpm / 10  % 10)  + '0';
    wpm_str[2] = (wpm       % 10)  + '0';
    wpm_str[3] = '\n';
    wpm_str[4] = '\0';
    oled_write(wpm_str, false);
}

// ──────────────────────────────────────────────
// OLED rotation
// Both OLEDs on the Lulu are mounted vertically,
// so we rotate 270° to get a portrait canvas
// ──────────────────────────────────────────────
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// ──────────────────────────────────────────────
// Main OLED task
// ──────────────────────────────────────────────
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_status();
    } else {
        render_logo();
    }
    return false;
}
