CC = g++
CFLAGS = -Wall -g

COVIDMap: MapOutput.o MapTree.o 
	$(CC) $(CFLAGS) -o COVIDMap MapOutput.o MapTree.o 

MapOutput.o: MapOutput.cpp
	$(CC) $(CFLAGS) -c MapOutput.cpp

MapTree.o: MapTree.cpp 
	$(CC) $(CFLAGS) -c MapTree.cpp 

clean:
	rm *.o COVIDMap

# include TreeTraversals/
