#include <ncurses.h>
#include <string.h>

void init_theme_classic() {
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
}

void init_theme_ocean() {
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLUE);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}

void init_theme_solarized() {
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLUE);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_YELLOW);
}

void choose_theme(const char *theme_name) {
  if (strcmp(theme_name, "classic") == 0) {
    init_theme_classic();
  } else if (strcmp(theme_name, "ocean") == 0) {
    init_theme_ocean();
  } else if (strcmp(theme_name, "solarized") == 0) {
    init_theme_solarized();
  } else {
    init_theme_classic();
  }
}
