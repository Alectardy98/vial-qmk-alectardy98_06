# Teensy LC
MCU = MKL26Z64
BOOTLOADER = halfkay
USE_CHIBIOS_CONTRIB = yes

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

#SERIAL_MOUSE_MOUSESYSTEMS_ENABLE = yes
