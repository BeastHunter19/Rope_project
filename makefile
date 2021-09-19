CC=g++
CFLAGS=-I
target: src/main.cpp  src/Node.cpp src/Rope.cpp
	$(CC) -o src/main src/main.cpp src/Node.cpp src/Rope.cpp
