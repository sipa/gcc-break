test: test.c util.c
	gcc -m32 -O2 test.c util.c -save-temps -o test
