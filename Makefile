CXX := g++
CXXFLAGS := -Wall -Wextra -O2 -std=c++17 -I.
AR := ar
ARFLAGS := rcs
TARGET := libMyLib.a

# Find all .cpp source files under the modules directory and the main MyLib.cpp
SRC := $(shell find modules -name "*.cpp") MyLib.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
