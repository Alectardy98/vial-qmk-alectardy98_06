# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover

AUDIO_ENABLE = no
LTO_ENABLE = no  #make the file smaller
DYNAMIC_MACRO_ENABLE = no
UNICODE_ENABLE = no 		# Unicode
COMBO_ENABLE = no         #Required for stock beeper support
