all:
	g++ -std=c++11 -c *.cpp
	g++ -std=c++11 *.o -o huffman.out
clean:
	rm -rf *.o *.out
