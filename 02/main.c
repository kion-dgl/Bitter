#include <ncurses.h>
#include "src/hex.h"

int main(int argc, char *argv[]) {

	FILE *fp;

	if(argc != 2) {
		fprintf(stderr, "Usage: dxe <filename>\n");
		return 1;
	}

	initscr();
	noecho();

	dxe_options(argv[1]);
	dxe_loop();

	endwin();
	return 0;

}
