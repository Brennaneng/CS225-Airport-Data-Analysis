CC = g++
CFLAGS = -Wall -g 

COVIDMap: main.o ReadFile.o MapOutput.o
	$(CC) $(CFLAGS) -o COVIDMap main.o ReadFile.o MapOutput.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -std=c++11 main.cpp

ReadFile.o: ReadFile.cpp ReadFile.h
	$(CC) $(CFLAGS) -std=c++11 ReadFile.cpp 

MapOutput.o: MapOutput.cpp MapOutput.h
	$(CC) $(CFLAGS) -std=c++11 MapOutput.cpp 

# Use the cs225 makefile template:
include cs225/make/cs225.mk
