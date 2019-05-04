COMP=g++ -m32 -std=c++11 -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -pthread -D_FILE_OFFSET_BITS=64 -Wstack-protector -fstack-protector-all -fPIE -pipe -O2 -O2 -ggdb3 -Wall -c
LINK=g++ -m32 -std=c++11 -Wstack-protector -fstack-protector-all -fPIE -pipe -O2 -O2 -ggdb3 -Wall -pthread -Wl,-z -Wl,relro -Wl,-z -Wl,now -pie

test: test.o sha.o
	$(LINK) test.o sha.o -o test
test.o: test.cpp hash.h sha.h
	$(COMP) test.cpp -o test.o
sha.o: sha.cpp hash.h
	$(COMP) sha.cpp -o sha.o

