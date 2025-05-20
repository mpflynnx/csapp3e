# Define the target executable
TARGET = main

# Define the source file
SRC = main.c

# Define the C compiler
CC = gcc

# Define compiler flags
# -std=c99: Compile according to the C99 standard
# -g: Include debugging information
CFLAGS = -std=c99 -g

# Default target: build the executable
all: $(TARGET)

# Rule to build the executable from the source file
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -lm

# Clean up build artifacts
clean:
	rm -f $(TARGET)
