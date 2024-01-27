# TODO: Take a look in the file
CC = g++
CFLAGS = -g -Wall -Weffc++ -std=c++11
INC = -Iinclude

# List of source files
SOURCES = src/main.cpp src/WareHouse.cpp

# List of object files
OBJECTS = obj/main.o obj/WareHouse.o

# Executable name
EXECUTABLE = bin/warehouse

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^

obj/main.o: src/main.cpp
    $(CC) $(CFLAGS) $(INC) -c -o $@ $<

obj/WareHouse.o: src/WareHouse.cpp
    $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)