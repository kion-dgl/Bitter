#include <ncurses.h>
#include <stdlib.h>

#define ENDIAN_LITTLE 0
#define ENDIAN_BIG    1

void dxe_loop();
void dxe_draw_header();
void dxe_draw_offset();
void dxe_draw_body();
