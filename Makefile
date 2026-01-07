CXX = g++
CXXFLAGS = -Wall -g

TARGET = main

SRCS = main.cpp edge.cpp filters.cpp framereader.cpp writer.cpp color_converter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

