CC=g++
STD=-std=c++23

run:
	$(CC) $(STD) main.cpp; ./a.out; rm a.out

build:
	$(CC) $(STD) main.cpp -o $(OUT)