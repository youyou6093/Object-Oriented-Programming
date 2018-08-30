triangle: driver.o triangle.o
	g++ driver.o triangle.o -o triangle

driver.o: driver.cpp triangle.h
	g++ -c driver.cpp

triangle.o :triangle.cpp triangle.h
	g++ -c triangle.cpp

clean:
	rm *.o triangle