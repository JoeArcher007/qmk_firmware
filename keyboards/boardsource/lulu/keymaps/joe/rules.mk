# keyboards/boardsource/lulu/keymaps/joe/rules.mk

# VIA v3 support (usevia.app)
VIA_ENABLE = yes

# RGB is non-functional on this unit — disable to save flash space
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

# Encoder map support (used in keymap.c)
ENCODER_MAP_ENABLE = yes

# OLED displays
OLED_ENABLE = yes
SRC += oled.c

# WPM counter (used in oled.c)
WPM_ENABLE = yes
