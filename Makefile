# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Source directory
SRC_DIR = src

# Object directory
OBJ_DIR = obj

# Binary directory
BIN_DIR = bin

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable name with .exe extension for Windows
ifeq ($(PLATFORM),)
    PLATFORM = windows
endif

ifeq ($(PLATFORM),windows)
    EXE_SUFFIX = .exe
    DEL_CMD = del /Q
else
    EXE_SUFFIX =
    DEL_CMD = rm -rf
endif
TARGET = $(BIN_DIR)/i4$(EXE_SUFFIX)

# Main source file
MAIN_FILE = main.cpp

# Default target
all: clean $(TARGET)

# Compile each source file to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files and main file to create the executable
$(TARGET): $(OBJ_FILES)
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(CFLAGS) $^ -o $@

# Clean up
clean:
	$(DEL_CMD) "$(OBJ_DIR)" "$(BIN_DIR)"
