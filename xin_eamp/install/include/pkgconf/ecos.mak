ECOS_GLOBAL_CFLAGS = -Wall -Wpointer-arith -Wstrict-prototypes -Wundef -Woverloaded-virtual -Wno-write-strings -mthumb -g -O2 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
ECOS_GLOBAL_LDFLAGS = -mthumb -Wl,--gc-sections -Wl,-static -Wl,-n -g -nostdlib -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
ECOS_COMMAND_PREFIX = arm-eabi-
