# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

NKRO_ENABLE = yes           # USB Nkey Rollover
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes	    # Console for debug
DYNAMIC_MACRO_ENABLE = yes
LTO_ENABLE = yes

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

WAIT_FOR_USB = yes
CUSTOM_MATRIX = yes
PS2_USE_INT = yes
HARDWARE_SERIAL = no
SRC = matrix.c led.c
