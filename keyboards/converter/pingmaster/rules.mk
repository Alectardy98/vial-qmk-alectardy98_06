# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no  # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
CONSOLE_ENABLE = yes   # Console for debug
COMMAND_ENABLE = no   # Commands for debug and configuration
CUSTOM_MATRIX = yes # Custom matrix file for the HHKB
NKRO_ENABLE = yes            # Enable N-Key Rollover

LTO_ENABLE = yes  #make the file smaller
DYNAMIC_MACRO_ENABLE = yes
UNICODE_ENABLE = yes 		# Unicode
QMK_SETTINGS = no


# project specific files
SRC += matrix.c
#SRC += ibm4707.c
OPT_DEFS += -DIBM4704_ALPS

