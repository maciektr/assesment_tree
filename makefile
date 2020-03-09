# Makefile

main: 
	g++ -O2 -static -std="c++14" -o main.o main.cpp TreeMetrics.h Node.h TreeMetrics.cpp Node.cpp

devel: 
	g++ -O2 -static -std="c++14" -Wall -Wshadow  -o main.o main.cpp TreeMetrics.h Node.h

debug: 
	g++ -O2 -std="c++14" -Wall -Wshadow -fsanitize=address  -o main.o main.cpp TreeMetrics.h Node.h