#include <ncurses.h>

WINDOW *create_window() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  WINDOW *mywin = newwin(60, 95, 2, 10);
  box(mywin, 0, 0);

  return mywin;
}