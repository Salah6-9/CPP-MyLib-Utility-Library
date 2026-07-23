# Makefile لبناء مكتبة MyLib تلقائياً
CXX = g++
CXXFLAGS = -I. -Wall -std=c++17
SRCS = MyLib.cpp $(wildcard modules/*.cpp) $(wildcard modules/*/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = libMyLib.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $^
	rm -f $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
