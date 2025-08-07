#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

char *read_line(char *file_name, int win_width) {
  FILE *fptr;

  char *buffer = malloc(win_width + 1);
  if ((fptr = fopen(file_name, "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  size_t line = fwrite(buffer, sizeof(char), win_width, fptr);
  buffer[line] = '\0';

  fclose(fptr);

  return buffer;
}

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

  while (line_num < rows && fgets(line, sizeof(line), fp) != NULL) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    mvwprintw(page, line_num + 1, 1, "%s", line);
    line_num++;
  }

  wrefresh(page);

  fclose(fp);
}