TARGET = game

SRCS = main.cpp Food.cpp Snake.cpp Game.cpp

CXX = g++

CXXFLAGS = -lraylib -lpthread -lm -ldl -lrt

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET) $(CXXFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean