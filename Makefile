# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -fdiagnostics-color=always -g -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++17

# Libraries to link
LDFLAGS := -lgtest -lgtest_main -pthread

# Source files
SRCS := $(wildcard *.cpp)

# Header files
HDRS := $(wildcard *.h)

# Get the current folder name
FOLDERNAME := $(notdir $(CURDIR))

# Output executable
TARGET := $(FOLDERNAME)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET) run clean

# Compile source files into object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files into the executable
$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Run the executable
run:
	@chmod +x ./$(TARGET)
	@./$(TARGET)

# Clean up the generated files
clean:
	@rm -f $(TARGET) $(OBJS)

.PHONY: all clean
