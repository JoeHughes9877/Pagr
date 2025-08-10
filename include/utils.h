#include <ncurses.h>

WINDOW *create_window();
char *controller(WINDOW *win);
FILE *open_plain_txt_file(char *file_name);