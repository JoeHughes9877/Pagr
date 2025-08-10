#define _XOPEN_SOURCE_EXTENDED 1

#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <wchar.h>

WINDOW *create_window() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int y, x;
  getmaxyx(stdscr, y, x);

  WINDOW *mywin = newwin(y - 2, x - 16, 2, 10);
  box(mywin, 0, 0);

  return mywin;
}

FILE *open_plain_txt_file(char *file_name) {
  setlocale(LC_ALL, "");

  FILE *fptr;
  if ((fptr = fopen(file_name, "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  fwide(fptr, 1);
  return fptr;
}