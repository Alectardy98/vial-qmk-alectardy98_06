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

AUDIO_ENABLE = yes
LTO_ENABLE = yes  #make the file smaller
DYNAMIC_MACRO_ENABLE = yes
UNICODE_ENABLE = yes 		# Unicode
COMBO_ENABLE = no         #Required for stock beeper support
