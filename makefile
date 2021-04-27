make: main.o check.o Matrix.o write.o makebit.o gifenc.o
	gcc main.o check.o Matrix.o write.o makebit.o gifenc.o -o gameoflife 

main.o: main.c
	gcc -c main.c

check.o: check.c check.h
	gcc -c check.c

Matrix.o: Matrix.c Matrix.h
	gcc -c Matrix.c

write.o: write.c write.h
	gcc -c write.c

makebit.o: makebit.c makebit.h
	gcc -c makebit.c

gifenc.o: gifenc.c gifenc.h
	gcc -c gifenc.c

clean:
	rm *.o gameoflife 

