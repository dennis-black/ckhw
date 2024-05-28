all: main.cpp star.o date.o
	c++ main.cpp star.o date.o
	
star.o:	star.cpp star.h
	c++ -c star.cpp

date.o:	date.cpp date.cpp
	c++ -c date.cpp

clean:
	rm -f *.o *~ *.*~ a.out
