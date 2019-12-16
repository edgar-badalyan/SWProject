CCFLAGS = -std=c++11

main: main.o psqReader.o phrReader.o pinReader.o smithWaterman.o
	g++ main.o psqReader.o phrReader.o pinReader.o smithWaterman.o -o main -$(CCFLAGS)
	rm *.o

psqReader.o: psqReader.cpp psqReader.h
	g++ -c psqReader.cpp -$(CCFLAGS)

phrReader.o: phrReader.cpp phrReader.h
	g++ -c phrReader.cpp -$(CCFLAGS)

pinReader.o: pinReader.cpp pinReader.h psqReader.h phrReader.h
	g++ -c pinReader.cpp -$(CCFLAGS)
smithWaterman.o: smithWaterman.cpp smithWaterman.h
	g++ -c smithWaterman.cpp -$(CCFLAGS)
main.o: main.cpp pinReader.h psqReader.h phrReader.h
	g++ -c main.cpp -$(CCFLAGS)
