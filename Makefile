CCFLAGS = -std=c++11 -O3 -Ofast

main: main.o smithWaterman.o psqReader.o phrReader.o pinReader.o 
	g++ main.o smithWaterman.o psqReader.o phrReader.o pinReader.o -o main -$(CCFLAGS)
	rm *.o
	
psqReader.o: psqReader.cpp psqReader.h smithWaterman.h
	g++ -c psqReader.cpp -$(CCFLAGS)
	
phrReader.o: phrReader.cpp phrReader.h
	g++ -c phrReader.cpp -$(CCFLAGS)
	
pinReader.o: pinReader.cpp pinReader.h psqReader.h phrReader.h 
	g++ -c pinReader.cpp -$(CCFLAGS)

main.o: main.cpp pinReader.h psqReader.h phrReader.h
	g++ -c main.cpp -$(CCFLAGS)
	
smithWaterman.o: smithWaterman.cpp smithWaterman.h
	g++ -c smithWaterman.cpp -$(CCFLAGS)

smithWaterman3.o: smithWaterman3.cpp smithWaterman2.h
	g++ -c smithWaterman3.cpp -$(CCFLAGS)
	
psqReader2.o: psqReader2.cpp psqReader.h smithWaterman2.h
	g++ -c psqReader2.cpp -$(CCFLAGS)
	
main2: main.o smithWaterman3.o psqReader2.o phrReader.o pinReader.o 
	g++ main.o smithWaterman3.o psqReader2.o phrReader.o pinReader.o -o main2 -$(CCFLAGS)
	rm *.o
