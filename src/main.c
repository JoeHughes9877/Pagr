#include "../include/plain_txt.h"
#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <string.h>

bool usage_check(int argc);
int file_format(char *file);

const int arr_len = 16;

typedef struct {
  char *file_name;
  bool isArchive;
} FileFormat;

FileFormat acceptedFormats[] = {
    {".txt", false},  {".md", false},  {".csv", false},  {".log", false},
    {".ini", false},  {".cfg", false}, {".json", false}, {".xml", false},
    {".yaml", false}, {".yml", false}, {".rtf", false},  {".tex", false},
    {".html", false}, {".htm", false}, {".srt", false},  {".asc", false},
    {".epub", true},  {".EPUB", true}, {".docx", true},  {".zip", true}};

int main(int argc, char *argv[]) {

  if (usage_check(argc) == false) {
    printf("Usage: ./pagr <filename.filetype>\n");
    exit(0);
  }

  char *file_type;
  if (file_format(argv[1]) == 1) {
    file_type = argv[1];
  } else {
    printf("Invalid file type.\n");
    exit(0);
  }

  for (int i = 0; i < 15; i++) {
    if (strstr(file_type, &acceptedFormats->file_name[i]) == 0) {
      plain_txt_reading_loop(argv[1]);
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
    if (strstr(file, &acceptedFormats->file_name[i]) != NULL) {
      return 1;
    }
  }
  return 0;
}
