game: main.o core.o
	gcc -o game main.o core.o `sdl2-config --cflags --libs`

main.o: main.c core/core.h
	gcc -g -c main.c

core.o: core/core.c core/core.h
	gcc -g -c core/core.c

clean:
	rm *.o game