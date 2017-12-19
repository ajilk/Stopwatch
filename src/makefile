TARGET = a.out #Stopwatch
CXXFLAGS = -Wall -std=C++11 -lncurses
CC = g++

OBJFILES = main.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp

.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
