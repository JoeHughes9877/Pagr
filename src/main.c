#include "../include/plain_txt.h"
#include <ncurses.h>
#include <panel.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void usage_check(int argc);
bool is_valid_extension(char *file);
void open_file(char *file_to_open);

const char *acceptedFormats[] = {"txt",  "md",  "csv", "log",  "json", "xml",
                                 "yaml", "yml", "ini", "conf", "cfg",  "rtf",
                                 "tex",  "asc", "bat", "sh",   "htm"};
static const size_t arr_len =
    sizeof(acceptedFormats) / sizeof(acceptedFormats[0]);

void usage_check(int num_of_args) {
  if (num_of_args == 3) {
    return;
  } else {
    printf("Usage: ./pagr <filename.filetype> [theme]\n");
    exit(0);
  }
}

bool is_valid_extension(char *file) {
  for (size_t i = 0; i < arr_len; i++) {
    if (strstr(file, acceptedFormats[i]) != NULL) {
      return true;
    }
  }
  printf("Invalid file type.\n");
  exit(0);
}

void read_book(char *file_to_open) {
  for (size_t i = 0; i < arr_len; i++) {
    if (strstr(file_to_open, acceptedFormats[i])) {
      plain_txt_reading_loop(file_to_open);
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  usage_check(argc);

  char *file_to_open;
  if (is_valid_extension(argv[1])) {
    file_to_open = argv[1];
  }

  read_book(file_to_open);

  return 0;
}
