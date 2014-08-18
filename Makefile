all:
	gcc -O3 machine.c main.c -o machine.out
test:
	gcc -O3 machine.c mm_test.c -o test.out
	./test.out
