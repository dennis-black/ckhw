all: main.cpp contact.o
	c++ main.cpp contact.o

contact.o: contact.cpp contact.h
	c++ -c contact.cpp

clean:
	rm -f *.o *~ *.*~ a.out
	