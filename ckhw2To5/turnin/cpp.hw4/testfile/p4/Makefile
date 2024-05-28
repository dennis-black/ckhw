all: main.cpp dynamic2DArray.o
	c++ main.cpp dynamic2DArray.o

dynamic2DArray.o: dynamic2DArray.cpp dynamic2DArray.h
	c++ -c dynamic2DArray.cpp

clean:
	rm -f *.o *~ *.*~ a.out
	