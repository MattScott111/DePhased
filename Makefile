# De-Phased v1.2.0 DOD Build System
CXX = g++
CXXFLAGS = -std=c++20 -O3 -Wall -Wextra -march=native -I./include -I./chapters
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = source
CHAPTER_DIR = chapters
OBJ_DIR = obj
TARGET = DePhased_Test

# Create the OBJ_DIR if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Auto-detect source files (Notice main.cpp is now fetched from inside SRC_DIR)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(CHAPTER_DIR)/*.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

# Default rule
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compilation rules for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CHAPTER_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Compile and immediately play
run: all
	./$(TARGET)

.PHONY: all clean run
