#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <string.h>

bool usage_check(int argc);
char *file_format(char *file);

int main(int argc, char *argv[]) {

  if (usage_check(argc) == false) {
    printf("Usage: ./pagr <filename.filetype>\n");
    exit(0);
  }
  char *file_type = file_format(argv[1]);

  if (file_type == NULL) {
    printf("Invalid file type.\n");
    exit(0);
  }

  initscr();
  printw("Pagr!");
  refresh();
  getch();
  endwin();

  return 0;
}

bool usage_check(int num_of_args) {
  if (num_of_args != 2) {
    return false;
  }
  return true;
}

#include <stdio.h>
#include <string.h>

char *file_format(char *file) {

  // NULL is needed to determin length of the arrray during runtime
  char *accepted_file_formats[] = {"txt", "pdf", NULL};
  int arr_len = 0;

  while (accepted_file_formats[arr_len] != NULL) {
    arr_len++;
  }

  for (int i = 0; i < arr_len; i++) {
    if (strstr(file, accepted_file_formats[i]) != NULL) {
      return accepted_file_formats[i];
    }
  }
  return NULL;
}
