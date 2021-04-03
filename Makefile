nginx-utils: src/main.o src/validation.o src/makeNginx.o
	g++ src/main.o src/validation.o src/makeNginx.o -o dist/nginx-utils

validation.o: src/validation.cpp
	g++ -c -std=c++1z src/validation.cpp 

main.o: src/main.cpp
	g++ -c -std=c++1z src/main.cpp 

makeNginx.0: src/makeNginx.cpp
	g++ -c -std=c++1z src/makeNginx.cpp 

clean:
	rm src/*.o dist/nginx-utils

run:
	./dist/nginx-utils