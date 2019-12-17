CCFLAGS = -std=c++11 -O3 -Ofast

main: main.o smithWaterman.o psqReader.o phrReader.o pinReader.o databaseReader.o
	g++ main.o smithWaterman.o psqReader.o phrReader.o pinReader.o databaseReader.o -o main -$(CCFLAGS)
	rm *.o

psqReader.o: psqReader.cpp psqReader.h smithWaterman.h
	g++ -c psqReader.cpp -$(CCFLAGS)

phrReader.o: phrReader.cpp phrReader.h
	g++ -c phrReader.cpp -$(CCFLAGS)

pinReader.o: pinReader.cpp pinReader.h
	g++ -c pinReader.cpp -$(CCFLAGS)

databaseReader.o: databaseReader.cpp databaseReader.h pinReader.h psqReader.h phrReader.h
	g++ -c databaseReader.cpp -$(CCFLAGS)

main.o: main.cpp databaseReader.h
	g++ -c main.cpp -$(CCFLAGS)


smithWaterman.o: smithWaterman.cpp smithWaterman.h
	g++ -c smithWaterman.cpp -$(CCFLAGS)

smithWaterman3.o: smithWaterman3.cpp smithWaterman2.h
	g++ -c smithWaterman3.cpp -$(CCFLAGS)

psqReader20.o: psqReader20.cpp psqReader.h smithWaterman2.h
	g++ -c psqReader20.cpp -$(CCFLAGS)

main2: main.o smithWaterman3.o psqReader20.o phrReader.o pinReader.o
	g++ main.o smithWaterman3.o psqReader20.o phrReader.o pinReader.o -o main2 -$(CCFLAGS)
	rm *.o
