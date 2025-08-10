#include <stdio.h>
#define _XOPEN_SOURCE_EXTENDED 1

#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// arbatary number, place holder for logic before i use dynamic mem allocation.
#define MAX_PAGES 10000
long page_offsets[MAX_PAGES];
int current_page = 0;
int total_pages = 0;

void plain_txt_reading_loop(const char *file_name) {
  FILE *fp = open_plain_txt_file((char *)file_name);

  while (1) {
    page_offsets[current_page] = ftell(fp);

    WINDOW *page = create_window();
    int rows, cols;
    getmaxyx(page, rows, cols);

    wchar_t line[cols - 1];
    int line_num = 0;

    while (line_num < rows - 2 && fgetws(line, cols, fp) != NULL) {
      mvwaddnwstr(page, line_num + 1, 1, line, cols - 2);
      line_num++;
    }
    mvwprintw(page, line_num + 1, 1, "Page Number: %d", current_page);

    wrefresh(page);
    while (1) {
      int ch = wgetch(page);
      if (ch == 'n') { // next page
        delwin(page);
        current_page++;
        break;
      } else if (ch == 'b' && current_page > 0) { // prev page
        delwin(page);
        current_page--;
        fseek(fp, page_offsets[current_page], SEEK_SET);
        break;
      } else if (ch == 'q') { // close
        delwin(page);
        fclose(fp);
        endwin();
        exit(0);
      }
    }
  }
}