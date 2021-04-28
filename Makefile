nginx-utils: src/main.o src/validation.o src/makeNginx.o
	g++ src/main.o -o dist/nginx-utils -lstdc++fs

validation.o: src/validation.cpp
	g++  -std=c++17 src/validation.cpp

main.o: src/main.cpp
	g++ -std=c++17 src/main.cpp

menu.o: src/menu.cpp
	g++ -std=c++17 src/menu.cpp

makeNginx.o: src/makeNginx.cpp
	g++ -std=c++17 src/makeNginx.cpp

clean:
	rm src/*.o dist/nginx-utils

run:
	./dist/nginx-utils