# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here:
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
UNICODE_ENABLE = yes         # Unicode
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes

SRC = matrix.c
