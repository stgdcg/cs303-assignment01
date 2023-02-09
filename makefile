CC = g++
CFLAGS = -g -Wall

TARGET = main

all: main

main: main.o array_helpers.o array.o
	$(CC) $(CFLAGS) -o main main.o array_helpers.o array.o

main.o: main.cpp array_helpers.h array.h
	$(CC) $(CFLAGS) -c main.cpp

array_helpers.o: array_helpers.h array.h
	$(CC) $(CFLAGS) -c array_helpers.cpp

array.o: array.h
	$(CC) $(CFLAGS) -c array.cpp

clean:
	rm main.o array_helpers.o array.o
