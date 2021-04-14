COVIDMap: MapOutput.o MapTree.o test.o
	g++ MapOutput.o MapTree.o test.o -o COVIDMap

test: ReadFile.o 
	g++ ReadFile. o -o test

ReadFile.o: ReadFile.cpp 
	g++ -c ReadFile.cpp

MapOutput.o: MapOutput.cpp
	g++ -c MapOutput.cpp

MapTree.o: MapTree.cpp
	g++ -c MapTree.cpp

test.o: test.cpp
	g++ -c test.cpp

clean: 
	rm *.o COVIDMap test 
