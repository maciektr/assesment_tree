# Makefile

main: 
	g++ -O2 -static -std="c++14" -o main.o main.cpp TreeMetrics.h TreeMetrics.cpp Node.h Node.cpp

devel: 
	g++ -O2 -static -std="c++14" -Wall -Wshadow  -o main.o main.cpp TreeMetrics.h TreeMetrics.cpp Node.h Node.cpp

debug_glib: 
	g++ -O2 -std="c++14" -Wall -Wshadow -D_GLIBCXX_DEBUG  -o main.o main.cpp TreeMetrics.h TreeMetrics.cpp Node.h Node.cpp

debug_addr:
	g++ -O2 -std="c++14" -Wall -Wshadow -fsanitize=address  -o main.o main.cpp TreeMetrics.h TreeMetrics.cpp Node.h Node.cpp