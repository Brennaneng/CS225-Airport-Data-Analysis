CC = g++
CFLAGS = -Wall -g

COVIDMap: main.o ReadFile.o MapOutput.o
	$(CC) $(CFLAGS) -o COVIDMap main.o ReadFile.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp



ReadFile.o: ReadFile.cpp
	$(CC) $(CFLAGS) -c ReadFile.cpp

MapOutput.o: MapOutput.cpp
	$(CC) $(CFLAGS) -c MapOutput.cpp

clean:
	rm *.o COVIDMap

# Use the cs225 makefile template:
include cs225/make/cs225.mk
