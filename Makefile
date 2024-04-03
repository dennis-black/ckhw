cksystem_path := ./cksystem
cksystem_src := ${cksystem_path}/cksystem.cpp
cksystem := ${cksystem_path}/cksystem.o

all: main.cpp ${cksystem_path}/cksystem.o ${cksystem_path}/cksystem.hpp
	g++ -g main.cpp ${cksystem}

cksystem.o: ${cksystem_path}/cksystem.cpp ${cksystem_path}/cksystem.hpp
	g++ -c ${cksystem_src}

clear:
	rm -rf a.out a.exe *.*~ *.o
	rm -rf ${cksystem_path}/*.*~ ${cksystem_path}/*.o

recomp:
	make clear
	make