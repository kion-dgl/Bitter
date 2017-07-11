#include "hex.h"

void dxe_loop() {
	
	int ch, x, y, max_y, tmp, run;

	dxe_draw_header();
	dxe_draw_offset();
	dxe_draw_body();

	y = 1;
	x = 10;
	run = 1;
	max_y = getmaxy(stdscr);
	
	move(y, x);

	// Wait for End

	while((ch = getch()) != EOF) {
		
		switch(ch) {
			case 68:
				
				x--;

				if(x < 10) {
					
					if(y == 1) {
						x = 10;
					} else {
						y--;
						x = 47;
					}
				} else if(x % 10 > 7) {
					tmp = x / 10;
					x = tmp * 10 + 7;
				}

				mvprintw(max_y - 1, 0, "Left");

			break;
			case 67:
				
				x++;

				if(x > 47) {
					
					if(y == max_y - 2) {
						x = 47;
					} else {
						y++;
						x = 10;
					}
				} else if(x % 10 > 7) {
					tmp = x / 10;
					x = (tmp + 1) * 10;
				}
				
				mvprintw(max_y - 1, 0, "Right");

			break;
			case 65:
				y--;

				if(y < 1) {
					y = 1;
				}
				
				mvprintw(max_y - 1, 0, "Up");

			break;
			case 66:

				y++;

				if(y > max_y - 2) {
					y = max_y - 2;
				}

				mvprintw(max_y - 1, 0, "Down");

			break;
			case 'q':
				
				run = 0;

			break;
			default:
				
				mvprintw(max_y - 1, 0, "NUll %d", ch);

			break;
		}

		dxe_draw_header();
		dxe_draw_offset();
		dxe_draw_body();
			
		move(y, x);
		refresh();
		
		if(!run) {
			break;
		}

	}

}

void dxe_draw_header() {
	
	attron(A_UNDERLINE);
	mvprintw(0, 0, "Offset  ");
	
	mvprintw(0, 10, "0x00    ");
	mvprintw(0, 20, "0x04    ");
	mvprintw(0, 30, "0x08    ");
	mvprintw(0, 40, "0x0C    ");

	mvprintw(0, 50, "Ascii            ");

	attroff(A_UNDERLINE);

}

void dxe_draw_offset() {

	int i, y;

	y = getmaxy(stdscr);
	
	for(i = 1; i < y - 1; i++) {

		mvprintw(i, 0, "0x%06x", (i - 1) * 0x10);

	}

}

void dxe_draw_body() {

	int i, y;

	y = getmaxy(stdscr);

	for(i = 1; i < y - 1; i++) {

		mvprintw(i, 10, "01234567");
		mvprintw(i, 20, "01234567");
		mvprintw(i, 30, "01234567");
		mvprintw(i, 40, "01234567");

		mvprintw(i, 50, ".................");
	
	}

}
