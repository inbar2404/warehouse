# TODO: Check what written here
CXX = g++
CXXFLAGS = -g -Wall -Weffc++ -std=c++11
SRCDIR = ./src
BINDIR = ./bin
INCLUDEDIR = -I./include

SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRC_FILES))

EXECUTABLE = warehouse

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDEDIR) -c -o $@ $<

clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/$(EXECUTABLE)
