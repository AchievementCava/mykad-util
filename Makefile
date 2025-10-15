# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20

# Files
SRC = ic_util.cpp ic.cpp 
OBJ = $(SRC:.cpp=.o)
TARGET = mykad-parser

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)