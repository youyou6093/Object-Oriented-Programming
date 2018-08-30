play: menu.o playlist.o song.o
	g++ menu.o playlist.o song.o -o play

menu.o :menu.cpp  playlist.h
	g++ -c menu.cpp


song.o :song.cpp song.h
	g++ -c song.cpp

playlist.o :playlist.cpp playlist.h
	g++ -c playlist.cpp


clean:
	rm *.o play
