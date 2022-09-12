#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# A make file to support a multitarget build system including the host and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#	   build - Builds and links all source files
#	   all - Same as build
#	   clean - Removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#	   ARCH - ARM Architecture (arm, thumb)
#	   SPECS - Specs file to gifve the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM), HOST)
	PLATFORM = HOST
else ifeq ($(PLATFORM), MSP432)
	PLATFORM = MSP432
endif	

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
else ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
endif	
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)
TARGET = c1m2
CPPFLAGs = nil

# Object files creation
OBJS = $(SOURCES:.c=.o)

# Dependency files creation
DEPS = $(SOURCES:.c=.d)

# PreProcessed files creation
PRPS = $(SOURCES:.c=.i)

# Assembly files creation
ASMB = $(SOURCES:.c=.asm)

%.o : %.c
		$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c 
		$(CC) $(INCLUDES) -E $< $(CFLAGS) -o $@

%.asm : %.c 
		$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

%.d : %.c 
		$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $(TARGET).o

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEP)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(TARGET).asm: $(OBJS) $(DEP)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
		rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PP) $(AS) $(DEP) $(OBJS)