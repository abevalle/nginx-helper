CC = g++
CFLAGS = -std=c++17 -g -w -Wall

nginx-utils: src/main.o src/validation.o src/makeNginx.o src/menu.o
	$(CC) $(CFLAGS) src/main.o -o dist/nginx-utils -lstdc++fs

unit-test: src/test.o
	$(CC) $(CFLAGS) src/test.o -o dist/unit-test -lstdc++fs

validation.o: src/validation.h src/validation.cpp
	$(CC) $(CFLAGS) src/validation.cpp

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

test.o: src/test.cpp
	$(CC) $(CFLAGS) src/test.cpp

menu.o: src/menu.cpp
	$(CC) $(CFLAGS) src/menu.cpp
	

makeNginx.o: src/makeNginx.cpp
	$(CC) $(CFLAGS) src/makeNginx.cpp

clean:
	rm src/*.o dist/nginx-utils dist/unit-test

run:
	./dist/nginx-utils