#include <ncurses.h>

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