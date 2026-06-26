xxd-c: xxd-c.o
	gcc xxd-c.o -o xxd-c
	rm xxd-c.o

xxd-c.o: xxd-c.c
	gcc -c xxd-c.c -o xxd-c.o
