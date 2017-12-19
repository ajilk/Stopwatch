TARGET = a.out #Stopwatch
CXXFLAGS = -std=C++11
CC = g++

OBJFILES = main.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp

.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
