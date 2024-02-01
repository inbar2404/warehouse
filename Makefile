CC = g++
CFLAGS = -g -Wall -Weffc++ -std=c++11

# Include directory
INC = -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Create the obj and bin directories if they don't exist
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) \
          $(wildcard $(SRC_DIR)/Customer/*.cpp) \
          $(wildcard $(SRC_DIR)/Volunteer/*.cpp) \
          $(wildcard $(SRC_DIR)/Action/*.cpp) \
          $(wildcard $(SRC_DIR)/Order/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable file
EXECUTABLE = $(BIN_DIR)/warehouse

# Targets
all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Create subdirectories for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(shell mkdir -p $(@D))
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)