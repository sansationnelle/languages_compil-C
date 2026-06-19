TARGET = principal

CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++17

SOURCES = main.cpp principal.cpp contact.cpp savefile.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)