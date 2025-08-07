#include "../include/utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reading_loop(char *contents, char *file_name);

int num = 0;

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

  int total_rows, total_cols;
  int lines = 0;

  getmaxyx(win, total_rows, total_cols);

  char *line = malloc(total_cols + 1);

  int current_offset = 0;

  while (1) {
    strcpy(&contents[current_offset], line);
    current_offset += strlen(line);
    contents[current_offset++] = '\n';
    mvwprintw(win, 5, 10, "%s", line);

    wrefresh(win);
    lines++;
  }

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