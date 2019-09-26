TARGET = main
OBJECTS = main.o
FLAGS = -g

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $@ $^ $(FLAGS)

%.o: %.cpp
	g++ -c -Wall -o $@ $< $(FLAGS)

.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGET)
