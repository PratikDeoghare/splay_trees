

test: test.cc splaytree.o
	g++ test.cc splaytree.o -o test
splaytree.o: splaytree.h splaytree.cc
	g++ -c splaytree.cc
