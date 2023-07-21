# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina
F_CPU = 8000000

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes	    # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = yes      # Enable Bluetooth
BLUETOOTH_DRIVER = BluefruitLE # or RN42
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes
PS2_USE_INT = yes
HARDWARE_SERIAL = no
SRC = matrix.c


