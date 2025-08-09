#include "../include/plain_txt.h"
#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <string.h>

bool usage_check(int argc);
char *file_format(char *file);

const int arr_len = 15;

char *accepted_file_formats[] = {
    ".txt",  // Standard text file
    ".md",   // Markdown
    ".csv",  // Comma-separated values
    ".log",  // Log files
    ".ini",  // Configuration files
    ".cfg",  // Alternate config
    ".json", // JSON (technically structured text)
    ".xml",  // XML (structured text)
    ".yaml", // YAML
    ".yml",  // YAML alternative extension
    ".rtf",  // Rich Text Format
    ".tex",  // LaTeX source
    ".html", // HTML source
    ".htm",  // HTML alternative
    ".srt",  // SubRip subtitles
    ".asc"   // ASCII armored text
};

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

  for (int i = 0; i < 15; i++) {
    if (strstr(file_type, accepted_file_formats[i]) == 0) {
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

char *file_format(char *file) {

  for (int i = 0; i < arr_len; i++) {
    if (strstr(file, accepted_file_formats[i]) != NULL) {
      return accepted_file_formats[i];
    }
  }
  return NULL;
}
