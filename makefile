all: martingale.o
	gcc martingale.o -o martingale
martingale.o: martingale.c martingale.h
	gcc -c -O2 -o martingale.o martingale.c

clean:
	rm -rvf *.o martingale

