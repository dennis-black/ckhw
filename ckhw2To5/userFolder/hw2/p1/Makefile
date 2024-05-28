all: main.cpp string.o
	c++ main.cpp string.o

string.o: string.cpp string.h
	c++ -c string.cpp

clean:
	rm -f *.o *~ *.*~ a.out
