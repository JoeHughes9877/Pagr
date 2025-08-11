#include <ncurses.h>
#include <string.h>

void init_theme_classic() { init_pair(1, COLOR_WHITE, COLOR_BLACK); }

void init_theme_dracula() { init_pair(1, COLOR_MAGENTA, COLOR_BLACK); }

void init_theme_gruvbox() { init_pair(1, COLOR_RED, COLOR_BLACK); }

void init_theme_nord() { init_pair(1, COLOR_BLUE, COLOR_BLACK); }

void init_theme_monokai() { init_pair(1, COLOR_YELLOW, COLOR_BLACK); }

void choose_theme(const char *theme_name) {
  if (theme_name == NULL) {
    init_theme_dracula(); // default theme
  } else if (strcmp(theme_name, "dracula") == 0) {
    init_theme_dracula();
  } else if (strcmp(theme_name, "gruvbox") == 0) {
    init_theme_gruvbox();
  } else if (strcmp(theme_name, "nord") == 0) {
    init_theme_nord();
  } else if (strcmp(theme_name, "monokai") == 0) {
    init_theme_monokai();
  } else {
    init_theme_classic();
  }
}
