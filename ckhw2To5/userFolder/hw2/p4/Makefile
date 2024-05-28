all: main.cpp value.o
	c++ main.cpp value.o

value.o: value.cpp value.h
	c++ -c value.cpp

clean:
	rm -f *.o *~ *.*~ a.out
	