# Makefile for compiling app_read.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source file
SRC = main.c

# Output binary
OUTPUT = bin/main

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC)

clean:
	rm -f $(OUTPUT)
