importgame.o: importgame.cpp importgame.h
	g++ -c importgame.cpp

savegame.o: savegame.cpp savegame.h
	g++ -c savegame.cpp

shuffledeck.o: shuffledeck.cpp shuffledeck.h
	g++ -c shuffledeck.cpp

initializedeck.o: initializedeck.cpp initializedeck.h
	g++ -c initializedeck.cpp

pickcard.o: pickcard.cpp pickcard.h  
	g++ -c pickcard.cpp

main.o: main.cpp importgame.h savegame.h initializedeck.h pickcard.h shuffledeck.h
	g++ -c main.cpp

main: importgame.o savegame.o initializedeck.o pickcard.o shuffledeck.o main.o
	g++  importgame.o savegame.o initializedeck.o pickcard.o shuffledeck.o main.o -o main

clean:
	rm -f main.o importgame.o savegame.o initializedeck.o pickcard.o shuffledeck.o main

.PHONY: clean


