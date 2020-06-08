# g++ -o Algo main.cpp chapter3/Array.cpp
objects=Array.o list.o main.o cipher.o
Algo: $(objects)
	g++ -o Algo $(objects)
Array.o: chapter3/Array.cpp chapter3/Array.h
	g++ -o Array.o -c chapter3/Array.cpp
list.o: chapter3/list.cpp chapter3/list.h
	g++ -o list.o -c chapter3/list.cpp
cipher.o: chapter3/cipher.cpp chapter3/cipher.h
	g++ -o cipher.o -c chapter3/cipher.cpp
main.o: main.cpp main.h
	g++ -o main.o -c main.cpp
clean:
	rm $(objects) Algo