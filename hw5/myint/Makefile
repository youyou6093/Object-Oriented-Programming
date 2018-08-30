int: main.o myint.o
	g++ main.o myint.o -o int

main.o: main.cpp myint.h
	g++ -c main.cpp

mint.o :myint.cpp myint.h
	g++ -c myint.cpp

clean:
	rm *.o int