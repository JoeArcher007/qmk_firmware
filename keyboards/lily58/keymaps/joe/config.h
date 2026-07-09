// Add these lines to keyboards/boardsource/lulu/config.h
// (or create keyboards/boardsource/lulu/keymaps/joe/config.h with just these)
//
// Fixes the keyboard not initializing properly at boot / OS startup.
// SPLIT_USB_DETECT tells QMK to actively probe which half has USB
// rather than assuming a fixed master side.

#pragma once

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT      4000   // ms to wait for USB enumeration
#define SPLIT_USB_TIMEOUT_POLL   10   // polling interval in ms

// This is set below for the use of VIA
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 4095
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

// Prevents the RP2040 from stalling if the USB host goes to sleep or drops data during BIOS
#define NO_USB_STARTUP_CHECK

// Gives the motherboard BIOS more time to establish a stable connection with the Blok
#define USB_SUSPEND_WAKEUP_DELAY 250
