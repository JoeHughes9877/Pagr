#include "../include/utils.h"
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

FILE *read_line(char *file_name) {
  setlocale(LC_ALL, "");
  initscr();
  printw("[DEBUG] Locale set and ncurses initialized\n");
  refresh();

  FILE *fptr;
  printw("[DEBUG] Opening file: %s\n", file_name);
  refresh();
  if ((fptr = fopen(file_name, "r")) == NULL) {
    printw("[ERROR] Error opening file: %s\n", file_name);
    refresh();
    endwin();
    exit(1);
  }
  printw("[DEBUG] File opened successfully\n");
  refresh();

  int result = fwide(fptr, 1);
  printw("[DEBUG] fwide result: %d\n", result);
  refresh();

  if (result > 0) {
    printw("[DEBUG] File stream is wide oriented\n");
    refresh();
    return fptr;
  } else if (result < 0) {
    printw("[DEBUG] File stream is byte oriented\n");
    refresh();
  } else {
    printw("[DEBUG] File stream orientation is undecided\n");
    refresh();
  }
  return fptr;
}

void txt_reading_loop(const char *file_name) {
  printw("[DEBUG] Creating window...\n");
  refresh();
  WINDOW *page = create_window();

  int rows, cols;
  getmaxyx(page, rows, cols);
  printw("[DEBUG] Window size: rows=%d, cols=%d\n", rows, cols);
  refresh();

  FILE *fp = read_line((char *)file_name);

  char line[cols - 1];
  int line_num = 0;

  printw("[DEBUG] Start reading lines...\n");
  refresh();

  while (line_num < rows - 2 && fgets(line, sizeof(line), fp) != NULL) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    printw("[DEBUG] Line %d: %s\n", line_num, line);
    refresh();

    mvwprintw(page, line_num + 1, 1, "%s", line);
    line_num++;
  }

  wrefresh(page);
  printw("[DEBUG] Finished printing lines, waiting for user input...\n");
  refresh();

  while (1) {
    int ch = wgetch(page);
    printw("[DEBUG] User pressed: %c (code %d)\n", ch, ch);
    refresh();

    if (ch == 'n') {
      printw("[DEBUG] 'n' pressed (no action implemented)\n");
      refresh();
    } else if (ch == 'q') {
      printw("[DEBUG] 'q' pressed, quitting...\n");
      refresh();

      delwin(page);
      fclose(fp);
      endwin();
      exit(0);
    }
  }

  // This part is unreachable because of the infinite input loop,
  // but we include it for completeness.
  fclose(fp);
  wrefresh(page);
}
