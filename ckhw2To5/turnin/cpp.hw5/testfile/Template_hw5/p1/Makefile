all: main.cpp date.o
	c++ main.cpp date.o

date.o:	date.cpp date.h
	c++ -c date.cpp

clean:
	rm -f *.o *~ *.*~ a.out
