#define _XOPEN_SOURCE_EXTENDED 1

#include "../include/utils.h"
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

FILE *read_line(char *file_name) {
  setlocale(LC_ALL, "");
  initscr();

  FILE *fptr;
  if ((fptr = fopen(file_name, "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  int result = fwide(fptr, 1);

  if (result > 0) {
    printf("tiddies");
    return fptr;
  } else if (result < 0) {
    printf("no tiddies");
  }
  return fptr;
}

void txt_reading_loop(const char *file_name) {
  WINDOW *page = create_window();

  int rows, cols;
  getmaxyx(page, rows, cols);

  FILE *fp = read_line((char *)file_name);

  wchar_t line[cols - 1];
  int line_num = 0;

  while (line_num < rows - 2 && fgetws(line, cols, fp) != NULL) {
    size_t len = wcslen(line);
    if (len > 0 && line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    mvwaddnwstr(page, line_num + 1, 1, line, cols - 1);
    line_num++;
  }

  wrefresh(page);
  while (1) {
    int ch = wgetch(page);
    if (ch == 'n') {
    } else if (ch == 'q') {
      delwin(page);
      fclose(fp);
      endwin();
      exit(0);
    }
  }

  fclose(fp);
  wrefresh(page);
}