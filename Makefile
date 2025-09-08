## Simple Makefile for the chess engine

# Compiler and flags
CC      ?= cc
CFLAGS  ?= -std=c11 -Wall -Wextra -O2 -Iinclude -I.
LDFLAGS ?=
LDLIBS  ?=

# Target binary name
TARGET  ?= chess-engine

# Sources and objects
SRCS := \
    main.c \
    src/fen.c \
    src/utils.c \
    src/types.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

# Pattern rule for building objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Convenience target: build with debug symbols
debug: CFLAGS := -std=c11 -Wall -Wextra -O0 -g -Iinclude
debug: clean $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
