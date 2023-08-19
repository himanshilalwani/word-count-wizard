all: output

output: main.o hashtable.o vector.o hashnode.o heap.o
		g++ main.o hashtable.o vector.o hashnode.o heap.o -o output

main.o: main.cpp hashtable.h vector.h hashnode.h
		g++ -c main.cpp

hashtable.o: hashtable.cpp hashnode.h vector.h
		g++ -c hashtable.cpp

hashnode.o: hashnode.cpp
	g++ -c hashnode.cpp

vector.o:vector.cpp hashnode.h
	g++ -c vector.cpp

heap.o:heap.cpp hashnode.h
	g++ -c heap.cpp