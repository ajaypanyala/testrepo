# Makefile for DynamicArray project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2
TARGET = dynamic_array
SRC = main.cpp
HEADER = dynamic_array.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Rebuild
rebuild: clean all

.PHONY: all run clean rebuild
