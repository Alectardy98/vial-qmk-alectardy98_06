MCU = MKL26Z64
USE_CHIBIOS_CONTRIB = yes

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

CUSTOM_MATRIX = yes

SRC = matrix.c