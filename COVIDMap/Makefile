CC = g++
CFLAGS = -Wall -g 

COVIDMap: main.o 
	$(CC) $(CFLAGS) -o COVIDMap main.o 

main.o: main.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c main.cpp

ReadFile.o: ReadFile.cpp
	$(CC) $(CFLAGS) -std=c++11 -c ReadFile.cpp 

MapOutput.o: MapOutput.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c MapOutput.cpp 

# Use the cs225 makefile template:
include cs225/make/cs225.mk

