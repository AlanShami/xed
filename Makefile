#/*
#Name: Alan Shami
#Course: CS530 - System Software
#Term: Spring 2024
#Assignment #1: xed program
#File Name: Makefile
#*/

CC=gcc
CFLAGS=-Wall -Wextra -std=c11

# Name of the executable
TARGET=xed

# Source files
SOURCES=main.c methods.c

OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
