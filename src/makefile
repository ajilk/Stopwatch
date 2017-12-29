TARGET = stopwatch
CXXFLAGS = -Wall -std=C++11 -Wc++11-extensions -lncurses
CC = g++

OBJFILES = main.o Screen.o Coordinate.o Digits.o Stats.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Coordinate.o: Coordinate.cpp Coordinate.h
	$(CC) -c Coordinate.cpp
Digits.o: Digits.cpp Digits.h
	$(CC) -c Digits.cpp
Stats.o: Stats.cpp Stats.h
	$(CC) -c Stats.cpp


.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
