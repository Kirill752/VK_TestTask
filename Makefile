CC=g++
STD=-std=c++23

all:
	$(CC) $(STD) main.cpp Graph.o validation.o utils.o; ./a.out; rm a.out

build:
	$(CC) $(STD) main.cpp Graph.o validation.o utils.o -o $(OUT)