#define _XOPEN_SOURCE_EXTENDED 1
#include "../include/themes.h"
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>

WINDOW *create_window(char *theme) {
  initscr();
  start_color();
  choose_theme(theme);
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int y, x;
  getmaxyx(stdscr, y, x);

  WINDOW *mywin = newwin(y - 2, x - 16, 2, 10);
  wattron(mywin, COLOR_PAIR(1));
  wrefresh(mywin);
  return mywin;
}

FILE *open_plain_txt_file(char *file_name) {
  setlocale(LC_ALL, "");

  printf("\file name: %s\n", file_name);

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