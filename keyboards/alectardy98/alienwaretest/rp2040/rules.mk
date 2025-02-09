MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover

LTO_ENABLE = yes  #make the file smaller
ENCODER_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
UNICODE_ENABLE = yes 		# Unicode
