.FORCE:
test: test.c
	gcc -m32 -O1 -finline-small-functions -save-temps $^ -o $@
	./$@

clean:
	rm -f *.s *.i *.o test

