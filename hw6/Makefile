int: main.o student.o
	g++ main.o student.o -o student

main.o: main.cpp student.h
	g++ -c main.cpp

student.o :student.cpp student.h
	g++ -c student.cpp

clean:
	rm *.o student