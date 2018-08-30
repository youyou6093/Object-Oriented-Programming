temp: main.o temperature.o
	g++ main.o temperature.o -o temp

main.o: main.cpp temperature.h
	g++ -c main.cpp

temperature.o :temperature.cpp temperature.h
	g++ -c temperature.cpp

clean:
	rm *.o temp