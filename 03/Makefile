all:
	gcc -o src/hex.o -c src/hex.c -lncurses
	gcc -o dxe main.c src/hex.o -lncurses

run:
	./dxe main.c data/ST00_01.BIN

clean:
	rm dxe

edit:
	vim src/hex.c
