# Teensy 2.0
MCU = atmega32u4
BOOTLOADER = halfkay

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes

SRC = matrix.c

DEFAULT_FOLDER = converter/vt50/vt50a