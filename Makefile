# Compiler
CXX = g++
# Compiler flags: 
# -Wall = enable all warnings
# -Wextra = extra warnings
# -std=c++17 = use C++17 standard
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SRC = main.cpp char.cpp char_classes.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Name of the final executable
TARGET = game

# Default target
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Optional: Rebuild from scratch
rebuild: clean all
