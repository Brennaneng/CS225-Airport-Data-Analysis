COVIDMap: MapOutput.o MapTree.o
	g++ MapOutput.o MapTree.o -o COVIDMap

MapOutput.o: MapOutput.cpp
	g++ -c MapOutput.cpp

MapTree.o: MapTree.cpp
	g++ -c MapTree.cpp

clean: 
	rm *.o COVIDMap
