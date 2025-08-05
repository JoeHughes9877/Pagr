#include <ncurses.h>
#include <panel.h>

int main(int argc, char *argv[]) {
  initscr();
  printw("Pagr!!!");
  refresh();
  getch();
  endwin();

  return 0;
}