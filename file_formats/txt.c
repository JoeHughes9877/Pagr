#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>

char *read_line(char *file_name, int win_width) {
  int num;
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

void txt_reading_loop(char *file_name) {}