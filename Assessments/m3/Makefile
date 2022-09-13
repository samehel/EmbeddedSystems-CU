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
LINKER_FILE = ./msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	SIZE = size
	NM = nm
else ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	NM = arm-none-eabi-nm
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(ARMFLAGS)
endif	
TARGET = c1m3
CPPFLAGs = -D$(PLATFORM) $(INCLUDES)

# Object files creation
OBJS = $(SOURCES:.c=.o)

# Dependency files creation
DEPS = $(SOURCES:.c=.d)

# PreProcessed files creation
PRPS = $(SOURCES:.c=.i)

# Assembly files creation
ASMB = $(SOURCES:.c=.asm)

%.o : %.c
		$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i : %.c 
		$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm : %.c 
		$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d : %.c 
		$(CC) -M $< $(CFLAGS) $(CPPFLAGS) -o

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
		$(SIZE) $@
		$(NM) $(@) > $(@).nm


.PHONY: clean
clean:
		rm -f $(TARGET).asm *.asm *.i *.o *.d $(TARGET).out $(TARGET).map $(PRPS) $(ASMB) $(DEPS) $(OBJS)