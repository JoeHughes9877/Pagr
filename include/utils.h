#include <ncurses.h>

WINDOW *create_window();
char *controller(WINDOW *win);
FILE *read_line(char *file_name);