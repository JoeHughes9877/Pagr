#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>

void usagecheck(int argc);

int main(int argc, char *argv[]) {
  usagecheck(argc);

  return 0;
}

void usagecheck(int argc) {
  if (argc != 1) {
    printf("Usage: ./pagr <filename.filetype>\n");
    exit(0);
  }
}