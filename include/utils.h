#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

WINDOW *create_window();

FILE *open_plain_txt_file(char *file_name);

int unzip_file(char *file_name);

void close_application(WINDOW *page, FILE *fp);