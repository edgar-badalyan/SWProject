CCFLAGS = -std=c++11 -O3 -Ofast

main: main.o smithWaterman.o psqReader.o phrReader.o pinReader.o databaseReader.o
	g++ $^ -o main -$(CCFLAGS)
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

