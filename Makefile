# Makefile for the Palindrome and Prime Number Checker

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99
LDFLAGS = -lm
TARGET  = number_checker
SRC     = number_checker.c

# Default target: build the program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Remove the compiled binary
clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean
