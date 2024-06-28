# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -fdiagnostics-color=always -g -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++17

# Libraries to link
LDFLAGS := -lgtest -lgtest_main -pthread

# Coverage flags
CCOV := -fprofile-arcs -ftest-coverage -O0

# Source files
SRCS := $(wildcard *.cpp)

# Header files
HDRS := $(wildcard *.h)

# Get the current folder name
FOLDERNAME := $(notdir $(CURDIR))

# Output executable
MAIN_TARGET := $(FOLDERNAME).main
TEST_TARGET := $(FOLDERNAME).test

# Object files
OBJS := $(SRCS:.cpp=.o)

# Filtered object files
MAIN_OBJS := $(filter-out $(FOLDERNAME).test.o, $(OBJS))
TEST_OBJS := $(filter-out $(FOLDERNAME).main.o, $(OBJS))

# Build directory
BUILD_DIR := build

# Ensure the build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Default target
all: build-main

# Build the project executable
build-main: $(BUILD_DIR) $(MAIN_TARGET) clean-objs

# Build the project testing file
build-test: $(BUILD_DIR) $(TEST_TARGET) clean-objs

# Compile source files into object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) $(CCOV) -c $< -o $@

# Link the object files into the executable
$(MAIN_TARGET): $(MAIN_OBJS)
	@$(CXX) $(CXXFLAGS) $(CCOV) $(MAIN_OBJS) $(LDFLAGS) -o $(BUILD_DIR)/$(MAIN_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	@$(CXX) $(CXXFLAGS) $(CCOV) $(TEST_OBJS) $(LDFLAGS) -o $(BUILD_DIR)/$(TEST_TARGET)

# Run the main executable
run-main:
	@chmod +x ./$(BUILD_DIR)/$(MAIN_TARGET)
	@./$(BUILD_DIR)/$(MAIN_TARGET)

# Run the test executable
run-test:
	@chmod +x ./$(BUILD_DIR)/$(TEST_TARGET)
	@./$(BUILD_DIR)/$(TEST_TARGET)

# Run memory leak check using test executable
run-memory-leak-check:
	@valgrind --leak-check=full ./$(BUILD_DIR)/$(TEST_TARGET)

# Clean up the generated executables
clean-build:
	@rm -rf $(BUILD_DIR)

# Clean up the generated object files
clean-objs:
	@rm -f $(OBJS)

test: build-test run-test clean-build

.PHONY: all build-main build-test run-main run-test run-memory-leak-check clean-build clean-objs test
