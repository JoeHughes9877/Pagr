#include "../include/plain_txt.h"
#include "../include/utils.h"
#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <string.h>

bool usage_check(int argc);
int file_format(char *file);

const int arr_len = 16;

const char *acceptedFormats[] = {"txt",  "md",  "csv", "log",  "json", "xml",
                                 "yaml", "yml", "ini", "conf", "cfg",  "rtf",
                                 "tex",  "asc", "bat", "sh",   "htm"};

int main(int argc, char *argv[]) {

  if (usage_check(argc) == false) {
    printf("Usage: ./pagr <filename.filetype>\n");
    exit(0);
  }

  char *file_to_open;
  if (file_format(argv[1]) == 1) {
    file_to_open = argv[1];
  } else {
    printf("Invalid file type.\n");
    exit(0);
  }

  for (int i = 0; i < arr_len; i++) {
    if (strstr(file_to_open, acceptedFormats[i]) == 0) {
      printf("file to open: %s", file_to_open);
      plain_txt_reading_loop(file_to_open);
    }
  }

  return 0;
}

bool usage_check(int num_of_args) {
  if (num_of_args != 2) {
    return false;
  }
  return true;
}

int file_format(char *file) {
  for (int i = 0; i < arr_len; i++) {
    if (strstr(file, acceptedFormats[i]) != NULL) {
      return 1;
    }
  }
  return 0;
}
