#define _XOPEN_SOURCE_EXTENDED 1

#include "../include/utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

// arbatary number, i think no books will pass.
#define MAX_PAGES 10000
long page_offsets[MAX_PAGES];
int current_page = 0;
int total_pages = 0;
int eof = 0;

void plain_txt_reading_loop(const char *file_name) {
  FILE *fp = open_plain_txt_file((char *)file_name);

  while (1) {
    page_offsets[current_page] = ftell(fp);

    WINDOW *page = create_window();
    int rows, cols;
    getmaxyx(page, rows, cols);

    wchar_t line[cols - 1];
    int line_num = 0;
    int page_eof = 0;

    while (line_num < rows - 2 && fgetws(line, cols - 2, fp) != NULL) {
      mvwaddnwstr(page, line_num + 1, 1, line, cols - 2);
      line_num++;
    }

    mvwprintw(page, line_num + 1, 1, "Page Number: %d", current_page);
    wrefresh(page);

    if (feof(fp)) {
      page_eof = 1;
      mvwprintw(page, line_num + 2, 1, "The End.'");
    }

    // reformat page border
    box(page, 0, 0);
    wrefresh(page);

    while (1) {
      int ch = wgetch(page);
      if (ch == 'n' && !page_eof) {
        delwin(page);
        current_page++;
        break;
      } else if (ch == 'b' && current_page > 0) {
        delwin(page);
        current_page--;
        fseek(fp, page_offsets[current_page], SEEK_SET);
        break;
      } else if (ch == 'q') {
        close_application(page, fp);
      }
    }
  }
}
