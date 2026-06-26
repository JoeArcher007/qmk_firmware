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
