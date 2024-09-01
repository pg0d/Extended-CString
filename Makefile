# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -std=c99

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source and object files
SRCS = $(SRC_DIR)/string.c $(SRC_DIR)/alloc.c main.c
OBJS = $(OBJ_DIR)/string.o $(OBJ_DIR)/alloc.o $(OBJ_DIR)/main.o
TARGET = $(BIN_DIR)/main

# Test files
TEST_SRCS = test.c
TEST_OBJS = $(OBJ_DIR)/test.o
TEST_TARGET = $(BIN_DIR)/test

# Default target
all: $(TARGET)

# Create binary directory if not exists and link the object files
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c main.c -o $@

# Test target
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Compile test program
$(TEST_TARGET): $(TEST_OBJS) $(OBJ_DIR)/string.o $(OBJ_DIR)/alloc.o | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(OBJ_DIR)/string.o $(OBJ_DIR)/alloc.o

$(OBJ_DIR)/test.o: test.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c test.c -o $@

# Create necessary directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up object and binary files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean test