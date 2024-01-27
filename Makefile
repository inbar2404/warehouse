# Compiler
CC = g++

# Compiler flags
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

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) \
          $(wildcard $(SRC_DIR)/Customer/*.cpp) \
          $(wildcard $(SRC_DIR)/Volunteer/*.cpp) \
		  $(wildcard $(SRC_DIR)/Order/*.cpp) \ 
		  $(wildcard $(SRC_DIR)/Action/*.cpp)

# List of object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable name
EXECUTABLE = $(BIN_DIR)/warehouse

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
