dis: main.o distance.o
	g++ main.o distance.o -o dis

main.o: main.cpp distance.h
	g++ -c main.cpp

distance.o: distance.cpp distance.h
	g++ -c distance.cpp

clean:
	rm *.o dis 