all: main.cpp findAMac.o
	c++ main.cpp findAMac.o

findAMac.o: findAMac.cpp findAMac.h
	c++ -c findAMac.cpp

clean:
	rm -f *.o *~ *.*~ a.out
	