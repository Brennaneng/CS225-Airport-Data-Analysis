CC = g++
CFLAGS = -Wall -g

COVIDMap: main.o  
	$(CC) $(CFLAGS) -o COVIDMap main.o 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp



ReadFile.o: ReadFile.cpp
	$(CC) $(CFLAGS) -c ReadFile.cpp

clean:
	rm *.o COVIDMap

# include TreeTraversals/
