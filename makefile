# Makefile

classes = TreeMetrics.h TreeMetrics.cpp Node.h Node.cpp Tree.h Tree.cpp

main: 
	g++ -O2 -static -std="c++14" -o main.out main.cpp $(classes)

devel: 
	g++ -O2 -static -std="c++14" -Wall -Wshadow  -o main.out main.cpp $(classes)

debug_glib: 
	g++ -O2 -std="c++14" -Wall -Wshadow -D_GLIBCXX_DEBUG  -o test.out test.cpp $(classes)

debug_addr:
	g++ -O2 -std="c++14" -Wall -Wshadow -fsanitize=address  -o test.out test.cpp $(classes)

test: 
	g++ -O2 -std="c++14" -Wall -Wshadow -D_GLIBCXX_DEBUG  -o test.out test.cpp $(classes)
	./test.out
	g++ -O2 -std="c++14" -Wall -Wshadow -fsanitize=address  -o test.out test.cpp $(classes)
	./test.out
