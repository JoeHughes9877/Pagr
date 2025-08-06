#include <ncurses.h>
#include <stdio.h>

void reading_loop(char *contents);

void open_txt_file(char *file_name) {
  FILE *fptr;

  fptr = fopen(file_name, "r");

  char myString[10000];

  fgets(myString, 100, fptr);

  reading_loop(myString);
}

void reading_loop(char *contents) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  mvprintw(1, 1, "%s", contents);

  refresh();
  getch();

  endwin();
}