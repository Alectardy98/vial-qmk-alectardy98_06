#
MCU = atmega32u4
BOOTLOADER = caterina
F_CPU = 8000000
BLUETOOTH_ENABLE = yes
BLUETOOTH_DRIVER = BluefruitLE # or RN42
CONSOLE_ENABLE = yes	    # Console for debug
DYNAMIC_MACRO_ENABLE = no
LTO_ENABLE = yes

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes
PS2_USE_INT = yes
HARDWARE_SERIAL = yes
SRC = matrix.c led.c
