CC = g++
CFLAGS = -g -Wall -Weffc++ -std=c++11
INC = -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Create the obj and bin directories if they don't exist
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Executable name
EXECUTABLE = $(BIN_DIR)/warehouse

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJ_DIR)/WareHouse.o: $(SRC_DIR)/WareHouse.cpp include/WareHouse.h
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
