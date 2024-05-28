all: main.cpp twoNumbers.o
	c++ main.cpp twoNumbers.o

twoNumbers.o: twoNumbers.cpp twoNumbers.h
	c++ -c twoNumbers.cpp

clean:
	rm -f *.o *~ *.*~ a.out
	