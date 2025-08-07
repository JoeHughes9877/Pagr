#include <ncurses.h>

WINDOW *create_window() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  WINDOW *mywin = newwin(0, 0, 0, 0);

  return mywin;
}