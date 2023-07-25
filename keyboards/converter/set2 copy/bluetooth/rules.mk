MCU = atmega32u4
BOOTLOADER = caterina

F_CPU = 8000000
BLUETOOTH_ENABLE = yes
BLUETOOTH_DRIVER = BluefruitLE # or RN42

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes
PS2_USE_INT = yes
HARDWARE_SERIAL = yes
SRC = matrix.c led.c
SRC += protocol/serial_uart.c
SERIAL_MOUSE_MICROSOFT_ENABLE ?= no
SERIAL_MOUSE_MOUSESYSTEMS_ENABLE ?= yes

DEFAULT_FOLDER = converter/set2/bluetooth


ifeq ($(strip $(SERIAL_MOUSE_MICROSOFT_ENABLE)), yes)
    SRC += serial_mouse_microsoft.c
    OPT_DEFS += -DSERIAL_MOUSE_ENABLE -DSERIAL_MOUSE_MICROSOFT \
                -DMOUSE_ENABLE
endif

ifeq ($(strip $(SERIAL_MOUSE_MOUSESYSTEMS_ENABLE)), yes)
    SRC += serial_mouse_mousesystems.c
    OPT_DEFS += -DSERIAL_MOUSE_ENABLE -DSERIAL_MOUSE_MOUSESYSTEMS \
                -DMOUSE_ENABLE
endif
