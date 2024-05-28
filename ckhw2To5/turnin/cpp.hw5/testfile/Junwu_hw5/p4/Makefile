all: Main.cpp Movie.o Star.o
	c++ Main.cpp Movie.o Star.o

Movie.o: Movie.cpp Movie.h 
	c++ -c Movie.cpp 

Star.o:	Star.cpp Star.h
	c++ -c Star.cpp

clean:
	rm -f *.o *~ *.*~ a.out
