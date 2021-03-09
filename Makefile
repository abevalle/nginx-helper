output: src/main.o
	g++ src/main.o -o dist/output

validation.o: src/validation.cpp
	g++ -c src/validation.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm src/*.o dist/output

run:
	./dist/output