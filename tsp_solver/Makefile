solver: main.o solve.o plot.o city.o
	gcc -o solver main.o solve.o plot.o city.o -lm

main.o: main.c
	gcc -c main.c

solve.o: solve.c
	gcc -c solve.c

plot.o: plot.c
	gcc -c plot.c

city.o: city.c
	gcc -c city.c

.PHONY: clean
clean:
	rm -f *.o *~ solver
