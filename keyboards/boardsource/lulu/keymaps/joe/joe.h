// joe.h — shared definitions for Joe's Lulu keymap
// Include this in oled.c and any other split-out files

#pragma once

#include QMK_KEYBOARD_H

// Layer enum — must match keymap.c exactly
enum layers {
    _BASE,
    _FN,
    _SYM,
    _GAME
};
