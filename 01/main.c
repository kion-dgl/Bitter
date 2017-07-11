#include <ncurses.h>
#include "src/hex.h"

int main(int argc, char *argv[]) {

	FILE *fp;

	if(argc != 2) {
		fprintf(stderr, "Usage: dxe <filename>\n");
		return 1;
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		fprintf(stderr, "Could not open %s for reading\n", argv[1]);
		return 1;
	}

	initscr();
	noecho();
	
	dxe_loop();

	endwin();
	fclose(fp);

	return 0;

}
