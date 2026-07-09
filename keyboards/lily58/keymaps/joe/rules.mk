# keyboards/lily58/keymaps/joe/rules.mk

# Boardsource Lulu DIY uses the Blok controller
CONVERT_TO = blok

# VIA v3 support (usevia.app)
VIA_ENABLE = yes
EEPROM_ENABLE = yes
LTO_ENABLE = yes

# RGB is non-functional on this unit — disable to save flash space
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

# Encoder map support
ENCODER_MAP_ENABLE = yes

# Multimedia keys and such
EXTRAKEY_ENABLE = yes

# OLED displays
OLED_ENABLE = yes
SRC += oled.c

# WPM counter (used in oled.c)
WPM_ENABLE = yes
