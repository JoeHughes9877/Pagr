#include "../include/utils.h"
#include <ncurses.h>
#include <stdio.h>

void reading_loop(char *contents, char *file_name);

static int num = 1;

void open_txt_file(char *file_name) {
  FILE *fptr;
  num++;

  fptr = fopen(file_name, "r");

  char myString[10000];

  fgets(myString, 1000 * num, fptr);

  reading_loop(myString, file_name);
}

void reading_loop(char *contents, char *file_name) {
  WINDOW *win = create_window();
  refresh();

  mvwprintw(win, 1, 1, "%s", contents);
  wrefresh(win);

  int ch;
  while (1) {
    ch = getch();

    if (ch == 'n') {
      wclear(win);
      open_txt_file(file_name);
    } else if (ch == 'c') {
      delwin(win);
      endwin();
      break;
    }
  }
}