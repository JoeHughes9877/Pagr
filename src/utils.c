#define _XOPEN_SOURCE_EXTENDED 1
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>

WINDOW *create_window() {
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int y, x;
  getmaxyx(stdscr, y, x);

  WINDOW *mywin = newwin(y - 2, x - 16, 2, 10);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  return mywin;
}

FILE *open_plain_txt_file(char *file_name) {
  setlocale(LC_ALL, "");

  FILE *fptr;
  if ((fptr = fopen(file_name, "r")) == NULL) {
    printf("Error! opening file\n");
    exit(1);
  }

  fwide(fptr, 1);
  return fptr;
}

void close_application(WINDOW *page, FILE *fp) {
  delwin(page);
  fclose(fp);
  endwin();
  exit(0);
}