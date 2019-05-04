COMP=g++ -m32 -std=c++11 -O2 -c
LINK=g++ -m32 -std=c++11

test: test.cpp util.cpp
	g++ -m32 -O2 test.cpp util.cpp -o test

