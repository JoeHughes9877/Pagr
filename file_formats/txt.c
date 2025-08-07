#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void txt_reading_loop(const char *file_name) {
  FILE *fp = fopen(file_name, "r");
  if (!fp) {
    perror("Failed to open file");
    return;
  }

  WINDOW *page = create_window();

  int rows, cols;
  getmaxyx(page, rows, cols);

  char line[cols - 1];
  int line_num = 0;

  while (line_num < rows - 2 && fgets(line, sizeof(line), fp) != NULL) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    mvwprintw(page, line_num + 1, 1, "%s", line);
    line_num++;
  }

  while (1) {
    int ch = wgetch(page);
    if (ch == 'n') {
      printw("You pressed n!\n");
    }
  }

  wrefresh(page);
  fclose(fp);
}