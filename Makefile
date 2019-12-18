CCFLAGS = -std=c++11 -O3 -Ofast

<<<<<<< HEAD
main: main.o psqReader.o phrReader.o pinReader.o smithWaterman.o
	g++ main.o psqReader.o phrReader.o pinReader.o smithWaterman.o -o main -$(CCFLAGS)
	rm *.o

psqReader.o: psqReader.cpp psqReader.h
=======
main: main.o smithWaterman.o psqReader.o phrReader.o pinReader.o databaseReader.o
	g++ main.o smithWaterman.o psqReader.o phrReader.o pinReader.o databaseReader.o -o main -$(CCFLAGS)
	rm *.o

psqReader.o: psqReader.cpp psqReader.h smithWaterman.h
>>>>>>> master2
	g++ -c psqReader.cpp -$(CCFLAGS)

phrReader.o: phrReader.cpp phrReader.h
	g++ -c phrReader.cpp -$(CCFLAGS)
<<<<<<< HEAD

pinReader.o: pinReader.cpp pinReader.h psqReader.h phrReader.h
	g++ -c pinReader.cpp -$(CCFLAGS)
smithWaterman.o: smithWaterman.cpp smithWaterman.h
	g++ -c smithWaterman.cpp -$(CCFLAGS)
main.o: main.cpp pinReader.h psqReader.h phrReader.h
	g++ -c main.cpp -$(CCFLAGS)
=======

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
>>>>>>> master2
