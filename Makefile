output: main.o
	g++ main.o -o output

validation.o: validation.cpp
	g++ -c validation.cpp

main.o: main.cpp
	g++ -c main.cpp