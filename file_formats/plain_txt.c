#define _XOPEN_SOURCE_EXTENDED 1

#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

void plain_txt_reading_loop(const char *file_name) {
  FILE *fp = read_line((char *)file_name);
  int page_num = 0;

  while (1) {
    WINDOW *page = create_window();

    int rows, cols;
    getmaxyx(page, rows, cols);

    wchar_t line[cols - 1];
    int line_num = 0;

    while (line_num < rows - 2 && fgetws(line, cols, fp) != NULL) {
      mvwaddnwstr(page, line_num + 1, 1, line, cols - 2);
      line_num++;
    }
    mvwprintw(page, line_num + 1, 1, "Page Number: %d", page_num);

    wrefresh(page);
    while (1) {
      int ch = wgetch(page);
      if (ch == 'n') {
        delwin(page);
        page_num++;
        break;
      } else if (ch == 'q') {
        delwin(page);
        fclose(fp);
        endwin();
        exit(0);
      } else if (ch == 'b' && page_num > 0) {
        delwin(page);
        page_num--;
        break;
      }
    }
  }
}